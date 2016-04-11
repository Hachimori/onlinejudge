#include<iostream>
#include<string>
#include<vector>
#define BUF 10000
using namespace std;

int nWord;
string str[BUF];

bool read(){
  int len;
  if(!(cin >> nWord >> len)) return false;
  for(int i=0;i<nWord;i++)
    cin >> str[i];
  return true;
}

bool rec(int curr, bool visited[BUF], vector<int> &ans){
  if(curr==1) return true;
  visited[curr] = true;
  for(int i=0;i<nWord;i++){
    if(visited[i]) continue;
    int cnt = 0;
    for(int j=0;j<str[i].size();j++)
      cnt += str[i][j]!=str[curr][j];
    if(cnt==1 && rec(i,visited,ans)){
      ans.push_back(i);
      return true;
    }
  }
  return false;
}

void work(){
  bool visited[BUF];
  for(int i=0;i<nWord;i++) visited[i] = false;

  vector<int> ans;
  rec(0,visited,ans);
  
  cout << str[0] << endl;
  for(int i=ans.size()-1;i>=0;i--)
    cout << str[ans[i]] << endl;
}

int main(){
  while(read()) work();
  return 0;
}
