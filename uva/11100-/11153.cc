// ä»ó™âªÇÃà◊ÅA nNode Çâ∆ÇÃèÍèäÇ∆Ç∑ÇÈ

#include<iostream>
#include<queue>
#include<algorithm>
#define NODE 14
#define WAIT 15
#define BUF ((1<<13)+5)
#define INF 10000000
using namespace std;

class Data{
public:
  int p, s;
  
  Data(){}
  Data(int p, int s): p(p), s(s){}
};

int money, limit, nNode, adj[NODE][NODE];
int fee[NODE], val[NODE];

void read(){
  int nEdge;
  cin >> money >> limit >> nNode >> nEdge;
  
  for(int i=0;i<nNode+1;i++){
    for(int j=0;j<nNode+1;j++)
      adj[i][j] = INF;
    adj[i][i] = 0;
  }

  for(int i=0;i<nNode;i++)
    cin >> fee[i] >> val[i];

  for(int i=0;i<nEdge;i++){
    int src, dst, c;
    cin >> src >> dst >> c;
    src--, dst--;
    if(src<0) src = nNode;
    if(dst<0) dst = nNode;
    adj[src][dst] = min(adj[src][dst],c);
    adj[dst][src] = min(adj[dst][src],c);
  }
}

void warshall(){
  int tmp[NODE][NODE];

  for(int i=0;i<nNode+1;i++)
    for(int j=0;j<nNode+1;j++)
      tmp[i][j] = adj[i][j];
  
  for(int k=0;k<nNode+1;k++)
    for(int i=0;i<nNode+1;i++)
      for(int j=0;j<nNode+1;j++)
	tmp[i][j] = min(tmp[i][j],tmp[i][k]+tmp[k][j]);

  for(int i=0;i<nNode+1;i++)
    for(int j=0;j<nNode+1;j++)
      adj[i][j] = tmp[i][j];
}

void bfs(int tcost[][BUF], int mcost[][BUF], int sumV[][BUF]){
  queue<Data> Q;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<(1<<nNode);j++)
      tcost[i][j] = INF;

  tcost[nNode][0] = mcost[nNode][0] = sumV[nNode][0];
  Q.push(Data(nNode,0));

  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();

    for(int i=0;i<nNode;i++){
      Data next = Data(i,curr.s|(1<<i));
      
      if(tcost[i][next.s]>tcost[curr.p][curr.s]+adj[curr.p][i]+WAIT){
	if(tcost[i][next.s]==INF)
	  Q.push(next);
	tcost[i][next.s] = tcost[curr.p][curr.s]+adj[curr.p][i]+WAIT;
	mcost[i][next.s] = mcost[curr.p][curr.s]+fee[i];
	sumV[i][next.s] = sumV[curr.p][curr.s]+val[i];
      }
    }
  }
}

void work(int cases){
  warshall();

  static int tcost[NODE][BUF], mcost[NODE][BUF], sumV[NODE][BUF];
  bfs(tcost,mcost,sumV);
  
  int maxV = -INF;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<(1<<nNode);j++)
      if(tcost[i][j]+adj[i][nNode]<=limit && mcost[i][j]<=money)
	maxV = max(maxV,sumV[i][j]);

  cout << "Case " << cases << ": ";
  if(maxV==-INF) cout << "No possible trip." << endl;
  else cout << maxV << endl;
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
