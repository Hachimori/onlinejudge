#include<iostream>
#include<cstdio>
using namespace std;
const int DIGIT = 65, BUF = 2000;

class BigInt{
public:
  int leng, digit[DIGIT];
  
  BigInt(){}
  BigInt(int n){
    memset(digit,0,sizeof(digit));
    leng = 0;
    while(n){
      digit[leng++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt opp) {
    for(int i=0;i<leng;i++) opp.digit[i] += digit[i];
    for(int i=0;i+1<DIGIT;i++){
      if(opp.digit[i]) opp.leng = i+1;
      opp.digit[i+1] += opp.digit[i]/10;
      opp.digit[i] %= 10;
    }
    return opp;
  }

  void print(){
    for(int i=leng-1;i>=0;i--)
      printf("%d",digit[i]);
  }
};

int main(){
  int nVal = 1;
  static BigInt val[BUF], nex[BUF];

  val[0] = 1;
  while(1){
    for(int i=0;i<nVal;i++){
      if(i) cout << ' ';
      val[i].print();
    }cout << endl;

    for(int i=0;i<nVal;i++)
      if(val[i].leng>=61)
        return 0;

    for(int i=0;i<=nVal;i++){
      if(i==0)
        nex[i] = val[i];
      else if(i==nVal)
        nex[i] = val[i-1];
      else
        nex[i] = val[i-1]+val[i];
    }
    
    for(int i=0;i<=nVal;i++) val[i] = nex[i];
    nVal++;
  }
  
  return 0;
}
