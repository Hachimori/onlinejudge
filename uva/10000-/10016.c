#include<stdio.h>
#define MAX_C 5
#define MAX_N 100

int Input_matrix( void );  /* 行列から,リングの数を返す */ 
void Operation( int );     /* リングの数の分,行列に対し操作をする */ 
void Move_1(int,int);      /*  Move_1(a,b) は,                     */
void Move_2(int,int);      /*  a 個のリングのうち, b番目のリングに */
void Move_3(int,int);      /*  操作を加えるということ              */
void Move_4(int,int);      /*                                      */
void Output( void );

int N,T;
int array[MAX_N][MAX_N];

main(){

  int M,num_ring;

  scanf("%d",&M);

  for(;M>0;M--){

    num_ring=Input_matrix();
    Operation(num_ring);
    
    /* printf("%d\n",num_ring); */

    Output();

  }

}

int Input_matrix( void ){

  int i,j;

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&array[i][j]);
    }
  }

  return (N+1)/2;

}
  
void Operation( int T ){

  int i,j,num_operation,C;

  for(i=0;i<T;i++){
    
    scanf("%d",&num_operation);
    
    for(j=0;j<num_operation;j++){
      scanf("%d",&C);
      if(C==1) Move_1(N,i+1);
      else if(C==2) Move_2(N,i+1);
      else if(C==3) Move_3(N,i+1);
      else if(C==4) Move_4(N,i+1);
    }

  }

  return;

}

void Move_1(int Rings, int where){

  int i,j,tmp;

   /* printf("where = %d  Rings = %d\n",where,Rings); */

  for(i=where-1;i<Rings/2;i++){
    for(j=where-1;j<Rings-where+1;j++){
      
      if(i==where-1 || j==where-1 || i == Rings-where || j == Rings-where){  /* リングの外であったらやり直し */
      
      tmp = array[i][j];
      array[i][j] =  array[Rings-1-i][j];
      array[Rings-1-i][j] = tmp;
    
      }
      
    }
  }

  return;

}

void Move_2(int Rings, int where){

  int i,j,tmp;

  for(i=where-1;i<Rings-where+1;i++){
    for(j=where-1;j<Rings/2;j++){

      if(i==where-1 || j==where-1 || i == Rings-where || j == Rings-where){  /* リングの外であったらやり直し */
      
      tmp = array[i][j];
      array[i][j] =  array[i][Rings-1-j];
      array[i][Rings-1-j] = tmp;
    
      }
      
    }
  }

  return;

}

void Move_3(int Rings, int where){

  int i,j,tmp;

  for(i=where-1;i<Rings-where+1;i++){
    for(j=i+1;j<Rings-where+1;j++){
      
      if(i==where-1 || j==where-1 || i == Rings-where || j == Rings-where){  /* リングの外であったらやり直し */
      
      tmp = array[i][j];
      array[i][j] =  array[j][i];
      array[j][i] = tmp;
    
      }
      
    }
  }

  return;

}

void Move_4(int Rings, int where){

    int i,j,tmp;

  for(i=where-1;i<Rings-where+1;i++){
    for(j=where-1;j<Rings-1-i;j++){
      
      if(i==where-1 || j==where-1 || i == Rings-where || j == Rings-where){  /* リングの外であったらやり直し */
      
      tmp = array[i][j];
      array[i][j] =  array[Rings-1-j][Rings-1-i];
      array[Rings-1-j][Rings-1-i] = tmp;
    
      }
      
    }
  }

  return;

}

void Output( void ){

  int i,j;

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(j==N-1){ printf("%d",array[i][j]); break;}
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }

  return;

}
