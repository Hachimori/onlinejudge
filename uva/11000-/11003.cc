#include<iostream>
using namespace std;
const int BOX = 1001, CAP = 3001;

int nBox, weight[BOX], cap[BOX];

bool read(){
  cin >> nBox;
  if(nBox==0) return false;
  for(int i=0;i<nBox;i++)
    cin >> weight[i] >> cap[i];
  return true;
}

int rec(int id, int ca, int dp[BOX][CAP+1]){
  if(id==nBox) return 0;
  int &ret = dp[id][ca];
  if(ret!=-1) return ret;
  if(ca==CAP)
    ret = max(ret,rec(id+1,cap[id],dp)+1);
  else if(ca-weight[id]>=0)
    ret = max(ret,rec(id+1,min(cap[id],ca-weight[id]),dp)+1);
  ret = max(ret,rec(id+1,ca,dp));
  return ret;
}

void work(){
  static int dp[BOX][CAP+1];
  memset(dp,-1,sizeof(dp));
  cout << rec(0,CAP,dp) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
