#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n;

bool read(){
  if(scanf("%d",&n)==EOF) return false;
  return true;
}

void rec(int idx, long long curr, long long &ans, vector<int> &factor){
  if(idx==factor.size()){
    if(curr>n && ans>curr) ans = curr;
    return;
  }
  
  for(long long next=curr*factor[idx];next<2000000;next*=factor[idx])
    rec(idx+1,next,ans,factor);
}

void work(){
  if(n==1 || n==0){
    printf("Not Exist!\n");
    return;
  }
  
  vector<int> factor;
  int curr = n;
  
  for(int i=2;i*i<=curr;i++)
    if(curr%i==0){
      while(curr%i==0) curr /= i;
      factor.push_back(i);
    }
  if(curr!=1) factor.push_back(curr);

  long long ans = 2000000;
  rec(0,1,ans,factor);
  
  if(ans==2000000) printf("Not Exist!\n");
  else printf("%lld\n",ans);
}

int main(){
  while(read())
    work();
  
  return 0;
}
