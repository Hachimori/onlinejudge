#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int BUF = 40;

int nL, nR, adj[BUF][BUF];

void read(){
  memset(adj,0,sizeof(adj));
  cin >> nR >> nL;
  string sz[] = {"XXL","XL","L","M","S","XS"};
  for(int i=0;i<nL;i++){
    string a, b;
    cin >> a >> b;
    int aId = find(sz,sz+6,a)-sz, bId = find(sz,sz+6,b)-sz;
    for(int j=0;j<nR/6;j++){
      adj[i][aId*(nR/6)+j] = true;
      adj[i][bId*(nR/6)+j] = true;
    }
  }
}

bool aug(int cur, bool visited[BUF], int L2R[BUF], int R2L[BUF]){
  if(cur==-1) return true;
  visited[cur] = true;
  for(int i=0;i<nR;i++){
    if(!adj[cur][i] || (R2L[i]!=-1 && visited[R2L[i]])) continue;
    if(aug(R2L[i],visited,L2R,R2L)){
      L2R[cur] = i;
      R2L[i] = cur;
      return true;
    }
  }
  return false;
}

int maxMatch(){
  int L2R[BUF], R2L[BUF], ret = 0;
  memset(L2R,-1,sizeof(L2R));
  memset(R2L,-1,sizeof(R2L));
  for(int i=0;i<nL;i++){
    if(L2R[i]!=-1) continue;
    bool visited[BUF]={0};
    if(aug(i,visited,L2R,R2L)) ret++;
  }
  return ret;
}

void work(){
  cout << (maxMatch()==nL ? "YES" : "NO") << endl;
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
