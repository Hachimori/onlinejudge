#include<stdio.h>
#define MAX_num 100

void put0(void);
void Make_primelist(void);
void Input(void);
void Output(void);

int N;
int prime[MAX_num];
int list[MAX_num];

main()
{
  
  Make_primelist();
  put0();

  while(1){
    Input();
    if(N==0)break;
    Output();
  }

}

void put0(void){

  int i;

  for(i=0;i<MAX_num;i++) list[i]=0;

  return;

}

void Make_primelist(void){

  int i,j;

  for(i=0;i<MAX_num;i++) prime[i]=1;

  for(i=2;i*i<MAX_num;i++)
    for(j=i*2;j<MAX_num;j+=i)      
      prime[j]=0;

  /*
     for(i=2;i<MAX_num;i++) if(prime[i]==1) printf("%d ",i);
     printf("\n");
     */ 

  return;

}

void Input(void){

  int i,j,tmp;
  
  scanf("%d",&N);

  if(N==0) return;

  for(i=2;i<=N;i++){
    for(j=2;j<MAX_num;j++){

      if(prime[j]==1 && i%j==0){
	tmp = i;
	while(tmp%j==0){
	  tmp/=j;
	  list[j]++;
	}
      }

    }
  }

  return;

}

void Output(void){

  int i,num=0;

  printf("%3d! =",N);

  for(i=0;i<MAX_num;i++) if(list[i]!=0){
    if(num==15) printf("\n      ");
    printf("%3d",list[i]);
    list[i]=0;
    num++;    
  }
  printf("\n");

  return;

}
