#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector< pair<int,int> > factor;

bool read(){
  factor.clear();
  string s;
  getline(cin,s);
  if(s=="0") return false;

  stringstream in(s);
  int p, n;
  while(in >> p >> n) factor.push_back(make_pair(p,n));
  
  return true;
}


void work(){
  int val = 1;
  for(int i=0;i<factor.size();i++){
    pair<int,int> pn = factor[i];
    for(int j=0;j<pn.second;j++)
      val *= pn.first;
  }
  
  val--;

  vector< pair<int,int> > ans;
  for(int i=2;val>1;i++)
    if(val%i==0){
      int cnt = 0;
      while(val%i==0){
        val /= i;
        cnt++;
      }
      ans.push_back(make_pair(i,cnt));
    }

  for(int i=ans.size()-1;i>=0;i--){
    if(i!=ans.size()-1) cout << ' ';
    cout << ans[i].first << ' ' << ans[i].second;
  }
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
