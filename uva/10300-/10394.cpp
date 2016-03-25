#include<stdio.h>
#include<iostream>

#define MAX 20000000

int S;

bool prime[MAX];

void make_prime(){
  
  for(int i=0;i<MAX;i++) prime[i]=true;


  for(int i=3;i<MAX;i+=2){
    if(prime[i])
      for(int j=i*2;j<MAX;j+=i){
	prime[j]=false;
      }
  }

}

class Solver{
 public:

  bool read(){

    if(scanf("%d",&S)==EOF) return false;

    return true;
  }

  void work(){
    if(prime[S]==false) cout << "NO" << endl;
    else if(prime[S]==true) cout << "YES" << endl;
  }

};

main(){

  Solver solver;

  make_prime();

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
