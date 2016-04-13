#include<iostream>
#include<set>
#include<cmath>

#define MAX_SIZE 15

using namespace std;

unsigned long long target;

bool read(){
  cin >> target;
  if(target==0) return false;
  return true;
}

unsigned long long myPow(unsigned long long n, double p){
  
  unsigned long long ans=1;
  
  for(unsigned long long i=0;i<(unsigned long long)p;i++)
    ans*=n;
  
  return ans;
}

void work(){

  unsigned long long N=target*10/9;
  set<unsigned long long> S;
  
  //cout << log10((double)(target)) << endl;
  
  for(unsigned long long i=N-10;i<=N+10;i++)
    if(i-i/10==target)
      S.insert(i);
  
  
  for(set<unsigned long long>::iterator i=S.begin();i!=S.end();i++){
    if(i!=S.begin()) cout << ' ';
    cout << *i;
  }cout << endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
