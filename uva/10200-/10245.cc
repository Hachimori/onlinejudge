#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

#define MAX_SIZE 10005
#define INF 40000

using namespace std;

class Point{
public:
  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y){}
  
  double distance(Point &p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
  
  bool operator< (const Point &p) const {
    if(x<p.x) return true;
    else if(x==p.x) return y<p.y;

    return false;
  }
  
};

int nPoint;
Point pList[MAX_SIZE];

bool read(){
  
  cin >> nPoint;
  if(nPoint==0) return false;
  
  for(int i=0;i<nPoint;i++)
    cin >> pList[i].x >> pList[i].y;
  
  return true;
}

void work(){
  
  sort(pList,pList+nPoint);
  
  bool succeed=false;
  double minDis = INF*INF;
  
  for(int i=0;i<nPoint;i++){
    for(int j=i+1;j<nPoint;j++){
    
      if(sqrt(minDis)<=pList[j].x-pList[i].x) break;
      
      if(minDis>(pList[i].x-pList[j].x)*(pList[i].x-pList[j].x) +
	        (pList[i].y-pList[j].y)*(pList[i].y-pList[j].y) ) {

	
	minDis = (pList[i].x-pList[j].x)*(pList[i].x-pList[j].x) +
         	  (pList[i].y-pList[j].y)*(pList[i].y-pList[j].y)  ;
	
	succeed = true;
      }
          
    }
  }
  
  if(sqrt(minDis)>=10000)
    printf("INFINITY\n");
  else
    printf("%.4lf\n",sqrt(minDis));
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
