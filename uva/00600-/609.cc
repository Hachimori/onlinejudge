// geometry (cut polygon)
// 
//
// 凸多角形を直線でカットする。
// 高速化のために O(2^n) のメモライゼーションを行った。
//
// また、前原さんのライブラリを大いに参考にさせてもらった。
// http://www.prefield.com/algorithm/geometry/convex_cut.html

#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<queue>
#include<cstdio>
#define CUT 10
#define BUF ((1<<8)+5)
#define EPS (1.0e-7)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define INF 2000000000
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;

typedef complex<double> Point;
typedef vector<Point> Polygon;

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

int nCut;
Polygon init;
Segment cut[CUT];

void read(){
  double x, y;
  cin >> x >> y;

  init.clear();
  init.push_back(Point(0,0));
  init.push_back(Point(0,y));
  init.push_back(Point(x,y));
  init.push_back(Point(x,0));
  
  Polygon poly;
  cin >> nCut;
  for(int i=0;i<nCut;i++){
    cin >> x >> y;
    poly.push_back(Point(x,y));
  }

  for(int i=0;i<nCut;i++)
    cut[i] = Segment(poly[i],poly[(i+1)%nCut]);
}

double dot(Point a, Point b){
  return real(conj(a)*b);
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;    
  if(LT(norm(d1),norm(d2))) return 2;
  return 0;                          
}

Point calcIntersect(Segment a, Segment b){
  Point d1, d2;
  d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

double cutPolygon(Segment &l, Polygon &p){
  int n = p.size();
  Polygon next;
  vector<Point> cutP;
  
  for(int i=0;i<n;i++){
    if(ccw(l.bgn,l.end,p[i])!=1)
      next.push_back(p[i]);
    if(ccw(l.bgn,l.end,p[i])*ccw(l.bgn,l.end,p[(i+1)%n])==-1)
      next.push_back(calcIntersect(l,Segment(p[i],p[(i+1)%n])));
    
    if(!EQ(cross(l.bgn-l.end,p[i]-p[(i+1)%n]),0) &&
       ccw(l.bgn,l.end,p[i])*ccw(l.bgn,l.end,p[(i+1)%n])<=0)
      cutP.push_back(calcIntersect(l,Segment(p[i],p[(i+1)%n])));
  } 
  
  p = next;
  
  return (cutP.size()==2 ? abs(cutP[0]-cutP[1]) : 0);
}

double bfs(){
  double cost[BUF];
  Polygon state[BUF];
  queue<int> Q;
  
  fill(cost,cost+BUF,INF);
  
  for(int i=0;i<nCut;i++){
    Polygon poly = init;
    
    Q.push(1<<i);
    cost[1<<i] = cutPolygon(cut[i],poly);
    state[1<<i] = poly;
  }

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    for(int i=0;i<nCut;i++){
      int next = curr|(1<<i);
      if(curr==next) continue;
      
      Polygon poly = state[curr];
      double toAdd = cutPolygon(cut[i],poly);

      if(cost[next]>cost[curr]+toAdd){
	state[next] = poly;
	cost[next] = cost[curr]+toAdd;
	Q.push(next);
      }
    }
  }
  
  return cost[(1<<nCut)-1];
}

void work(){;
  printf("Minimum total length = %.3lf\n",bfs());
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
