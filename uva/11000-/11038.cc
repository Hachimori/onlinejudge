#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 10
using namespace std;
typedef long long ll;

ll bgn, end, tbl[2][BUF];

void makeTable(){
  tbl[0][0] = tbl[1][0] = 1;
  
  for(ll i=1,p=10;i<BUF;i++,p*=10){
    tbl[0][i] = 9*tbl[1][i-1]+tbl[0][i-1];
    tbl[1][i] = 10*tbl[1][i-1]+p;
  }
}

bool read(){
  cin >> bgn >> end;
  if(bgn==-1 && end==-1) return false;
  return true;
}

ll calc(ll n){
  ll ret = 0;
  vector<int> v;

  for(ll k=n;k>0;k/=10) v.push_back(k%10);
  
  if(v.size()>=2) ret += tbl[0][v.size()-2];
  
  for(ll i=1,pp=10;i<v.size();i++,pp*=10){
    if(i==v.size()-1){
      ret += (v[i]-1)*tbl[1][i-1];
      continue;
    }
    if(v[i]==0){
      for(ll j=0,p=1;j<i;j++,p*=10) ret += v[j]*p;
      ret++;
      continue;
    }
    ret += v[i]*tbl[1][i-1];
    ret += pp;
  }
  ret++;
  
  return ret;
}

void work(){
  int cnt = 0;
  for(ll n=bgn;n>0;n/=10) if(n%10==0) cnt++;
  
  if(bgn==0) cout << calc(end) << endl;
  else cout << calc(end)-calc(bgn)+cnt << endl;
}

int main(){
  makeTable();
  while(read())
    work();
  
  return 0;
}
