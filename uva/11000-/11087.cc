#include<iostream>
#include<set>
#include<cstdio>
#include<cassert>
#define NUM 100005
#define MOD 1010
#define MSHIFT 505
#define BUF 20000010
#define BSHIFT 10000005
using namespace std;

int nNum, mod, num[NUM];
bool pushed[BUF];

void read(){
  cin >> nNum >> mod;

  for(int i=0;i<nNum;i++){
    scanf("%d",&num[i]);
    pushed[BSHIFT+num[i]] = false;
  }
}

void work(int cases){
  int cntMod[MOD], cnt = 0;
  set<int> pushTwice;
  
  fill(cntMod,cntMod+MOD,0);

  for(int i=0;i<nNum;i++){
    if(pushed[BSHIFT+num[i]]){
      if(abs(num[i]*2)%mod==0) pushTwice.insert(num[i]);
      continue;
    }
    
    pushed[BSHIFT+num[i]] = true;
    
    if(num[i]<0)
      cntMod[MSHIFT-((-num[i])%mod)]++;
    else
      cntMod[MSHIFT+num[i]%mod]++;
  }

  long long ans = 0;
  for(int i=-mod+1;i<mod;i++){
    if(abs(i*2)%mod==0)
      ans += cntMod[MSHIFT+i]*(cntMod[MSHIFT+i]-1)/2;
    for(int j=i+1;j<mod;j++)
      if(abs(i+j)%mod==0)
	ans += cntMod[MSHIFT+i]*cntMod[MSHIFT+j];
    assert(ans>=0);
  }

  cout << "Case " << cases << ": " << ans+pushTwice.size() << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
