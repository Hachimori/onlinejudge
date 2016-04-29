// bicoloring できるかどうか判定する。
// 
// 以下のグラフはbicoloring出来るが、NOと表示されるべき。
// 
// ------------------------
// |                      |
// 1 - 2 - 3 -  4 -  5 -  6 
// |   |   |    |    |    |
// 7 - 8 - 9 - 10 - 11 - 12
// |   |   |    |    |    |
// ------------------------
//
// ノード数が4で割れるかどうかも考慮に入れてない
/*
  12
  1 2
  1 7
  1 6
  2 3
  2 8
  3 4
  3 9
  4 5
  4 10
  5 6
  5 11
  6 12
  7 8
  7 12
  8 9
  9 10
  10 11
  11 12
  0 0
  0
*/
#include<iostream>
#include<vector>
using namespace std;
const int BUF = 305;

int nNode, adj[BUF][3];
bool adjBool[BUF][BUF];

bool read(){
  int degree[BUF]={};
  memset(adjBool,0,sizeof(adjBool));
  cin >> nNode;
  if(nNode==0) return false;
  while(1){
    int s, t;
    cin >> s >> t;
    if(s==0 && t==0) break;
    s--, t--;
    adj[s][degree[s]++] = t;
    adj[t][degree[t]++] = s;
    adjBool[s][t] = adjBool[t][s] = true;
  }
  return true;
}

bool rec(int cur, bool curColor, int color[BUF]){
  color[cur] = curColor;
  for(int i=0;i<3;i++){
    if(color[adj[cur][i]]==-1 && !rec(adj[cur][i],!curColor,color)) return false;
    if(color[adj[cur][i]]!=-1 && color[adj[cur][i]]==curColor) return false;
  }
  return true;
}

void work(){
  int color[BUF];
  memset(color,-1,sizeof(color));
  for(int i=0;i<nNode;i++){
    if(color[i]==-1 && !rec(i,0,color)){
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main(){
  while(read()) work();
  return 0;
}
