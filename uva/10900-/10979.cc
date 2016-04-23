#include<iostream>
#include<complex>
#include<vector>
#define SEGMENT 15
#define POINT 100
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
using namespace std;
typedef complex<double> Point;

namespace std {
  bool operator< (const Point& a, const Point& b) {
    if(EQ(a.real(),b.real())) return LT(a.imag(),b.imag());
    return LT(a.real(),b.real());
  }
}

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

double dot(Point a, Point b){
  return real(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;

  // a,b,cは直線上に存在する
  if(LT(dot(d1,d2),0)) return -2;      // b - a - c
  if(LT(norm(d1),norm(d2))) return 2;  // a - b - c
  return 0;                            // a - c - b
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

bool onSegment(Segment a, Point p){
  return ccw(a.bgn,a.end,p)==0;
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

int nSeg;
vector<Segment> seg;

bool read(){
  if(!(cin >> nSeg)) return false;
  
  seg.clear();
  for(int i=0;i<nSeg;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg.push_back(Segment(Point(x1,y1),Point(x2,y2)));
  }
  
  return true;
}

bool canMerge(Segment a, Segment b){
  if(!isParallel(a,b)) return false;
  return onSegment(a,b.bgn) || onSegment(a,b.end) || 
         onSegment(b,a.bgn) || onSegment(b,a.end);
}

Segment merge(Segment a, Segment b){
  return Segment(min(min(a.bgn,a.end),min(b.bgn,b.end)),
		 max(max(a.bgn,a.end),max(b.bgn,b.end)));
}

void work(){
  vector<Point> crossPt;
  
  for(int i=0;i<seg.size();i++)
    for(int j=i+1;j<seg.size();j++){
      if(canMerge(seg[i],seg[j])){
	seg[i] = merge(seg[i],seg[j]);
	seg.erase(seg.begin()+j);
	j--;
      }
    }
  nSeg = seg.size();
  
  for(int i=0;i<nSeg;i++)
    for(int j=i+1;j<nSeg;j++)
      if(isIntersect(seg[i],seg[j]))
	crossPt.push_back(calcIntersect(seg[i],seg[j]));

  for(int i=0;i<crossPt.size();i++)
    for(int j=i+1;j<crossPt.size();j++)
      if(EQ(abs(crossPt[i]-crossPt[j]),0)){
	crossPt.erase(crossPt.begin()+j);
	j--;
      }


  int nPt = crossPt.size();
  bool adj[POINT][POINT];
  
  for(int i=0;i<nPt;i++)
    for(int j=0;j<nPt;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nSeg;i++){
    vector<int> ptId;
    for(int j=0;j<nPt;j++)
      if(onSegment(seg[i],crossPt[j]))
	ptId.push_back(j);
    
    for(int j=0;j<ptId.size();j++)
      for(int k=0;k<ptId.size();k++)
	adj[ptId[j]][ptId[k]] = true;
  }
  
  
  int cnt = 0;
  for(int i=0;i<nPt;i++)
    for(int j=i+1;j<nPt;j++){
      for(int k=j+1;k<nPt;k++){
	if(abs(ccw(crossPt[i],crossPt[j],crossPt[k]))!=1) continue;
	if(adj[i][j] && adj[j][k] && adj[k][i]) cnt++;
      }
    }
  
  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
