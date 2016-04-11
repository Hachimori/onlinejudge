// ad-hoc
//
// すべての点はcenter of symmetry (CSP) を中心に対象移動した点を持つと仮定する。
// そうすると、最小のxの中の最小のyをもつ点をCSPを中心に対象移動したとき
// 　　　　　　最大のxの中の最大のyをもつ点になるはずである。
//
// こうして、CSPを仮に決定して、全点がCSPを中心に対象移動した点を持つかどうかを判定する。
//
//
// すべての点は格子点上に存在していることから、
// CSPを中心に対象移動した点が、格子点上に無いとき no と出力しなくてはならない。

#include<iostream>
#include<algorithm>
#include<cfloat>

#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define MAX_SIZE 10005

using namespace std;

class Point{
public:
  int x, y;

  Point(){}
  Point(int x, int y): x(x), y(y){}

  bool operator< ( const Point &p ) const {
    if(x==p.x) return y<p.y;
    return x<p.x;
  }
};

int nPoint;
Point point[MAX_SIZE];

void read(){
  cin >> nPoint;
  
  for(int i=0;i<nPoint;i++)
    cin >> point[i].x >> point[i].y;
}

void work(){
  double centerX, centerY;
  
  sort(point,point+nPoint);
  
  centerX = (point[0].x+point[nPoint-1].x)/2;
  centerY = (point[0].y+point[nPoint-1].y)/2;
  
  for(int i=0;i<nPoint;i++){
    double doubleX = (point[i].x + 2*(centerX-point[i].x));
    double doubleY = (point[i].y + 2*(centerY-point[i].y));
    
    int intX, intY;
    
    if(doubleX<0)
      intX = (int)(doubleX-0.5);
    else
      intX = (int)(doubleX+0.5);

    if(doubleY<0)
      intY = (int)(doubleY-0.5);
    else
      intY = (int)(doubleY+0.5);
    

    
    if( !EQ(intX,doubleX) || !EQ(intY,doubleY) ){ 
      cout << "no" << endl;
      return;
    }

    if(!binary_search(point,point+nPoint,Point(intX,intY))){
      cout << "no" << endl;
      return;
    }
  }

  cout << "yes" << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
    
  return 0;
}
