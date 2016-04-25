#include<iostream>
#include<algorithm>
#define INF 2000000000
#define BUF 100005
using namespace std;

int nMan, val[BUF];

void read(){
  cin >> nMan;
  for(int i=0;i<nMan;i++)
    cin >> val[i];
}

void work(){
  int minV[BUF];
  
  minV[nMan-1] = val[nMan-1];
  for(int i=nMan-2;i>=0;i--)
    minV[i] = min(val[i],minV[i+1]);
  
  int ans = -INF;
  for(int i=0;i<nMan-1;i++)
    ans = max(ans,val[i]-minV[i+1]);
  
  cout << ans << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
