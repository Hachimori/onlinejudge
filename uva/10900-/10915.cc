#include<iostream>
#include<numeric>
#include<cmath>
#define BUF 105
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
const double PI = acos(-1.0);
const double RADIUS = 40000/(PI*2);
using namespace std;

class Point{
public:
  double x, y, z;
  
  Point(){}
  Point(double x, double y, double z): x(x), y(y), z(z){}

  double dist(const Point &p){
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
  } 
};

int nTarget, nGun;
Point target[BUF], gun[BUF];

bool read(){
  cin >> nGun >> nTarget;
  if(nGun==0 && nTarget==0) return false;

  for(int i=0;i<nGun;i++){
    double x, y, z;
    cin >> x >> y >> z;
    gun[i] = Point(x,y,z);
  }
  
  for(int i=0;i<nTarget;i++){
    double x, y, z;
    cin >> x >> y >> z;
    target[i] = Point(x,y,z);
  }
  
  return true;
}

bool isHit(Point g, Point t){
  double OG = g.dist(Point(0,0,0)), TG = g.dist(t);
  double theta = acos((OG*OG-RADIUS*RADIUS-TG*TG)/(-2*RADIUS*TG));
  
  if(EQ(theta,PI) || EQ(theta,0)) return TG<OG;
  return theta>PI/2;
}

void work(){
  bool hit[BUF];

  for(int i=0;i<nTarget;i++)
    hit[i] = false;
  
  for(int i=0;i<nGun;i++)
    for(int j=0;j<nTarget;j++)
      if(isHit(gun[i],target[j]))
	hit[j] = true;
  
  cout << accumulate(hit,hit+nTarget,0) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
