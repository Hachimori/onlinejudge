#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int NODE = 35;

class Node{
public:
  int id;
  vector<int> v;
  
  Node(){}
  Node(int id, vector<int> v): id(id), v(v){}

  bool isUpon(Node n){
    for(int i=0;i<v.size();i++)
      if(v[i]>=n.v[i])
        return false;
    return true;
  }

  bool operator< (const Node &n) const {
    return v<n.v;
  }
};

int nNode;
Node node[NODE];

bool read(){
  int dim;
  if(!(cin >> nNode >> dim)) return false;
  
  for(int i=0;i<nNode;i++){
    vector<int> v;
    for(int j=0;j<dim;j++){
      int vv;
      cin >> vv;
      v.push_back(vv);
    }
    sort(v.begin(),v.end());
    node[i] = Node(i+1,v);
  }
  sort(node,node+nNode);
  node[nNode] = Node(nNode,vector<int>(dim,1<<30));
  return true;
}

int rec(int curr, int dp[NODE], int nex[NODE]){
  if(dp[curr]!=-1) return dp[curr];

  dp[curr] = 1;
  nex[curr] = -1;
  for(int i=0;i<curr;i++)
    if(node[i].isUpon(node[curr]) && dp[curr]<rec(i,dp,nex)+1){
      dp[curr] = rec(i,dp,nex)+1;
      nex[curr] = i;
    }
  
  return dp[curr];
}

void work(){
  int dp[NODE], nex[NODE];
  memset(dp,-1,sizeof(dp));
  rec(nNode,dp,nex);

  vector<int> ans;
  for(int i=nNode;i!=-1;i=nex[i])
    ans.push_back(node[i].id);
  
  cout << ans.size()-1 << endl;
  for(int i=ans.size()-1;i>0;i--){
    if(i!=ans.size()-1) cout << ' ';
    cout << ans[i];
  }cout << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
