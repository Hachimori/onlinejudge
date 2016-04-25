// http://www.math.uncc.edu/~ghetyei/courses/old/S03.3166/stirling.pdf

#include<iostream>
#include<algorithm>
#define BUF 30
#define INF 18446744073709551615ULL
using namespace std;
typedef unsigned long long ull;

ull tbl[BUF][BUF];

ull calc(int m, int n){
  if(tbl[m][n]!=INF) return tbl[m][n];

  return tbl[m][n]=calc(m-1,n-1)+(m-1)*calc(m-1,n);
}

int M, N;

bool read(){
  cin >> M >> N;
  if(M==0 && N==0) return false;
  return true;
}

void work(){
  N = abs(M-N);
  cout << calc(M,N) << endl;
}

int main(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      tbl[i][j] = INF;
  
  for(int i=0;i<BUF;i++)
    tbl[0][i] = 0;
  tbl[1][1] = 1;
  
  while(read())
    work();
  
  return 0;
}
