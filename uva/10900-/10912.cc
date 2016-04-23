#include<iostream>
#define LENG 30
#define VAL 500
#define LASTCH 27
using namespace std;

int tbl[LENG][VAL][LASTCH];
void makeTable(){
  for(int i=0;i<LENG;i++)
    for(int j=0;j<VAL;j++)
      for(int k=0;k<LASTCH;k++)
	tbl[i][j][k] = 0;
  
  for(int i=1;i<=26;i++)
    tbl[1][i][i] = 1;

  for(int r=1;r+1<LENG;r++)
    for(int c=0;c<VAL;c++)
      for(int ch=1;ch<=26;ch++){
	if(tbl[r][c][ch]==0) continue;
	
	for(int nch=ch+1;nch<=26;nch++)
	  tbl[r+1][c+nch][nch] += tbl[r][c][ch];
      }
}

int leng, val;

bool read(){
  cin >> leng >> val;
  return !(leng==0 && val==0);
}

void work(int cases){
  cout << "Case " << cases << ": ";

  if(leng<LENG && val<VAL){
    int sum = 0;
    for(int i=1;i<=26;i++)
      sum += tbl[leng][val][i];
    cout << sum << endl;
  }
  else
    cout << 0 << endl;
}

int main(){
  makeTable();

  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
