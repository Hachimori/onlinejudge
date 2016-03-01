#include<iostream>
#include<map>
using namespace std;
const int QUERY = 10000, BUF = 100, INF = 1<<28;

int nNode, adj[BUF][BUF], nQuery, query[QUERY][3];

void read(){
  memset(adj,0,sizeof(adj));
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      adj[i][j] = INF;

  int nEdge;
  cin >> nNode >> nEdge >> nQuery;

  map<string,int> s2i;
  for(int i=0;i<nNode;i++){
    string s;
    cin >> s;
    s2i[s] = i;
  }

  for(int i=0;i<nEdge;i++){
    string s, t;
    cin >> s >> t;
    adj[s2i[s]][s2i[t]] = adj[s2i[t]][s2i[s]] = 1;
  }

  for(int i=0;i<nQuery;i++){
    int cost;
    string s, t;
    cin >> cost >> s >> t;
    query[i][0] = cost;
    query[i][1] = s2i[s];
    query[i][2] = s2i[t];
  }
}


void work(int cases){
  cout << endl;
  cout << "DATA SET  " << cases << endl;
  cout << endl;
  
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);

  for(int loop=0;loop<nQuery;loop++){
    int s = query[loop][1], t = query[loop][2];
    if(adj[s][t]==INF)
      cout << "NO SHIPMENT POSSIBLE" << endl;
    else
      cout << '$' << adj[s][t]*query[loop][0]*100 << endl;
  }
}


int main(){
  cout << "SHIPPING ROUTES OUTPUT" << endl;
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  cout << endl;
  cout << "END OF OUTPUT" << endl;
  return 0;
}
