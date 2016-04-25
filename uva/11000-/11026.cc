// 与えられる数を V_0, V_1, V_2, .... V_M とおく。
//
// dp[k][m]に K個の数の積のうち、V_mを最後に掛けたものの総和を入れる。
// 
// 漸化式は以下の通り
// dp[k+1][m] = (dp[k+1][m-1]+dp[k][m-1]*V_m)%MOD
// 
//
// 以下はテーブルに入っている要素(N=4のとき)
// 
// 1   a    b   c    d
//     ---------------
// 2       ab  ac   ad
//              +    +
//             bc   bd
//                   +
//                  cd
//     ---------------
// 3          abc  abd
//                  +
//                 acd
//                  +
//                 bcd
//     ---------------
// 4              abcd

#include<iostream>
#include<algorithm>
#define NUM 1005
using namespace std;
typedef long long ll;

int nNum, mod, num[NUM];

bool read(){
  cin >> nNum >> mod;
  if(nNum==0 && mod==0) return false;
  
  for(int i=0;i<nNum;i++)
    cin >> num[i];

  return true;
}

void work(){
  static ll sum[NUM], dp[NUM][NUM]; 
  
  for(int i=0;i<nNum;i++){
    for(int j=0;j<nNum;j++)
      dp[i][j] = 0;
    sum[i] = 0;
  }
  
  for(int i=0;i<nNum;i++)
    sum[0] = (sum[0]+num[i])%mod;
  
  dp[0][0] = num[0]%mod;
  for(int i=1;i<nNum;i++)
    dp[0][i] = (dp[0][i-1]+num[i])%mod;
    
  for(int i=0;i+1<nNum;i++)
    for(int j=i+1;j<nNum;j++){
      sum[i+1] = (sum[i+1]+dp[i][j-1]*num[j])%mod;
      dp[i+1][j] = (dp[i+1][j-1]+dp[i][j-1]*num[j])%mod;
    }

  cout << *max_element(sum,sum+nNum) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
