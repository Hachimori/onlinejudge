#include<iostream>
#include<algorithm>
#include<cstdio>
#define BUF 15
#define INF (1<<20)
using namespace std;

int nA, nB, a[BUF], b[BUF];

bool read(){
  cin >> nA;
  if(nA==0) return false;
  cin >> nB;

  for(int i=0;i<nA;i++) cin >> a[i];
  for(int i=0;i<nB;i++) cin >> b[i];

  return true;
}

void work(){
  int nRate = 0;
  double rate[BUF*BUF];

  for(int i=0;i<nB;i++)
    for(int j=0;j<nA;j++)
      rate[nRate++] = 1.0*b[i]/a[j];
  sort(rate,rate+nRate);
  
  double ans = -INF;
  for(int i=0;i+1<nRate;i++)
    ans = max(ans,rate[i+1]/rate[i]);

  printf("%.2lf\n",ans);
}

int main(){
  while(read())
    work();
  
  return 0;
}
