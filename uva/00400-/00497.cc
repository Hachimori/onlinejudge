#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<vector>
#include<cstdlib>

#define MAX_SIZE 1000000

using namespace std;

int nDigit;
int digitList[MAX_SIZE];
int sequence[MAX_SIZE];
int pi[MAX_SIZE];

void init(){  
  fill(sequence,sequence+MAX_SIZE,0);
  fill(pi,pi+MAX_SIZE,-1);
}

void read(){
  
  nDigit=0;
  
  while(true){
    
    string str;
    getline(cin,str);
    
    if(str.empty()) break;
    
    digitList[nDigit]=atoi(str.c_str());
    
    nDigit++;    
  }  
  
}

void work(){

  int maxVal=0;
  int tail=0;

  for(int i=0;i<nDigit;i++){
    for(int j=i-1;j>=0;j--){

      /*
      for(int k=0;k<nDigit;k++)
	cout << sequence[k] << ' ';
      cout << endl;
      */
      /*
      for(int k=0;k<nDigit;k++)
	cout << pi[k] << ' ';
      cout << endl;
      */

      if(digitList[i]>digitList[j]){
	
	if(sequence[i]<sequence[j]+1){	  
	  sequence[i] = sequence[j]+1;
	  if(maxVal<sequence[i]){ 
	    maxVal = sequence[i];
	    tail = i;
	  }
	  pi[i] = j;	
	}
	
      }
      
    }
  }
  
  cout << "Max hits: " << sequence[tail]+1 << endl;
  
  vector<int> path;
 
  for(int i=tail;i!=-1;i=pi[i])
    path.push_back(i);

  for(int i=path.size()-1;i>=0;i--)
    cout << digitList[path[i]] << endl;
  
}

int main(){

  string str;

  int cases;
  cin >> cases; getline(cin,str); getline(cin,str);

  
  for(int i=0;i<cases;i++){
    init();
    if(i!=0) cout << endl;
    read();
    work();
  }  

  return 0;
}
