#include<iostream>
#include<vector>
using namespace std;
const int BUF = 5005, HASH = 10007;

class Hash{
public:
  vector< pair<int,int> > v[HASH]; // (val,cnt)

  void insert(int num){
    for(int i=0;i<v[num%HASH].size();i++)
      if(v[num%HASH][i].first==num){
        v[num%HASH][i].second++;
        return;
      }
    v[num%HASH].push_back(make_pair(num,1));
  }

  int get(int num){
    for(int i=0;i<v[num%HASH].size();i++)
      if(v[num%HASH][i].first==num)
        return v[num%HASH][i].second;
    return 0;
  }
};

int main(){
  int n, v[BUF];
  while(cin >> n){
    Hash h;
    for(int i=0;i<n;i++){
      cin >> v[i];
      h.insert(v[i]);
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        ans += h.get(v[i]+v[j]);
    cout << ans << endl;
  }
  return 0;
}
