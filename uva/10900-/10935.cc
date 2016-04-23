#include<iostream>
#include<vector>
using namespace std;


int n;

bool read(){
  cin >> n;
  return n!=0;
}


void work(){
  vector<int> v;  // v.front() -> top,  v.back() -> bottom
  for(int i=0;i<n;i++) v.push_back(i); 

  vector<int> discarded;
  for(int i=0;i+1<n;i++){
    discarded.push_back(v.front());
    v.erase(v.begin());
    v.push_back(v.front());
    v.erase(v.begin());
  }

  cout << "Discarded cards:";
  for(int i=0;i<discarded.size();i++){
    if(i) cout << ",";
    cout << ' ' << discarded[i]+1;
  }
  cout << endl;

  cout << "Remaining card: " << v[0]+1 << endl;
}


int main(){
  while(read()) work();
  return 0;
}
