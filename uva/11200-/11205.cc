#include<iostream>
#include<set>
#define NUM 105
#define BIT 15
#define BUF (1<<BIT)
#define INF (1<<20)
using namespace std;

int nBit, nNum;
bool num[NUM][BIT];

void read(){
  cin >> nBit >> nNum;

  for(int i=0;i<nNum;i++)
    for(int j=0;j<nBit;j++){
      int v; cin >> v;
      num[i][j] = v;
    }
}

int cntBit(int n){
  int ret = 0;
  while(n>0){
    ret += n%2;
    n /= 2;
  }
  return ret;
}

void work(){
  int minV = INF;

  for(int mask=0;mask<(1<<nBit);mask++){
    if(minV<=cntBit(mask)) continue;
    
    set<int> S;
    for(int i=0;i<nNum;i++){
      int sum = 0;
      for(int j=0;j<nBit;j++)
	if((mask&(1<<j)) && num[i][j])
	  sum += (1<<j);

      if(S.count(sum)) goto finish;
      S.insert(sum);
    }
    
    minV = cntBit(mask);
  finish:;
  }

  cout << minV << endl;
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
