#include<stdio.h>
#define MAX 5000
#define EoF -1

void Make_list(void);
int Input_Output(void);

long long list[MAX+1];

main()
{

  list[0]=0;
  list[1]=1;

  Make_list();

  while(1){
    
    if(Input_Output()==EoF) break;

  }

}

void Make_list(void){

  int i;

  for(i=2;i<=MAX;i++){

    list[i]=list[i-1]+list[i-2];

  }

  return;

}

int Input_Output(void){

  int N;

  if(scanf("%d",&N)==EOF) return EoF;

  printf("The Fibonacci number for %d is %lld\n",N,list[N]);

  return 1;

}

		       
