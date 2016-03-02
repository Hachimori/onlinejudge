#include<stdio.h>

int Input(void);

char c;

main()
{

  while(1){
    if(Input()==0) break;
    
  }

}

int Input(void){

  if(scanf("%c",&c)==EOF){  return 0; }
  if(c=='\n'){ printf("\n"); return 1; }
 
  printf("%c",c-7);

  return 1;

}
