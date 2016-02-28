#include<iostream>
#include<climits>
#include<algorithm>

#define MAX_SIZE 102

using namespace std;

int size;
int board[MAX_SIZE][MAX_SIZE];
int bestState[MAX_SIZE][MAX_SIZE][MAX_SIZE];

bool read(){

  if(!(cin >> size)) return false;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cin >> board[i][j];  
 
  return true;
}

void work(){
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      for(int k=0;k<size;k++)
	bestState[i][j][k] = 0;

  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
     
      int sum=0;
      for(int k=j;k>=0;k--){
	sum+=board[i][k];
	
	if(i>0)
	  bestState[i][j][j-k] = max(sum,sum+bestState[i-1][j][j-k]);	
	else
	  bestState[i][j][j-k]=sum;
	
      }
      
    }
  }
  

  int maxVal=INT_MIN;
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      for(int k=0;k<=j;k++)
	maxVal = max(bestState[i][j][k],maxVal);

  cout << maxVal << endl;
  
  
}

int main(){

  while(read())
    work();

  return 0;
}
