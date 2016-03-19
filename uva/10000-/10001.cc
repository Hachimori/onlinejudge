#include<iostream>
#include<cstring>
using namespace std;
const int BUF = 40;

int mask2bit[1<<3];
int nBit, dst[BUF];


bool read(){
  int mask;
  if(!(cin >> mask >> nBit)) return false;
  
  for(int i=0;i<8;i++) mask2bit[i] = (mask&(1<<i))>0;
  
  for(int i=0;i<nBit;i++){
    char bit;
    cin >> bit;
    dst[i] = bit=='1';
  }
  
  return true;
}

int convert(int pre, int cur, int nex){
  return mask2bit[(pre<<2)+(cur<<1)+nex];
}

int rec(int bit0, int bit1, int preBit, int curBit, int curIdx, int dp[2][2][2][2][BUF]){
  int &ret = dp[bit0][bit1][preBit][curBit][curIdx];
  if(ret!=-1) return ret;
  if(curIdx==nBit-1) return ret = convert(preBit,curBit,bit0)==dst[nBit-1] &&
                            rec(bit0,bit1,curBit,bit0,0,dp);
  if(curIdx==0) return ret = convert(preBit,curBit,bit1)==dst[0];
  ret = 0;
  for(int nexBit=0;nexBit<2;nexBit++){
    if(convert(preBit,curBit,nexBit)!=dst[curIdx]) continue;
    if(rec(bit0,bit1,curBit,nexBit,(curIdx+1)%nBit,dp)) return ret = 1;
  }
  return ret;
}


void work(){
  int dp[2][2][2][2][BUF];
  memset(dp,-1,sizeof(dp));
  for(int bit0=0;bit0<2;bit0++)
    for(int bit1=0;bit1<2;bit1++)
      if(rec(bit0,bit1,bit0,bit1,1,dp)){
        cout << "REACHABLE" << endl;
        return;
      }
  cout << "GARDEN OF EDEN" << endl;
}


int main(){
  while(read()) work();
  return 0;
}
