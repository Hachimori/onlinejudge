#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
const int BUF = 25;

int nNode, adj[BUF][BUF];
int ch2i[128];
char i2ch[26];

void read(){
  nNode = 0;
  for(int i=0;i<BUF;i++) for(int j=0;j<BUF;j++) adj[i][j] = 1;

  string dummy; getline(cin,dummy);
  string s; getline(cin,s);
  stringstream in(s);

  vector<char> chList;
  for(int i=0;in>>s;i++) chList.push_back(s[0]);
  sort(chList.begin(),chList.end());
  
  nNode = chList.size();
  for(int i=0;i<nNode;i++){
    ch2i[chList[i]] = i;
    i2ch[i] = chList[i];
  }

  getline(cin,s);
  in.clear();
  in.str(s);
  while(in>>s){
    int src = ch2i[s[0]], dst = ch2i[s[2]];
    adj[dst][src] = 0;
  }
}

bool valid(){
  int mat[BUF][BUF];
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      mat[i][j] = !adj[j][i];
  
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        mat[i][j] |= (mat[i][k]&mat[k][j]);

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      if(mat[i][j] && mat[j][i])
        return false;
  return true;
}

void rec(int nVisited, int cur, bool visited[BUF], int history[BUF]){
  if(nVisited==nNode){
    for(int i=0;i<nNode;i++){
      if(i) cout << ' ';
      cout << i2ch[history[i]];
    }
    cout << endl;
    return;
  }
  for(int i=0;i<nNode;i++){
    if(visited[i]) continue;
    bool ok = true;
    for(int j=0;j<nVisited;j++)
      if(!adj[history[j]][i])
        ok = false;
    if(!ok) continue;
    
    visited[i] = true;
    history[nVisited] = i;
    rec(nVisited+1,i,visited,history);
    visited[i] = false;
  }
}

void work(){
  if(!valid()){
    cout << "NO" << endl;
    return;
  }
  
  bool visited[BUF]={};
  int history[BUF];
  rec(0,nNode,visited,history);
}


int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
