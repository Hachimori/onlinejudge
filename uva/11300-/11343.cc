#include<iostream>
#include<complex>
#define EPS  (1.0e-7)
#define GT(x,y) ((x)>=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;
const int SEGMENT = 105;

class Segment{
public:
  Point bgn, end;
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

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

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 &&
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0;
}

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int nSeg;
    Segment seg[SEGMENT];
    cin >> nSeg;
    for(int i=0;i<nSeg;i++){
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      seg[i] = Segment(Point(x1,y1),Point(x2,y2));
    }
    
    int cnt = 0;
    for(int i=0;i<nSeg;i++){
      for(int j=0;j<nSeg;j++)
        if(i!=j && isIntersect(seg[i],seg[j]))
          goto _fail;
      cnt++;
    _fail:;
    }
    cout << cnt << endl;
  }
  return 0;
}
