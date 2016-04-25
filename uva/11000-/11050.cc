#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#define VERTICAL 0
#define HORIZONTAL 1
#define UP 1
#define RIGHT 2
#define BOTTOM 4
#define LEFT 8
#define INF (1<<20)
#define r first
#define c second
using namespace std;
typedef pair<int,int> Point;

class Wall{
public:
  int r, c, len, dir;

  Wall(){}
  Wall(int r, int c, int l, int d): r(r), c(c), len(l), dir(d){}

  bool intersect(Wall &w){
    if(dir==w.dir){
      if(dir==VERTICAL && c==w.c && max(r,w.r)<min(r+len,w.r+w.len)) return true;
      else if(dir==HORIZONTAL && r==w.r && max(c,w.c)<min(c+len,w.c+w.len)) return true;
    }
    else {
      if(dir==VERTICAL && w.c<c && c<w.c+w.len && r<w.r && w.r<r+len) return true;
      else if(dir==HORIZONTAL && w.r<r && r<w.r+w.len && c<w.c && w.c<c+len) return true;
    }
    return false;
  }
};

int len[3];
string path;

bool read(){
  for(int i=0;i<3;i++) cin >> len[i];

  if(!(len[0]|len[1]|len[2])) return false;
  
  cin >> path;
  
  return true;
}

bool isInside(Point &p){
  return 0<=p.r && p.r<6 && 0<=p.c && p.c<6;
}

int bfs(Point &src, Point &dst, int b[6][6]){
  static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  static int cost[6][6];
  queue<Point> Q;
  
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      cost[i][j] = INF;
  cost[src.r][src.c] = 0;
  Q.push(src);
  
  while(!Q.empty() && cost[dst.r][dst.c]==INF){
    Point curr = Q.front();
    Q.pop();
    
    if(cost[curr.r][curr.c]>=path.size()) break;
        
    for(int i=0;i<4;i++){
      Point next(curr.r+dr[i],curr.c+dc[i]);
      if(cost[next.r][next.c]!=INF || (b[curr.r][curr.c]&(1<<i)) || !isInside(next)) continue;


      cost[next.r][next.c] = cost[curr.r][curr.c]+1;
      Q.push(next);
    }
  }

  return cost[dst.r][dst.c];
}

int minR, minC, maxR, maxC;

bool rec(int curr, Point &src, Point &dst, int go[6][6], int b[6][6], Wall wall[3]){
  if(curr==3){
    /*
    cout << src.r << ' ' << src.c << endl;
    cout << dst.r << ' ' << dst.c << endl;
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++)
	cout << b[i][j] << ' ';
      cout << endl;
    }
    cout << bfs(src,dst,b) << endl << endl;

    for(int i=0;i<3;i++)
      cout << wall[i].r << ' ' << wall[i].c << ' ' << wall[i].len << ' ' << wall[i].dir << endl;
    cout << endl;
    cout << endl;*/
    return bfs(src,dst,b)==path.size();
  }
  

  for(int dir=0;dir<2;dir++)
    for(int r=(maxR-minR<=len[curr]?0:minR);r<=(maxR-minR<=len[curr]?6:maxR);r++)
      for(int c=(maxC-minC<=len[curr]?0:minC);c<=(maxC-minC<=len[curr]?6:maxC);c++){
	if(dir==  VERTICAL && r+len[curr]>(maxR-minR<=len[curr]?6:maxR)) continue;
	if(dir==HORIZONTAL && c+len[curr]>(maxC-minC<=len[curr]?6:maxC)) continue;
	
	wall[curr] = Wall(r,c,len[curr],dir);
	
	bool fail = false;
	for(int i=0;i<curr;i++)
	  if(wall[i].intersect(wall[curr])){
	    fail = true;
	    break;
	  }

	if(fail) continue;
	
	for(int j=0;j<len[curr];j++){
	  Wall &w = wall[curr];
	  if(w.dir==VERTICAL){
	    if(w.c<6){
	      b[w.r+j][w.c] |= LEFT;
	      if(go[w.r+j][w.c]&LEFT) fail = true;
	    }
	    if(w.c>0){
	      b[w.r+j][w.c-1] |= RIGHT;
	      if(go[w.r+j][w.c-1]&RIGHT) fail = true;
	    }
	  }
	  else{
	    if(w.r<6){
	      b[w.r][w.c+j] |= UP;
	      if(go[w.r][w.c+j]&UP) fail = true;
	    }
	    if(w.r>0){
	      b[w.r-1][w.c+j] |= BOTTOM;
	      if(go[w.r-1][w.c+j]&BOTTOM) fail = true;
	    }
	  }
	}
	
	if(fail) goto finish1;
	
	if(rec(curr+1,src,dst,go,b,wall)) return true;

      finish1:;
	for(int j=0;j<len[curr];j++){
	  Wall &w = wall[curr];
	  if(w.dir==VERTICAL){
	    if(w.c<6) b[w.r+j][w.c] &= ~LEFT;
	    if(w.c>0) b[w.r+j][w.c-1] &= ~RIGHT;
	  }
	  else{
	    if(w.r<6) b[w.r][w.c+j] &= ~UP;
	    if(w.r>0) b[w.r-1][w.c+j] &= ~BOTTOM;
	  }
	}
      }
	
  
  return false;
}

void work(){
  Wall wall[3];
  Point src, dst;
  int go[6][6], b[6][6];

  for(int r=0;r<6;r++)
    for(int c=0;c<6;c++){

      src = dst = Point(r,c);

      for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	  go[i][j] = b[i][j] = 0;
      
      minR = r, minC = c, maxR = r, maxC = c;
      for(int i=0;i<path.size();i++){
	int dir;
	Point next = dst;
	switch(path[i]){
	case 'N': next.r--; dir = UP; break;
	case 'E': next.c++; dir = RIGHT; break;
	case 'S': next.r++; dir = BOTTOM; break;
	case 'W': next.c--; dir = LEFT; break;
	}
	if(!isInside(next)) goto finish2;
	go[dst.r][dst.c] |= dir;
	dst = next;
	minR = min(minR,dst.r), minC = min(minC,dst.c);
	maxR = max(maxR,dst.r+1), maxC = max(maxC,dst.c+1);
      }
      //minR = max(minR-1,0), minC = max(minC-1,0);
      //maxR = min(maxR+1,6), maxC = min(maxC+1,6);
      /*
      cout << minR << '-' << maxR << "   " << minC << "-" << maxC << endl;
      cout << src.r << ' ' << src.c << endl;
      cout << dst.r << ' ' << dst.c << endl << endl;
      */
      if(rec(0,src,dst,go,b,wall)){
	cout << src.c+1 << ' ' << src.r+1 << endl;
	cout << dst.c+1 << ' ' << dst.r+1 << endl;
	
	for(int i=0;i<3;i++)
	  cout << wall[i].c << ' ' << wall[i].r << ' ' 
	       << wall[i].c+(wall[i].dir==VERTICAL?0:len[i]) << ' '
	       << wall[i].r+(wall[i].dir==VERTICAL?len[i]:0) << endl;
	return;
      }
      
    finish2:;
    }
}

int main(){
  while(read())
    work();

  return 0;
}
