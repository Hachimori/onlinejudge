#include<iostream>
#include<algorithm>
#define BUF 10005
#define INF (1LL<<62)
using namespace std;
typedef long long integer;

int c, m, n;
int cap[BUF], price[BUF];
int size[BUF], num[BUF];

bool read(){
  cin >> c >> m >> n;
  if((c|m|n)==0) return false;

  for(int i=0;i<m;i++) cin >> cap[i] >> price[i];
  for(int i=0;i<n;i++) cin >> size[i] >> num[i];
  
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(size[i]<size[j]){
        swap(size[i],size[j]);
        swap(num[i],num[j]);
      }
  
  return true;
}

void work(int cases){
  integer dp[BUF];
  for(int i=0;i<n;i++) dp[i] = INF;

  for(int i=0;i<n;i++){
    integer minV = INF;

    for(int j=0;j<m;j++)
      if(size[i]<=cap[j] && minV>price[j])
        minV = price[j];
    
    if(minV==INF){
      cout << "case " << cases << ": not possible" << endl;
      return;
    }
    
    integer sum = 0;
    for(int j=i;j<n;j++){
      sum += num[j];
      dp[j] = min(dp[j],(i==0?0:dp[i-1])+sum*minV+c);
    }
  }

  cout << "case " << cases << ": " << dp[n-1] << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
