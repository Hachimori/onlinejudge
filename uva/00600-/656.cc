#include<iostream>
#include<stack>
#include<cstdlib>
#include<algorithm>

#define ADD 0
#define DIV 1
#define DUP 2
#define MUL 3
#define SUB 4
#define MAX_SIZE 11

using namespace std;

int nNum;
int initList[MAX_SIZE];
int ansList[MAX_SIZE];
int minLeng;
int minAns[MAX_SIZE];

bool read(){

  cin >> nNum;
  if(nNum==0) return false;

  for(int i=0;i<nNum;i++)
    cin >> initList[i];
  
  for(int i=0;i<nNum;i++)
    cin >> ansList[i];

  return true;
}

bool isValid(int nOpe, int ope[MAX_SIZE], stack<int> &nums){

  if(nums.size()!=1) return false;
  if(nums.top()!=ansList[0]) return false;

  stack<int> tmpStack[MAX_SIZE];

  for(int i=0;i<nNum;i++)
    tmpStack[i].push(initList[i]);

  for(int i=0;i<nOpe;i++){
    for(int j=0;j<nNum;j++){

      int a,b;
      
      if(ope[i]==DUP){
	tmpStack[j].push(tmpStack[j].top());
	continue;
      }
      
      a = tmpStack[j].top();
      tmpStack[j].pop();
      b = tmpStack[j].top();
      tmpStack[j].pop();

      if(ope[i]==ADD){	
	if(abs(a+b)>30000) return false;
	tmpStack[j].push(a+b);
      }
      if(ope[i]==MUL){	
	if(abs(a*b)>30000) return false;
	tmpStack[j].push(a*b);
      }
      if(ope[i]==SUB){	
	if(abs(b-a)>30000) return false;
	tmpStack[j].push(b-a);
      }
      if(ope[i]==DIV){	
	if(a==0) return false;
	tmpStack[j].push(b/a);
      }   

    }
  }

  for(int i=0;i<nNum;i++)
    if(tmpStack[i].top()!=ansList[i]) return false;

  return true;
}

bool rec(int curr, int ope[MAX_SIZE], stack<int> &nums, int cntDup){
  
  if(curr>minLeng) return false;
  if(isValid(curr,ope,nums)){
    if(curr==0){ 
      minLeng=0;
      return true;
    }

    if(minLeng>curr){
      minLeng = curr;
      for(int i=0;i<curr;i++)
	minAns[i] = ope[i];
    }
    else if(minLeng==curr){
      for(int i=0;i<curr;i++)
	if(minAns[i]>ope[i]){
	  for(int j=0;j<curr;j++)
	    minAns[j] = ope[j];
	  break;
	}
	else if(minAns[i]<ope[i]) break;
      
    }
    
    return false;
  }
  if(curr>=minLeng) return false;

  //ADD
  if(nums.size()>1){
    int a,b;
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();

    if(abs(a+b)<=30000){
      nums.push(a+b);
      ope[curr] = ADD;
      
      if(rec(curr+1,ope,nums,cntDup)) return true;
      
      nums.pop();
    }
    
    nums.push(b);
    nums.push(a);
  }

  //DIV
  if(nums.size()>1){
    int a,b;
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();
    
    if(a!=0){
      nums.push(b/a);
      ope[curr] = DIV;
      
      if(rec(curr+1,ope,nums,cntDup)) return true;
      
      nums.pop();
    }
    
    nums.push(b);
    nums.push(a);
  }

  //MUL
  if(nums.size()>1){
    int a,b;
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();

    if(abs(a*b)<=30000){
      nums.push(a*b);
      ope[curr] = MUL;
      
      if(rec(curr+1,ope,nums,cntDup)) return true;
      
      nums.pop();
    }
    
    nums.push(b);
    nums.push(a);
  }

  //SUB
  if(nums.size()>1){
    int a,b;
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();

    if(abs(b-a)<=30000){
      nums.push(b-a);
      ope[curr] = SUB;
      
      if(rec(curr+1,ope,nums,cntDup)) return true;
      
      nums.pop();
    }

    nums.push(b);
    nums.push(a);
  }


  //DUP
  if(cntDup<5){

    nums.push(nums.top());
    ope[curr] = DUP;
    
    if(rec(curr+1,ope,nums,cntDup+1)) return true;

    nums.pop();
  }
  
  return false;
}

void work(int cases){
  
  int ope[MAX_SIZE];
  stack<int> nums;

  minLeng=11;
  nums.push(initList[0]);
  

  cout << "Program " << cases << endl;
  rec(0,ope,nums,0);
    
  if(minLeng==0)
    cout << "Empty sequence" << endl;
  else if(minLeng==11)
    cout << "Impossible" << endl;
  else {
    for(int i=0;i<minLeng;i++){
      if(i!=0) cout << ' ';
      if(minAns[i]==ADD) cout << "ADD";
      if(minAns[i]==SUB) cout << "SUB";
      if(minAns[i]==MUL) cout << "MUL";
      if(minAns[i]==DIV) cout << "DIV";
      if(minAns[i]==DUP) cout << "DUP";
    }
    cout << endl;
  }
             	
}

int main(){

  for(int cases=1;read();cases++){
    work(cases);
    cout << endl;
  }

  return 0;
}
