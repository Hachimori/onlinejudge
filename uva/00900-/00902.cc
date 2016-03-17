#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cassert>
#define BACKET 50021
#define BUF 1000005
using namespace std;
typedef long long ll;

class Hash{
public:
  vector< pair<ll,int> > backet[BACKET];
  
  int insert(ll n){
    for(int i=0;i<backet[n%BACKET].size();i++)
      if(backet[n%BACKET][i].first==n){
	backet[n%BACKET][i].second++;
	return backet[n%BACKET][i].second;
      }
    backet[n%BACKET].push_back(make_pair(n,1));
    return 1;
  }
};

int leng, nCh, str[BUF];

bool read(){
  char s[BUF];
  if(scanf("%d%s",&leng,s)==EOF) return false;
  
  nCh = strlen(s);
  for(int i=0;i<nCh;i++)
    str[i] = s[i]-'a';

  return true;
}

void work(){
  static Hash M;
  ll toPush = 0, mod = 1, maxV, maxS;
  
  for(int i=0;i<BACKET;i++)
    M.backet[i].clear();
  
  for(int i=0;i<leng;i++){
    mod *= 26;
    toPush *= 26;
    toPush += str[i];
  }
  M.insert(toPush);

  maxV = 1, maxS = toPush;
  
  for(int i=leng;i<nCh;i++){
    toPush *= 26;
    toPush += str[i];
    toPush %= mod;
    int ret = M.insert(toPush);
    
    if(maxV<ret){
      maxV = ret;
      maxS = toPush;
    }
  }
  
  string ans;
  for(int i=0;i<leng;i++){
    ans += maxS%26 + 'a';
    maxS /= 26;
  }
  reverse(ans.begin(),ans.end());
  
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}

