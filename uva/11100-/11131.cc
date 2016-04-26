// —^‚¦‚ç‚ê‚½tree‚Ìpostorder•‹t‚Ìpostorder‚ğ•\¦B

#include<iostream>
#include<vector>
#include<string>
#include<map>
#define NODE 5005
using namespace std;

int nNode;
map<string,int> n2id;
map<int,string> id2n;
vector<int> adj[NODE];

vector<string> split(string &s){
  vector<string> ret;
  int cur = 0;
  
  while(cur<s.size()){
    string toPush;
    while(cur<s.size() && s[cur]!=',') toPush += s[cur++];
    while(cur<s.size() && s[cur]==',') cur++;
    
    ret.push_back(toPush);
  }

  return ret;
}

bool read(){
  n2id.clear();
  id2n.clear();
  for(int i=0;i<NODE;i++)
    adj[i].clear();
  
  for(int k=0;;k++){
    string str;
    if(getline(cin,str)==NULL || str.empty()){
      if(k==0) return false;
      else break;
    }
    
    vector<string> sList = split(str);
    
    for(int i=0;i<sList.size();i++){
      if(!n2id.count(sList[i])){
	int size = n2id.size();
	n2id[sList[i]] = size;
	id2n[size] = sList[i];
      }
    }

    for(int i=1;i<sList.size();i++)
      adj[n2id[sList[0]]].push_back(n2id[sList[i]]);
  }
  
  nNode = n2id.size();
  
  return true;
}

void dfs(int curr, vector<int> &ret, bool first){
  int bgn = (first ? 0 : (int)(adj[curr].size()-1));
  int end = (first ? (int)adj[curr].size() : -1);
  int toAdd = (first ? 1 : -1);
  
  for(int i=bgn;i!=end;i+=toAdd)
    dfs(adj[curr][i],ret,first);

  ret.push_back(curr);
}


void work(){
  vector< vector<int> > nList;
  nList.push_back(vector<int>());
  dfs(0,nList.back(),true);
  nList.push_back(vector<int>());
  dfs(0,nList.back(),false);

  if(nList[0]==nList[1]) nList.pop_back();
  
  cout << nList.size() << endl;
  for(int i=0;i<nList.size();i++){
    cout << endl;
    for(int j=0;j<nList[i].size();j++)
      cout << id2n[nList[i][j]] << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
