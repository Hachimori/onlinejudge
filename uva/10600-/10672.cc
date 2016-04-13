#include<iostream>

#define MAX_SIZE 10005

using namespace std;

int nNode;
int nMarble[MAX_SIZE], nChild[MAX_SIZE];
int parent[MAX_SIZE];

bool read(){
  
  cin >> nNode;
  if(nNode==0) return false;
  
  for(int i=0;i<nNode;i++){
    int id;
    cin >> id;
    cin >> nMarble[id-1] >> nChild[id-1];

    for(int j=0;j<nChild[id-1];j++){
      int childId;
      cin >> childId;

      parent[childId-1]=id-1;
    }

  }

  return true;  

}

void work(){

  int nDeleted=0, ans=0;
  bool deleted[MAX_SIZE];
  
  
  for(int i=0;i<nNode;i++)
    deleted[i]=false;

  while(nDeleted!=nNode-1){
    
    for(int i=0;i<nNode;i++){
      if(!deleted[i] && nChild[i]==0){
	
	if(nMarble[i]>1){
	  nMarble[parent[i]]+=nMarble[i]-1;
	  ans+=nMarble[i]-1;
	}
	else if(nMarble[i]<=0){
	  nMarble[parent[i]]+=nMarble[i]-1;
	  ans-=nMarble[i]-1;
	}

	deleted[i] = true;
	nChild[parent[i]]--;      
	nDeleted++;
	break;
      }
    }
    
  }
  
  cout << ans << endl;

}

int main(){
  
  while(read())
    work();

  return 0;
}
