// uva 659
// raytracing
//
// 
//
// 2次方程式を解いて円と半直線の交点(X,Y)を求める。
// 半直線の発射地点をp, 進行方向をv, 円の座標をc, 半径をr とする。
// 
// cx + vx*t = X              ... 1
// cy + vy*t = Y              ... 2
// (X-px)^2 + (Y-py)^2 = r^2  ... 3
// 
// 1 と 2 を 3 に代入して、tに関する2次方程式を解く。
// 
// 
// 
// 半直線が円に当たった後のベクトルの向きを求める。
//
// 円と交わるときの角度をwとする。
// http://online-judge.uva.es/p/v6/659.html
// 新しいベクトルの向きは、元のベクトルをw*2だけ反時計回りに回転させたもの。

#include<iostream>
#include<complex>
#include<vector>
#define CIRCLE 30
#define EPS (1.0e-9)
#define INF (1<<20)
using namespace std;
typedef complex<double> Point;
const double PI = acos(-1.0);

class Circle{
public:
  Point p;
  double r;

  Circle(){}
  Circle(Point p, double r): p(p), r(r){}
};

int nCircle;
Circle c[CIRCLE];
Point init, initDir;

bool read(){
  cin >> nCircle;
  if(nCircle==0) return false;
  
  for(int i=0;i<nCircle;i++){
    double x, y, r;
    cin >> x >> y >> r;
    c[i] = Circle(Point(x,y),r);
  }
  
  double ix, iy, dx, dy;
  cin >> ix >> iy >> dx >> dy;

  init = Point(ix,iy);
  initDir = Point(dx,dy);
  
  return true;
}

// p: 現在地,  v: 発射方向, xp: 交差点
// 線分と違う扱いになっている事に注意
Point calcIntersect(Point p, Point v, Circle c){
  double A = norm(v);
  double B = 2*(v.real()*real(p-c.p) + v.imag()*imag(p-c.p));
  double C = norm(p-c.p)-c.r*c.r;
  
  // 交差しない
  if(B*B-4*A*C<0) return Point(-INF,-INF);

  double t = (-B-sqrt(B*B-4*A*C))/(2*A);
  
  // 交差点が、進行方向の逆側にあったり円周上にある
  if(t<EPS) return Point(-INF,-INF);
  return p+v*t;
}

// p と v の値を変えてしまうので注意
void reflect(Point &p, Point &v, Point xp, Circle c){
  Point h = xp-c.p;
  h = Point(h.imag(),-h.real());

  v = v*polar(1.0,2*arg(h/v));
  p = xp;
}

void work(int cases){
  vector<int> ans;
  Point cur = init, dir = initDir;
  
  for(int i=0;i<11;i++){
    int id = -1;
    double minV = INF;
    Point crossPt;
    
    for(int j=0;j<nCircle;j++){
      Point pt = calcIntersect(cur,dir,c[j]);
      
      if(minV>abs(pt-cur)){
        crossPt = pt;
        minV = abs(pt-cur);
        id = j;
      }
    }

    if(id==-1) break;
    
    reflect(cur,dir,crossPt,c[id]);
    
    ans.push_back(id);
  }

  cout << "Scene " << cases << endl;
  for(int i=0;i<min((int)ans.size(),10);i++)
    cout << ans[i]+1 << ' ';
  cout << (ans.size()==11 ? "..."  : "inf") << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
