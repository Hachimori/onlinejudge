#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 128
using namespace std;

vector<int> adj[BUF];

void read(){
  for(int i=0;i<BUF;i++) adj[i].clear();

  int dummy, nEdge;
  cin >> dummy >> dummy >> nEdge;

  for(int i=0;i<nEdge;i++){
    char s, t, ch;
    cin >> s >> ch >> t;
    adj[s].push_back(t);
  }
}

void dfs(int curr, int init, bool visited[BUF], vector<int> &toPush, vector<vector<int> > &seq){
  toPush.push_back(curr);
  visited[curr] = true;

  for(int i=0;i<adj[curr].size();i++){
    int next = adj[curr][i];
    if(next==init){
      toPush.push_back(next);
      seq.push_back(toPush);
      toPush.pop_back();
      continue;
    }
    if(visited[next]) continue;
    dfs(next,init,visited,toPush,seq);
  }
    
  toPush.pop_back();
  visited[curr] = false;
}

vector<int> clean(vector<int> v){
  vector< vector<int> > elem;
  
  v.pop_back();
  for(int i=0;i<v.size();i+=2){
    vector<int> toPush;
    for(int j=0,k=i;j<v.size();j++,k=(k+1)%v.size())
      toPush.push_back(v[k]);
    elem.push_back(toPush);
  }

  vector<int> ret = *min_element(elem.begin(),elem.end());
  ret.push_back(ret[0]);
  return ret;
}

bool mycmp(vector<int> a, vector<int> b){
  if(a.size()!=b.size()) return a.size()<b.size();
  return a<b;
}

void work(){
  vector< vector<int> > seq;
  
  for(int i='A';i<='Z';i++){
    vector<int> toPush;
    bool visited[BUF];
    for(int j=0;j<BUF;j++) visited[j] = false;
    
    dfs(i,i,visited,toPush,seq);
  }
  
  vector< vector<int> > ans;
  for(int i=0;i<seq.size();i++)
    ans.push_back(clean(seq[i]));
  
  sort(ans.begin(),ans.end(),mycmp);
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  
  if(ans.size()==0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for(int i=0;i<ans.size();i++){
      for(int j=0;j<ans[i].size();j++){
        if(j) cout << '-';
        cout << (char)ans[i][j];
      }cout << endl;
    }
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
