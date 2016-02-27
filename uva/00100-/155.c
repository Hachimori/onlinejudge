#include<stdio.h>

#define MAX 2048
#define INITIAL 1024
#define EoF -1
#define CONTINUE 1

int Input_Output(void);
void Search(int,int,int,int,int);

int num_square;

main()
{
  while(1){
    num_square=0;
    if(Input_Output()==EoF) break;
  }

}

int Input_Output(void){

  int i,j;
  int k,x,y;

  scanf("%d%d%d",&k,&x,&y);
  if(k==0 && x==0 && y==0) return EoF;

  Search(INITIAL,INITIAL,x,y,k);

  printf("%3d\n",num_square);

  return;

}

void Search(int x_arg, int y_arg, int x, int y, int k){
  
  if( x_arg<=x && x<=x_arg+k  &&  y_arg<=y && y<=y_arg+k  ||
      x_arg<=x && x<=x_arg+k  &&  y_arg-k<=y && y<=y_arg  ||
      x_arg-k<=x && x<=x_arg  &&  y_arg<=y && y<=y_arg+k  ||
      x_arg-k<=x && x<=x_arg  &&  y_arg-k<=y && y<=y_arg ) num_square++;

  if(k==1) return;

  if( x_arg<=x && y_arg<=y && x_arg+k<=MAX && y_arg+k<=MAX ){
    Search(x_arg+k,y_arg+k,x,y,k/2);
  }
  else if( x_arg<=x && y_arg>=y && x_arg+k<=MAX && y_arg-k>=0 ){
    Search(x_arg+k,y_arg-k,x,y,k/2);
  }
  else if( x_arg>=x && y_arg<=y && x_arg-k>=0 && y_arg+k<=MAX ){
    Search(x_arg-k,y_arg+k,x,y,k/2);
  } 
  else if( x_arg>=x && y_arg>=y && x_arg-k>=0 && y_arg-k>=0 ){
    Search(x_arg-k,y_arg-k,x,y,k/2);
  } 

  return;
}
