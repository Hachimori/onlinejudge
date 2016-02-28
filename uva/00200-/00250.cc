#include<iostream>
#include<cfloat>
#include<climits>

#define MAX_SIZE 30
#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)-(y)>=EPS)
#define LT(x,y) ((x)-(y)<=-EPS)

using namespace std;

int row, column;
double table[MAX_SIZE][MAX_SIZE];

bool read(){
  cin >> row >> column;
  if(row==0 && column==0) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      cin >> table[i][j];
  
  return true;
}

void work(int cases){
  
  int minR=0, minC=0;
  double minVal=INT_MAX;
    
  for(int j=0;j<column;j++){
    for(int i=0;i<row;i++){
      
      double uRow=0, dRow=0, lCol=0, rCol=0;
      
      for(int r=0;r<i;r++)
	for(int c=0;c<column;c++)
	  uRow += table[r][c];
	  
      for(int r=i+1;r<row;r++)
	for(int c=0;c<column;c++)
	  dRow += table[r][c];

      for(int r=0;r<row;r++)
	for(int c=0;c<j;c++)
	  lCol += table[r][c];

      for(int r=0;r<row;r++)
	for(int c=j+1;c<column;c++)
	  rCol += table[r][c];
     
      if( GT(minVal,fabs(uRow-dRow)+fabs(lCol-rCol)) ){
	minR = i;
	minC = j;
	minVal = fabs(uRow-dRow)+fabs(lCol-rCol);
      }
      else if(EQ(minVal,fabs(uRow-dRow)+fabs(lCol-rCol))){
	minR = i;
	minC = j;
	minVal = fabs(uRow-dRow)+fabs(lCol-rCol);
      }
    }
  }
 
  cout << "Case " << cases << ": center at "
       << "(" << minR+1 << ", " << minC+1 << ')' << endl;

}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
