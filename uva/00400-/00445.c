#include<stdio.h>
#include<stdlib.h>

#define EoF -1
#define CONTINUE 1

int Input_Output(void);

main()
{

  while(1){

    if(Input_Output()==EoF) break;

  }

}

int Input_Output(void){

  int i;
  static int sum=0;
  char c;

  if(scanf("%c",&c)==EOF) return EoF;

  if(c>='0' && c<='9'){
    
    sum+=atoi(&c);

  }
  else if(c=='\n' || c=='!') printf("\n");
  else if(c=='b'){
    for(i=0;i<sum;i++)
      printf(" ");
    sum=0;
  }
  else if(c==' '){}
  else{
    for(i=0;i<sum;i++)
      printf("%c",c);
    sum=0;
  }

  return CONTINUE;

}
