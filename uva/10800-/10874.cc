#include<iostream>
#include<algorithm>
#define INF (1<<28)
#define BUF 20005
using namespace std;

int row, range[BUF][2];

bool read(){
  cin >> row;
  if(row==0) return false;

  for(int i=0;i<row;i++)
    cin >> range[i][0] >> range[i][1];
  
  return true;
}

void work(){
  int cost[BUF][2];  //cost[row][LEFT or RIGHT] = minVal;
  
  for(int i=0;i<BUF;i++)
    for(int j=0;j<2;j++)
      cost[i][j] = INF;
  cost[0][1] = range[0][1]-1;
  
  for(int i=0;i+1<row;i++)
    for(int j=0;j<2;j++){
      int col = range[i][j], curCost = cost[i][j];
      
      if(col<=range[i+1][0]){
        int nextCost = curCost+range[i+1][1]-col;
        cost[i+1][1] = min(cost[i+1][1],nextCost);
      }
      else if(range[i+1][0]<col && col<range[i+1][1]){
        int nextCost = curCost+2*abs(range[i+1][0]-col)+range[i+1][1]-col;
        cost[i+1][1] = min(cost[i+1][1],nextCost);

        nextCost = curCost+2*(range[i+1][1]-col)+abs(range[i+1][0]-col);
        cost[i+1][0] = min(cost[i+1][0],nextCost);
      }
      else {
        int nextCost = curCost+abs(range[i+1][0]-col);
        cost[i+1][0] = min(cost[i+1][0],nextCost);
      }
    }
  
  int minV = (1<<30);
  for(int i=0;i<2;i++){
    int col = range[row-1][i], curCost = cost[row-1][i];
    
    if(range[row-1][0]<=col)
      minV = min(minV,curCost+row-col);
    else 
      minV = min(minV,curCost+2*abs(range[row-1][0]-col)+row-col);
  }

  cout << minV+row-1 << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
