#include<iostream>
#define LEFT 500
#define RIGHT  500
using namespace std;
 
int nLeft, nRight;
bool adj[LEFT][RIGHT];

void read(){
  cin >> nLeft >> nRight;

  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      cin >> adj[i][j];
}

bool augment(int curr, int L2R[], int R2L[], bool visited[]){
  if(curr==-1) return true;

  for(int i=0;i<nRight;i++){
    if(!adj[curr][i] || visited[i]) continue;
    visited[i] = true;
    
    if(augment(R2L[i],L2R,R2L,visited)){
      L2R[curr] = i;
      R2L[i] = curr;
      return true;
    }
  }

  return false;
}

int maxMatch(){
  int L2R[LEFT], R2L[RIGHT], ret = 0;
  
  for(int i=0;i<nLeft;i++) L2R[i] = -1;
  for(int i=0;i<nRight;i++) R2L[i] = -1;
  
  for(int i=0;i<nLeft;i++){
    bool visited[RIGHT];
    for(int j=0;j<nRight;j++)
      visited[j] = false;

    if(augment(i,L2R,R2L,visited))
      ret++;
  }

  return ret;
}

void work(int cases){
  cout << "Case " << cases << ": a maximum of "
       << maxMatch() << " nuts and bolts can be fitted together" << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
      
  return 0;
}
