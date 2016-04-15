#include<iostream>
using namespace std;
const int SZ = 5, BUF = 75;

int b[SZ][SZ], seq[BUF];

void read(){
  b[2][2] = -1;
  for(int i=0;i<SZ;i++)
    for(int j=0;j<SZ;j++)
      if(!(i==2 && j==2))
        cin >> b[i][j];
  for(int i=0;i<BUF;i++)
    cin >> seq[i];
}

bool bingo(bool ok[SZ][SZ]){
  for(int i=0;i<SZ;i++){
    bool hor = true, ver = true;
    for(int j=0;j<SZ;j++){
      hor &= ok[i][j];
      ver &= ok[j][i];
    }
    if(hor||ver) return true;
  }
  return (ok[0][0] && ok[1][1] && ok[2][2] && ok[3][3] && ok[4][4])||
         (ok[0][4] && ok[1][3] && ok[2][2] && ok[3][1] && ok[4][0]);
}

void work(){
  bool ok[SZ][SZ]={};
  ok[2][2] = true;
  for(int i=0;i<BUF;i++){
    for(int j=0;j<SZ;j++)
      for(int k=0;k<SZ;k++)
        if(b[j][k]==seq[i])
          ok[j][k] = true;
    if(bingo(ok)){
      cout << "BINGO after " << i+1 << " numbers announced" << endl;
      break;
    }
  }
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
