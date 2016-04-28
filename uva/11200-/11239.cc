#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define MEMBER 100005
#define PROJECT 105
using namespace std;

int nProject;
string projectName[PROJECT];
vector<int> project[PROJECT];

bool read(){
  for(int i=0;i<PROJECT;i++) project[i].clear();

  map<string,int> n2i;

  nProject = -1;
  while(true){
    string s;
    getline(cin,s); 
    if(s[0]=='0') return false;
    if(s[0]=='1') break;

    for(int i=0;i<s.size();i++)
      if(isupper(s[i])){
        projectName[++nProject] = s;
        goto finish;
      }

    if(!n2i.count(s)){
      int sz = n2i.size();
      n2i[s] = sz;
    }
    
    project[nProject].push_back(n2i[s]);
  finish:;
  }
  
  nProject++;
  
  return true;
}

bool cmp(pair<int,string> a, pair<int,string> b){
  if(a.first!=b.first) return a.first>b.first;
  return a.second<b.second;
}

void work(){
  int mem2proj[MEMBER];
  set<int> proj2mem[PROJECT];

  for(int i=0;i<MEMBER;i++) mem2proj[i] = -1;
  
  for(int i=0;i<nProject;i++)
    for(int j=0;j<project[i].size();j++){
      int id = project[i][j];
      
      if(mem2proj[id]!=i && mem2proj[id]>=0){
        proj2mem[mem2proj[id]].erase(id);
        mem2proj[id] = -2;
      }
      else if(mem2proj[id]==-1){
        mem2proj[id] = i;
        proj2mem[i].insert(id);
      }
    }
  
  vector<pair<int,string> > ans;
  for(int i=0;i<nProject;i++)
    ans.push_back(make_pair(proj2mem[i].size(),projectName[i]));

  sort(ans.begin(),ans.end(),cmp);

  for(int i=0;i<ans.size();i++)
    cout << ans[i].second << ' ' << ans[i].first << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
