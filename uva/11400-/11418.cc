#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
const int BUF = 30;

int nNode;
vector<string> node2str[BUF];

void read(){
  for(int i=0;i<BUF;i++) node2str[i].clear();
  cin >> nNode;
  for(int i=0;i<nNode;i++){
    int nStr;
    cin >> nStr;
    for(int j=0;j<nStr;j++){
      string s;
      cin >> s;
      for(int k=0;k<s.size();k++)
        s[k] = k==0 ? toupper(s[k]) : tolower(s[k]);
      node2str[i].push_back(s);
    }
  }
}


void work(int cases){
  bool used[BUF]={};
  pair<int,int> toUse[BUF];

  while(count(used,used+nNode,0)){
    for(int letter=0;letter<nNode;letter++){
      int matchCnt = 0, matchNode, matchStr;
      for(int node=0;node<nNode;node++){
        if(used[node]) continue;
        for(int i=0;i<node2str[node].size();i++)
          if(node2str[node][i][0]-'A'==letter){
            matchCnt++;
            matchNode = node;
            matchStr = i;
          }
      }
      if(matchCnt==1){
        used[matchNode] = true;
        toUse[letter] = make_pair(matchNode,matchStr);
      }
    }
  }

  cout << "Case #" << cases << ":" << endl;
  for(int i=0;i<nNode;i++)
    cout << node2str[toUse[i].first][toUse[i].second] << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int caze=0;caze<cases;caze++){
    read();
    work(caze+1);
  }
  return 0;
}
