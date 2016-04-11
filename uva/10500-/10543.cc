#include<iostream>
#include<queue>
#define cur first 
#define walk second
using namespace std;
typedef pair<int,int> Data;
const int BUF = 55, NWALK = 25;

int nNode, nWalk;
bool adj[BUF][BUF];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge >> nWalk;
  if(!(nNode|nEdge|nWalk)) return false;
  memset(adj,0,sizeof(adj));
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s][t] = true;
  }
  return true;
}

void work(){
  static bool dp[BUF][NWALK];
  memset(dp,0,sizeof(dp));
  queue<Data> Q;

  Q.push(Data(0,1));
  dp[0][1] = true;

  while(!Q.empty()){
    Data dat = Q.front();
    Q.pop();

    if(dat.cur==nNode-1 && dat.walk>=nWalk){
      cout << dat.walk << endl;
      return;
    }
    if(dat.walk>=20) continue;

    for(int i=0;i<nNode;i++){
      if(!adj[dat.cur][i] || dat.cur==i) continue;
      Data nex = Data(i,dat.walk+1);
      if(!dp[nex.cur][nex.walk]){
        dp[nex.cur][nex.walk] = true;
        Q.push(nex);
      }
    }
  }

  cout << "LOSER" << endl;
}

int main(){
  while(read()) work();
  return 0;
}

