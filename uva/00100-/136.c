/* The 1500'th ugly number is 859963392. */

#include<stdio.h>
#define The_Number 1500

void Search(void);
int Ugly_chk(int);
void Output(void); 

int number;

main(){
  
  Search();
  Output();

}

void Search(void){

  int i,num;

  for(i=2,num=1;num!=The_Number;i++){
    if(i%2!=0 &&  i%3!=0 && i%5!=0) continue;
    if(i%7==0) continue;
    if(Ugly_chk(i)==1){
      num++;
      printf("%d\n",i);
    }
  }
  
  number = i-1;

  return;
}

int Ugly_chk(int n){

  while(n%2==0){
    n/=2;
  }

  while(n%3==0){
    n/=3;
  }

  while(n%5==0){
    n/=5;
  }

  if( n==1 ) return 1;
  else return 0;
}

void Output(void){
  
  printf("The %d'th ugly number is %d.\n",The_Number,number);

  return;

}
