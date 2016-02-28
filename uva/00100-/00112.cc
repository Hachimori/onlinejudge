#include<iostream>
#include<string>
#include<vector>

#define TAIL -99999999
#define MAX_SIZE 10000

using namespace std;

int target;
int nNode;
int valList[MAX_SIZE];
vector<int> buffer[MAX_SIZE];

void rec(int currNode, int depth){


  int sum=0;
  int cntBranch=0;
  bool isNegative=false;

  while(true){
    
    char c;    
    cin >> c;    

    if(c=='(' || c==')'){ 
      cin.putback(c);
      break;
    }
    if(c=='-'){ 
      isNegative=true;
      continue;
    }

    sum*=10;
    sum+=c-'0'; 
  }

  if(isNegative) sum*=(-1);

  while(true){
    char c;
    cin >> c;
    
    //cout << c << ' ' << sum << ' ' << depth << endl;
    
    if(c==')'){ 
      return;
    }
    else if(c=='('){ 
      cntBranch++;
      if(cntBranch==1){
	valList[currNode]=sum;
	buffer[currNode].push_back(nNode+1);
	nNode++;
	rec(nNode,depth+1);
      }	
      else{
	buffer[currNode].push_back(nNode+1);
	nNode++;
	rec(nNode,depth+1);
	cntBranch=0;
      }
    }
  }
  

}

bool read(){
  
  if(!(cin >> target)) return false;
  
  nNode=0;
  for(int i=0;i<MAX_SIZE;i++){
    buffer[i].clear();
    valList[i]=TAIL;
  }

  char c;
  cin >> c;
  
  rec(0,0);
  
  return true;
}

bool find(int curr, int sum){
  //cout << sum << endl;
  //if(sum==target) return true;
  
  if(valList[buffer[curr][0]]==TAIL && valList[buffer[curr][1]]==TAIL && 
     sum==target) return true;
 
  for(int i=0;i<2;i++){
    
    if(valList[buffer[curr][i]]==TAIL)
      continue;
    

    if(find(buffer[curr][i],sum+valList[buffer[curr][i]])) return true;
    
  }
  
  return false;
}

void work(){
  /*
  for(int currNode=0;currNode<nNode;currNode++)
    for(int i=0;i<buffer[currNode].size();i++){
      cout << valList[currNode] << " -> " << valList[buffer[currNode][i]] << endl;
    }
  cout << endl;
  */
  //cout << valList[0] << e
  
  if(find(0,valList[0])) cout << "yes" << endl;
  else cout << "no" << endl;

}

int main(){
  
  while(read())
    work();
  
  return 0;
}
