#include<iostream>
#include<algorithm>
#include<vector>
#define SOLVE 1005
#define PROBLEM 10005
using namespace std;

int nSolve[3], solve[3][SOLVE];

void read(){
  for(int i=0;i<3;i++){
    cin >> nSolve[i];
    for(int j=0;j<nSolve[i];j++)
      cin >> solve[i][j];
  }
}

void work(int cases){
  int cnt[PROBLEM];
  for(int i=0;i<PROBLEM;i++) cnt[i] = 0;

  for(int i=0;i<3;i++)
    for(int j=0;j<nSolve[i];j++)
      cnt[solve[i][j]]++;
  
  int maxV = 0;
  vector<int> id[3];
  for(int i=0;i<3;i++){
    for(int j=0;j<nSolve[i];j++)
      if(cnt[solve[i][j]]==1)
        id[i].push_back(solve[i][j]);
    maxV = max(maxV,(int)id[i].size());
  }
  
  cout << "Case #" << cases << ":" << endl;
  for(int i=0;i<3;i++)
    if(maxV==id[i].size()){
      cout << i+1 << ' ' << maxV;
      sort(id[i].begin(),id[i].end());
      for(int j=0;j<id[i].size();j++)
        cout << ' ' << id[i][j];
      cout << endl;
    }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
