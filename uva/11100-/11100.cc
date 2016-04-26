// この問題が要求していること:
//
// 
// 大きいバッグに小さいバッグをつめてゆき、一番外側にある
//    バックの数を最小にする。
// 
// バッグの中にあるバッグの数の最大値を最小にする。
// 例:  
// 6
// 1 1 1 2 3 4
// これに対し、
//
// 3
// 1 2 3 4
// 1
// 1
//
// このような答えは間違いで、正しい答えは、
//
// 3
// 1 2
// 1 3
// 1 4
//
//
//  
// 解法:
// 与えられるバックのサイズの中で一番個数の多いものに注目する。
// それが一番外側にあるバッグの数と等しくなる。また、バッグは
// 大きさの違うものを集めれば一つのバッグにまとめることが出来る。
// その理由は、あるバックよりも大きいものがあればそちらに取り込まれ
// 小さいものがあればそちらを取り込むので、結局一つにまとまるからである。
// なので、一番外側にあるバッグの数だけの入れ物を用意して、
// その入れ物に同じサイズのバックを入れないように、また全てのバッグを均等に
// 入れ物に入れるようにすると用件を満たせる。

#include<iostream>
#include<algorithm>
#include<vector>
#define BAG 100005
#define RANGE 1000005
using namespace std;

int maxCnt, cntSize[RANGE];

bool read(){
  int nBag;
  cin >> nBag;
  if(nBag==0) return false;
  
  maxCnt = 0;
  for(int i=0;i<RANGE;i++)
    cntSize[i] = 0;
  
  for(int i=0;i<nBag;i++){
    int n;
    cin >> n;
    cntSize[n]++;
    maxCnt = max(maxCnt,cntSize[n]);
  }

  return true;
}

void work(){
  int cur = 0;
  vector<int> ans[BAG];
  
  for(int i=0;i<RANGE;i++)
    for(int j=0;j<cntSize[i];j++,cur=(cur+1)%maxCnt)
      ans[cur].push_back(i);
    
  cout << maxCnt << endl;
  for(int i=0;i<maxCnt;i++){
    for(int j=0;j<ans[i].size();j++){
      if(j) cout << ' ';
      cout << ans[i][j];
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}
