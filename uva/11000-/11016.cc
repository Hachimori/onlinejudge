#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>
#include<cmath>
#define RANGE 10001
#define SEGMENT 105
using namespace std;
typedef complex<double> Point;

class Segment{
public:
  Point b, e;

  Segment(){}
  Segment(Point _b, Point _e){
    if(_b.real()>_e.real())
      swap(_b,_e);
    b = _b;
    e = _e;
  }

  double calcIntersect(double x){
    double mul = (x-b.real())/(e.real()-b.real());
    Point d = e-b;
    
    return imag(b+mul*d);
  }
};

class Range{
public:
  int a, b;
  
  Range(){}
  Range(int a, int b): a(a), b(b){}

  bool operator< (const Range &r) const {
    if(a!=r.a) return a<r.a;
    return b<r.b;
  }
};

int nSeg;
Segment seg[SEGMENT];

bool read(){
  int nPt;
  Point pt[SEGMENT];

  cin >> nPt;
  if(nPt==0) return false;
  
  for(int i=0;i<nPt;i++){
    int x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
  }
  
  nSeg = 0;
  for(int i=0;i<nPt;i++){
    if(pt[i].real()!=pt[(i+1)%nPt].real())
      seg[nSeg++] = Segment(pt[i],pt[(i+1)%nPt]);
  }

  return true;
}

void work(){
  static vector<Range> range[RANGE];
  for(int x=0;x<RANGE;x++) range[x].clear();
  
  for(int x=0;x<RANGE;x++){
    vector<double> v1, v2;
    for(int i=0;i<nSeg;i++)
      if(seg[i].b.real()<=x && x<seg[i].e.real()){
	v1.push_back(seg[i].calcIntersect(x));
	v2.push_back(seg[i].calcIntersect(x+1));
      }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<v1.size();i+=2){
      int l = (int)ceil(max(v1[i],v2[i]));
      int u = (int)floor(min(v1[i+1],v2[i+1]));
      if(l<u)
	range[x].push_back(Range(l,u));
    }
  }

  int dark = 0, light = 0;
  for(int x=0;x<RANGE;x++)
    for(int i=0;i<range[x].size();i++)
      if(range[x][i].a%2==x%2){
	dark += (range[x][i].b-range[x][i].a+1)/2;
	light += (range[x][i].b-range[x][i].a)/2;
      }
      else{
	light += (range[x][i].b-range[x][i].a+1)/2;
	dark += (range[x][i].b-range[x][i].a)/2;
      }
  
  cout << max(light,dark) << ' ' << min(light,dark) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
