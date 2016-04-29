#include<iostream>
using namespace std;
const int BUF = 100;

int A, B, MOD;

void read(){
  cin >> A >> B >> MOD;
}


int rec(int mulDigit, int sumDigit, int isEq, int nThDigit, int val[10], int dp[BUF][BUF][2][10]){
  if(nThDigit==10) return mulDigit==0 && sumDigit==0;
  int &ret = dp[mulDigit][sumDigit][isEq][nThDigit];
  if(ret!=-1) return ret;
  ret = 0;
  if(isEq==0){
    for(int i=0;i<=9;i++)
      ret += rec((mulDigit*10+i)%MOD,(sumDigit+i)%MOD,0,nThDigit+1,val,dp);
  }
  else {
    for(int i=0;i<val[nThDigit];i++)
      ret += rec((mulDigit*10+i)%MOD,(sumDigit+i)%MOD,0,nThDigit+1,val,dp);
    ret += rec((mulDigit*10+val[nThDigit])%MOD,(sumDigit+val[nThDigit])%MOD,1,nThDigit+1,val,dp);
  }
  return ret;
}


int calc(int n){
  static int val[10], dp[BUF][BUF][2][10];
  for(int i=0;i<10;i++){
    val[9-i] = n%10;
    n /= 10;
  }
  memset(dp,-1,sizeof(dp));
  return rec(0,0,1,0,val,dp);
}


void work(){
  if(MOD>=BUF)
    cout << 0 << endl;
  else
    cout << calc(B)-calc(A-1) << endl;
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
