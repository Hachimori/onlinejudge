#include<iostream>
#include<cstdio>
#define MAN 25
using namespace std;

int nMan, nBuy;
long double p[MAN];

bool read(){
  cin >> nMan >> nBuy;
  if(nMan==0 && nBuy==0) return false;

  for(int i=0;i<nMan;i++)
    cin >> p[i];
  
  return true;
}

void rec(int idx, int nChose, long double buyP[], int chose[],
	 long double curP, long double &sum){
  
  if(idx==nMan){
    if(nChose!=nBuy) return;
    for(int i=0;i<nBuy;i++)
      buyP[chose[i]] += curP;
    sum += curP;
    return;
  }
  if(nChose>nBuy) return;
  
  chose[nChose] = idx;
  rec(idx+1,nChose+1,buyP,chose,curP*p[idx],sum);

  rec(idx+1,nChose,buyP,chose,curP*(1-p[idx]),sum);
}


void work(int cases){
  long double buyP[MAN], sum = 0;
  int chose[MAN];

  for(int i=0;i<nMan;i++) buyP[i] = 0;
    
  rec(0,0,buyP,chose,1.0,sum);

  cout << "Case " << cases << ":" << endl;
  for(int i=0;i<nMan;i++)
    printf("%.6Lf\n",buyP[i]/sum);
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
