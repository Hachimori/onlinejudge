#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

bool read(){
  return cin >> n;
}

void work(){
  int limit = 1;
  for(int i=0;i<n/2;i++) limit *= 10;
  
  vector<int> ans;
  for(int x=limit/10;x<limit;x++)
    for(int y=x;y<limit;y++){
      if(((x&1) && (y&1)) || (x%10==0 && y%10==0)) continue;
      int cnt[10]={0};
      for(int v=x;v;v/=10) cnt[v%10]++;
      for(int v=y;v;v/=10) cnt[v%10]++;
      for(int v=x*y;v;v/=10) cnt[v%10]--;
      for(int i=0;i<10;i++)
        if(cnt[i])
          goto _fail;
      ans.push_back(x*y);
    _fail:;
    }

  sort(ans.begin(),ans.end());
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  for(int i=0;i<ans.size();i++)
    cout << ans[i] << endl;
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
