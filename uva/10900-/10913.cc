#include<iostream>
#include<algorithm>
#define BUF 80
#define LIFE 10
#define INF (1<<30)
using namespace std;

int size, life, b[BUF][BUF];

bool read(){
  cin >> size >> life;
  if(size==0 && life==0) return false;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cin >> b[i][j];
  
  return true;
}

int cntNeg(int r, int c1, int c2){
  int sum = 0;
  for(int i=c1;i<=c2;i++)
    if(b[r][i]<0) 
      sum++;
  return sum;
}

int cntCost(int r, int c1, int c2){
  int sum = 0;
  for(int i=c1;i<=c2;i++)
    sum += b[r][i];
  return sum;
}

int dp(){
  int cost[BUF][BUF][LIFE];
  for(int i=0;i<=size;i++)
    for(int j=0;j<size;j++)
      for(int k=0;k<=life;k++)
	cost[i][j][k] = -INF;
  
  cost[0][0][life] = 0;

  for(int r=0;r<size;r++){
    for(int c=0;c<size;c++){
      for(int l=0;l<=life;l++){
	for(int nc=0;nc<size;nc++){
	  if(cost[r][c][l]==-INF) continue;
	  
	  int nNeg = cntNeg(r,min(c,nc),max(c,nc));
	  int nextCost = cost[r][c][l]+cntCost(r,min(c,nc),max(c,nc));

	  if(l-nNeg<0) continue;
	  if(cost[r+1][nc][l-nNeg]<nextCost)
	    cost[r+1][nc][l-nNeg] = nextCost;

	}
      }
    }
  }

  return *max_element(cost[size][size-1],cost[size][size-1]+life+1);
}

void work(int cases){
  int ans = dp();
  
  cout << "Case " << cases << ": ";
  if(ans==-INF) cout << "impossible" << endl;
  else cout << ans << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
