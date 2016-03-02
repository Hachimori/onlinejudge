#include<stdio.h>
#include<assert.h>
#define MAX 600030

typedef struct{

  int x,y;

}Point;

int gcd( int num1, int num2 )
{

  int remainder = num2 % num1;

  if ( remainder != 0 )
    return gcd( remainder,num1 );

  return num1;
}

int target;
Point list[MAX];

void make_list(){

  int tmp;
  int x,y,counter=3;
  int limit_y,limit_x;

  list[0].y =1;
  list[0].x =1;

  list[1].y =0;
  list[1].x =1;

  list[2].y =-1;
  list[2].x =1;

  for(y=2,x=-1;counter<560000;y=y*(-1)+1,x*=(-1)){

    for(limit_x=x*(-1)+1;x<limit_x;x++){
      if(x==0) continue;
      else if(x<0){
	tmp = gcd(x*(-1),y);
	if(tmp==1){
	  list[counter].y = (-1)*y;
	  list[counter].x = (-1)*x;
	  counter++;
	}
      }
      else if(x>0){
	tmp = gcd(x,y);
	if(tmp==1){
	  list[counter].y = y;
	  list[counter].x = x;
	  counter++;
	}
      }
    }

    for(limit_y=y*(-1);y>limit_y;y--){
      if(y==0) continue;
      else if(y<0){
	tmp = gcd(x,(-1)*y);
	if(tmp==1){
	  list[counter].y = y;
	  list[counter].x = x;
	  counter++;
	}
      }
      else if(y>0){
	tmp = gcd(x,y);
	if(tmp==1){
	  list[counter].y = y;
	  list[counter].x = x;
	  counter++;
	}
      }
    }

  }

}

int input(){

  if(scanf("%d",&target)==EOF) return -1;

  return 1;

}

void work(){

  printf("%d / %dn",list[target].y,list[target].x);

  return;
}

main(){

  make_list();

  while(1){
    if(input()==-1) break;
    work();
  }
}
