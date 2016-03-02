// 453
// Circle Intersection

#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cstdio>
#include<cassert>

#define EPS 1.0e-8
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)

using namespace std;

typedef complex<double> Point;

class Circle{
public:
  Point p;
  double r;

  Circle(){}
  Circle(Point p, double r): p(p), r(r){}
};

Circle c1, c2;

bool read(){
  double x, y, r;
  
  if(!( cin >> x >> y >> r)) return false;
  c1 = Circle(Point(x,y),r);
  
  if(!( cin >> x >> y >> r)) return false;
  c2 = Circle(Point(x,y),r);  
  
  return true;
}

bool isSame(Circle c1, Circle c2){
  return EQ(c1.p.real(),c2.p.real()) && 
         EQ(c1.p.imag(),c2.p.imag()) && 
         EQ(c1.r,c2.r);
}

bool isIntersect(Circle c1, Circle c2){
  double d = abs(c1.p-c2.p);
  
  if(LT(c1.r+c2.r,d) || LT(c1.r+d,c2.r) || LT(c2.r+d,c1.r))
    return false;
  
  return true;
}

vector<Point> calcIntersect(Circle c1, Circle c2){
  double d = abs(c1.p-c2.p);
  vector<Point> ret;
  
  double angle = acos( (c2.r*c2.r-c1.r*c1.r-d*d)/(-2*c1.r*d) );

  Point pRet = (c2.p-c1.p)*polar(c1.r/d,angle)+c1.p;
  ret.push_back(pRet);
  
  pRet = (c2.p-c1.p)*polar(c1.r/d,-angle)+c1.p;
  ret.push_back(pRet);
  
  return ret;
}

double out(double n){
  return fabs(n)<1.0e-4 ? 0 : n;
}

void work(){
  if( EQ(c1.r,0) && EQ(c2.r,0) && EQ(c1.p.real(),c2.p.real()) && EQ(c1.p.imag(),c2.p.imag()) ){
    printf("(%.3lf,%.3lf)\n", out(c1.p.real()), out(c1.p.imag()));
    return;
  }
	
  if(isSame(c1,c2)){
    printf("THE CIRCLES ARE THE SAME\n");
    return;  
  }
  
  if(!isIntersect(c1,c2)) {
    printf("NO INTERSECTION\n");
    return;  
  }
  
  
  if(LT(c1.r,c2.r)) swap(c1,c2);
  
  Point v = Point(c2.p-c1.p);
  Point M = c1.p + v*(c1.r/abs(c1.p-c2.p));
  
  double a=c1.r;
  double b=c2.r;
  double d=abs(c1.p-c2.p);
  
  if(EQ(a+b,d)||EQ(b+d,a)||EQ(d+a,b)){
    printf("(%.3lf,%.3lf)\n",out(M.real()),out(M.imag()));
    return;
  }
  
  
  vector<Point> pList = calcIntersect(c1,c2);
  
  if(GT(pList[0].real(),pList[1].real()) || 
     (EQ(pList[0].real(),pList[1].real()) && GT(pList[0].imag(),pList[1].imag())))
    swap(pList[0],pList[1]);
  
  for(int i=0;i<pList.size();i++)
    printf("(%.3lf,%.3lf)",out(pList[i].real()),out(pList[i].imag()));
  printf("\n");
}

int main(){
  while(read())
    work();
  
  return 0;
}
