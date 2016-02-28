#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<cfloat>
#include<climits>

#define PI acos(-1.0)
#define MAX_KINGDOM 25
#define MAX_NODE 105

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
  Segment(Point b, Point e): begin(b), end(e){}
  
  double length(){
    return sqrt( (begin.x-end.x)*(begin.x-end.x) + 
		 (begin.y-end.y)*(begin.y-end.y) );
  }
  
  double calcDegree(Point p){
    double a,b,c;
    
    if( (begin.x==p.x && begin.y==p.y) ||
	(begin.x==p.x && begin.y==p.y) ) return 2*PI;
    
    a = length();
    b = Segment(begin,p).length();
    c = Segment(end,p).length();

    return acos( (a*a+b*b-c*c)/(2*a*b) );
  }
  
};

int nKingdom=0;
vector<Point> pList[MAX_KINGDOM];
vector<Point> missile;

void read(){
  
  while(true){
    int nPoint;
    cin >> nPoint;

    if(nPoint==-1) break;
    
    for(int i=0;i<nPoint;i++){
      Point toPush;

      cin >> toPush.x >> toPush.y;
      pList[nKingdom].push_back(toPush);
    }
    
    nKingdom++;
  }
  
  while(true){
    
    Point toPush;
    if(!(cin >> toPush.x >> toPush.y)) break;
    

    missile.push_back(toPush);
  }
  
}

void findConvex(int id, vector<Point> convex[MAX_KINGDOM]){
  
  Point firstP = pList[id][0];
  int first=0;
  bool used[MAX_NODE];
  
  for(int i=0;i<pList[id].size();i++)
    used[i] = false;

  for(int i=0;i<pList[id].size();i++)
    if(firstP.x>pList[id][i].x){
      firstP = pList[id][i];
      first = i;
    }
    else if(firstP.x==pList[id][i].x && firstP.y<pList[id][i].y){
      firstP = pList[id][i];
      first = i;
    }
      
  used[first] = true;
  convex[id].push_back(firstP);

  
  double minDegree;
  Segment base=Segment(firstP,Point(firstP.x,firstP.y+1));

  while(true){
    
    int minNode;
    minDegree=2*PI;
        
    for(int i=0;i<pList[id].size();i++){
      if(minDegree>base.calcDegree(pList[id][i])){
	minNode = i;
	minDegree = base.calcDegree(pList[id][i]);
      }
    }
    
    if(used[minNode]) break;
    used[minNode] = true;
    
    convex[id].push_back(pList[id][minNode]);
    
    base = Segment(pList[id][minNode], Point( pList[id][minNode].x*2-base.begin.x,
					      pList[id][minNode].y*2-base.begin.y) );
    
  }

}

double calcArea(vector<Point> area){
  double sum=0;
  
  for(int i=0;i<area.size();i++)
    sum += (area[i].x-area[(i+1)%area.size()].x)
           *(area[i].y+area[(i+1)%area.size()].y);
  
  return fabs(sum)/2;
}

bool contain(vector<Point> area, Point p){
  
  for(int i=0;i<area.size();i++){
    Segment seg = Segment(area[i],area[(i+1)%area.size()]);
    
    if( (seg.end.x-seg.begin.x)*(p.y-seg.begin.y) -
	(p.x-seg.begin.x)*(seg.end.y-seg.begin.y) >0 ) return false;
  }
  
  return true;
}

void work(){
  
  double ans=0;
  vector<Point> convex[MAX_KINGDOM];
  
  for(int i=0;i<nKingdom;i++)
    findConvex(i,convex);
  
  for(int i=0;i<nKingdom;i++){
    for(int j=0;j<missile.size();j++){
      if(contain(convex[i],missile[j])){
	ans+=calcArea(convex[i]);
	break;
      }
    }
  }
  
  printf("%.2lf\n",ans);
}

int main(){
  
  read();
  work();
  
  return 0;
}
