#include<stdio.h>
#define MAX 10000

void Input_Output(void);

main()
{

  Input_Output();

}

void Input_Output(void){

  int i,order[MAX],num;
  char new_order[MAX][20];
  char c;

  for(num=0;;num++){
    scanf("%d",&order[num]);
    scanf("%c",&c);
    if(c=='\n') break;
  }

  for(i=0;i<=num;i++)
    scanf("%s",new_order[order[i]]);

  for(i=1;i<=num+1;i++)
    printf("%s\n",new_order[i]);

  return;
}
