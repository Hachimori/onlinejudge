#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
#define MAX_array 9

typedef struct{

  int x,y;

}X_Y;

int Input(void);
int My_atoi(char);
void Put0(int [][]);
int Search(void);
void Output(int);

char a[3],b[3];

main()
{

  int m;

  a[2]='\0';
  b[2]='\0';

  while(1){

    if(Input()==0) break;
    m=Search();
    Output(m);

  }

}
  
int Input(void){

  if(scanf("%s%s",a,b)==EOF) return 0;

  return 1;

}

int My_atoi(char c)
{

  if(c=='1') return 1;
  if(c=='2') return 2;
  if(c=='3') return 3;
  if(c=='4') return 4;  
  if(c=='5') return 5;
  if(c=='6') return 6;
  if(c=='7') return 7;
  if(c=='8') return 8;
  if(c=='a') return 1;
  if(c=='b') return 2;
  if(c=='c') return 3;
  if(c=='d') return 4;
  if(c=='e') return 5;
  if(c=='f') return 6;
  if(c=='g') return 7;
  if(c=='h') return 8;

  printf("c=%c",c);
  
  printf("error\n");
  exit(0);   

}

int Search(void){

  int i,j,k,l;
  int a_x,a_y,b_x,b_y,num=0;
  X_Y history[MAX];
  int array[MAX_array][MAX_array];
   
  int move_x[MAX_array-1]={1,2,2,1,-1,-2,-2,-1};
  int move_y[MAX_array-1]={2,1,-1,-2,-2,-1,1,2};

  Put0(array);

  a_x=My_atoi(a[0]);
  a_y=My_atoi(a[1]);
  b_x=My_atoi(b[0]);
  b_y=My_atoi(b[1]);

  if(a_x==b_x && a_y==b_y) return 0;
  
  history[num].x = a_x;
  history[num].y = a_y;
  num++;
  array[a_y][a_x]=1;
  array[b_y][b_x]=1000;
  
  for(i=0;i<MAX;i++){
    for(j=0;j<MAX_array-1;j++){

      if( 0<history[i].y+move_y[j] && history[i].y+move_y[j]<MAX_array &&
	  0<history[i].x+move_x[j] && history[i].x+move_x[j]<MAX_array &&
	  array[history[i].y+move_y[j]][history[i].x+move_x[j]] == 0 ){
	
	history[num].x = history[i].x+move_x[j];  
	history[num].y = history[i].y+move_y[j];

	num++;
	
	array[history[i].y+move_y[j]][history[i].x+move_x[j]] 
	  = array[history[i].y][history[i].x]+1;
	
      }
      else if( 0<history[i].y+move_y[j] && history[i].y+move_y[j]<MAX_array &&
	       0<history[i].x+move_x[j] && history[i].x+move_x[j]<MAX_array &&
	       array[history[i].y+move_y[j]][history[i].x+move_x[j]]==1000 ){

	return array[history[i].y][history[i].x];

      }

    }

  }

  printf("error\n");
  exit(1);

}

void Put0(int array[MAX_array][MAX_array]){

  int i,j;

  for(i=1;i<MAX_array;i++)
    for(j=1;j<MAX_array;j++)
      array[i][j]=0;

  return;

}
      
void Output(int m){

  printf("To get from %s to %s takes %d knight moves.\n",a,b,m);

  return;

}
