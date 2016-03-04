#include<stdio.h>
#define MAX 7490

void Make_list( void );
void put0( void );

int array[6][MAX];

main()
{

  int n,i,j;

  put0();
  Make_list();
  
  /*
  for(i=0;i<6;i++){
    for(j=0;j<27;j++){
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  */

  while( scanf("%d",&n) != EOF){
    
    printf("%d\n",array[5][n]);
    
  }
 
}

void put0( void ){

  int i,j;
  
  for(i=0;i<6;i++){
    for(j=0;j<MAX;j++){
      array[i][j] = 0;
    }
  }

  return;

}

void Make_list( void ){

  int i,j;

  for(i=0;i<MAX;i++) array[1][i] = 1;
  
  for(i=0;i<MAX;i++){
    for(j=0;i-j>=0;j+=5){
      array[2][i]+=array[1][i-j];
    }
  }

  for(i=0;i<MAX;i++){
    for(j=0;i-j>=0;j+=10){
      array[3][i]+=array[2][i-j];
    }
  }
  
  for(i=0;i<MAX;i++){
    for(j=0;i-j>=0;j+=25){
      array[4][i]+=array[3][i-j];
    }
  }
  
  for(i=0;i<MAX;i++){
    for(j=0;i-j>=0;j+=50){
      array[5][i]+=array[4][i-j];
    }
  } 

  return;

}
