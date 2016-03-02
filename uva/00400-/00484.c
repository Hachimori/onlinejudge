#include<stdio.h>
#define MAX 100000

void put0(void);
void Num_search( void );
void Output( void );

int num[MAX],num_num[MAX],num_apparence[MAX];
int num_max,kazu=0;

main()
{

  int i;

  put0();

  for(i=0;;i++) if(scanf("%d",&num[i]) == EOF) break;

  num_max=i;

  Num_search();
  Output();

}

void put0( void ){

  int i;

  for(i=0;i<MAX;i++) num_apparence[i] = 0;

  return;

}

void Num_search( void ){

  int i,j,check=0;

  for(i=0;i<num_max;i++){

    for(j=0;j<kazu;j++){
      if(num[i] == num_num[j]){
	check=1;
	num_apparence[j]++;
	break;
      }
    }

    if(check==1) check=0;
    else{
      num_num[kazu] = num[i];
      num_apparence[kazu]++;
      kazu++;
    }

  }
      
  return;
}

void Output( void ){

  int i;

  for(i=0;i<kazu;i++) printf("%d %d\n",num_num[i],num_apparence[i]);

  return;
}
