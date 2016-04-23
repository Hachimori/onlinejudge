#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#define BUF 1005
using namespace std;

int nWord;
string a, b, word[BUF];

void read(){
  cin >> a >> b;
  cin >> nWord;
  for(int i=0;i<nWord;i++)
    cin >> word[i];
}

void work(){
  if(a.size()>b.size()) swap(a,b);
  for(int i=0;i<a.size();i++)
    if(a[i]!=b[i]){
      cout << -1 << endl;
      return;
    }

  map<string,int> visited;
  queue<string> Q;
  Q.push(b.substr(a.size()));
  visited[b.substr(a.size())] = 0;

  while(!Q.empty()){
    string curr = Q.front();
    Q.pop();
    
    if(curr==""){
      cout << visited[curr] << endl;
      return;
    }

    for(int i=0;i<nWord;i++){
      string nex = "#";
      if(curr.size()<=word[i].size() && curr==word[i].substr(0,curr.size()))
        nex = word[i].substr(curr.size());
      else if(curr.size()>word[i].size() && curr.substr(0,word[i].size())==word[i])
        nex = curr.substr(word[i].size());

      if(nex!="#" && !visited.count(nex)){
        visited[nex] = visited[curr]+1;
        Q.push(nex);
      }
    }
  }

  cout << -1 << endl;
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
