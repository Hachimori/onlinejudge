#include<iostream>
#include<complex>
#include<cmath>
#define BUF 1005
#define EPS (1.0e-9)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

class Circle{
public:
  Point p;
  double r;

  Circle(){}
  Circle(Point p, double r): p(p), r(r){}

  double area(){
    return r*r*PI;
  }

  bool contain(const Point &pp){
    return LT(abs(p-pp),r);
  }
};

int nCircle;
Circle circle[BUF];

bool read(){
  cin >> nCircle;
  if(nCircle==0) return false;
  
  for(int i=0;i<nCircle;i++){
    double x, y, r;
    cin >> x >> y >> r;
    circle[i] = Circle(Point(x,y),r);
  }
  
  return true;
}

void work(){
  for(int i=1;i<nCircle;i++){
    double sumArea = circle[i].area();
    Point sumPt = circle[i].p*circle[i].area();
    
    bool ok = true;
    for(int j=i-1;j>=0;j--){
      if(!circle[j].contain(sumPt/sumArea)){
	ok = false;
	break;
      }
      
      sumArea += circle[j].area();
      sumPt += circle[j].p*circle[j].area();
    }

    if(!ok){
      cout << "Unfeasible " << i << endl;
      return;
    }
  }
  
  cout << "Feasible" << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
