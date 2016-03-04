#include<stdio.h>
#define MAX 33000

void input_prime( void );  /* 素数を Prime[MAX] に代入する関数 */
void put_1( int * );
int pair_count( int );     /*  n = 素数 + 素数 の数をカウント  */

int primes[MAX]; 
int Prime[MAX];

main()
{

  int n,answer;

  input_prime();

  while(1){

    scanf("%d",&n);
    if(n==0) break;
    
    answer = pair_count(n); 

    printf("%d\n",answer);
  }

}

void input_prime( void ){

  int i,j,num_prime=0;

  put_1(primes);

  for(i=2;i*i<MAX;i++){       
    if(primes[i]==1) for(j=i*2;j<MAX;j+=i) primes[j] = 0;      
  }

  /* for(i=0;i<MAX;i++) printf("%d ",primes[i]);
     printf("\n"); */

  for(i=2;i<MAX;i++){
    if( primes[i]==1 ){
      Prime[num_prime] = i;
      num_prime++;
    }
  }
  
  /* for(i=0;i<MAX;i++) printf("%d ",Prime[i]);
     printf("\n"); */

  return;
}      
	 
void put_1( int x[MAX] ){
  
  int i;

  for(i=0;i<MAX;i++) x[i] = 1;

  return;
}

int pair_count( int n ){

  int i,j,counter=0; /* counter は素数の組合わせの数 */ 

  for(i=0;Prime[i];i++){
    for(j=i;Prime[j];j++){
      if(Prime[i] + Prime[j] > n ) break;
      if(Prime[i] + Prime[j] == n ){
	/* printf("%d + %d = %d\n",Prime[i],Prime[j],n); */
	counter++;
	break;
      }
    }
  }

  return counter;
}
