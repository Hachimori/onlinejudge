#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
const int BUF = 505, INF = 1<<30;

int n, k, val[BUF];

void read(){
  cin >> n >> k;
  for(int i=0;i<n;i++) cin >> val[i];
}

int cntSlash(long long capacity, vector<int> &ans){
  if(*max_element(val,val+n)>capacity) return k+1;
  int cnt = 0;
  for(int i=n-1;i>=0;){
    long long sum = 0;
    while(i>=k-cnt-1 && val[i]+sum<=capacity)
      sum += val[i--];
    ans.push_back(i+1);
    cnt++;
  }
  reverse(ans.begin(),ans.end());
  return cnt;
}

void work(){
  long long L = 0, R = accumulate(val,val+n,0LL)+1;
  while(L<R){
    vector<int> dummy;
    long long mid = (L+R)/2;
    if(cntSlash(mid,dummy)<=k)
      R = mid;
    else
      L = mid+1;
  }

  vector<int> ans;
  cntSlash(L,ans);
  for(int i=0,aIdx=1;i<n;i++){
    if(i) cout << ' ';
    if(aIdx<ans.size() && ans[aIdx]==i){
      cout << "/ ";
      aIdx++;
    }
    cout << val[i];
  }cout << endl;
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
