#include<iostream>
#define BUF 9
#define NUM 10
using namespace std;

int b[BUF][BUF];

bool read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      if(!(cin >> b[i][j])) return false;
  return true;
}

bool isValid(bool rUsed[BUF][NUM], bool cUsed[BUF][NUM], bool gUsed[BUF][NUM]){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<NUM;j++)
      rUsed[i][j] = cUsed[i][j] = gUsed[i][j] = false;
  
  for(int r=0;r<BUF;r++)
    for(int c=0;c<BUF;c++){
      if(b[r][c]==0) continue;
      if(rUsed[r][b[r][c]]) return false;
      if(cUsed[c][b[r][c]]) return false;
      if(gUsed[r/3*3+c/3][b[r][c]]) return false;
      rUsed[r][b[r][c]] = cUsed[c][b[r][c]] = gUsed[r/3*3+c/3][b[r][c]] = true;
    }
  
  return true;
}

void rec(int r, int c, 
	 bool rUsed[][NUM], bool cUsed[][NUM], bool gUsed[][NUM], int &cnt){
  if(r==BUF){
    cnt++;
    return;
  }
  if(c==BUF){
    rec(r+1,0,rUsed,cUsed,gUsed,cnt);
    return;
  }
  if(b[r][c]!=0){
    rec(r,c+1,rUsed,cUsed,gUsed,cnt);
    return;
  }
  
  for(int i=1;i<=9;i++){
    if(rUsed[r][i] || cUsed[c][i] || gUsed[r/3*3+c/3][i]) continue;
    rUsed[r][i] = cUsed[c][i] = gUsed[r/3*3+c/3][i] = true;
    rec(r,c+1,rUsed,cUsed,gUsed,cnt);
    rUsed[r][i] = cUsed[c][i] = gUsed[r/3*3+c/3][i] = false;
  }
}
	 

void work(int cases){
  bool rUsed[BUF][NUM], cUsed[BUF][NUM], gUsed[BUF][NUM];
  
  cout << "Case " << cases << ": ";

  if(!isValid(rUsed,cUsed,gUsed)){
    cout << "Illegal." << endl;
    return;
  }

  int cnt = 0;
  rec(0,0,rUsed,cUsed,gUsed,cnt);

  if(cnt==0) cout << "Impossible." << endl;
  if(cnt==1) cout << "Unique." << endl;
  if(cnt>=2) cout << "Ambiguous." << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
