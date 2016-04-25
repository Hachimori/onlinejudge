#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define BUF 100
#define INF (1<<20)
using namespace std;

int nNode, adj[BUF][BUF], nQuery;
string query[BUF][3];
map<string,int> n2i;
map<int,string> i2n;

void read(){
  n2i.clear();
  i2n.clear();

  cin >> nNode;

  for(int i=0;i<nNode;i++){
    string toPush; cin >> toPush;
    
    int sz = n2i.size();
    n2i[toPush] = sz;
    i2n[sz] = toPush;
  }

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      int c; cin >> c;
      adj[i][j] = (c==-1 ? INF : c);
    }

  cin >> nQuery;

  for(int i=0;i<nQuery;i++)
    for(int j=0;j<3;j++) 
      cin >> query[i][j];
}

void warshall(int pi[BUF][BUF], int cost[BUF][BUF]){
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      cost[i][j] = adj[i][j];
      if(adj[i][j]!=INF)
	pi[i][j] = i;
      else
	pi[i][j] = -1;
    }

  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	if(cost[i][j]>cost[i][k]+cost[k][j]){
	  cost[i][j] = cost[i][k]+cost[k][j];
	  pi[i][j] = pi[k][j];
	}
}

void work(){
  int pi[BUF][BUF], cost[BUF][BUF];

  warshall(pi,cost);
  

  for(int i=0;i<nQuery;i++){
    if(!n2i.count(query[i][1]) || !n2i.count(query[i][2])){
      cout << "Sorry Mr " << query[i][0] << " you can not go from " 
	   << query[i][1] << " to " << query[i][2] << endl;
      continue;
    }
    
    int s = n2i[query[i][1]], t = n2i[query[i][2]];

    if(cost[s][t]==INF){
      cout << "Sorry Mr " << query[i][0] << " you can not go from " 
	   << query[i][1] << " to " << query[i][2] << endl;
      continue;
    }

    cout << "Mr " << query[i][0] << " to go from " 
	 << query[i][1] << " to " << query[i][2] << ", you will receive "
	 << cost[s][t] << " euros" << endl;
    
    vector<int> path;
    for(int cur=t;cur!=-1;cur=pi[s][cur]){
      path.push_back(cur);
      if(cur==s && path.size()!=1) break;
    }
    reverse(path.begin(),path.end());

    
    cout << "Path:";
    for(int i=0;i<path.size();i++){
      if(i) cout << ' ';
      cout << i2n[path[i]];
    }
    cout << endl;
  }
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
