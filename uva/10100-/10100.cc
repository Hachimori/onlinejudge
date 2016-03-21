#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
const int BUF = 1005, INF = 1<<20;

vector<string> sList[2];

bool read(){
  sList[0] = sList[1] = vector<string>();

  for(int i=0;i<2;i++){
    string str;
    if(!getline(cin,str)) return false;

    for(int j=0;j<str.size();j++) if(!isalnum(str[j])) str[j] = ' ';
    stringstream in(str);
    while(in >> str) sList[i].push_back(str);
  }

  return true;
}


void work(int cases){
  static int dp[BUF][BUF];
  for(int r=0;r<sList[0].size();r++)
    for(int c=0;c<sList[1].size();c++){
      int up = r==0 ? 0 : dp[r-1][c];
      int left = c==0 ? 0 : dp[r][c-1];
      int ul = (r==0 || c==0 ? 0 : dp[r-1][c-1]) + (sList[0][r]==sList[1][c]);
      dp[r][c] = max(up,max(left,ul));
    }

  int ans = sList[0].empty() || sList[1].empty() ? 0 : dp[sList[0].size()-1][sList[1].size()-1];
  if(ans==0)
    printf("%2d. Blank!\n",cases);
  else
    printf("%2d. Length of longest match: %d\n",cases,ans);
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
