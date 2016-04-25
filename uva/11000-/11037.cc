// geometry
// 
// 
// 方針としては、３つの円をそれぞれ同じ比率で拡大してゆき、
// ３つの円の交差点が等しい点を見つけて出力する。
// 
// 拡大比率は２分法で決める。３つの円の半径のうち小さい２円に注目して、
// ・３つの円が重なっていなければ、比率を大きくする
// ・注目した２つの円が一方の円を包んでいれば、比率を小さくする
// ・注目した２つの円の交差点をもう一方の円が包んでいれば、比率を小さくする
//
// 半径の小さい２つの円に注目しなくてはならないのは、半径の大きい２つの円を
// 拡大した結果、２つの円の交差点がもう一方の円を通り過ぎていくことを防ぐためである。
// 半径の小さい２つの円に注目すれば、　２つの円の拡大速度≧もう一方の円の拡大速度　
// となるので上記のケースは発生しない。
//
// 厳しいEQUALと甘いEQUALを使い分ける必要がある。
// 厳しいEQUAL: ２分法のleftとright
// 甘いEQUAL:   ２つの円の交差点からの距離ともう１つの円の半径

#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cstdio>
#define EPS (1.0e-8)
#define INF (1.0e+8)
#define LEFT (1.0e-6)
#define RIGHT (1.0e+6)
#define CONTAIN 0
#define SEPARATE 1
#define JOIN 2
#define SEQ(x,y) (fabs((x)-(y))<EPS)    // 厳しいEQUAL
#define WEQ(x,y) (fabs((x)-(y))<1.0e-6) // 甘いEQUAL
#define  LT(x,y) ((x)<=(y)-EPS)
using namespace std;

typedef complex<double> Point;

class Circle{
public:
  Point p;
  double r;

  Circle(){}
  Circle(Point p, double r): p(p), r(r){}
  
  bool operator< (const Circle &c) const {
    return r<c.r;
  }
};

Circle cir[3];

bool read(){
  for(int i=0;i<3;i++){
    double x, y;
    cin >> x >> y >> cir[i].r;
    cir[i].p = Point(x,y);
  }
  
  if(cir[0].r==0) return false;
  
  return true;
}

int isIntersect(Circle c1, Circle c2){
  double d = abs(c1.p-c2.p);
  
  if(LT(c1.r+c2.r,d))
    return SEPARATE;

  if(LT(c1.r+d,c2.r) || LT(c2.r+d,c1.r))
    return CONTAIN;
  
  return JOIN;
}

vector<Point> calcIntersect(Circle c1, Circle c2){
  double d = abs(c1.p-c2.p);
  vector<Point> ret;
  
  double angle = acos( (c2.r*c2.r-c1.r*c1.r-d*d)/(-2*c1.r*d) );

  ret.push_back((c2.p-c1.p)*polar(c1.r/d, angle)+c1.p);
  ret.push_back((c2.p-c1.p)*polar(c1.r/d,-angle)+c1.p);
  
  return ret;
}

Point check(){
  for(int i=0;i<3;i++)
    if(isIntersect(cir[i],cir[(i+1)%3])!=JOIN)
      return Point(INF,INF);

  vector<Point> pt = calcIntersect(cir[0],cir[1]);
  if(abs(cir[2].p-pt[0])>abs(cir[2].p-pt[1])) swap(pt[0],pt[1]);
  
  return (WEQ(abs(pt[0]-cir[2].p),cir[2].r) ?  pt[0] : Point(INF,INF));
}

Point bisect(double l, double r, double ratio){
  double mid = (l+r)/2;

  for(int i=0;i<3;i++) cir[i].r *= mid/ratio;
  ratio = mid;

  if(SEQ(l,r)) return check();
  
  switch(isIntersect(cir[0],cir[1])){
  case CONTAIN:
    return bisect(l,mid,ratio);
  case SEPARATE:
    return bisect(mid,r,ratio);
  case JOIN:
    vector<Point> pt = calcIntersect(cir[0],cir[1]);
    
    if(abs(cir[2].p-pt[0])>abs(cir[2].p-pt[1])) swap(pt[0],pt[1]);
    
    if(abs(pt[0]-cir[2].p)<cir[2].r)
      return bisect(l,mid,ratio);
    else
      return bisect(mid,r,ratio);
  }
}

void work(){
  sort(cir,cir+3);
  
  Point ans = bisect(LEFT,RIGHT,1);

  if(ans!=Point(INF,INF))
    printf("%.2lf %.2lf\n",ans.real(),ans.imag());
  else
    cout << "No solution" << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
