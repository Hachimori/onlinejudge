// DP
//
//
// 二つのテーブルを用意する。
//
// table[n][idx] には、 idx,idx+1 の棒を使い、
//                       かつidx+2~nStickの棒をn-1回使った最小のbadnessを保存。
//
// minVal[n][idx] には、 idx~nStick までの棒をn回使った最小のbadnessを保存。
//
//
// テーブルの値を更新するには、
// table[n][idx] = (stick[idx]-stick[idx+1])^2 + minVal[n-1][idx+2];
// minVal[n][idx] = min(table[n][idx],minVal[n][idx+1]);
// とする。 
//
// テーブルの更新を nStick-(i+1)*3 から始めるのは、
// ３個目に使う棒を十分に残しておくため。

#include<iostream>
#include<climits>
#include<algorithm>

#define MAX_PEOPLE 1015
#define MAX_STICK 5005

using namespace std;

int nPeople, nStick, stick[MAX_STICK];

void read(){
  cin >> nPeople >> nStick;

  nPeople += 8;

  for(int i=0;i<nStick;i++)
    cin >> stick[i];
}

void work(){
  // ここでは table[idx]:      table[n-1][idx],
  //          nextTable[idx]:  table[n][idx]
  //          minVal[idx]:     minVal[n-1][idx],
  //          nextMinVal[idx]: minVal[n][idx]
  
  int table[MAX_STICK], minVal[MAX_STICK];
  int nextTable[MAX_STICK], nextMinVal[MAX_STICK];

  for(int i=0;i<nStick;i++) 
    minVal[i] = 0;
  
  for(int i=0;i<nPeople;i++){
    nextMinVal[nStick-(i+1)*3+1] = INT_MAX;
    for(int j=nStick-(i+1)*3;j>=0;j--){
      nextTable[j] = (stick[j]-stick[j+1])*(stick[j]-stick[j+1]) + minVal[j+2];
      nextMinVal[j] = min(nextTable[j],nextMinVal[j+1]);
    }
    
    for(int j=0;j<nStick;j++){
      table[j] = nextTable[j];
      minVal[j] = nextMinVal[j];
    }
  }

  cout << minVal[0] << endl;
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
