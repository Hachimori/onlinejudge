#include<iostream>
#include<vector>
#include<complex>
#include<queue>
#define INF (1<<20)
#define EPS (1.0e-8)
#define BUF 2000
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define GT(x,y) ((x)>=(y)+EPS)
using namespace std;
typedef complex<double> Point;

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
  return  0;
}

bool isParallel(Segment a, Segment b){
  return EQ(cross(a.end-a.bgn,b.end-b.bgn),0);
}

bool isIntersect(Segment a, Segment b){
  return ccw(a.bgn,a.end,b.bgn)*ccw(a.bgn,a.end,b.end)<=0 && 
         ccw(b.bgn,b.end,a.bgn)*ccw(b.bgn,b.end,a.end)<=0; 
}

Point calcIntersect(Segment a, Segment b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);

  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

vector<Segment> init;
Point dst;

void read(){
  init.clear();
  init.push_back(Segment(Point(  0,  0),Point(100,  0)));
  init.push_back(Segment(Point(100,  0),Point(100,100)));
  init.push_back(Segment(Point(100,100),Point(  0,100)));
  init.push_back(Segment(Point(  0,100),Point(  0,  0)));
  
  int nWall;
  cin >> nWall;

  for(int i=0;i<nWall;i++){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    init.push_back(Segment(Point(x1,y1),Point(x2,y2)));
  }

  double x, y;
  cin >> x >> y;
  dst = Point(x,y);
}

int bfs(vector<Segment> &wall){
  int n = wall.size();
  queue<int> Q;
  int cost[BUF];
  Point pt[BUF];

  for(int i=0;i<n;i++){
    cost[i] = INF;
    pt[i] = (wall[i].bgn+wall[i].end)/2.0;
  }
  
  Q.push(n);
  cost[n] = 0;
  pt[n] = dst;

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    for(int i=0;i<n;i++){
      if(cost[i]!=INF) continue;

      Segment path = Segment(pt[curr],pt[i]);
      
      int cnt = 0;
      for(int j=0;j<init.size();j++)
	if(isIntersect(path,init[j])){
	  cnt++;
	  if(cnt>2) break;
	}

      if((curr==n && cnt<=1) || (curr!=n && cnt<=2)){
	cost[i] = cost[curr]+1;
	Q.push(i);
      }
	
      if(cost[i]!=INF && 
	 ( EQ(pt[i].real(),  0) || EQ(pt[i].real(),100) ||
	   EQ(pt[i].imag(),  0) || EQ(pt[i].imag(),100) ) ) return cost[i];
    }
  }
}

void work(){
  vector<Segment> wall = init;

  for(int i=0;i<init.size();i++){
    vector<Segment> toPush;
    for(int j=0;j<wall.size();j++){
      if(!isIntersect(init[i],wall[j]) || isParallel(init[i],wall[j])) continue;

      Point xp = calcIntersect(init[i],wall[j]);

      if(EQ(norm(xp-wall[j].bgn),0) || EQ(norm(xp-wall[j].end),0)) continue;
      
      toPush.push_back(Segment(wall[j].bgn,xp));
      toPush.push_back(Segment(xp,wall[j].end));
      wall.erase(wall.begin()+j--);
    }
    wall.insert(wall.end(),toPush.begin(),toPush.end());
  }

  cout << "Number of doors = " << bfs(wall) << endl;
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
