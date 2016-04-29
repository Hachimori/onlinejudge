#include<iostream>
using namespace std;
const int BUF = 2005, DIGIT = 500;

class bi{
public:
  int leng, v[DIGIT];
  
  bi(){}
  bi(int n){
    memset(v,0,sizeof(v));
    leng = 0;
    while(n){
      v[leng++] = n%10;
      n /= 10;
    }
  }

  void print(){
    if(leng==0){
      cout << 0 << endl;
      return;
    }
    for(int i=leng-1;i>=0;i--) cout << v[i];
    cout << endl;
  }

  bi operator+ (bi opp){
    for(int i=0;i<DIGIT;i++) opp.v[i] += v[i];
    for(int i=0;i<DIGIT;i++){
      if(opp.v[i]>=10){
        opp.v[i+1]++;
        opp.v[i] -= 10;
      }
      if(opp.v[i]) opp.leng = i+1;
    }
    return opp;
  }

  bi operator+= (bi opp){
    *this = *this+opp;
    return *this;
  }
};

int need[]={6,2,5,5,4,5,6,3,7,6};
bi dp[BUF];
bi rec(int n){
  bi &ret = dp[n];
  if(ret.leng!=-1) return ret;
  ret = 1;
  for(int i=0;i<=9;i++)
    if(n-need[i]>=0)
      ret = ret+rec(n-need[i]);
  return ret;
}

int main(){
  for(int i=0;i<BUF;i++) dp[i].leng = -1;
  
  int n;
  while(cin >> n){
    bi sum = n>=6 ? 1 : 0;
    for(int i=1;i<=9;i++)
      if(n-need[i]>=0)
        sum = sum+rec(n-need[i]);
    sum.print();
  }
  return 0;
}
