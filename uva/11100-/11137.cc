#include<iostream>
#include<algorithm>
#include<numeric>

#define BUF 10000

using namespace std;

int n;
long long tbl[BUF][22];

void makeTable(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<=21;j++)
      tbl[i][j] = 0; 
  
  tbl[0][0] = 1;
  
  for(int i=1;i<BUF;i++){
    for(int j=1;j<=21;j++)
      for(int k=0;k<=j;k++)
	if(i-j*j*j>=0)
	  tbl[i][j] += tbl[i-j*j*j][k];
  }
}

bool read(){
  if(!(cin >> n)) return false;
  return true;
}

void work(){
  cout << accumulate(tbl[n],tbl[n]+22,0LL) << endl;
}

int main(){
  makeTable();
  while(read())
    work();
  return 0;
}
