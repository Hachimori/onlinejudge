#include<iostream>
#include<complex>
#define EPS (1e-8)
using namespace std;
typedef complex<double> Point;

string toPrint;
double minX, maxX, minY, maxY, dx, dy;

void read(){
  cin >> toPrint >> minY >> maxY >> dy >> minX >> maxX >> dx;
  toPrint = toPrint.substr(1,12)+' ';
}

int get(Point toAdd){
  int cnt = 0;
  Point cur(0,0);
  while(cnt<=12 && abs(cur)<=2+EPS){
    cur = cur*cur+toAdd;
    cnt++;
  }
  return cnt-1;
}

void work(){
  for(double y=minY;y<=maxY+EPS;y+=dy){
    for(double x=minX;x<=maxX+EPS;x+=dx){
      cout << toPrint[get(Point(x,y))];
    }
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
