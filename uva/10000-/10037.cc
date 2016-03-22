#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
const int BUF = 1005;


int nMan, val[BUF];

void read(){
  cin >> nMan;
  for(int i=0;i<nMan;i++) cin >> val[i];
}

void gen(int &sum, vector<pair<int,int> > &ans){
  for(int loop=0;loop<nMan/2-1;loop++){
    int a = val[0], b = val[1], A = val[nMan-2-loop*2], B = val[nMan-1-loop*2];
    if(a*2+A+B<a+b*2+B){
      ans.push_back(make_pair(a,A));
      ans.push_back(make_pair(a,-1));
      ans.push_back(make_pair(a,B));
      ans.push_back(make_pair(a,-1));
      sum += a*2+A+B;
    }
    else{
      ans.push_back(make_pair(a,b));
      ans.push_back(make_pair(a,-1));
      ans.push_back(make_pair(A,B));
      ans.push_back(make_pair(b,-1));
      sum += a+b*2+B;
    }
  }
  if(nMan%2==1){
    int a = val[0], b = val[1], A = val[2];
    ans.push_back(make_pair(a,b));
    ans.push_back(make_pair(a,-1));
    ans.push_back(make_pair(a,A));
    sum += a+b+A;
  }
  else{
    ans.push_back(make_pair(val[0],val[1]));
    sum += val[1];
  }
}


void work(){
  if(nMan==0){
    cout << 0 << endl;
    return;
  }
  if(nMan==1){
    cout << val[0] << endl;
    cout << val[0] << endl;
    return;
  }

  sort(val,val+nMan);

  
  int sum = 0;
  vector< pair<int,int> > ans;
  gen(sum,ans);

  cout << sum << endl;
  for(int i=0;i<ans.size();i++){
    cout << ans[i].first;
    if(ans[i].second!=-1)
      cout << ' ' << ans[i].second;
    cout << endl;
  }
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
