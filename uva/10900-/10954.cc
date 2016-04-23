#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int BUF = 5005;

int main(){
  int n;
  while(cin >> n,n){
    priority_queue<long long,vector<long long>,greater<long long> > Q;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      Q.push(v);
    }
    long long ans = 0;;
    while(Q.size()>=2){
      long long a = Q.top(); Q.pop();
      long long b = Q.top(); Q.pop();
      ans += a+b;
      Q.push(a+b);
    }
    cout << ans << endl;
  }
  return 0;
}
