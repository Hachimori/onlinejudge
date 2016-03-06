#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const int BUF = 105;

int row, col;
bool wall[BUF][BUF];

void read(){
  memset(wall,0,sizeof(wall));
  cin >> row >> col;
  string s;
  getline(cin,s);
  for(int i=0;i<row;i++){
    getline(cin,s);
    stringstream in(s);
    int n;
    in >> n;
    while(in >> n) wall[i][n-1] = true;
  }
}

void work(){
  long long dp[BUF][BUF]={};
  dp[0][0] = wall[0][0] ? 0 : 1;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(i+1<row && !wall[i+1][j]) dp[i+1][j] += dp[i][j];
      if(j+1<col && !wall[i][j+1]) dp[i][j+1] += dp[i][j];
    }
  cout << dp[row-1][col-1] << endl;
}
int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
