#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
using namespace std;
const int YET = 1<<30, BUF = 25;


int row, col;
string b[BUF][BUF],_b[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      cin >> _b[i][j];
      b[i][j] = _b[i][j];
      if(b[i][j][0]!='-' && b[i][j][0]!='+') b[i][j] = '+'+b[i][j];
    }
  return true;
}


int calc(int r, int c, int dp[BUF][BUF]){
  int &ret = dp[r][c];
  if(ret!=-1) return ret;
  ret = YET;
  int sum = 0;
  for(int i=0;i<b[r][c].size();){
    char ope = b[r][c][i++];
    if(isalpha(b[r][c][i])){
      int rr = b[r][c][i++]-'A';
      int cc = b[r][c][i++]-'0';
      int tmp = calc(rr,cc,dp);
      if(tmp==YET) return ret = YET;
      sum += ope=='+' ? tmp : -tmp;
    }
    else{
      string num;
      while(i<b[r][c].size() && isdigit(b[r][c][i])) num += b[r][c][i++];
      int tmp = atoi(num.c_str());
      sum += ope=='+' ? tmp : -tmp;
    }
  }
  return ret = sum;
}


void work(){
  int dp[BUF][BUF];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      calc(i,j,dp);

  bool yetExist = false;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(dp[i][j]==YET)
        yetExist = true;

  if(yetExist){
    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
        if(dp[i][j]==YET)
          cout << (char)(i+'A') << (char)(j+'0') << ": " << _b[i][j] << endl;
  }
  else{
    cout << ' ';
    for(int j=0;j<col;j++) printf("%6d",j);
    cout << endl;
    for(int i=0;i<row;i++){
      cout << (char)(i+'A');
      for(int j=0;j<col;j++)
        printf("%6d",dp[i][j]);
      cout << endl;
    }
  }
}


int main(){
  while(read()){
    work();
    cout << endl;
  }
  return 0;
}
