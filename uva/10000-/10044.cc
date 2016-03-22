#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<cctype>
#include<cassert>
using namespace std;
const int BUF = 4000;


int nPaper, nQuery;
vector<string> paper, query;

void read(){
  cin >> nPaper >> nQuery;
  paper = vector<string>(nPaper);
  query = vector<string>(nQuery);
  string dummy; getline(cin,dummy);
  for(int i=0;i<nPaper;i++) getline(cin,paper[i]);
  for(int i=0;i<nQuery;i++) getline(cin,query[i]);
}


void bfs(int init, vector<int> &cost, int nNode, vector<vector<int> > &adj){
  queue<int> Q;

  cost[init] = 0;
  Q.push(init);

  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();

    for(int i=0;i<adj[cur].size();i++){
      int nex = adj[cur][i];
     if(cost[nex]!=-1) continue;
      cost[nex] = cost[cur]+1;
      Q.push(nex);
    }
  }
}


void trim(string &s){
  int head = 0, back = s.size()-1;
  while(head<s.size() && isspace(s[head])) head++;
  while(back>=0 && isspace(s[back])) back--;
  if(head<=back)
    s = string(s.begin()+head,s.begin()+back+1);
  else
    s = "";
}


void work(int cases){
  vector< vector<string> > nameAdj;
  map<string,int> n2i;
  map<int,string> i2n;

  for(int i=0;i<nPaper;i++){
    vector<string> name;
    for(int j=0;;j++){
      string fst, scd;
      while(j<paper[i].size() && paper[i][j]!=':' && paper[i][j]!=',') fst += paper[i][j++];
      j++;
      while(j<paper[i].size() && paper[i][j]!=':' && paper[i][j]!=',') scd += paper[i][j++];
      j++;
      trim(fst);
      trim(scd);
      if(fst.empty() || scd.empty()) break;
      name.push_back(fst+", "+scd);
      if(j-1==paper[i].size() || paper[i][j-1]==':') break;
    }

    for(int j=0;j<name.size();j++)
      if(!n2i.count(name[j])){
        int sz = n2i.size();
        n2i[name[j]] = sz;
        i2n[sz] = name[j];
      }
    
    nameAdj.push_back(name);
  }

  vector< vector<int> > adj(n2i.size());
  for(int i=0;i<nameAdj.size();i++)
    for(int j=0;j<nameAdj[i].size();j++)
      for(int k=j+1;k<nameAdj[i].size();k++){
        adj[n2i[nameAdj[i][j]]].push_back(n2i[nameAdj[i][k]]);
        adj[n2i[nameAdj[i][k]]].push_back(n2i[nameAdj[i][j]]);
      }

  vector<int> cost(n2i.size(),-1);
  if(n2i.count("Erdos, P.")) bfs(n2i["Erdos, P."],cost,n2i.size(),adj);

  cout << "Scenario " << cases << endl;
  for(int i=0;i<nQuery;i++){
    string fst, scd;
    int j = 0;
    while(j<query[i].size() && query[i][j]!=',') fst += query[i][j++];
    j++;
    while(j<query[i].size() && query[i][j]!=',') scd += query[i][j++];
    j++;
    trim(fst);
    trim(scd);
    query[i] = fst+", "+scd;
    cout << query[i] << ' ';
    if(!n2i.count(query[i]) || cost[n2i[query[i]]]==-1)
      cout << "infinity" << endl;
    else
      cout << cost[n2i[query[i]]] << endl;
  }
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
