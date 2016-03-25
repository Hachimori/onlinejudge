#include<iostream>
#include<complex>
#include<vector>
#include<cstdio>
#include<cmath>
#define EPS (1e-8)
#define INF (1<<20)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;
typedef complex<double> Point;
const int BUF = 1005;

struct Circle{
  Point p;
  double r;
};

int nCircle;
Circle circle[BUF];

void read(){
  cin >> nCircle;
  for(int i=0;i<nCircle;i++){
    double x, y, r;
    cin >> x >> y >> r;
    circle[i].p = Point(x,y);
    circle[i].r = r;
  }
}

Point calcIntersect(Circle c, double x){
  if((LE(x,c.p.real()) && LT(c.p.real()-c.r,x)) || 
     (LE(c.p.real(),x) && LT(x,c.p.real()+c.r)))
    return Point(x,c.p.imag()-sqrt(c.r*c.r-(c.p.real()-x)*(c.p.real()-x)));
  return Point(INF,INF);
}

void rec(int cur, double &minLY, double &maxLY, double &minRY, double &maxRY,
         bool &top, bool &bottom, bool visited[BUF]){
  visited[cur] = true;

  int pos[2]={0,1000};
  for(int i=0;i<2;i++){
    Point xp = calcIntersect(circle[cur],pos[i]);
    if(EQ(norm(xp-Point(INF,INF)),0) || LT(xp.imag(),0) || LT(1000,xp.imag())) continue;  
    if(i==0){
      minLY = min(minLY,xp.imag());
      maxLY = max(maxLY,xp.imag());
    }
    else{
      minRY = min(minRY,xp.imag());
      maxRY = max(maxRY,xp.imag());    
    }
  }
  if(LT(1000,circle[cur].p.imag()+circle[cur].r)) top = true;
  if(LT(circle[cur].p.imag()-circle[cur].r,0)) bottom = true;

  for(int i=0;i<nCircle;i++){
    if(visited[i] || LE(circle[cur].r+circle[i].r,abs(circle[cur].p-circle[i].p))) continue;
    rec(i,minLY,maxLY,minRY,maxRY,top,bottom,visited);
  }
}

void work(){
  int nYLeft = 0, nYRight = 0;
  double yLeft[BUF], yRight[BUF];
  for(int i=0;i<nCircle;i++){
    int pos[2]={0,1000};
    for(int j=0;j<2;j++){
      Point xp = calcIntersect(circle[i],pos[j]);
      if(EQ(norm(xp-Point(INF,INF)),0) || LT(xp.imag(),0) || LT(1000,xp.imag())) continue;
      bool isOk = true;
      for(int k=0;k<nCircle;k++)
        if(LT(abs(circle[k].p-xp),circle[k].r))
          isOk = false;
      if(!isOk) continue;
      (j==0 ? yLeft[nYLeft++] : yRight[nYRight++]) = xp.imag();
    }
  }

  Point t[2]={Point(0,1000),Point(1000,1000)};
  for(int i=0;i<2;i++){
    bool isOk = true;
    for(int j=0;j<nCircle;j++)
      if(LT(abs(circle[j].p-t[i]),circle[j].r))
          isOk = false;
    if(!isOk) continue;
    (i==0 ? yLeft[nYLeft++] : yRight[nYRight++]) = 1000;
  }
 
  sort(yLeft,yLeft+nYLeft);
  sort(yRight,yRight+nYRight);
  reverse(yLeft,yLeft+nYLeft);
  reverse(yRight,yRight+nYRight);
  
  bool visited[BUF]={0}; // for circle
  bool okL[BUF], okR[BUF];
  bool adj[BUF][BUF]; // adj[yLeft][yRight]: true if yLeft->yRight is possible

  for(int i=0;i<nYLeft;i++){
    okL[i] = true;
    for(int j=0;j<nYRight;j++){
      okR[j] = true;
      adj[i][j] = true;
    }
  }

  for(int k=0;k<nCircle;k++){
    if(visited[k]) continue;
    double minLY = INF, maxLY = -INF, minRY = INF, maxRY = -INF;
    bool top = false, bottom = false;
    rec(k,minLY,maxLY,minRY,maxRY,top,bottom,visited);
    
    if(top && bottom){
      cout << "Bill will be bitten." << endl;
      return;
    }
    if(top){
      for(int i=0;i<nYLeft;i++) if(GT(yLeft[i],minLY)) okL[i] = false;
      for(int i=0;i<nYRight;i++) if(GT(yRight[i],minRY)) okR[i] = false;
    }
    if(bottom){
      for(int i=0;i<nYLeft;i++) if(LE(yLeft[i],maxLY)) okL[i] = false;
      for(int i=0;i<nYRight;i++) if(LE(yRight[i],maxRY)) okR[i] = false;
    }
    if(!EQ(minLY,INF) && !EQ(minRY,INF))
      for(int i=0;i<nYLeft;i++)
        for(int j=0;j<nYRight;j++){
          int idL, idR;
          if(GT(yLeft[i],maxLY))
            idL = 0;
          else if(GT(yLeft[i],minLY))
            idL = 1;
          else
            idL = 2;
          if(GT(yRight[i],maxRY))
            idR = 0;
          else if(GT(yRight[i],minRY))
            idR = 1;
          else
            idR = 2;
          if(idL!=idR)
            adj[i][j] = false;
        }
    if(!EQ(minLY,INF)){
      for(int i=0;i<nYLeft;i++)
        if(LT(minLY,yLeft[i]) && LE(yLeft[i],maxLY))
          okL[i] = false;
    }
    if(!EQ(minRY,INF)){
      for(int i=0;i<nYRight;i++)
        if(LT(minRY,yRight[i]) && LE(yRight[i],maxRY))
          okR[i] = false;
    }
  }

  for(int i=0;i<nYLeft;i++)
    for(int j=0;j<nYRight;j++)
      if(okL[i] && okR[j] && adj[i][j]){
        printf("Bill enters at (%.2lf, %.2lf) and leaves at (%.2lf, %.2lf).\n",0.,yLeft[i],1000.,yRight[j]);
        return;
      }
  cout << "Bill will be bitten." << endl;
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
