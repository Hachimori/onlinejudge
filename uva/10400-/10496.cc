#include<iostream>
#include<climits>
#include<cstdlib>

#define MAX_BEEPER 11

class Point{
public:
  
  int x,y;
  
  Point(){}
  Point(int x, int y): x(x), y(y){}
  
};

Point start;
int minMove;
int xSize, ySize, nBeeper;
Point beeperList[MAX_BEEPER];

void read(){
  
  cin >> xSize >> ySize;
  cin >> start.x >> start.y;
  
  cin >> nBeeper;
  for(int i=0;i<nBeeper;i++)
    cin >> beeperList[i].x >> beeperList[i].y;

}

void calc(int order[MAX_BEEPER]){

  int sum=0;
  sum+=abs(start.x-beeperList[order[0]].x)+
         abs(start.y-beeperList[order[0]].y);

  for(int i=0;i<nBeeper-1;i++)
    sum+=abs(beeperList[order[i]].x-beeperList[order[i+1]].x)+
          abs(beeperList[order[i]].y-beeperList[order[i+1]].y);

  sum+=abs(start.x-beeperList[order[nBeeper-1]].x)+
         abs(start.y-beeperList[order[nBeeper-1]].y);
  
  if(minMove>sum)
    minMove = sum;
}

void makeOrder(int curr, int order[MAX_BEEPER], bool used[MAX_BEEPER]){

  if(curr==nBeeper){
    calc(order);
    return;
  }

  for(int i=0;i<nBeeper;i++){
    if(!used[i]){
      
      order[curr]=i;
      used[i]=true;
      
      makeOrder(curr+1,order,used);

      used[i]=false;
    }
  }

}

void work(){

  int order[MAX_BEEPER];
  bool used[MAX_BEEPER];

  minMove = INT_MAX;
  for(int i=0;i<nBeeper;i++)
    used[i]=false;

  makeOrder(0,order,used);

  cout << "The shortest path has length " << minMove << endl;

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
