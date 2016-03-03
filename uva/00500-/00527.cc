#include<iostream>
#include<complex>
#include<vector>
#include<cassert>
#define SEGMENT 15
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
using namespace std;
typedef complex<long double> Point;

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

long double cross(Point a, Point b){
  return imag(conj(a)*b);
}

long double dot(Point a, Point b){
  return real(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;     
  if(LT(norm(d1),norm(d2))) return 2;  
  return 0;                            
}

bool isIntersect(Segment a, Segment b){
  if(EQ(abs(a.bgn-b.bgn),0) || EQ(abs(a.bgn-b.end),0) ||
     EQ(abs(a.end-b.bgn),0) || EQ(abs(a.end-b.end),0) ) return false;
  
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isSame(Segment a, Segment b){
  return (EQ(cross(a.end-a.bgn,b.end-b.bgn),0) && 
	  ccw(a.bgn,a.end,b.bgn)==0);
}

vector<Segment> seg;

void read(){
  int nSeg;
  cin >> nSeg;
  
  seg.clear();
  
  for(int i=0;i<nSeg;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg.push_back(Segment(Point(x1,y1),Point(x2,y2)));
  }
  
  for(int i=0;i<seg.size();i++)
    for(int j=i+1;j<seg.size();j++){
      if(isSame(seg[i],seg[j])){
	seg.erase(seg.begin()+j);
	j--;
      }
    }

  for(int i=0;i<seg.size();i++)
    if(isSame(seg[i],Segment(Point(0,0),Point(1000,0))) ||
       isSame(seg[i],Segment(Point(1000,0),Point(1000,1000))) ||
       isSame(seg[i],Segment(Point(1000,1000),Point(0,1000))) ||
       isSame(seg[i],Segment(Point(0,1000),Point(0,0))) ){
      seg.erase(seg.begin()+i);
      i--;
    }

}

void work(){
  int ans = 0;
  
  for(int i=0;i<seg.size();i++){
    vector<Point> crossPt;
    for(int j=0;j<i;j++){
      if(isIntersect(seg[i],seg[j])){
	Point ret = calcIntersect(seg[i],seg[j]);

	bool same = false;
	for(int k=0;k<crossPt.size();k++)
	  if(EQ(abs(crossPt[k]-ret),0)){
	    same = true;
	    break;
	  }
	if(!same) crossPt.push_back(ret);
      }
    }

    ans += crossPt.size();
  }
  
  cout << ans+seg.size()+1 << endl;
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
