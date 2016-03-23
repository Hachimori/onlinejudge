#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define MAX_SIZE 100

using namespace std;

int nNum, nSum;
int sum[MAX_SIZE];

bool read(){
  if(!(cin >> nNum)) return false;
  
  nSum = nNum*(nNum-1)/2;
  
  for(int i=0;i<nSum;i++)
    cin >> sum[i];
    
  return true;
}

bool rec(vector<int> &ans, int curr, multiset<int> &remain){
  if(curr==nNum-1) return true;

  int nextNum = *remain.begin() - ans[0];

  multiset<int> next = remain;
  
  for(int i=0;i<ans.size();i++){
    multiset<int>::iterator pos = next.find(nextNum+ans[i]);
    
    if(pos==next.end()) return false;
    else
      next.erase(pos);
  }

  ans.push_back(nextNum);
  
  return rec(ans,curr+1,next);
}

void work(){
  sort(sum,sum+nSum);
  
  multiset<int> remain;
  for(int i=0;i<nSum;i++)
    remain.insert(sum[i]);
  
  int d[]={-1,1}; 
  bool idx;

  if(sum[0]<0) idx = 0;
  else idx = 1;
  
  for(int i=(sum[0]+d[idx])/2;i<=d[idx]*sum[0];i++){
    vector<int> ans;

    ans.push_back(sum[0]-i);
    ans.push_back(i);
    
    multiset<int>::iterator iter = remain.begin();
    int tmp = *iter;
    remain.erase(iter);

    if(!rec(ans,1,remain)){
      remain.insert(tmp);
      continue;
    }

    for(int j=0;j<nNum;j++){
      if(j!=0) cout << ' ';
      cout << ans[j];
    }
    cout << endl;
    return;
  }

  cout << "Impossible" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
