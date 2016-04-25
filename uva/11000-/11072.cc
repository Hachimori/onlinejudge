// geometry
//
// 
// 点Pが多角形の中にあるかどうかの判定はO(log n)のアルゴリズムを使用している。
// 
// まず、多角形の内側に任意の点Cをとり、Cから多角形を作る点へ向かって直線を引く。
// 二つの直線は角度をもつので、直線と直線の間を角度を持ったエリアとして考える。
// エリアの開始角度を、一番最初の直線とエリアの片方の直線のなす角度と定義する。 
// 
// 点Pはこれらのエリアのうちいずれかに含まれる。どのエリアに含まれるかは
// 点Cからの角度を求めて,それをもとにbinary searchを使えばO(log n)でわかる。
// 
// 点Cから多角形へ向かって引いた直線二つと多角形の持つ辺は三角形を作っている。
// 点Pがその三角形に含まれていれば、点Pは多角形に含まれると判断できる。
//
// このアルゴリズムは凸多角形のみ有効である。
//
//
// 参考:
// http://www.acm.org/pubs/tog/editors/erich/ptinpoly/
// http://gis.esri.com/library/userconf/proc01/professional/papers/pap388/p388.htm

#include<iostream>
#include<algorithm>
#include<vector>
#include<complex>
#include<cstdio>
#define EPS (1.0e-12)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
#define GT(x,y) ((x)>=(y)+EPS)
#define GE(x,y) (EQ(x,y) || GT(x,y))
#define POINT 100005
const double PI = acos(-1.0);
using namespace std;
typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

int nPoint, nQuery;
Point pt[POINT], query[POINT*5];

bool read(){
  if(scanf("%d",&nPoint)==EOF) return false;
  
  for(int i=0;i<nPoint;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    pt[i] = Point(x,y);
  }
  
  scanf("%d",&nQuery);
  
  for(int i=0;i<nQuery;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    query[i] = Point(x,y);
  }
  
  return true;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);

  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

bool cmp(const Point &a, const Point &b){
  if(a.real()==b.real()) return a.imag()<b.imag();
  return a.real()<b.real();
}

void pushPt(int &nPolyPt, Point ret[], bool low){
  int bgn = (low ? 0 : nPoint-1);
  int end = (low ? nPoint : -1);
  int d = (low ? 1 : -1);
  
  ret[nPolyPt++] = pt[bgn];
  int m = nPolyPt;
  
  for(int i=bgn+d;i!=end;i+=d){
    for(int k;(k=nPolyPt)>m && 
	  ccw(ret[k-2],ret[k-1],pt[i])<=0;) 
      nPolyPt--;
    ret[nPolyPt++] = pt[i];
  }
  nPolyPt--;
}

void calcConvex(int &nPolyPt, Point ret[]){
  sort(pt,pt+nPoint,cmp);
  pushPt(nPolyPt,ret,true);
  pushPt(nPolyPt,ret,false);
}

bool onSegment(Segment s, Point p){
  return LE(abs(p-s.bgn)+abs(s.end-p),abs(s.end-s.bgn));
} 

bool insideTri(Point a, Point b, Point c, Point p){
  int s1 = ccw(a,b,p), s2 = ccw(b,c,p), s3 = ccw(c,a,p);

  return ( (s1>=0 && s2>=0 && s3>=0) || (s1<=0 && s2<=0 && s3<=0) );
}

int isInside(int n, Point poly[], double angle[], Point inP, Point pt){
  double ret = arg((pt-inP)/(poly[0]-inP));
  double theta = (ret>0 ? ret : ret+2*PI);
  
  int idx = upper_bound(angle,angle+n,theta)-angle-1;
  
  Point a = inP, b = poly[idx], c = poly[(idx+1)%n];

  if(onSegment(Segment(b,c),pt)) return 0;
  
  return (insideTri(a,b,c,pt) ? 1 : -1); 
}

void work(){
  int nPolyPt = 0;
  Point poly[POINT];
  
  calcConvex(nPolyPt,poly);
  
  static double angle[POINT];
  Point inP = (poly[0]+poly[1]+poly[2])/3.0;
  
  for(int i=0;i<nPolyPt;i++){
    double theta = arg((poly[i]-inP)/(poly[0]-inP));
    angle[i] = (GE(theta,0) ? theta : theta+2*PI);
  }
  
  for(int i=0;i<nQuery;i++)
    if(isInside(nPolyPt,poly,angle,inP,query[i])==-1)
      printf("outside\n");
    else
      printf("inside\n");
}

int main(){
  while(read())
    work();

  return 0;
}
