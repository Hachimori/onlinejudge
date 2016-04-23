
#include<iostream>
#include<vector>
#include<algorithm>
#define NONE 0
#define ROCK 1
#define ROW 9
#define COL 8
#define INF (1<<30)
using namespace std;

class Point{
public:
  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}

  int dist(Point p){
    return max(abs(r-p.r),abs(c-p.c));
  }

  Point moveTo(Point p){
    int dr,dc;
    
    if(c<p.c) dc = 1;
    if(c==p.c) dc = 0;
    if(c>p.c) dc = -1;
    
    if(r<p.r) dr = 1;
    if(r==p.r) dr = 0;
    if(r>p.r) dr = -1;
    
    return Point(r+dr,c+dc);
  }

  bool operator== (const Point &p) const {
    return r==p.r && c==p.c;
  }
};

const static int dr[]={-1,-1,-1,0,1,1,1,0}, dc[]={-1,0,1,1,1,0,-1,-1};
int b[ROW][COL];
Point self;
vector<Point> enemy;

void read(){
  enemy.clear();
  
  for(int i=0;i<ROW;i++)
    for(int j=0;j<COL;j++){
      char ch;
      cin >> ch;

      b[i][j] = (ch=='#' ? ROCK : NONE);
      
      if(ch=='E') enemy.push_back(Point(i,j));
      if(ch=='S') self = Point(i,j);
    }
}

bool isInside(Point p){
  return 0<=p.r && p.r<ROW && 0<=p.c && p.c<COL;
}

int manhattan(vector<Point> &e){
  vector<Point> rock;

  for(int i=0;i<ROW;i++)
    for(int j=0;j<COL;j++)
      if(b[i][j]==ROCK)
	rock.push_back(Point(i,j));

  int ret = INF;
  
  for(int i=0;i<rock.size();i++)
    for(int j=0;j<e.size();j++)
      ret = min(ret,rock[i].dist(e[j]));

  for(int i=0;i<e.size();i++)
    for(int j=i+1;j<e.size();j++)
      ret = min(ret,(e[i].dist(e[j])+1)/2);

  return ret;
}

void moveEnemy(Point s, vector<Point> &e, 
	       vector<Point> &nextE, vector<Point> &garbage){
  
  for(int i=0;i<e.size();i++){
    Point to = e[i].moveTo(s);
    //cout << s.r << ',' << s.c << "   " <<  to.r << ' ' << to.c << endl;
    if(count(nextE.begin(),nextE.end(),to)){
      garbage.push_back(to);
      nextE.erase(find(nextE.begin(),nextE.end(),to));
      continue;
    }

    if(count(garbage.begin(),garbage.end(),to)) continue;
    if(b[to.r][to.c]==ROCK) continue;
    
    nextE.push_back(to);
  }
}

bool dfs(int nMove, Point s, vector<Point> &e){
  if(e.empty()) return true;
  if(nMove+manhattan(e)==10) return false;

  for(int i=0;i<8;i++){
    Point next = Point(s.r+dr[i],s.c+dc[i]); 
    if(!isInside(next) || b[next.r][next.c]==ROCK) continue;
    //cout << nMove << ' ' << i << endl;
    vector<Point> nextE, garbage;
    moveEnemy(next,e,nextE,garbage);
    
    if(count(e.begin(),e.end(),next) || 
       count(nextE.begin(),nextE.end(),next) || 
       count(garbage.begin(),garbage.end(),next)) continue;
    
    for(int j=0;j<garbage.size();j++)
      b[garbage[j].r][garbage[j].c] = ROCK;

    if(dfs(nMove+1,next,nextE)) return true;

    for(int j=0;j<garbage.size();j++)
      b[garbage[j].r][garbage[j].c] = NONE;
  }
  
  return false;
}

void work(){
  if(dfs(0,self,enemy)) cout << "I'm the king of the Seven Seas!" << endl;
  else cout << "Oh no! I'm a dead man!" << endl;
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
