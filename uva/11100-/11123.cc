#include<iostream>
#include<complex>
#include<algorithm>
#define POINT 205
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define x first
#define y second
using namespace std;
typedef pair<int,int> Point;


class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e){
    if(e<b) swap(b,e);
    bgn = b;
    end = e;
  }

  bool operator< (const Segment &s) const {
    //Point d = end-bgn, dd = s.end-s.bgn;
    //if( d.real()<0)  d = bgn-end;
    //if(dd.real()<0) dd = s.bgn-s.end;

    // return (d.imag()/d.real()<dd.imag()/dd.real())

    return 1LL*(end.y-bgn.y)*(s.end.x-s.bgn.x) <
           1LL*(s.end.y-s.bgn.y)*(end.x-bgn.x);
  }
};


long long dot(Point a, Point b){
  return 1LL*a.x*b.x+1LL*a.y*b.y;
}

long long cross(Point a, Point b){
  return 1LL*a.x*b.y-1LL*a.y*b.x;
}

int ccw(Point a, Point b, Point c){
  Point d1 = Point(b.x-a.x,b.y-a.y), d2 = Point(c.x-a.x,c.y-a.y);
  if(cross(d1,d2)>0) return 1;
  if(cross(d1,d2)<0) return -1;
  if(dot(d1,d2)<0) return -2;
  if(dot(d1,d1)<dot(d2,d2)) return 2;
  return 0;
}

bool isOnline(Segment s, Point p){
  return abs(ccw(s.bgn,s.end,p))!=1;
}

bool isParallel(Segment a, Segment b){
  return cross(Point(a.end.x-a.bgn.x,a.end.y-a.bgn.y),
	       Point(b.end.x-b.bgn.x,b.end.y-b.bgn.y))==0;
}

int nPt;
Point pt[POINT];

bool read(){
  cin >> nPt;
  if(nPt==0) return false;

  for(int i=0;i<nPt;i++){
    int valx, valy;
    cin >> valx >> valy;
    pt[i] = Point(valx,valy);
  }

  return true;
}

void work(int cases){
  int nSeg = 0;
  Segment seg[POINT*POINT];

  for(int i=0;i<nPt;i++)
    for(int j=i+1;j<nPt;j++)
      seg[nSeg++] = Segment(pt[i],pt[j]);

  sort(seg,seg+nSeg);
  
  int ans = 0;
  for(int i=0;i<nSeg;i++){
    int bgn, end;
    bgn = lower_bound(seg+i,seg+nSeg,seg[i])-seg;

    //Segment ss = seg[i]; ss.end.y++;

    end = upper_bound(seg+i,seg+nSeg,seg[i])-seg;
    
    for(int j=bgn;j<end;j++)
      for(int k=j+1;k<end;k++){
	Segment s1 = Segment(seg[j].bgn,seg[k].bgn);
	Segment s2 = Segment(seg[j].end,seg[k].end);
	if(!isParallel(s1,s2) && !isOnline(s1,s2.bgn)) ans++;
      }
    
    i = end-1;
  }

  cout << "Case " << cases << ": " << ans << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}