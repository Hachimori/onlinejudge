#include<iostream>
#include<vector>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int n;
    cin >> n;
    if(n<=1){
      cout << n << endl;
      continue;
    }
    vector<int> v;
    for(int i=9;i>=2;i--)
      while(n%i==0){
        n /= i;
        v.push_back(i);
      }
    if(n>1)
      cout << -1 << endl;
    else{
      for(int i=v.size()-1;i>=0;i--)
        cout << v[i];
      cout << endl;
    }
  }
  return 0;
}
