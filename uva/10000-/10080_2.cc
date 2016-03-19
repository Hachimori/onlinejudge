#include<iostream>
#include<queue>
#include<algorithm>

#define INF 100000000
#define LEFT 105
#define RIGHT 105

using namespace std;

class Point{
public:
  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y) {}
  
  double distance(Point p){
    return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
  }
};

int nLeft, nRight;
bool adj[LEFT][RIGHT];

bool read(){
  Point g[LEFT], h[RIGHT];
  double timeLimit, speed;
  
  if(!(cin >> nLeft >> nRight >> timeLimit >> speed)) return false;
  
  for(int i=0;i<nLeft;i++)
    cin >> g[i].x >> g[i].y;

  for(int i=0;i<nRight;i++)
    cin >> h[i].x >> h[i].y;
  
  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++)
      if(g[i].distance(h[j])/speed<timeLimit)
	adj[i][j] = true;

  return true;
}

int maxMatch(){
  bool used[RIGHT];
  int L2R[LEFT], R2L[RIGHT], nMatch = 0;

  fill(used,used+nRight,false);
  fill(L2R,L2R+nLeft,-1);
  fill(R2L,R2L+nRight,-1);
  
  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++){
      if(used[j]) continue;
      if(!adj[i][j]) continue;
      
      used[j] = true;
      nMatch++;
      L2R[i] = j;
      R2L[j] = i;
      break;
    }

 ExtendMatch:
  for(int i=0;i<nLeft;i++){
    if(L2R[i]!=-1) continue;
    
    int preL2R[LEFT], preR2L[RIGHT];
    queue<int> Q;
    
    for(int j=0;j<nLeft;j++) preL2R[j] = -1;
    for(int j=0;j<nRight;j++) preR2L[j] = -1;
    Q.push(i);

    while(!Q.empty()){
      int curr = Q.front();
      Q.pop();

      for(int j=0;j<nRight;j++){
	if(!adj[curr][j]) continue;
	if(preR2L[j]!=-1) continue;
	
	preR2L[j] = curr;
	
	if(R2L[j]==-1){
	  int currL = curr, currR = j;
	  
	  while(true){
	    L2R[currL] = currR;
	    R2L[currR] = currL;
	    if(preL2R[currL]==-1) break;
	    currR = preL2R[currL];
	    currL = preR2L[currR];
	    R2L[currR] = -1;
	  }
	  nMatch++;
	  goto ExtendMatch;
	}
	else{
	  preL2R[R2L[j]] = j;
	  Q.push(R2L[j]);
	}
      }
    }
  }
  
  return nMatch;
}

void work(){
  cout << nLeft-maxMatch() << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
