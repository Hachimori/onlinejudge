#include<iostream>
#define BUF 105
using namespace std;

int nLeft, nRight;
bool adj[BUF][BUF];

void read(){
  int numL[BUF], numR[BUF];

  cin >> nLeft;
  for(int i=0;i<nLeft;i++)
    cin >> numL[i];

  cin >> nRight;
  for(int i=0;i<nRight;i++)
    cin >> numR[i];

  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      if(numL[i]==0)
        adj[i][j] = numR[j]==0;
      else
        adj[i][j] = numR[j]%numL[i]==0;
}

bool aug(int curr, bool visited[BUF], int R2L[BUF]){
  if(curr==-1) return true;
  visited[curr] = true;
  
  for(int i=0;i<nRight;i++){
    if(!adj[curr][i] || (R2L[i]!=-1 && visited[R2L[i]])) continue;
    
    if(aug(R2L[i],visited,R2L)){
      R2L[i] = curr;
      return true;
    }
  }

  return false;
}

int maxMatch(){
  int cnt = 0, R2L[BUF];
  for(int i=0;i<nRight;i++)
    R2L[i] = -1;
  
  for(int i=0;i<nLeft;i++){
    bool visited[BUF];
    for(int j=0;j<nLeft;j++)
      visited[j] = false;
    
    cnt += aug(i,visited,R2L);
  }

  return cnt;
}

void work(int cases){
  cout << "Case " << cases << ": " << maxMatch() << endl;
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
