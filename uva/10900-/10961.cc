// $B2rK!(B:
// Giovanni$B$H(BLeporello$B$,C)$C$?F;$r@~J,$KCV$-49$($F!"8r:9E@$rD4$Y$k!#(B
// $BN><T$N%9%?!<%HE@$+$i8r:9E@$^$G$N5wN%$,Ey$7$1$l$P!"$=$3$G(B
// $B=P2q$&$b$N$H$9$k!#(B
//
// $B$3$NLdBj$N:GBg$NFq=j$O(B, Giovanni$B$H(BLeporello$B$,F1$8@~>e$rAv$k;~$K(B
// $B=P2q$&$+$I$&$+$rH=Dj$9$k$H$3$m!#(B
// 
// $BFs?M$,5U$NJ}8~$K8~$+$C$F$$$k>l9g!"Fs$D$N@~J,$N=E$J$C$F$$$kItJ,$r(B
// $B<h$j=P$7!"(BGiovanni$B$H(BLeporello$B$,$=$NItJ,$K$$$k;~4V$r5a$a$k!#(B
// $B$=$N;~4V$K=E$J$j$,$"$l$P!"(B2$B?M$O=P2q$&!#(B
//
// $BFs?M$,F1$8J}8~$K8~$+$C$F$$$k>l9g!"Fs$D$N@~J,$N=E$J$C$F$$$kItJ,$r(B
// $B<h$j=P$7!"(BGiovanni$B$H(BLeporello$B$,$=$NItJ,$K:G=i$KF~$k;~4V$r5a$a$k!#(B
// $B$=$N;~4V$,F1$8$J$i$P!"(B2$B?M$O=P2q$&!#(B

#include<iostream>
#include<complex>
#include<algorithm>
#define POINT 110
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;
typedef complex<double> Point;

namespace std {
  bool operator< (const Point& a, const Point& b) {
    if(EQ(a.real(),b.real())) return LT(a.imag(),b.imag());
    return LT(a.real(),b.real());
  }
}

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

double PI = acos(-1.0);

double dot(Point a, Point b){
  return real(conj(a)*b);
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  Point d1 = b-a, d2 = c-a;
  if(GT(cross(d1,d2),0)) return 1;
  if(LT(cross(d1,d2),0)) return -1;
  if(LT(dot(d1,d2),0)) return -2;      
  if(LT(norm(d1),norm(d2))) return 2;  
  return 0;                            
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

Segment overlap(Segment a, Segment b){
  return Segment(max(min(a.bgn,a.end),min(b.bgn,b.end)),
		 min(max(a.bgn,a.end),max(b.bgn,b.end)));
}

int nPt[2];
Point pt[2][POINT];

void read(){
  int x1, y1, x2, y2;
  cin >> y1 >> x1 >> y2 >> x2;

  pt[1][0] = Point(x1,y1), pt[0][0] = Point(x2,y2);
  
  for(int i=0;i<2;i++){
    cin >> nPt[i];
    nPt[i]++;
    for(int j=1;j<nPt[i];j++){
      int x, y;
      cin >> y >> x;
      pt[i][j] = Point(x,y);
    }
  }
}

void work(){
  double dist[]={0,0};
  
  for(int i=0;i+1<nPt[0];i++){
    dist[1] = 0;
    for(int j=0;j+1<nPt[1];dist[1]+=abs(pt[1][j]-pt[1][j+1]),j++){
      Segment ds = Segment(pt[0][i],pt[0][i+1]);
      Segment ls = Segment(pt[1][j],pt[1][j+1]);
      double theta = arg((pt[0][i+1]-pt[0][i])/(pt[1][j+1]-pt[1][j]));
      
      if(!isIntersect(ds,ls)) continue;

      if(EQ(fabs(theta),PI)){
	Segment seg = overlap(ds,ls);
	double minL = min(abs(seg.bgn-pt[0][i]),abs(seg.end-pt[0][i]));
	double maxL = max(abs(seg.bgn-pt[0][i]),abs(seg.end-pt[0][i]));
	double minD = min(abs(seg.bgn-pt[1][j]),abs(seg.end-pt[1][j]));
	double maxD = max(abs(seg.bgn-pt[1][j]),abs(seg.end-pt[1][j]));
	
	if(LT(max(minL,minD),min(maxL,maxD))){
	  cout << "No" << endl;
	  return;
	}
	continue;
      }
      if(EQ(theta,0)){ 
	Segment seg = overlap(ds,ls);
	double minL = min(abs(seg.bgn-pt[0][i]),abs(seg.end-pt[0][i]));
	double minD = min(abs(seg.bgn-pt[1][j]),abs(seg.end-pt[1][j]));
	
	if(EQ(dist[0]+minL,dist[1]+minD)){
	  cout << "No" << endl;
	  return;
	}
	continue;
      }
      
      Point crossP = calcIntersect(ds,ls);
      if(EQ(abs(crossP-pt[0][i+1]),0)) continue;
      
      double d1 = dist[0]+abs(pt[0][i]-crossP);
      double d2 = dist[1]+abs(pt[1][j]-crossP);
      
      if(EQ(d1,d2)){
	cout << "No" << endl;
	return;
      }
    }
    dist[0] += abs(pt[0][i]-pt[0][i+1]);
  }
  cout << "Yes" << endl;
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
