#include<iostream>
#include<complex>
#include<algorithm>
#define INF (1<<20)
#define POINT 505
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
#define GT(x,y) ((x)>=(y)+EPS)
#define GE(x,y) (GT(x,y) || EQ(x,y))
using namespace std;
typedef complex<double> Point;
typedef pair<double,double> Range;
double PI = acos(-1.0);

int nPt;
double limit;
Point pt[POINT];

void read(){
  cin >> nPt >> limit;

  for(int i=0;i<nPt;i++){
    double x, y;
    cin >> x >> y;
    pt[i] = Point(x,y);
    if(LE(abs(pt[i]),limit)){
      i--;
      nPt--;
    }
  }
}

int cnt(Range r[POINT]){
  int ret = 0;

  for(int i=0;i<nPt;){
    double curH = r[i].second;
    while(i<nPt && GE(curH,r[i].first)){
      curH = min(curH,r[i].second);
      i++;
    }
    ret++;
  }

  return ret;
}

void work(){
  if(nPt==0){
    cout << 0 << endl;
    return;
  }

  Range range[POINT];  // low, high   [0-4*PI]

  for(int i=0;i<nPt;i++){
    double center = arg(pt[i]);
    double angle = asin(limit/abs(pt[i]));
    
    range[i] = Range(center-angle,center+angle);

    if(range[i].first<0){
      range[i].first += PI*2;
      range[i].second += PI*2;
    }
  }
  sort(range,range+nPt);


  int minV = INF;
  for(int i=0;i<nPt;i++){
    Range next[POINT];

    for(int j=0;j<nPt;j++){
      next[j].first = range[j].first-range[i].second;
      next[j].second = range[j].second-range[i].second;

      if(LT(next[j].second,0)){
        next[j].first += 2*PI;
        next[j].second += 2*PI;
      }
    }
    sort(next,next+nPt);
    minV = min(minV,cnt(next));
  }

  cout << minV << endl;
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
