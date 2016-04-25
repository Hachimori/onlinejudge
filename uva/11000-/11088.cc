#include<iostream>
#include<algorithm>
#include<set>
#define MAN 20
using namespace std;

class Data{
public:
  int sum, nMan;

  Data(){}
  Data(int s, int n): sum(s), nMan(n){}

  bool operator< (const Data &d) const {
    if(sum!=d.sum) return sum<d.sum;
    return nMan<d.nMan;
  }
};

class State{
public:
  multiset<Data> b;
  
  State(){}
  State(int n){
    for(int i=0;i<n;i++)
      b.insert(Data(0,0));
  }
  
  int delPush(Data data, int v){
    if(data.nMan==3) return -1;

    bool yes = data.sum<20;

    b.erase(b.find(data));
    
    data.sum += v, data.nMan++;
    if(data.sum>=20) data.sum = 20;
    
    b.insert(data);

    return (data.sum==20 && yes ? 1 : 0);
  }
  
  bool operator< (const State &s) const {
    return b<s.b;
  }
};

int nMan, val[MAN];

bool read(){
  cin >> nMan;
  if(nMan==0) return false;

  for(int i=0;i<nMan;i++)
    cin >> val[i];

  return true;
}

void rec(int idx, State curr, int cnt, set<State> &visited, int &ans){
  if(idx==nMan){
    ans = max(ans,cnt);
    return;
  }

  for(multiset<Data>::iterator i=curr.b.begin();i!=curr.b.end();i++){
    State next = curr;
    int ret = next.delPush(*i,val[idx]);
    if(ret==-1) continue;
    if(visited.count(next)) continue;
    visited.insert(next);
    rec(idx+1,next,cnt+ret,visited,ans);
  }
}

void work(int cases){
  set<State> visited;
  int ans = 0;
  
  sort(val,val+nMan);
  reverse(val,val+nMan);
  nMan -= nMan%3;
  
  rec(0,State(nMan/3),0,visited,ans);
  
  cout << "Case " << cases << ": " << ans << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
