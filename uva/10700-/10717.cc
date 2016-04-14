#include<iostream>
using namespace std;
const int  BUF = 55, INF = 1<<30;

long long gcd(long long a, long long b){
  return b==0 ? a : gcd(b,a%b);
}

long long lcm(long long a, long long b){
  return a/gcd(a,b)*b;
}

long long calc(int a, int b, int c, int d){
  long long ret = 1;
  ret = lcm(ret,a);
  ret = lcm(ret,b);
  ret = lcm(ret,c);
  ret = lcm(ret,d);
  return ret;
}

int main(){
  int nCoin, coin[BUF], nTable, table[BUF];
  while(cin >> nCoin >> nTable,nCoin|nTable){
    for(int i=0;i<nCoin;i++)
      cin >> coin[i];
    for(int i=0;i<nTable;i++)
      cin >> table[i];
    for(int i=0;i<nTable;i++){
      long long minBigger = INF, maxSmaller = -INF;
      for(int j=0;j<nCoin;j++)
        for(int k=j+1;k<nCoin;k++)
          for(int l=k+1;l<nCoin;l++)
            for(int m=l+1;m<nCoin;m++){
              long long lcm = calc(coin[j],coin[k],coin[l],coin[m]);
              if(table[i]%lcm==0)
                minBigger = maxSmaller = table[i];
              else{
                minBigger = min(minBigger,(table[i]/lcm+1)*lcm);
                maxSmaller = max(maxSmaller,table[i]/lcm*lcm);
              }
            }
      cout << maxSmaller << ' ' << minBigger << endl;
    }
  }
  return 0;
}
