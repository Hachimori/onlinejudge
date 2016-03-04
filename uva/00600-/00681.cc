#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cmath>

#define SIZE 600
#define EPS (1.0e-9)
#define EQ(x,y) (abs(x-y)<EPS)

using namespace std;

typedef complex<int> Point;

int nPoint;
Point pt[SIZE];

void read(){
  cin >> nPoint;
  
  for(int i=0;i<nPoint;i++){
    int x,y;
    cin >> x >> y;

    pt[i] = Point(x,y);
  }
  nPoint--;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);

  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

bool cmp(const Point &a, const Point &b){
  if(EQ(a.real(),b.real())) return a.imag()<b.imag();
  return a.real()<b.real();
}

void pushPt(vector<Point> &ret, bool low){
  int bgn = (low ? 0 : nPoint-1);
  int end = (low ? nPoint : -1);
  int d = (low ? 1 : -1);
  
  ret.push_back(pt[bgn]);
  int m = ret.size();
  
  for(int i=bgn+d;i!=end;i+=d){
    for(int k;(k=ret.size())>m && 
	  ccw(ret[k-2],ret[k-1],pt[i])<=0;)
      ret.pop_back();
    ret.push_back(pt[i]);
  }
  ret.pop_back();
}

vector<Point> calcConvex(){
  sort(pt,pt+nPoint,cmp);
  vector<Point> ret;
  pushPt(ret,true);
  pushPt(ret,false);
  return ret;
}

void work(){
  vector<Point> ans = calcConvex();

  int bgn = 0;
  for(int i=0;i<ans.size();i++)
    if(ans[bgn].imag()>ans[i].imag())
      bgn = i;
    else if(ans[bgn].imag()==ans[i].imag() && 
	    ans[bgn].real()>ans[i].real())
      bgn = i;
  
  cout << ans.size()+1 << endl;
  for(int i=bgn,j=0;j<ans.size();i=(i+1)%ans.size(),j++)
    cout << ans[i].real() << ' ' << ans[i].imag() << endl;
  cout << ans[bgn].real() << ' ' << ans[bgn].imag() << endl;
}

int main(){
  int cases;
  cin >> cases;  cout << cases << endl;

  for(int i=0;i<cases;i++){
    if(i){ int dummy; cin >> dummy;  cout << dummy << endl; }
    read();
    work();
  }
  
  return 0;
}
