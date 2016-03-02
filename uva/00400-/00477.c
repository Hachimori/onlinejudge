#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 10

typedef struct{

  int num_figure;
  double x1,y1,x2,y2;
  double r;
  char shape[2];

}Figure;



void Input_Output(void);
int chk_figure(double,double,int,int,Figure *);

main()
{

  Input_Output();

}

void Input_Output(void){

  int i,num_figure=0;
  double tmp_x,tmp_y;
  char tmp[2];
  Figure figures[MAX];

  while(1){

    scanf("%s",&tmp);
    
    if(strcmp(tmp,"*")==0) break;
    else if(strcmp(tmp,"r")==0){
      
      scanf("%lf%lf%lf%lf",&figures[num_figure].x1,
	                    &figures[num_figure].y1,
	                     &figures[num_figure].x2,
	                      &figures[num_figure].y2);

      figures[num_figure].num_figure = num_figure+1;
      strcpy(figures[num_figure].shape,tmp);
      num_figure++;

    }
    else if(strcmp(tmp,"c")==0){
      
      scanf("%lf%lf%lf",&figures[num_figure].x1
	                ,&figures[num_figure].y1,&figures[num_figure].r);

      figures[num_figure].num_figure = num_figure+1;
      strcpy(figures[num_figure].shape,tmp);
      num_figure++;
      
    }   
      
  }

  
  for(i=1;;i++){

    scanf("%lf%lf",&tmp_x,&tmp_y);

    if( tmp_x==9999.9 && tmp_y==9999.9 ) break;

    if(chk_figure(tmp_x,tmp_y,num_figure,i,figures)==0) 
      printf("Point %d is not contained in any figure\n",i);

  }

  return;

}

int chk_figure(double x,double y,int num,int point,Figure figures[]){

  int i,num_figure=0;

  for(i=0;i<num;i++)
    if( strcmp(figures[i].shape,"r")==0 && figures[i].x1< x && 
       x<figures[i].x2 && figures[i].y2< y && y<figures[i].y1 ){
      num_figure++;
      printf("Point %d is contained in figure %d\n",point,i+1);
    }      
    else if( strcmp(figures[i].shape,"c")==0 &&
	     figures[i].r > sqrt( (figures[i].x1 - x)*(figures[i].x1 - x) + (figures[i].y1 - y)*(figures[i].y1 - y) ) ){
      num_figure++;
      printf("Point %d is contained in figure %d\n",point,i+1);
    }

  return num_figure;

}
