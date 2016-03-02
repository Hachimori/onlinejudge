#include<stdio.h>

#define MAX_row 10000
#define MAX_column 26

void Put0(void);
int Input(void);
void Search(void);
void Output(void);

int num_space[MAX_row];
int num_void,sum_space,min_space,N;
char array[MAX_row][MAX_column];

main()
{

  while(1){
    Put0();
    if(Input()==0) break;
    Search();
    Output();

  }

}

void Put0(void){

  int i;
  
  for(i=0;i<MAX_row;i++) num_space[i]=0;
  sum_space=0;
  min_space=MAX_column;

  return;

}

int Input(void){

  int i,j;
  char tmp;

  scanf("%d",&N);
  if(N==0) return 0;

 while(1){
    scanf("%c",&tmp); if(tmp=='\n') break;
  }

  for(i=0;i<N;i++){
    for(j=0;j<MAX_column;j++){
      scanf("%c",&array[i][j]);
      if(array[i][j]==' ') num_space[i]++;
      else if(array[i][j]=='\n') break;
    }
    if(min_space>num_space[i]) min_space = num_space[i];
    sum_space+=num_space[i];
    
  }

  return 1;

}

void Search(void){

  int i;

  for(i=0;i<min_space;i++) sum_space-=N;

  return;

}

void Output(void){

  printf("%d\n",sum_space);

  return;

}
