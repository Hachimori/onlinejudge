#include<iostream>

#define MAX 50

int num_digit1;
int num_digit2;
int two_dicimal1[MAX];
int two_dicimal2[MAX];

class Solver{
 public:

  bool read(){
    
    unsigned long long a;
    unsigned long long b;

    if( !(cin >> a >> b) ) return false;


    for(int i=0;i<MAX;i++){
      two_dicimal1[i] = 0;
      two_dicimal2[i] = 0;
    }

    for(num_digit1=0;a!=0;num_digit1++,a/=2){
      if(a%2==0) two_dicimal1[num_digit1]=0;
      else two_dicimal1[num_digit1]=1;
    }
    for(num_digit2=0;b!=0;num_digit2++,b/=2){
      if(b%2==0) two_dicimal2[num_digit2]=0;
      else two_dicimal2[num_digit2]=1;
    }

    return true;
  }

  void work(){
    
    int added_array[MAX];
    int limit;
    

    if(num_digit1>num_digit2) limit = num_digit1;
    else limit = num_digit2;
    /*
    for(int i=0;i<3;i++)
      cout << two_dicimal1[i] <<' ';
    cout << endl;
    */
    for(int counter=0;counter<limit;counter++){
      if((two_dicimal1[counter]+two_dicimal2[counter])%2==0) added_array[counter]=0;
      else added_array[counter]=1;
    }
    /*
    for(int i=0;i<5;i++)
      cout << added_array[i] << ' ';
    cout << endl;
    */
    unsigned long long answer=0;

    
    for(int counter=0,k=1;counter<limit;k*=2,counter++){
      if(added_array[counter]%2==0) continue;
      else answer+=k;
    }
    

    cout << answer << endl;
  }

};

int main(){

  Solver solver;
  
  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
