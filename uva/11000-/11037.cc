// geometry
// 
// 
// $BJ}?K$H$7$F$O!"#3$D$N1_$r$=$l$>$lF1$8HfN($G3HBg$7$F$f$-!"(B
// $B#3$D$N1_$N8r:9E@$,Ey$7$$E@$r8+$D$1$F=PNO$9$k!#(B
// 
// $B3HBgHfN($O#2J,K!$G7h$a$k!##3$D$N1_$NH>7B$N$&$A>.$5$$#21_$KCmL\$7$F!"(B
// $B!&#3$D$N1_$,=E$J$C$F$$$J$1$l$P!"HfN($rBg$-$/$9$k(B
// $B!&CmL\$7$?#2$D$N1_$,0lJ}$N1_$rJq$s$G$$$l$P!"HfN($r>.$5$/$9$k(B
// $B!&CmL\$7$?#2$D$N1_$N8r:9E@$r$b$&0lJ}$N1_$,Jq$s$G$$$l$P!"HfN($r>.$5$/$9$k(B
//
// $BH>7B$N>.$5$$#2$D$N1_$KCmL\$7$J$/$F$O$J$i$J$$$N$O!"H>7B$NBg$-$$#2$D$N1_$r(B
// $B3HBg$7$?7k2L!"#2$D$N1_$N8r:9E@$,$b$&0lJ}$N1_$rDL$j2a$.$F$$$/$3$H$rKI$0$?$a$G$"$k!#(B
// $BH>7B$N>.$5$$#2$D$N1_$KCmL\$9$l$P!"!!#2$D$N1_$N3HBgB.EY!f$b$&0lJ}$N1_$N3HBgB.EY!!(B
// $B$H$J$k$N$G>e5-$N%1!<%9$OH/@8$7$J$$!#(B
//
// $B87$7$$(BEQUAL$B$H4E$$(BEQUAL$B$r;H$$J,$1$kI,MW$,$"$k!#(B
// $B87$7$$(BEQUAL: $B#2J,K!$N(Bleft$B$H(Bright
// $B4E$$(BEQUAL:   $B#2$D$N1_$N8r:9E@$+$i$N5wN%$H$b$&#1$D$N1_$NH>7B(B

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
#define SEQ(x,y) (fabs((x)-(y))<EPS)    // $B87$7$$(BEQUAL
#define WEQ(x,y) (fabs((x)-(y))<1.0e-6) // $B4E$$(BEQUAL
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
