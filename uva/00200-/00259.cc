#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cctype>

#define MAX_PC 10
#define MAX_SIZE 500

using namespace std;

int nAppli;
char appliName[MAX_SIZE];
bool adjList[MAX_SIZE][MAX_SIZE];

bool maxMatching(char allocated[10]){
  
  int nMatch=0;
  int L2R[MAX_SIZE], R2L[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    L2R[i] = R2L[i] = -1;
  
 ExtendMatching:

  for(int i=0;i<nAppli;i++){
    
    if(L2R[i]!=-1) continue;

    int prevL2R[MAX_SIZE], prevR2L[MAX_SIZE];
    queue<int> Q;

    for(int j=0;j<MAX_SIZE;j++)
      prevL2R[j] = prevR2L[j] = -1;
    Q.push(i);

    
    while(!Q.empty()){

      int curr=Q.front();
      Q.pop();

      for(int j=0;j<MAX_PC;j++){
	
	if(!adjList[curr][j]) continue;
	if(prevR2L[j]!=-1) continue;
	
	prevR2L[j] = curr;

	if(R2L[j]==-1){
	  
	  int currLeft=curr, currRight=j;

	  while(true){
	    
	    L2R[currLeft] = currRight;
	    R2L[currRight] = currLeft;
	    
	    if(prevL2R[currLeft]==-1) break;
	    
	    currRight = prevL2R[currLeft];
	    currLeft = prevR2L[currRight];

	    R2L[currRight] = -1;
	  }
	  
	  nMatch++;
	  goto ExtendMatching;
	}
	else{
	  prevL2R[R2L[j]] = j;
	  Q.push(R2L[j]);
	}

      }
      
    }
    
  }
  
  for(int i=0;i<nAppli;i++)
    if(L2R[i]!=-1)
      allocated[L2R[i]] = appliName[i];
  
  return nMatch==nAppli;
  
}

void work(){
  
  char allocated[10];
  
  for(int i=0;i<10;i++)
    allocated[i] = '_';

  if(nAppli>10 || !maxMatching(allocated)) cout << "!" << endl;
  else {
    for(int i=0;i<10;i++)
      cout << allocated[i];
    cout << endl;
  }
  
}

bool read(){
  
  nAppli=0;

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      adjList[i][j] = false;

  while(true){
    string str;
    if(getline(cin,str)==NULL){ 
      work();
      return false;
    }

    if(str.size()==0) break;

    for(int i=nAppli;i<nAppli+str[1]-'0';i++)
      appliName[i] = str[0];
    
    for(int i=nAppli;i<nAppli+str[1]-'0';i++)
      for(int j=2;str[j]!=';';j++)
	adjList[i][str[j]-'0'] = true;
    
    nAppli+=str[1]-'0';
  }
  
  return true;
}


int main(){
  
  while(read())
    work();
  
  return 0;
}
