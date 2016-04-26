#include<iostream>
#include<complex>
#include<cstdio>
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define AP 0
#define BP 1
#define CP 2
using namespace std;
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

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

Point pt[3];

void read(){
  for(int i=0;i<3;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }
}

void work(){
  Segment BD, CD;
  BD = Segment(pt[BP],pt[BP]+polar(1.0,arg((pt[AP]-pt[BP])/(pt[CP]-pt[BP]))/3+arg(pt[CP]-pt[BP])));
  CD = Segment(pt[CP],pt[CP]+polar(1.0,arg((pt[AP]-pt[CP])/(pt[BP]-pt[CP]))/3+arg(pt[BP]-pt[CP])));
  
  Point DP = calcIntersect(BD,CD);

  
  Segment CE, AE;
  CE = Segment(pt[CP],pt[CP]+polar(1.0,arg((pt[BP]-pt[CP])/(pt[AP]-pt[CP]))/3+arg(pt[AP]-pt[CP])));
  AE = Segment(pt[AP],pt[AP]+polar(1.0,arg((pt[BP]-pt[AP])/(pt[CP]-pt[AP]))/3+arg(pt[CP]-pt[AP])));

  Point EP = calcIntersect(CE,AE);
  

  Segment AF, BF;
  AF = Segment(pt[AP],pt[AP]+polar(1.0,arg((pt[CP]-pt[AP])/(pt[BP]-pt[AP]))/3+arg(pt[BP]-pt[AP])));
  BF = Segment(pt[BP],pt[BP]+polar(1.0,arg((pt[CP]-pt[BP])/(pt[AP]-pt[BP]))/3+arg(pt[AP]-pt[BP])));

  Point FP = calcIntersect(AF,BF);


  printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",
	 DP.real(),DP.imag(),
	 EP.real(),EP.imag(),
	 FP.real(),FP.imag());
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
