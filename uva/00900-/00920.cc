#include<iostream>
#include<cstdio>
#include<cmath>
#define x first
#define y second
#define sq(a) ((a)*(a))
using namespace std;
typedef pair<double,double> Point;
const int BUF = 105;

int nPt;
Point pt[BUF];

void read(){
  cin >> nPt;
  for(int i=0;i<nPt;i++)
    cin >> pt[i].x >> pt[i].y;
  sort(pt,pt+nPt);
}

void work(){
  double maxH = 0, ans = 0;
  for(int i=nPt-1;i-1>=0;i--){
    Point pre = pt[i-1], cur = pt[i];
    if(pre.y<=maxH) continue;
    double xPos = pre.x+(cur.x-pre.x)*(maxH-pre.y)/(cur.y-pre.y);
    ans += sqrt(sq(pre.x-xPos)+sq(pre.y-maxH));
    maxH = pre.y;
  }
  printf("%.2lf\n",ans);
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
