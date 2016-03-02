#include<iostream>
#include<queue>
#include<algorithm>

#define MAX_SIZE 30
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

class Segment{
public:

  int x,y,direction;

  Segment(){}
  Segment(int x, int y, int d): x(x), y(y), direction(d) {}
  
};

int nSegment;
queue<Segment> segmentList;
bool isSegment[MAX_SIZE][MAX_SIZE];
bool isCollision[MAX_SIZE][MAX_SIZE];
const static int rMove[4]={1,0,-1,0};
const static int cMove[4]={0,1,0,-1};

bool isInside(int x, int y){
  return 0<=x && x<MAX_SIZE && 0<=y && y<MAX_SIZE;
}

bool read(){

  if(!(cin >> nSegment)) return false;

  for(int i=0;i<MAX_SIZE;i++){
    fill(isSegment[i],isSegment[i]+MAX_SIZE,false);
    fill(isCollision[i],isCollision[i]+MAX_SIZE,false);    
  }

  for(int i=0;i<nSegment;i++){
    
    int x,y,length,direction;
    char c;

    cin >> c >> length >> x >> y;
    
    if(c=='U') direction=UP;
    if(c=='R') direction=RIGHT;
    if(c=='D') direction=DOWN;
    if(c=='L') direction=LEFT;
    int currX=x, currY=y;

    for(int j=0;j<length;j++,currX-=cMove[direction],currY-=rMove[direction])
      if(isInside(currX,currY)){
	segmentList.push(Segment(currX,currY,direction));
	isSegment[currX][currY]=true;
      }
  }

  return true;
}

void work(){

  while(!segmentList.empty()){

    Segment curr=segmentList.front();
    segmentList.pop();


    if(isCollision[curr.x][curr.y]) continue;
    
    
    int nextX=curr.x+cMove[curr.direction];
    int nextY=curr.y+rMove[curr.direction];
    
    if(!isInside(nextX,nextY)){ 
      isSegment[curr.x][curr.y]=false;
      continue;
    }

    if(isSegment[nextX][nextY]) {
      isCollision[nextX][nextY]=true;
      isSegment[curr.x][curr.y]=false;
    }
    else {
      isSegment[curr.x][curr.y]=false;
      isSegment[nextX][nextY]=true;
      
      segmentList.push(Segment(nextX,nextY,curr.direction));
    }

  }


  cout << "  ";
  for(int i=0;i<MAX_SIZE;i++){
    cout << " " << i/10;
  }cout << endl;

  cout << "  ";
  for(int i=0;i<MAX_SIZE;i++){
    cout << " " << i%10;
  }cout << endl;
  
  for(int i=MAX_SIZE-1;i>=0;i--){
    if(i<10) cout << 0;
    cout << i;

    for(int j=0;j<MAX_SIZE;j++){
      if(isCollision[j][i]) cout << " X";
      else cout << " .";
    }
    cout << endl;
  }
  
  cout << endl;

}

int main(){
  
  while(read())
    work();
  
  return 0;
  
}
