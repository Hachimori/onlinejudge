#include<stdio.h>
#define MAX 100

int Count( int, int, int [MAX][MAX]);   
/* ビットを換える必要がないならば０を返す   */ 
/* ビットを換えることができるならば１を返す */ 
/* ビットを換えて修復不可能ならば２を返す   */

int x,y,n;

main()
{
  
  int i,j,array[MAX][MAX],num_changeable=0,tmp,check_corrupt=0;
  
  
  while(1){

    /* 変数の初期化 */
    num_changeable = 0;
    check_corrupt = 0;
    

    /* Input n=0 ならば入力終了 */
    scanf("%d",&n);
    if(n==0) break;

    /* 行列の入力 */
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf("%d",&array[i][j]);
      }
    }

    /* 行列を調べる */
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	tmp = Count(i,j,array);
	/* printf("n = %d , tmp = %d , i = %d , x = %d , y = %d\n",n,tmp,i,x,y); */
	if(tmp == 1) num_changeable++;
	else if( tmp == 2 ) check_corrupt = 1;
      }
    }

    /* Output */
    if(check_corrupt == 0 && num_changeable==0) printf("OK\n");
    else if(check_corrupt == 1 && num_changeable==1) printf("Change bit (%d,%d)\n",y,x);
    else printf("Corrupt\n");
    /* else if(num_changeable >1) printf("Corrupt\n"); */
  }

}

int Count( int tate, int yoko, int array[MAX][MAX]){
  
  int i,j,sum=0,sum2=0;
  
  for(j=0;j<n;j++){  /* 一つの列の合計を調べる */
    sum+=array[tate][j];
    /* printf("array[%d][%d]=%d\n",num,j,array[num][j]); */
  }

  for(i=0;i<n;i++){  /* 一つの行の合計を調べる */
    sum2+=array[i][n-yoko-1];
    /* printf("array[%d][%d]=%d\n",i,n-num-1,sum2+=array[i][n-num-1]); */
  }

  if(sum%2 == 1 && sum2%2 == 1){
    y=tate+1;
    x=n-yoko;
    return 1;
  }
  else if(sum%2 == 0 && sum2%2 == 1 || sum%2 == 1 && sum2%2 == 0) return 2;
  else return 0; 

}
