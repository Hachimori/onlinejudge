// 10534
// 前原さんのLISライブラリを参考にした

#include<iostream>
#include<algorithm>
#include<vector>
const int INF = 1<<30;
using namespace std;


vector<int> lis(vector<int> num){
  vector<int> seq(num.size(),INF); // 逐次更新される増加列
  vector<int> idx(num.size(),INF); // idx[n]: n番目のnumが増加列のどこにあるか
  
  for(int i=0;i<num.size();i++){
    int pos = lower_bound(seq.begin(),seq.end(),num[i])-seq.begin();
    seq[pos] = num[i];
    idx[i] = pos;
  }

  int len = *max_element(idx.begin(),idx.end())+1;
  vector<int> ret(len);
  for(int i=num.size()-1;i>=0;i--)
    if(idx[i]==len-1)
      ret[--len] = num[i];

  //return ret;
  return idx;
}


vector<int> v;


bool read(){
  int nNum;
  if(!(cin >> nNum)) return false;
  v.clear();
  for(int i=0;i<nNum;i++){
    int t;
    cin >> t;
    v.push_back(t);
  }
  return true;
}


void work(){
  vector<int> dp1, dp2;
  dp1 = lis(v);
  reverse(v.begin(),v.end());
  dp2 = lis(v);
  reverse(dp2.begin(),dp2.end());
  
  int ans = 0;
  for(int i=0;i<v.size();i++)
    ans = max(ans,min(dp1[i],dp2[i])*2+1);
  cout << ans << endl;
}


int main(){
  while(read()) work();
  return 0;
}
