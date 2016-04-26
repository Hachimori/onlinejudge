#include<iostream>

#define PRIME 1000005

using namespace std;

int ans[PRIME];

void makeTable(){
  static int nNum = 0, num[PRIME], cnt[PRIME];
  static bool isPrime[PRIME];
  
  for(int i=0;i<PRIME;i++){
    cnt[i] = 0;
    isPrime[i] = true;
  }

  for(int i=1;i*4+1<PRIME;i++) 
    num[nNum++] = i*4+1;

  for(int i=0;num[i]*num[i]<PRIME;i++)
    if(isPrime[num[i]])
      for(int j=i;num[i]*num[j]<PRIME;j++)
	isPrime[num[i]*num[j]] = false;
  
  int aa = 0;
  for(int i=0;num[i]*num[i]<PRIME;i++){
    if(!isPrime[num[i]]) continue;
    for(int j=i;j<nNum && num[i]*num[j]<PRIME;j++){
      if(!isPrime[num[j]]) continue;
      cnt[num[i]*num[j]] = 1;
    }
  }
  
  ans[0] = cnt[0];
  for(int i=1;i<PRIME;i++)
    ans[i] = cnt[i]+ans[i-1];
}

int H;

bool read(){
  cin >> H;
  if(H==0) return false;
  return true;
}

void work(){
  cout << H << ' ' << ans[H] << endl;
}

int main(){
  makeTable();
  
  while(read())
    work();

  return 0;
}
