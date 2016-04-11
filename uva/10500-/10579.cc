#include<iostream>
using namespace std;
const int BUF = 5000, TBL = 5000;

class BigInt{
public:
  int len, v[BUF];
  BigInt(){}
  BigInt(int n){
    len = 0;
    memset(v,0,sizeof(v));
    while(n){
      v[len++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt bi){
    for(int i=0;i<BUF;i++)
      bi.v[i] += v[i];
    for(int i=0;i<BUF;i++){
      if(bi.v[i]) bi.len = i+1;
      if(bi.v[i]>=10){
        bi.v[i+1] += bi.v[i]/10;
        bi.v[i] %= 10;
      }
    }
    return bi;
  }
};

int n;

int main(){
  static BigInt tbl[TBL+1];
  tbl[1] = 1;
  tbl[2] = 1;
  for(int i=3;i<=TBL;i++)
    tbl[i] = tbl[i-1]+tbl[i-2];
  while(cin >> n){
    for(int i=tbl[n].len-1;i>=0;i--)
      cout << tbl[n].v[i];
    cout << endl;
  }
  return 0;
}
