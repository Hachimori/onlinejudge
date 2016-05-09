#include<iostream>
#include<complex>
#include<cmath>
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

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
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}


Point A, B, C;

void read(){
  for(int i=0;i<3;i++){
    double x, y;
    cin >> x >> y;
    if(i==0) A = Point(x,y);
    if(i==1) B = Point(x,y);
    if(i==2) C = Point(x,y);
  }
}


void work(){
  Point D = B-(B-C)/3.0;
  Point E = C-(C-A)/3.0;
  Point F = A-(A-B)/3.0;
  Segment AD = Segment(A,D);
  Segment CF = Segment(C,F);
  Segment BE = Segment(B,E);
  
  Point P = calcIntersect(AD,BE);
  Point Q = calcIntersect(BE,CF);
  Point R = calcIntersect(AD,CF);

  cout << (int)(fabs(cross(P-Q,R-Q)*0.5)+0.5) << endl;
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
