#include<iostream>

#define MAX 2147483648

int lower,upper;
bool prime[MAX];

class Solver{
 public:
  bool read(){

    cin >> lower >> upper;
    if(cin.eof()) return false;

    return true;
    
  }

  void work(){
    cout << " ok" << endl;
  }


};

main(){

  Solver solver;

  while(true){

    if(solver.read()==false) break;
    solver.work();

  }


}
