#include<stdio.h>
#include<string.h>

#define MAX 10

typedef struct{

  double x1,y1,x2,y2;

}Rectangle;


void Input_Output(void);
int chk_rectangle(double,double,int,int,Rectangle *);

main()
{

  Input_Output();

}

void Input_Output(void){

  int i,num_rectangle=0,num_figure;
  double tmp_x,tmp_y;
  char tmp[2];
  Rectangle rectangles[MAX];

  while(1){

    scanf("%s",&tmp);
    /* printf("%s\n",tmp); */
    if(strcmp(tmp,"*")==0) break;
    else if(strcmp(tmp,"r")==0){
      
      scanf("%lf%lf%lf%lf",&rectangles[num_rectangle].x1,
	                    &rectangles[num_rectangle].y1,
	                     &rectangles[num_rectangle].x2,
	                      &rectangles[num_rectangle].y2);
      num_rectangle++;

    }

  }

  
  for(i=1;;i++){

    scanf("%lf%lf",&tmp_x,&tmp_y);

    if( tmp_x==9999.9 && tmp_y==9999.9 ) break;
 
    num_figure = chk_rectangle(tmp_x,tmp_y,i,num_rectangle,rectangles);

    if(num_figure==0) printf("Point %d is not contained in any figure\n",i);

  }

  return;

}

int chk_rectangle(double x,double y,int point,int num,Rectangle rectangle[]){

  int i,num_figure=0;

  for(i=0;i<num;i++)
    if( rectangle[i].x1< x && x<rectangle[i].x2 &&
	rectangle[i].y2< y && y<rectangle[i].y1 ){
      num_figure++;
      printf("Point %d is contained in figure %d\n",point,i+1);
    }      

  return num_figure;

}
