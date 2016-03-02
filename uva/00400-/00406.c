#include<stdio.h>
#define MAX 1001

void Make_prime(void);
int Input(void);
void Search(void);

int prime[MAX],sorted_list[MAX];
int N,C;


main()
{
  
  Make_prime();

  while(1){
    if(Input()==0) break;
    Search();
  }
  
}

void Make_prime(void){

  int i,j;
  
  for(i=0;i<MAX;i++) prime[i]=1;

  prime[0]=0;

  for(i=2;i*i<MAX-1;i++)
    for(j=i+i;j<MAX;j+=i) prime[j]=0;

  for(i=0,j=0;i<MAX;i++)  /* prime[i] が何番目の数字かを代入 */
    if(prime[i]==1){      /* 素数をソートして配列に代入      */
      sorted_list[j] = i; 
      j++;
      prime[i]=j;
    }
 
  /*
  for(i=0;i<j;i++) printf("%4d",sorted_list[i]);
  printf("\n");
  */

  return;
  
}

int Input(void){

  if(scanf("%d%d",&N,&C)==EOF) return 0;

  return 1;

}

void Search(void){

  int i,j,length;

  for(i=N;;i--) if(prime[i]!=0) break;  /* N に最も近い素数を探す */

  length = prime[i];

  if(length%2==0){
    printf("%d %d:",N,C);
    if( C*2 <= length )
      for(i=length - (length + C*2)/2,j=0;j<C*2;i++,j++) printf(" %d",sorted_list[i]);
    else for(i=0;i<length;i++) printf(" %d",sorted_list[i]);
    printf("\n\n");
    return;
  }
  else if(length%2==1){
    printf("%d %d:",N,C); 
    if( C*2-1 <= length )
      for(i=length - (length + C*2-1)/2,j=0;j<C*2-1;i++,j++) printf(" %d",sorted_list[i]);
    else for(i=0;i<length;i++) printf(" %d",sorted_list[i]);
    printf("\n\n");
    return;
  }

}

  
