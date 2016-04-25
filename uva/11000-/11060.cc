#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int BUF = 105;

int nNode, nIn[BUF];
vector<int> adj[BUF];
map<string,int> a2i;
map<int,string> i2a;

bool read(){
  i2a.clear();
  for(int i=0;i<BUF;i++){
    adj[i].clear();
    nIn[i] = 0;
  }
  if(!(cin >> nNode)) return false;
  for(int i=0;i<nNode;i++){
    string s;
    cin >> s;
    a2i[s] = i;
    i2a[i] = s;
  }

  int nEdge;
  cin >> nEdge;
  for(int i=0;i<nEdge;i++){
    string s, t;
    cin >> s >> t;
    adj[a2i[s]].push_back(a2i[t]);
    nIn[a2i[t]]++;
  }

  return true;
}

void work(int cases){
  bool used[BUF]={0};
  cout << "Case #" << cases << ": Dilbert should drink beverages in this order:";
  for(int i=0;i<nNode;i++){
    for(int j=0;j<nNode;j++)
      if(!used[j] && nIn[j]==0){
        cout << ' ' << i2a[j];
        for(int k=0;k<adj[j].size();k++)
          nIn[adj[j][k]]--;
        used[j] = true;
        break;
      }
  }
  cout << '.' << endl << endl;
}

int main(){
  for(int i=0;read();i++)
     work(i+1);
  return 0;
}
