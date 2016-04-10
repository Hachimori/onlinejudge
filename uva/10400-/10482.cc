#include<iostream>
#include<map>
using namespace std;
const int BUF = 35;

int nVal, val[BUF];

void read(){
  cin >> nVal;
  for(int i=0;i<nVal;i++) cin >> val[i];
}

int clean(int st){
  int t[] = {st/1000/1000,st/1000%1000,st%1000};
  sort(t,t+3);
  return t[2]*1000*1000+t[1]*1000+t[0];
}

int rec(int cur, int st, map<int,int> &dp){
  if(dp.count(st)) return dp[st];
  if(cur==nVal) return st/1000/1000-st%1000;
  int minV = 1<<20;
  for(int i=0,p=1;i<3;i++,p*=1000){
    st += val[cur]*p;
    minV = min(minV,rec(cur+1,clean(st),dp));
    st -= val[cur]*p;
  }
  return dp[st] = minV;
}

void work(int cases){
  map<int,int> dp;
  cout << "Case " << cases << ": " << rec(0,0,dp) << endl;
}

int main(){
  int cases;
  cin>> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
