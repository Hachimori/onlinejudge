#include<iostream>
#include<vector>
using namespace std;
const int BUF = 2005;

int nNode, nA, nB;
bool adj[BUF][BUF];

void read(){
  memset(adj,0,sizeof(adj));
  int nEdge;
  cin >> nA >> nB >> nEdge;
  nNode = nA+nB;
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    adj[s-1][t-1] = adj[t-1][s-1] = true;
  }
}

bool bicolor(bool b, int cur, int color[BUF], int cnt[2]){
  cnt[b]++;
  color[cur] = b;
  for(int i=0;i<nNode;i++){
    if(!adj[cur][i]) continue;
    if(color[i]==-1 && !bicolor(!b,i,color,cnt)) return false;
    if(color[i]!=-1 && color[i]==b) return false;
  }
  return true;
}

void work(){
  vector< pair<int,int> > toAdd;
  int color[BUF];
  memset(color,-1,sizeof(color));
  for(int i=0;i<nNode;i++)
    if(color[i]==-1){
      int cnt[2]={};
      if(!bicolor(0,i,color,cnt)){
        cout << "no" << endl;
        return;
      }
      toAdd.push_back(make_pair(cnt[0],cnt[1]));
    }
 
  static bool can[BUF][BUF];
  memset(can,0,sizeof(can));
  can[0][0] = true;
  for(int k=0;k<toAdd.size();k++)
    for(int i=nA;i>=0;i--)
      for(int j=nB;j>=0;j--)
        if(can[i][j]){
          can[i+toAdd[k].first][j+toAdd[k].second] = true;
          can[i+toAdd[k].second][j+toAdd[k].first] = true;
        }
  cout << (can[nA][nB] ? "yes" : "no") << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
