#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
#include<algorithm>

#define RADIUS 2.5
#define MAX_SIZE 205

using namespace std;

class Point{
public:

  double x, y;

  Point(){}
  Point(double x, double y): x(x), y(y){}

  double calcDis(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }

};

int nPoint;
Point pList[MAX_SIZE];

void read(){

  nPoint=0;

  while(true){

    string str;
    getline(cin,str);

    if(str.length()==0) break;

    sscanf(str.c_str(),"%lf%lf",&pList[nPoint].x,&pList[nPoint].y);
    
    nPoint++;
  }

}

void work(){
  /*
  for(int i=0;i<nPoint;i++)
    cout << pList[i].x << ' ' << pList[i].y << endl;
  cout << endl;
  */

  int nMax=1;
  
  for(int i=0;i<nPoint;i++){
    for(int j=i+1;j<nPoint;j++){
      
      if(pList[i].calcDis(pList[j])>2*RADIUS+0.00001) continue;
      //cout << i << ' ' << j << endl;
      Point p1=pList[i], p2=pList[j];

      double a = 1+((p2.x-p1.x)/(p1.y-p2.y))*((p2.x-p1.x)/(p1.y-p2.y));
      double b = (-2)*(p2.x+p2.y*(p2.x-p1.x)/(p1.y-p2.y));
      double c = p2.x*p2.x+p2.y*p2.y-RADIUS*RADIUS;

      b=(-2)*(p2.x+p2.y*((p2.x-p1.x)/(p1.y-p2.y))-((p2.x-p1.x)/(p1.y-p2.y))*
	       ( ( p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y)) )  ;
      
      c+=(-2)*p2.y*(p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y)  ;
      c+=( ( p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y)  ) *
	( ( p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y)  )  ;
		   
      
      Point center;
      
      center.x = (-b+sqrt(b*b-4*a*c))/(2*a);
      center.y = center.x*(p2.x-p1.x)/(p1.y-p2.y)
	+( p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y);
      
      
      int cnt=0;
      for(int k=0;k<nPoint;k++)
	if(center.calcDis(pList[k])<=RADIUS+0.000001)
	  cnt++;

      nMax = max(nMax,cnt);


      center.x = (-b-sqrt(b*b-4*a*c))/(2*a);
      center.y = center.x*(p2.x-p1.x)/(p1.y-p2.y)
	+( p1.x*p1.x+p1.y*p1.y-(p2.x*p2.x+p2.y*p2.y))/(2*p1.y-2*p2.y);

      

      cnt=0;
      for(int k=0;k<nPoint;k++)
	if(center.calcDis(pList[k])<=RADIUS+0.000001)
	  cnt++;

      nMax = max(nMax,cnt);      

    }
  }

  cout << nMax << endl;
  
}

int main(){

  string str;
  int cases;

  cin >> cases; getline(cin,str); getline(cin,str);

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
