#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define LEFT 55
#define RIGHT 55
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
using namespace std;

class Point{
public:
  double x,y;
  
  Point(){}
  Point(double x, double y): x(x), y(y){}

  double dist(const Point &p) {
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
  }
};

int nLeft, nRight, nAllow;
double dist[LEFT][RIGHT];

void read(){
  cin >> nLeft >> nRight >> nAllow;
  
  Point pt[LEFT+RIGHT];
  for(int i=0;i<nLeft+nRight;i++)
    cin >> pt[i].x >> pt[i].y;

  for(int i=0;i<nLeft;i++)
    for(int j=nLeft;j<nLeft+nRight;j++)
      dist[i][j-nLeft] = pt[i].dist(pt[j]);
}

bool augment(int curr, bool adj[][LEFT], int L2R[], int R2L[], bool visited[]){
  if(curr<0) return true;
  
  for(int i=0;i<nRight;i++){
    if(!adj[curr][i] || visited[i]) continue;
    visited[i] = true;
    
    if(augment(R2L[i],adj,L2R,R2L,visited)){
      L2R[curr] = i;
      R2L[i] = curr;
      return true;
    }
  }
  
  return false;
}

bool maxMatch(double limit){
  int nMatch = 0, L2R[LEFT], R2L[RIGHT];
  static bool adj[LEFT][RIGHT];
  
  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      adj[i][j] = LE(dist[i][j],limit);

  fill(L2R,L2R+LEFT,-1);
  fill(R2L,R2L+RIGHT,-1);
  
  for(int i=0;i<nLeft;i++){
    bool visited[RIGHT];
    fill(visited,visited+nRight,false);
    
    if(augment(i,adj,L2R,R2L,visited))
      nMatch++;
  }

  return nMatch>=nLeft-nAllow;
}

void work(int cases){
  int nLimit = 0;
  double limit[LEFT*RIGHT];
  
  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      limit[nLimit++] = dist[i][j];
  limit[nLimit++] = 0;
  
  sort(limit,limit+nLimit);

  cout << "Case #" << cases << ":" << endl;
  for(int i=0;i<nLimit;i++)
    if(maxMatch(limit[i])){
      printf("%.3lf\n",limit[i]);
      return;
    }
  
  cout << "Too bad." << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
