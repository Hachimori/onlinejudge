#include<stdio.h>

#define MAX_SIZE 105

int main(){
  int i, j, r, c, limR, limC;
  int row, column, succeed, ans;
  int board[MAX_SIZE][MAX_SIZE];
  
  while(1){
    scanf("%d%d",&row,&column);
    if(row==0 && column==0) break;
    
    for(i=0;i<row;i++)
      for(j=0;j<column;j++)
	scanf("%d",&board[i][j]);
    
    ans = 0;
    
    for(r=0;r<row;r++)
      for(c=0;c<column;c++)
	for(limR=r;limR<row;limR++)
	  for(limC=c;limC<column;limC++){
	    
	    succeed = 1;
	    for(i=r;i<=limR;i++)
	      for(j=c;j<=limC;j++)
		if(board[i][j]==1){
		  succeed = 0;
		  goto _finish;
		}
	    
	  _finish:
	    if(succeed && ans<(limR-r+1)*(limC-c+1))
	      ans = (limR-r+1)*(limC-c+1);
	  }
	
    printf("%d\n",ans);
  }
  
  return 0;
}
