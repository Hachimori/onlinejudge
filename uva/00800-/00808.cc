#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<utility>

#define SHIFT 150
#define MAX_SIZE 300
#define MAX_NUM 10005

using namespace std;

class Point{
public:

  int x, y;
  
  Point(){}
  Point(int x, int y): x(x), y(y) {}

};

Point pos[MAX_NUM];
int visited[2][MAX_SIZE][MAX_SIZE];
int dx[6]={-1,-1,0,1,1,0}, dy[6]={0,-1,-1,0,1,1};

int &access(int j, int x, int y){
  return visited[j][x+SHIFT][y+SHIFT];
}


void makePos(){
  
  int currNum=2;
  
  pos[1] = Point(0,0);
  
  for(int depth=1;;depth++){
    Point currPos=Point(depth,depth);
    
    for(int i=0;i<6;i++){
      for(int j=0;j<depth;j++){
	currPos.x+=dx[i];
	currPos.y+=dy[i];
	
	pos[currNum] = currPos;
	currNum++;
	if(currNum==MAX_NUM) return;
      }
    }

  }

}

int source, target;

bool read(){
  
  cin >> source >> target;
  if(source==0 && target==0) return false;
  
  return true;
}

int calc(){

  Point a, b;

  if(pos[source].x>pos[target].x) 
    a=pos[target], b=pos[source];
  else
    b=pos[target], a=pos[source];

  
  
  int ans=0;
  /*
  cout << a.x << " " <<  a.y << "  " 
       << b.x << " " <<  b.y << endl;
  */
  ans+=abs(pos[source].x-pos[target].x);

  if(a.y<b.y){
    if(b.y-a.y>abs(b.x-a.x))
      a.y += abs(b.x-a.x);
    else
      a.y = b.y;
  }
  
  ans+=abs(b.y-a.y);

  return ans;
}

void work(){
  
  cout << "The distance between cells " << source << " and " 
       << target << " is " << calc() << "." << endl;

}

int main(){
  
  makePos();

  while(read())
    work();
  
  return 0;

}
