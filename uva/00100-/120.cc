#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#define NUM 35
using namespace std;

int n, init[NUM];

bool read(){
  n = 0;
  string s; if(getline(cin,s)==NULL) return false;

  stringstream in(s);
  while(in >> init[n]) n++;
  
  return true;
}

void work(){
  vector<int> ans;  
  int curr[NUM];

  for(int i=0;i<n;i++) curr[i] = init[i];
  
  for(int k=n-1;k>=1;k--){
    int pos = max_element(curr,curr+k+1)-curr;

    if(curr[k]==curr[pos]) continue;

    if(curr[0]!=curr[pos]){
      ans.push_back(pos+1);
      reverse(curr,curr+pos+1);
    }
    
    ans.push_back(k+1);
    reverse(curr,curr+k+1);
  }
  ans.push_back(n+1);

  for(int i=0;i<n;i++){
    if(i) cout << ' ';
    cout << init[i];
  }cout << endl;

  for(int i=0;i<ans.size();i++){
    if(i) cout << ' ';
    cout << n-ans[i]+1;
  }cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
