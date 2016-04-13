#include<iostream>
#include<numeric>
using namespace std;
const int BUF = 1005, INF = 1<<20;

int n, v[BUF];

bool read(){
  cin >> n;
  if(n==0) return false;
  for(int i=0;i<n;i++) cin >> v[i];
  return true;
}

void work(){
  if(accumulate(v,v+n,0)==0)
    cout << 0 << endl;
  else{
    bool fst = true;
    for(int i=0;i<n;i++){
      if(!v[i]) continue;
      if(fst){
        fst = false;
        cout << v[i];
        continue;
      }
      cout << ' ' << v[i];
    }
    cout << endl;
  }
}

int main(){
  while(read()) work();
  return 0;
}
