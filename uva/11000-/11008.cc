#include<iostream>
#include<algorithm>
#include<complex>
#include<queue>
#include<cassert>
#define NODE 30
#define BUF ((1<<16)+5)
#define INF 100000000
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
typedef complex<int> Point;

class Line{
public:
  Point bgn, end;

  Line(){}
  Line(Point b, Point e): bgn(b), end(e){}
};

int cross(Point a, Point b){
  return imag(conj(a)*b);
}

bool isOnline(Line line, Point pt){
  return cross(line.end-line.bgn,pt-line.bgn)==0;
}

int nNode, nCut;
Point node[NODE];
vector<int> adj[NODE][NODE];   // adj[a][b]: a ‚©‚ç b ‚Ö’¼ü‚ðˆø‚¢‚½‚Æ‚«‚É’Ê‚é“_

void read(){
  cin >> nNode >> nCut;

  for(int i=0;i<nNode;i++){
    int x, y;
    cin >> x >> y;
    node[i] = Point(x,y);
  }
}

int cntBit(int mask){
  int cnt = 0;
  for(;mask>0;mask>>=1)
    cnt += mask&1;
  return cnt;
}

int bfs(){
  static int cost[BUF];
  queue<int> Q;

  fill(cost,cost+(1<<nNode),INF);
  cost[0] = 0;
  Q.push(0);

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    int t = cntBit(curr);
    if(t>=nCut) return cost[curr];
    if(t==nCut-1 && nCut==nNode){ 
      cost[(1<<nNode)-1] = min(cost[(1<<nNode)-1],cost[curr]+1);
      Q.push((1<<nNode)-1);
      continue;
    }
    
    for(int i=0;i<nNode;i++){
      if(curr&(1<<i)) continue;
      for(int j=i+1;j<nNode;j++){
	if(curr&(1<<j)) continue;
	
	int next = curr;
	for(vector<int>::iterator k=adj[i][j].begin();k!=adj[i][j].end();k++)
	  next |= (1<<*k);
	
	if(cost[next]>cost[curr]+1){
	  cost[next] = cost[curr]+1;
	  Q.push(next);
	}
      }
    }
  }
  
  assert(false);
}

void work(int cases){
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      adj[i][j] = adj[j][i] = vector<int>();
  
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++){
      Line line = Line(node[i],node[j]);
      
      for(int k=0;k<nNode;k++)
	if(isOnline(line,node[k]))
	  adj[i][j].push_back(k);
      adj[j][i] = adj[i][j];
    }
  
  cout << "Case #" << cases << ":" << endl << bfs() << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work(i+1);
  }
  
  return 0;
}
