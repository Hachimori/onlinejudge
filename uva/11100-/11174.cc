// 以下の漸化式を解く。
//
// rec(id, nChild[]){
//   ret = 1, sum = 0;
//
//   for each id's child {
//      next = id's child;
//      ret *= rec(next) * combination(nChild[id]-sum,nChild[next]+1);
//      sum += nChild[next]+1;
//   }
//
//   return ret;
// }

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define NODE 40005
#define NUM_PRIME 4300   // 0-40005間の素数の数は4203個
#define MOD 1000000007
using namespace std;

int nPrime, prime[NUM_PRIME], prime2Idx[NODE];
vector<pair<int,int> > factor[NODE];

void makePrime(){
  bool isPrime[NODE];
  for(int i=0;i<NODE;i++){
    isPrime[i] = true;
    prime2Idx[i] = -1;
  }

  for(int i=2;i*i<NODE;i++)
    if(isPrime[i])
      for(int j=i*2;j<NODE;j+=i)
	isPrime[j] = false;
  
  nPrime = 0;
  for(int i=2;i<NODE;i++)
    if(isPrime[i]){
      prime[nPrime] = i;
      prime2Idx[i] = nPrime;
      nPrime++;
    }
}

void factorize(){
  for(int i=2;i<NODE;i++){
    int cur = i;
    for(int j=0;prime[j]*prime[j]<=cur;j++){
      if(cur%prime[j]!=0) continue;

      int cnt = 0;
      while(cur%prime[j]==0) cur/=prime[j], cnt++;
      factor[i].push_back(make_pair(j,cnt));
    }
    if(cur!=1)
      factor[i].push_back(make_pair(prime2Idx[cur],1));
  }
}

int nNode;
vector<int> adj[NODE], back[NODE];

void read(){
  int nEdge;
  scanf("%d%d",&nNode,&nEdge);
  
  for(int i=0;i<NODE;i++){
    adj[i].clear();
    back[i].clear();
  }

  for(int i=0;i<nEdge;i++){
    int s, t;
    scanf("%d%d",&s,&t);
    s--, t--;
    adj[s].push_back(t);
    back[t].push_back(s);
  }
}

int nume[NUM_PRIME], deno[NUM_PRIME];

void add(int n, int m){
  typedef vector<pair<int,int> >::iterator iter;

  for(int i=max(m,n-m)+1;i<=n;i++)
    for(iter j=factor[i].begin();j!=factor[i].end();j++)
      nume[j->first] += j->second;
  
  for(int i=2;i<=min(m,n-m);i++)
    for(iter j=factor[i].begin();j!=factor[i].end();j++)
      deno[j->first] += j->second;
}

void dfs(int curr, int nChild[]){
  nChild[curr] = 0;
  for(int i=0;i<back[curr].size();i++){
    dfs(back[curr][i],nChild);
    nChild[curr] += nChild[back[curr][i]]+1;
  }
}

void rec(int curr, int child[]){
  int sum = 0;
  for(int i=0;i<back[curr].size();i++){
    int next = back[curr][i];
    rec(next,child);
    add(child[curr]-sum,child[next]+1);
    sum += child[next]+1;
  }
}

void work(){
  for(int i=0;i<nNode;i++)
    if(adj[i].size()==0){
      adj[i].push_back(nNode);
      back[nNode].push_back(i);
    }
  nNode++;
  
  int nChild[NODE];
  dfs(nNode-1,nChild);

  fill(nume,nume+NUM_PRIME,0);
  fill(deno,deno+NUM_PRIME,0);
  
  rec(nNode-1,nChild);
  
  for(int i=0;i<NUM_PRIME;i++) nume[i] -= deno[i];
  
  long long ret = 1;
  for(int i=0;i<NUM_PRIME;i++)
    for(int j=0;j<nume[i];j++)
      ret = (ret*prime[i])%MOD;
  
  cout << ret << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  makePrime();
  factorize();
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
