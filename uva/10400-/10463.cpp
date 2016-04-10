#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>

#define MAX_NUM 100
#define MAX_SIZE 20

using namespace std;

class Point{
public:

  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c) {}

};

int row, column;
Point start, goal;
int rMove[8]={3,3,1,-1,-3,-3,-1,1};
int cMove[8]={-1,1,3,3,1,-1,-3,-3};
bool isPrime[MAX_NUM];

void createPrime(){
	
  fill(isPrime,isPrime+MAX_NUM,true);
	
  for(int i=2;i*i<MAX_NUM;i++)
    if(isPrime[i])
      for(int j=i*2;j<MAX_NUM;j+=i)
	isPrime[j] = false;

  isPrime[0]=false;
  isPrime[1]=false;
}

bool isInside(Point p){
  return 0<=p.r && p.r<row && 0<=p.c && p.c<column;
}

bool read(){
  if(!(cin >> row >> column >> start.r >> start.c >> goal.r >> goal.c)) 
    return false;
  return true;
}

void bfsPrime(int &ans){
	
  queue<Point> Q;
  int cost[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<row;i++)
    fill(cost[i],cost[i]+column,INT_MAX);

  Q.push(start);
  cost[start.r][start.c] = 0;

  if(start.r==goal.r && start.c==goal.c) 
    return;
  
  while(!Q.empty()){
			
    Point curr=Q.front();
    Q.pop();

    for(int j=0;j<8;j++){			
      Point next=curr;
      
      next.r+=rMove[j], next.c+=cMove[j];

      if(!isInside(next)) continue;
	

      if(cost[next.r][next.c]==INT_MAX){
	cost[next.r][next.c]=cost[curr.r][curr.c]+1;	
	Q.push(next);
      }
      else if(isPrime[cost[next.r][next.c]] && isPrime[cost[curr.r][curr.c]+1] && 
	 cost[next.r][next.c]>cost[curr.r][curr.c]+1){
	cost[next.r][next.c]=cost[curr.r][curr.c]+1;	
	Q.push(next);
      }
      else if(!isPrime[cost[next.r][next.c]] && 
	      ( isPrime[cost[curr.r][curr.c]+1]||cost[next.r][next.c]>cost[curr.r][curr.c]+1) ){
	cost[next.r][next.c]=cost[curr.r][curr.c]+1;	
	Q.push(next);
      }
      
    }

  }

  if(cost[goal.r][goal.c]!=INT_MAX && isPrime[cost[goal.r][goal.c]])
    ans = cost[goal.r][goal.c];


}

void bfs(int &ans){
	
  queue<Point> Q;
  int cost[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<row;i++)
    fill(cost[i],cost[i]+column,INT_MAX);

  Q.push(start);
  cost[start.r][start.c] = 0;

	
  while(!Q.empty()){
			
    Point curr=Q.front();
    Q.pop();

    if(curr.r==goal.r && curr.c==goal.c)
      break;
		
    for(int j=0;j<8;j++){			
      Point next=curr;
			
      next.r+=rMove[j], next.c+=cMove[j];

      if(!isInside(next)) continue;
			
      if(cost[next.r][next.c]>cost[curr.r][curr.c]+1){
	cost[next.r][next.c]=cost[curr.r][curr.c]+1;	
	Q.push(next);
      }
			
    }

  }
  
  
  ans = cost[goal.r][goal.c];

}

void work(int cases){

  int ans=INT_MAX;
	
  cout << "CASE# " << cases << ": "; 
  

  bfsPrime(ans);

  if(ans!=INT_MAX) {
    cout << "The knight takes " << ans << " prime moves." << endl;
    return;
  }


  bfs(ans);
	
  if(ans!=INT_MAX) {
    cout << "The knight takes " << ans << " composite move(s)." << endl;
    return;
  }

  cout << "Destination is not reachable." << endl;

}

int main(){
	
  createPrime();

  for(int cases=1;read();cases++)
    work(cases);

  return 0;

}
