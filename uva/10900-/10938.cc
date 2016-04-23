#include<iostream>
#include<vector>
#include<algorithm>
#define BUF 5005
#define QUERY 505
using namespace std;

int nNode, nQuery, query[QUERY][2];
vector<int> adj[BUF];

bool read(){
  cin >> nNode;
  if(nNode==0) return false;

  for(int i=0;i<nNode;i++)
    adj[i].clear();
  
  for(int i=0;i<nNode-1;i++){
    int s, t; 
    cin >> s >> t; 
    s--, t--;

    adj[s].push_back(t);
    adj[t].push_back(s);
  }
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i][0] >> query[i][1];
    query[i][0]--, query[i][1]--;
  }
  
  return true;
}

void dfs(int curr, int pre, int parent[BUF]){
  parent[curr] = pre;

  for(int i=0;i<adj[curr].size();i++)
    if(adj[curr][i]!=pre)
      dfs(adj[curr][i],curr,parent);
}

void go(int curr, int cost[BUF], int parent[BUF], 
	vector<int> &seq, vector<int> &opp){
  seq.push_back(curr);

  if(parent[curr]!=-1){
    if(cost[parent[curr]]!=-1){
      seq.push_back(parent[curr]);
      int distance = cost[parent[curr]]+cost[curr]+1;
      
      if(distance%2==0){
	int meet;
	if(distance/2<seq.size())
	  meet = seq[distance/2];
	else
	  meet = opp[distance/2];

	cout << "The fleas meet at " << meet+1 << "." << endl;
      }
      else {
	int a, b;
	if(distance/2<seq.size()){
	  a = seq[distance/2];
	  b = (seq.size()-1==distance/2 ? opp[distance/2] : seq[distance/2+1]);
	}
	else{
	  a = opp[distance/2];
	  b = (opp.size()-1==distance/2 ? seq[distance/2] : opp[distance/2+1]);
	}
	
	if(a>b) swap(a,b);

	cout << "The fleas jump forever between " 
	     << a+1 << " and " << b+1 << "." << endl;
      }
    }
    else{
      cost[parent[curr]] = cost[curr]+1;
      go(parent[curr],cost,parent,seq,opp);
    }
  }
}

void work(){
  int parent[BUF];

  dfs(0,-1,parent);

  for(int i=0;i<nQuery;i++){
    if(query[i][0]==query[i][1]){
      cout << "The fleas meet at " << query[i][0]+1 << "." << endl;
      continue;
    }

    int cost[BUF];
    vector<int> seq1, seq2;

    for(int j=0;j<BUF;j++) cost[j] = -1;
    cost[query[i][0]] = cost[query[i][1]] = 0;
    
    go(query[i][0],cost,parent,seq1,seq2);
    go(query[i][1],cost,parent,seq2,seq1);
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
