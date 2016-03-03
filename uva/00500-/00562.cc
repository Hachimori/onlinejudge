// knapsack
//
// MAX_BUF は コインの最大の枚数*コインの最大の価値/2でよい。
// よって 100*500/2 = 25005 となる。
// 
// なぜ半分で済むのかというと、一方の取り分を価値の合計から
// 引くことでもう一方の取り分が求まり、価値の合計の半分をカバーすれば
// 一方の取り分ともう一方の取り分の全ての組み合わせが求められるから。


#include<iostream>

#define MAX_SIZE 105
#define MAX_BUF 25005

using namespace std;

int nCoin, coin[MAX_SIZE];
bool isAvail[MAX_SIZE][MAX_BUF];

void read(){
  cin >> nCoin;
  
  for(int i=0;i<nCoin;i++)
    cin >> coin[i];
}

void work(){
  int sum = 0;
  for(int i=0;i<nCoin;i++)
    sum += coin[i];
  
  for(int i=0;i<nCoin+1;i++)
    for(int j=0;j<=sum/2;j++)
      isAvail[i][j] = false;
  
  isAvail[0][0] = true;
  
  for(int curr=0;curr<nCoin;curr++){
    for(int val=0;val<=sum/2;val++){
      if(!isAvail[curr][val]) continue;
      
      isAvail[curr+1][val] = true;
      
      if(val+coin[curr]<=sum/2)
	isAvail[curr+1][val+coin[curr]] = true;
    }
  }
  
  int maxVal = 0;
  for(int i=0;i<=sum/2;i++)
    if(isAvail[nCoin][i])
      maxVal = i;

  cout << (sum-maxVal)-maxVal << endl;
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
