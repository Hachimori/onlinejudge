#include<iostream>
#include<vector>
using namespace std;

string _a, _b;

void read(){
  int dummy;
  cin >> dummy >> _a >> _b;
}

int rec(string a, string b, vector< vector<int> > &tree, vector<char> &ch){
  int id = tree.size();
  tree.push_back(vector<int>());
  ch.push_back(a[0]);
  if(a.size()==1) return id;
  for(int cnt=0;;cnt++)
    if(a[0]==b[cnt]){
      if(cnt) tree[id].push_back(rec(a.substr(1,cnt),b.substr(0,cnt),tree,ch));
      if(cnt+1<a.size()) tree[id].push_back(rec(a.substr(cnt+1),b.substr(cnt+1),tree,ch));
      break;
    }
  return id;
}

void rec2(int cur, vector< vector<int> > &tree, vector<char> &ch){
  for(int i=0;i<tree[cur].size();i++)
    rec2(tree[cur][i],tree,ch);
  cout << ch[cur];
}

void work(){
  vector<char> ch;
  vector< vector<int> > tree;
  rec(_a,_b,tree,ch);
  rec2(0,tree,ch);
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
