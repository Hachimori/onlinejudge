#include<iostream>
#include<stdio.h>

long long num_switch;
int counter;

class Solver{
 public:
  
  bool read(){
    scanf("%lld",&num_switch);
    if(num_switch==0) return false;
    return true;
  }

  void work(){

    counter=0;

    for(long long i=1;i*i<=num_switch;i++){
      if(i*i!=num_switch && num_switch%i==0){
	counter+=2;
      }
      else if(i*i==num_switch && num_switch%i==0){
	counter++;
      }
    }
    
    if(counter%2==0) printf("no\n");
    else printf("yes\n");

  }
  
};

main(){
  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }
  
}
