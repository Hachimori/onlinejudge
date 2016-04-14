#include<iostream>
#include<map>
#include<sstream>
#include<vector>
using namespace std;
const int BUF = 101;

int total;
vector<int> a, b;

bool read(){
  a = b = vector<int>();

  if(!(cin >> total)) return false;
  string dummy; 
  getline(cin,dummy);

  string s; 
  getline(cin,s);

  stringstream in(s);
  int num;
  while(in >> num) a.push_back(num);
  
  getline(cin,s);
  in.clear();
  in.str(s);
  while(in >> num) b.push_back(num);

  return true;
}

void work(){
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());

  map<int,pair<int,int> > M; // M[a[aIdx]+b[bIdx]]=(aIdx,bIdx);
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b.size();j++)
      if(!M.count(a[i]+b[j]))
        M[a[i]+b[j]] = make_pair(i,j);
  
  vector<int> ans(1,a.size());
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b.size();j++)
      if(M.count(total-a[i]-b[j])){
        int aIdx = M[total-a[i]-b[j]].first;
        int bIdx = M[total-a[i]-b[j]].second;
        if(aIdx==i || bIdx==j) continue;
        vector<int> toCmp;
        toCmp.push_back(min(i,aIdx));
        toCmp.push_back(min(j,bIdx));
        toCmp.push_back(max(i,aIdx));
        toCmp.push_back(max(j,bIdx));        
        if(ans>toCmp) ans = toCmp;
      }

  if(ans==vector<int>(1,a.size()))
    cout << "no solution" << endl;
  else{
    for(int i=0;i<4;i++){
      if(i) cout << ' ';
      cout << (i%2==0 ? a[ans[i]] : b[ans[i]]);
    }
    cout << endl;
  }
}

int main(){
  while(read()) work();
  return 0;
}
