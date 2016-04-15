#include<iostream>
#include<algorithm>
#include<cstdio>
#define BUF 500005
using namespace std;

int nNum, num[BUF];

bool read(){
  cin >> nNum;
  if(nNum==0) return false;

  for(int i=0;i<nNum;i++) 
    scanf("%d",&num[i]);
  
  return true;
}

void msort(int L, int R, long long &ans){
  if(L>=R) return;
  if(L+1==R){
    if(num[L]>num[R]){
      swap(num[L],num[R]);
      ans++;
    }
    return;
  }
  
  int mid = (L+R)/2;
  msort(L,mid,ans);
  msort(mid+1,R,ans);
  
  static int buf[BUF];
  for(int i=L,j=mid+1,cur=L;i<=mid || j<=R;){
    if(i>mid || (j<=R && num[i]>num[j])){
      buf[cur++] = num[j++];
      ans += mid-i+1;
    }
    else
      buf[cur++] = num[i++];
  }

  for(int i=L;i<=R;i++)
    num[i] = buf[i];
}

void work(){
  long long ans = 0;

  msort(0,nNum-1,ans);
  
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
