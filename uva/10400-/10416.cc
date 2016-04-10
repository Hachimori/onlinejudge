#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<cstdlib>
#define POINT 105
#define EPS  (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
typedef complex<double> Point; 

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

Point rotate(Point p){
  return Point(-p.imag(),p.real());
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);
  
  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

Point symmetry(Segment s, Point p) {
  Segment ss = Segment(p,p+rotate(s.bgn-s.end));
  
  return 2.0*calcIntersect(s,ss)-p;
}

int nPt;
vector<Point> pt;

void read(){
  pt.clear();

  cin >> nPt;
  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    pt.push_back(Point(x,y));
  }
  
  for(int i=0;i<pt.size();i++){
    while(true){
      Segment seg1 = Segment(pt[i],pt[(i+1)%pt.size()]);
      Segment seg2 = Segment(pt[i],pt[(i+2)%pt.size()]);
      
      if(!isParallel(seg1,seg2)) break;
      pt.erase(pt.begin()+i+1);
    }
  }
  
  nPt = pt.size();
}

bool isOk(Segment fold){
  int visited[POINT];
  for(int i=0;i<nPt;i++) visited[i] = -1;
    
  for(int i=0;i<nPt;i++){
    Point moved = symmetry(fold,pt[i]);
      
    bool found = false;
    for(int j=0;j<nPt;j++)
      if(EQ(abs(moved-pt[j]),0)){
	found = true;
	visited[j] = i;
	break;
      }
      
    if(!found) return false;
  }
    
  for(int j=0;j<nPt;j++)
    if(abs(visited[j]-visited[(j+1)%nPt])!=1 &&
       abs(visited[j]-visited[(j+1)%nPt])!=nPt-1 ) return false;
      
  return true;
}

void work(){
  for(int i=0;i<nPt;i++){
    Point p1 = pt[i], p2 = pt[(i+1)%nPt], mid = (p1+p2)/2.0;
    if(isOk(Segment(mid,mid+rotate(p1-p2)))){
      cout << "Yes" << endl;
      return;
    }
  }
  
  for(int i=0;i<nPt;i++)
    for(int j=i+1;j<nPt;j++){
      Point p1 = pt[i], p2 = pt[j];
      if(isOk(Segment(p1,p2))){
	cout << "Yes" << endl;
	return;
      }
    }
  
  cout << "No" << endl;
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
