#include<iostream>
#include<map>
using namespace std;

int N, D;

bool read(){
  cin >> N >> D;
  return !(N==0 && D==0);
}

void addFactor(int n, map<int,int> &M){
  for(int i=2;i*i<=n;i++)
    while(n%i==0){
      n /= i;
      M[i]++;
    }
  if(n>1) M[n]++;
}

void work(){
  map<int,int> factN, factD;
  for(int i=2;i<=N;i++) addFactor(i,factN);
  addFactor(D,factD);

  for(map<int,int>::iterator i=factD.begin();i!=factD.end();i++)
    if(!factN.count(i->first) || factN[i->first]<i->second){
      cout << 0 << endl;
      return;
    }
    else
      factN[i->first] -= i->second;
  
  long long ans = 1;
  for(map<int,int>::iterator i=factN.begin();i!=factN.end();i++)
    ans *= i->second+1;
  cout << ans << endl;
}

int main(){
  while(read()) work();
  return 0;
}
