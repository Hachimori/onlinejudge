#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int NUM = 1001, PRIME = 300, NPRIME = 62, TOADD = 15;

int nPrime, prime[NPRIME];

string itoa(int v){
  stringstream out;
  out << v;
  return out.str();
}

bool mySort(int a, int b){
  return itoa(a)<itoa(b);
}

void makePrime(){
  bool isPrime[PRIME];
  for(int i=0;i<PRIME;i++) isPrime[i] = true;
  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
        isPrime[j] = false;
  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
  sort(prime,prime+nPrime,mySort);
}

int n, toAdd;

bool read(){
  cin >> n >> toAdd;
  return !(n==0 && toAdd==0);
}


int dp[NUM][NPRIME][3][TOADD];
bool rec(int sum, int prev, int nPrevAdd, int nAdd){
  if(sum<0 || prev==nPrime) return false;
  int &ret = dp[sum][prev][nPrevAdd][nAdd];
  if(ret!=-1) return ret;
  if(sum==0 && nAdd==0) return ret = true;
  if(sum==0 || nAdd==0) return ret = false;
  if(nPrevAdd==2 || (prime[prev]==2 && nPrevAdd==1)) return ret = rec(sum,prev+1,0,nAdd);
  if(rec(sum-prime[prev],prev,nPrevAdd+1,nAdd-1)) return ret = true;
  if(rec(sum,prev+1,0,nAdd)) return ret = true;
  return ret = false;
}

void work(int cases){
  cout << "CASE " << cases << ":" << endl;
  if(!rec(n,0,0,toAdd))
    cout << "No Solution." << endl;
  else{
    vector<int> ans;
    int sum = n, prev = 0, nPrevAdd = 0, nAdd = toAdd;
    while(sum){
      if(nPrevAdd==2 || (prime[prev]==2 && nPrevAdd==1)){
        prev++;
        nPrevAdd = 0;
      }
      else if(sum-prime[prev]>=0 && dp[sum-prime[prev]][prev][nPrevAdd+1][nAdd-1]){
        ans.push_back(prime[prev]);
        sum -= prime[prev];
        nPrevAdd++;
        nAdd--;
      }
      else{
        prev++;
        nPrevAdd = 0;
      }
    }
    for(int i=0;i<ans.size();i++){
      if(i) cout << '+';
      cout << ans[i];
    }
    cout << endl;
  }
}

int main(){
  makePrime();
  memset(dp,-1,sizeof(dp));
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
