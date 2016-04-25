#include<iostream>
#include<string>
#include<numeric>
#include<algorithm>
#define BUF 1005
#define INF (1<<30)
using namespace std;

int nDate, date[BUF];
bool keep[BUF];

int convert(int mm, int dd, int hh, int MM){
  int ret = 0, p = 1;

  ret += MM*p; p*=60;
  ret += hh*p; p*=24;
  ret += dd*p; p*=32;
  ret += mm*p;
  
  return ret;
}

bool read(){
  cin >> nDate;
  if(nDate==0) return false;

  for(int i=0;i<nDate;i++){
    int month, day, hour, minute;
    char ch;
    string dummy;
    
    cin >> month >> ch >> day >> ch >> hour >> ch >> minute;
    cin >> dummy >> ch;
    
    date[i] = convert(month,day,hour,minute);
    keep[i] = (ch=='+');
  }
  
  return true;
}

void work(){
  if(accumulate(keep,keep+nDate,0)==0){
    cout << 0 << endl;
    return;
  }
  
  int keep2year[BUF];

  for(int i=0,curYear=0;i<nDate;i++,curYear++){
    int cur = i+1;
    
    keep2year[i] = curYear;
    while(cur<nDate && date[cur-1]<date[cur])
      keep2year[cur++] = curYear;
    
    i = cur-1;
  }
  
  
  int dp[BUF], bgn = 0;
  fill(dp,dp+nDate,INF);

  while(!keep[bgn]) dp[bgn++] = 0;
  dp[bgn++] = 1;
  
  for(int i=bgn;i<nDate;i++){
    for(int j=i-1;;j--){
      if(keep2year[j]==keep2year[i] && date[j]<date[i]){
	dp[i] = min(dp[i],dp[j]+1);	
      }
      if(keep2year[j]+1==keep2year[i] && date[j]>=date[i]){
	dp[i] = min(dp[i],dp[j]+1);
      }
      if(keep[j]) break;
    }
  }

  int ansIdx = nDate-1;
  while(!keep[ansIdx] && keep2year[ansIdx-1]==keep2year[ansIdx]) ansIdx--;

  cout << dp[ansIdx] << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
