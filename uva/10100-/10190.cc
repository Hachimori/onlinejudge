#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n, div;
  while(cin >> n >> div){
    vector<int> v;

    if(div<=1 || n<=1){
      cout << "Boring!" << endl;
      continue;
    }
    
    while(1){
      v.push_back(n);
      if(n==1) break;
      if(n%div!=0){
        v.clear();
        break;
      }
      n /= div;
    }

    if(v.empty())
      cout << "Boring!" << endl;
    else{
      for(int i=0;i<v.size();i++){
        if(i) cout << ' ';
        cout << v[i];
      }
      cout << endl;
    }
  }
  return 0;
}
