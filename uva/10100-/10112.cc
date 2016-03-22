#include<iostream>
#include<algorithm>
#include<cfloat>

#define MAX_SIZE 20

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  Point operator- ( Point p ){
    return Point(x-p.x,y-p.y);
  }

  double operator* ( Point p ){
    return x*p.y-y*p.x;
  }  

};

class Segment{
public:
  
  Point begin, end;

  Segment(){}
  Segment(Point b, Point e): begin(b), end(e) {}

};

double side(Segment a, Point b){
  
  double x1,x2,y1,y2;

  x1 = a.end.x-a.begin.x;
  x2 = b.x - a.begin.x;
  y1 = a.end.y - a.begin.y;
  y2 = b.y - a.begin.y;
  
  return x1*y2-x2*y1;
}

bool isIntersect(Segment a, Segment b){
  
  if( min(a.begin.x,a.end.x)>max(b.begin.x,b.end.x) ) return false;
  if( min(a.begin.y,a.end.y)>max(b.begin.y,b.end.y) ) return false;
  if( min(b.begin.x,b.end.x)>max(a.begin.x,a.end.x) ) return false;
  if( min(b.begin.y,b.end.y)>max(a.begin.y,a.end.y) ) return false;

  return ( 0>=side(a,b.begin)*side(a,b.end) && 0>=side(b,a.begin)*side(b,a.end) );

}

double crossProd(Point p1, Point p2){
  return p1.x*p2.y-p2.x*p1.y;
}

int nPoint;
Point pList[MAX_SIZE];
double maxArea;
char ans[3];

bool read(){

  cin >> nPoint;
  if(nPoint==0) return false;

  for(int i=0;i<nPoint;i++){
    char c;
    cin >> c >> pList[i].x >> pList[i].y;
  }

  return true;

}

void chose(int cursor, int nChose, int choseList[3], bool used[MAX_SIZE]){
  
  if(nChose==3){    

    for(int i=0;i<nPoint;i++){
      if(used[i]) continue;
      
      bool fail=true;

      
      for(int j=0;j<3;j++){
	if(0>(pList[choseList[(j+2)%3]]-pList[choseList[(j+1)%3]])*(pList[i]-pList[choseList[(j+1)%3]]) 
	   && 0<(pList[choseList[(j+1)%3]]-pList[choseList[j]])*(pList[i]-pList[choseList[j]]) ) fail=false;
	
	if(0<(pList[choseList[(j+2)%3]]-pList[choseList[(j+1)%3]])*(pList[i]-pList[choseList[(j+1)%3]]) 
	   && 0>(pList[choseList[(j+1)%3]]-pList[choseList[j]])*(pList[i]-pList[choseList[j]]) ) fail=false;
      }
      
      if(fail) return;      
    }
    
    if(maxArea<fabs( (pList[choseList[2]]-pList[choseList[0]])*(pList[choseList[1]]-pList[choseList[0]]) )/2){
      maxArea = fabs( (pList[choseList[2]]-pList[choseList[0]])*(pList[choseList[1]]-pList[choseList[0]]) )/2;
      ans[0] = choseList[0]+'A';
      ans[1] = choseList[1]+'A';
      ans[2] = choseList[2]+'A';	
    }
     
    return;
  }
  
  for(int i=cursor;i<nPoint;i++){
    
    choseList[nChose] = i;
    used[i] = true;

    chose(i+1,nChose+1,choseList,used);

    used[i] = false;
    
  }

}

void work(){
  
  int choseList[3];
  bool used[MAX_SIZE];

  for(int i=0;i<nPoint;i++)
    used[i] = false;
  
  maxArea=0;

  chose(0,0,choseList,used);
  
  cout << ans[0] << ans[1] << ans[2] << endl;

}

int main(){ 

  while(read())
    work();

  return 0;
}
