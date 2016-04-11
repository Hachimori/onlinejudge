#include<iostream>
#include<algorithm>
#include<cfloat>

#define EPS FLT_EPSILON
#define MAX_SIZE 505
#define GE(x,y) ((x)-(y)>-EPS)

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y){}
};

class Segment{
public:

  Point begin, end;
  
  Segment(){}
  Segment(Point b, Point e): begin(b), end(e) {}
};

double side(Segment a, Point p){
  
  double x1, x2, y1, y2;
  
  x1 = a.end.x - a.begin.x;
  x2 = p.x - a.begin.x;
  y1 = a.end.y - a.begin.y;
  y2 = p.y - a.begin.y;
  
  return x1*y2-x2*y1;
}

bool isIntersect(Segment a, Segment b){
  
  if( min(a.begin.x,a.end.x) > max(b.begin.x,b.end.x)) return false;
  if( min(a.begin.y,a.end.y) > max(b.begin.y,b.end.y)) return false;
  if( min(b.begin.x,b.end.x) > max(a.begin.x,a.end.x)) return false;
  if( min(b.begin.y,b.end.y) > max(a.begin.y,a.end.y)) return false;
  
  return ( GE(0,side(a,b.begin)*side(a,b.end)) && GE(0,side(b,a.begin)*side(b,a.end)));

}

int nWall;
Point init;
Segment sList[MAX_SIZE];

bool read(){
  
  cin >> nWall;
  if(nWall==0) return false;
  
  for(int i=0;i<nWall;i++)
    cin >> sList[i].begin.x >> sList[i].begin.y 
	>> sList[i].end.x >> sList[i].end.y;
  
  cin >> init.x >> init.y;
  
  return true;

}

void work(){
  
  int ans = -1;
  
  for(int i=0;i<nWall;i++){
    
    Point shootPoint = Point(1000*(sList[i].begin.x-init.x)+init.x,1000*(sList[i].begin.y-init.y)+init.y);
    Segment shoot = Segment(init,shootPoint);
    
    int cnt = 0;
    for(int j=0;j<nWall;j++)
      if(isIntersect(shoot,sList[j]))
	 cnt++;
    
    if(ans<cnt) ans = cnt;

    shootPoint = Point(1000*(sList[i].end.x-init.x)+init.x,1000*(sList[i].end.y-init.y)+init.y);
    shoot = Segment(init,shootPoint);

    cnt = 0;
    for(int j=0;j<nWall;j++)
      if(isIntersect(shoot,sList[j]))
	cnt++;
    
    
    if(ans<cnt) ans = cnt;
    
  }

  cout << ans << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
