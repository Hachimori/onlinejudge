#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    vector<int> ans;
    if(n<0)
      ans.push_back(-1);
    
    int v = abs(n);
    for(long long i=2;i*i<=v;i++)
      while(v%i==0){
        ans.push_back(i);
        v /= i;
      }
    if(v>1) ans.push_back(v);
    
    cout << n << " = ";
    for(int i=0;i<ans.size();i++){
      if(i)
        cout << " x ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
