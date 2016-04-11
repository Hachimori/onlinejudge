#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 205
using namespace std;

class DSet{
public:
  int pre[BUF];
  vector<int> group[BUF][2];

  DSet(){}
  DSet(int n){
    for(int i=0;i<n;i++){
      pre[i] = i;
      group[i][0].push_back(i);
    }
  }

  int find(int n){
    return pre[n]==n?n:pre[n]=find(pre[n]);
  }

  void merge(int a, int b){
    if(find(a)!=find(b)){
      int aGroup = find(a), bGroup = find(b);
      if(count(group[aGroup][0].begin(),group[aGroup][0].end(),a) ^
         count(group[bGroup][0].begin(),group[bGroup][0].end(),b)){
        group[aGroup][0].insert(group[aGroup][0].end(),group[bGroup][0].begin(),group[bGroup][0].end());
        group[aGroup][1].insert(group[aGroup][1].end(),group[bGroup][1].begin(),group[bGroup][1].end());
        group[bGroup][0].clear();
        group[bGroup][1].clear();
      }
      else{
        group[aGroup][0].insert(group[aGroup][0].end(),group[bGroup][1].begin(),group[bGroup][1].end());
        group[aGroup][1].insert(group[aGroup][1].end(),group[bGroup][0].begin(),group[bGroup][0].end());
        group[bGroup][0].clear();
        group[bGroup][1].clear();        
      }
      pre[bGroup] = aGroup;
    }
  }
};

int nMan;
vector<int> enemy[BUF];

void read(){
  cin >> nMan;
  for(int i=0;i<nMan;i++) enemy[i].clear();
  for(int i=0;i<nMan;i++){
    int nEnemy;
    cin >> nEnemy;
    for(int j=0;j<nEnemy;j++){
      int v;
      cin >> v;
      if(v<=nMan) enemy[i].push_back(v-1);
    }
  }
}

void work(){
  DSet dset(nMan);
  for(int i=0;i<nMan;i++)
    for(int j=0;j<enemy[i].size();j++)
      dset.merge(i,enemy[i][j]);

  int ans = 0;
  bool visited[BUF] = {false};
  for(int i=0;i<nMan;i++){
    int iGroup = dset.find(i);
    if(!visited[iGroup]){
      visited[iGroup] = true;
      bool invalid = false;
      for(int ii=0;ii<2;ii++)
        for(int j=0;j<dset.group[iGroup][ii].size();j++){
          int self = dset.group[iGroup][ii][j];
          for(int k=0;k<enemy[self].size();k++){
            int opp = enemy[self][k];
            if(count(dset.group[iGroup][ii].begin(),dset.group[iGroup][ii].end(),opp)){
              invalid = true;
              goto _finish;
            }
          }
        }
    _finish:
      if(!invalid) ans += max(dset.group[iGroup][0].size(),dset.group[iGroup][1].size());
    }
  }
  cout << ans << endl;
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
