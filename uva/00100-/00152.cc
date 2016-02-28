#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<climits>

#define MAX_SIZE 5005

using namespace std;

class Point{
public:

  double x,y,z;

  Point(){}
  Point(double x, double y, double z): x(x), y(y), z(z){}
  
  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z) );
  }

};

int nPoint;
Point pList[MAX_SIZE];

void read(){
  
  double x,y,z;
  
  nPoint=0;
  
  while(true){
    cin >> x >> y >> z;
    if(x==0 && y==0 && z==0) break;

    pList[nPoint] = Point(x,y,z);

    nPoint++;
  }
  
}

void work(){
  
  int cnt[10];

  for(int i=0;i<10;i++)
    cnt[i]=0;

  for(int i=0;i<nPoint;i++){

    double minDis = INT_MAX;

    for(int j=0;j<nPoint;j++){
      if(i==j) continue;
      minDis = min(minDis,pList[i].distance(pList[j]));
    }

    if(minDis<1)
      cnt[0]++;
    else if(1<=minDis && minDis<2)
      cnt[1]++;
    else if(2<=minDis && minDis<3)
      cnt[2]++;
    else if(3<=minDis && minDis<4)
      cnt[3]++;
    else if(4<=minDis && minDis<5)
      cnt[4]++;
    else if(5<=minDis && minDis<6)
      cnt[5]++;
    else if(6<=minDis && minDis<7)
	cnt[6]++;
    else if(7<=minDis && minDis<8)
      cnt[7]++;
    else if(8<=minDis && minDis<9)
      cnt[8]++;
    else if(9<=minDis && minDis<10)
      cnt[9]++;
      
  }
 
  for(int i=0;i<10;i++)
    printf("%4d",cnt[i]);
  cout << endl;
  
}

int main(){
  
  read();
  work();

  return 0;
}
