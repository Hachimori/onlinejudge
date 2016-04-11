#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<string>

#define MAX 1002000

int judge[MAX];
int pos_digit_prime[MAX];
int prime[MAX];
int prime_list[700000];

int a,b;

void make_primes(){

  int limit;
  int sum;

  for(int i=0;i<MAX;i++) prime[i]=1;

  for(int i=2;i*i<MAX;i++)
    for(int j=i*2;j<MAX;j+=i)
      prime[j]=0;
  
  for(int i=2,n=0;i<MAX;i++){
    if(prime[i]==1){
      prime_list[n] = i;
      n++;
      limit = n;
    }
  }

  for(int i=0,n=1;i<=limit;i++){
    sum=0;
    if(prime_list[i]>0){
      for(int j=prime_list[i];j>0;j/=10){
	int tmp = j%10;
	sum+=tmp;
      }
      if(prime[sum]==1){
	pos_digit_prime[prime_list[i]]=n;
	judge[n]=prime_list[i];
	n++;
      }

    }
  }
  
}

class Solver{

 public:

  void read(){

     scanf("%d%d",&a,&b);

  }

  void work(){

    int sum=0;
    int pos_first_prime=INT_MAX;

    for(int i=a;i<=b;i++){
      if(pos_digit_prime[i]>0 && prime[i]==1 && judge[pos_digit_prime[i]]>0){
	pos_first_prime=pos_digit_prime[i];
	break;
      }
    }

    if(pos_first_prime==INT_MAX){ printf("0\n"); return; }

    for(int i=pos_first_prime;judge[i]<=b;i++){
      sum++;
      //cout << judge[i] << endl;
    }
    
    printf("%d\n",sum);
    
  }

};

main(){
  
  int cases;
  Solver solver;

  make_primes();

  /*
  for(int i=1;i<50;i++){
    if(judge[i]==1)
    printf("%d : %d\n",i,prime_list[i]);
  }
  */
  /*
    for(int i=1;i<50;i++){
    printf("%d : %d\n",i,judge[i]);
  }
  */

  scanf("%d",&cases);

  for(int i=0;i<cases;i++){
    solver.read();
    solver.work();
  }

}

