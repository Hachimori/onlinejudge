#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

#define MAX_SIZE 100000

using namespace std;

int nPrime;
int prime[MAX_SIZE];

void makeTable(){
  
  bool isPrime[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    isPrime[i] = true;
  
  nPrime = 0;
  
  for(int i=2;i*i<MAX_SIZE;i++)
    if(isPrime[i])
      for(int j=i*2;j<MAX_SIZE;j+=i)
	isPrime[j] = false;

  
  for(int i=2;i<MAX_SIZE;i++)
    if(isPrime[i])
      prime[nPrime++] = i;

}

int remain, baked;

void read(){
  cin >> baked >> remain;
}

int power(int p, int n){
  
  if(n==0) return 1;
  if(n==1) return p;
  
  if(n%2==0) {
    int tmp = power(p,n/2);
    return tmp*tmp;
  }
  else {
    int tmp = power(p,n/2);
    return tmp*tmp*p;
  }
  
}

void rec(long long guest, int &nEat, map<int,int>::iterator &curr, 
	 map<int,int> &factor, vector<int> &ans){
  if(guest>nEat) return;
  
  if(curr==factor.end()){
    if(remain<nEat/guest)
      ans.push_back(nEat/guest);
    return;
  }
  
  for(int i=0;i<=curr->second;i++){
    int toMul = curr->first;
    curr++;
    
    rec(guest*power(toMul,i),nEat,curr,factor,ans);
    
    curr--;
  }
  
}

void work(int cases){
  
  map<int,int> factor;
  
  if(baked==remain){
    cout << "Case #" << cases << ": 0" << endl;
    return;
  }

  int nEat = baked-remain;
  
  
  for(int i=0;i<nPrime;i++){
    while(nEat%prime[i]==0) {
      if(!factor.count(prime[i])) factor[prime[i]] = 1;
      else factor[prime[i]]++;
      nEat /= prime[i];
    }
  }
  
  if(nEat!=1)
    factor[nEat] = 1;
  
  vector<int> ans;
  map<int,int>::iterator iter = factor.begin();
  
  nEat = baked-remain;

  rec(1,nEat,iter,factor,ans);
 
  sort(ans.begin(),ans.end());
 
  cout << "Case #" << cases << ":";
  for(int i=0;i<ans.size();i++)
      cout << " " << ans[i];

  cout << endl;
}

int main(){

  makeTable();
  
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
