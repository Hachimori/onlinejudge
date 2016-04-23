#include<iostream>
#include<cfloat>
#include<cassert>
#include<cmath>

#define MAX_SIZE 100000 
#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)-(y)<=-EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))

using namespace std;

class Point{
public:
  double x,y;

  Point(){}
  Point(double x, double y): x(x) ,y(y){}
};

double height, width, h, v;
int nQuery;
Point query[MAX_SIZE];

bool read(){
  cin  >> width >> height >> h >> v ;
  if(EQ(height,0.0) && EQ(width,0.0) && EQ(v,0.0) && EQ(h,0.0))
    return false;
  
  cin >> nQuery;

  for(int i=0;i<nQuery;i++)
    cin >> query[i].x >> query[i].y;
  
  return true;
}

bool rec(Point ll, Point ru, Point goal, bool isBlack){
 
  double dx = (ru.x-ll.x)*h;
  double dy = (ru.y-ll.y)*v;
  //cout << dx << ' ' << dy << endl;
  if(LE(ll.x,goal.x) && LE(goal.x,ll.x+dx) && 
     LE(ll.y+dy,goal.y) && LE(goal.y,ru.y) ) return isBlack;

  if(LE(ll.x+dx,goal.x) && LE(goal.x,ru.x) && 
     LE(ll.y,goal.y) && LE(goal.y,ll.y+dy) ) return isBlack;
  
  if(LE(ll.x,goal.x) && LE(goal.x,ll.x+dx) && 
     LE(ll.y,goal.y) && LE(goal.y,ll.y+dy) )
    return rec(ll,Point(ll.x+dx,ll.y+dy),goal,!isBlack);
  
  if(LE(ll.x+dx,goal.x) && LE(goal.x,ru.x) && 
     LE(ll.y+dy,goal.y) && LE(goal.y,ru.y) )
    return rec(Point(ll.x+dx,ll.y+dy),ru,goal,!isBlack);

  assert(false);
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;
  
  /*
  for(int i=0;i<nQuery;i++)
    cout << query[i].x << ' ' << query[i].y << endl;
  cout << endl;
  */
  
  for(int i=0;i<nQuery;i++){
    if(rec(Point(0,0),Point(width,height),query[i],true)) 
      cout << "black" << endl;
    else
      cout << "white" << endl;
  }

}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
