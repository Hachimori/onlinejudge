#include<iostream>
#include<stdio.h>

#define MAX 1000001

class Info{
 public:
  int y;
  double z;

};

int n;
Info data[MAX];

class Solver{
 public:

  void make_data(){

    int counter=0;
    double ans=1.0;

    for(int i=1;i<=MAX;i++){
      
      ans/=2;
      if(ans<1.00000){ 
	ans*=10;
	counter++;
      }
      
      data[i].y = counter;
      data[i].z = ans;

    }
    
  }

  bool read(){
    if(scanf("%d",&n)==EOF) return false;

    return true;
  }


  void work(){

    printf("2^-%d = %.3lfe-%d\n",n,data[n].z,data[n].y);

  }


};

main(){

  Solver solver;

  solver.make_data();

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
