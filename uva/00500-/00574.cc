#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int BUF = 1005, NUM = 15;

int goal, nNum, num[NUM];

bool read(){
  cin >> goal >> nNum;
  if(goal==0 && nNum==0) return false;
  for(int i=0;i<nNum;i++) cin >> num[i];
  sort(num,num+nNum);
  reverse(num,num+nNum);
  return true;
}


bool rec(int curNum, int sum, int nHistory, vector<int> &cnt, int history[NUM]){
  if(sum>goal) return false;
  if(sum==goal){
    for(int i=0;i<nHistory;i++){
      if(i) cout << '+';
      cout << history[i];
    }
    cout << endl;
    return true;
  }
  if(curNum==cnt.size()) return false;
  
  bool isOk = false;
  for(int i=cnt[curNum];i>=0;i--){
    for(int j=0;j<=i;j++)
      history[nHistory+j] = num[curNum];
    isOk |= rec(curNum+1,sum+i*num[curNum],nHistory+i,cnt,history);
  }
  return isOk;
}


void work(){
  vector<int> cnt;
  for(int i=0;i<nNum;){
    int j = i;
    while(j<nNum && num[i]==num[j]) j++;
    num[cnt.size()] = num[i];
    cnt.push_back(j-i);
    i = j;
  }

  cout << "Sums of " << goal << ":" << endl;
  int history[NUM];
  if(!rec(0,0,0,cnt,history))
    cout << "NONE" << endl;
}


int main(){
  while(read()) work();
  return 0;
}
