//9999というデータに対してかなり時間がかかる
//vector を配列にすると時間の短縮になる

#include<iostream>
#include<vector>
#include<climits>

#define MAX_SIZE 10001

using namespace std;

int target;

bool read(){
  cin >> target;
  if(target==0) return false;
  return true;
}

int manhattan(vector<int> &curr){
  int nNeed=1;
  int p=2;
  
  while(p*curr.back()<=target){ 
    p*=2;
    nNeed++;
  }

  return nNeed;
  
}

void rec(vector<int> &curr, int &currMin, vector<int> &ans){
  /*
  for(int i=0;i<curr.size();i++)
    cout << curr[i] << ' ';
  cout << endl;
  */
  if(curr.back()==target){
    if(curr.size()<currMin){
      ans = curr;
      currMin = curr.size();
    }
    return;
  }
  if(curr.back()>target) return;
  if(currMin==curr.size()) return;
  if(manhattan(curr)+curr.size()>=currMin) return;
  
  for(vector<int>::reverse_iterator i=curr.rbegin();i!=curr.rend();i++){
    for(vector<int>::reverse_iterator j=i;j!=curr.rend();j++){
      
      vector<int> next = curr;
      
      if(*i+*j<=curr.back()) continue;
      next.push_back(*i+*j);
      
      rec(next,currMin,ans);
      
    }
  }
  
}

void work(){
  
  int currMin=INT_MAX;
  vector<int> curr,ans;
  
  curr.push_back(1);
  
  rec(curr,currMin,ans);
  
  for(int i=0;i<ans.size();i++){
    if(i==0) cout << ans[i];
    else cout << ' ' << ans[i];
  }cout << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
