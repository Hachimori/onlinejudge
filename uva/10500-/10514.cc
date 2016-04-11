#include<iostream>
#include<vector>
#include<cmath>
#include<complex>
#include<cstdio>
#include<algorithm>
#define POLYGON 20
#define INF 2000000000
#define EPS (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;

double PI = acos(-1.0);

typedef complex<double> Point; 

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool onSegment(Segment s, Point p){
  return LE(abs(p-s.bgn)+abs(s.end-p),abs(s.end-s.bgn));
}

double calcDist(Segment s, Point p){
  Point pt = calcIntersect(s,Segment(p,p+rotate(s.end-s.bgn)));
  
  return onSegment(s,pt) ? abs(pt-p) : min(abs(s.bgn-p),abs(s.end-p));
}

int nPoly, nPt[POLYGON];
vector<Point> poly[POLYGON];

void read(){
  cin >> nPt[0] >> nPt[1] >> nPoly;
  
  nPoly += 2;
  
  for(int i=0;i<nPoly;i++)
    poly[i].clear();
  
  for(int i=0;i<nPoly;i++){
    if(i>=2) cin >> nPt[i];
    for(int j=0;j<nPt[i];j++){
      double x, y;
      cin >> x >> y;
      poly[i].push_back(Point(x,y));
    }
  }
}

void calcAdj(double adj[][POLYGON]){
  for(int i=0;i<nPoly;i++){
    adj[i][i] = 0;
    for(int j=i+1;j<nPoly;j++){
      int n = poly[i].size(), m = poly[j].size();
      double minV = INF;
      for(int k=0;k<(i<=1?n-1:n);k++)
	for(int l=0;l<m;l++)
	  minV = min(minV,calcDist(Segment(poly[i][k],poly[i][(k+1)%n]),poly[j][l]));

      for(int k=0;k<(j<=1?m-1:m);k++)
	for(int l=0;l<n;l++)
	  minV = min(minV,calcDist(Segment(poly[j][k],poly[j][(k+1)%m]),poly[i][l]));
      adj[i][j] = adj[j][i] = minV;
    }
  }
}

double dijkstra(double adj[][POLYGON]){
  double cost[POLYGON];
  bool visited[POLYGON];
  
  fill(cost,cost+nPoly,INF);
  fill(visited,visited+nPoly,false);
  
  cost[0] = 0;

  for(int k=0;k<nPoly;k++){
    int pos;
    double minV = INF;
    for(int i=0;i<nPoly;i++)
      if(minV>cost[i] && !visited[i]){
	pos = i;
	minV = cost[i]; 
      }

    if(EQ(minV,INF)) break;
    visited[pos] = true;
    
    for(int i=0;i<nPoly;i++)
      if(cost[i]>cost[pos]+adj[pos][i])
	cost[i] = cost[pos]+adj[pos][i];
  }
  
  return cost[1];
}

void work(){
  double adj[POLYGON][POLYGON];  
  calcAdj(adj);
  
  printf("%.3lf\n",dijkstra(adj));
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
