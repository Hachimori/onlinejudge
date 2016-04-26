#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#define BUF 105
#define EPS  (1.0e-8)
#define INF 10000000
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;

typedef complex<double> Point;
const double PI = acos(-1.0);

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);
  
  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool onSegment(Segment &s, Point &p){
  return LE(abs(s.bgn-p)+abs(p-s.end),abs(s.bgn-s.end));
}

double calcDist(Segment s, Point p){
  double theta = arg(s.end-s.bgn)+PI/2;
  Point pt = calcIntersect(s,Segment(p,p+polar(1.0,theta)));
  
  return onSegment(s,pt) ? abs(pt-p) : min(abs(s.bgn-p),abs(s.end-p));
}

int nNode, init, cycle, nPt[BUF];
Point poly[BUF][BUF];

void read(){
  cin >> nNode;
  
  for(int i=0;i<nNode;i++){
    cin >> nPt[i];
    for(int j=0;j<nPt[i];j++){
      double x, y;
      cin >> x >> y;
      poly[i][j] = Point(x,y);
    }
  }
  cin >> init >> cycle;
}

double calcArea(Point pt[], int nPt){
  double sum = 0;
  for(int i=0;i<nPt;i++)
    sum += (pt[i].real()-pt[(i+1)%nPt].real())*
           (pt[i].imag()+pt[(i+1)%nPt].imag());
  return fabs(sum)/2;
}

bool reachable(int a, int b){
  for(int i=0;i<nPt[a];i++)
    for(int j=0;j<nPt[b];j++)
      if(LT(calcDist(Segment(poly[a][i],poly[a][(i+1)%nPt[a]]),poly[b][j]),30))
	return true;
  
  return false;
}

void dijkstra(int adj[][BUF], int cost[]){
  bool visited[BUF];
  
  fill(visited,visited+nNode,false);
  fill(cost,cost+nNode,INF);
  cost[init] = 0;
  
  for(int k=0;k<nNode;k++){
    int pos, minV = INF;
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
	pos = i;
	minV = cost[i];
      }

    if(minV>=cycle) return;
    visited[pos] = true;
    for(int i=0;i<nNode;i++)
      if(cost[i]>cost[pos]+adj[pos][i] && (reachable(pos,i)||reachable(i,pos)))
	cost[i] = cost[pos]+adj[pos][i];
  }
}

void work(){
  double area[BUF];
  int adj[BUF][BUF], cost[BUF];
  
  for(int i=0;i<nNode;i++)
    area[i] = calcArea(poly[i],nPt[i]);

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = (i==j ? 0 : ceil(10*area[j]/area[i]));

  dijkstra(adj,cost);

  bool fst = true;
  for(int i=0;i<nNode;i++){
    if(cost[i]>cycle) continue;
    if(fst) fst = false;
    else cout << ' ';
    cout << i;
  }
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
