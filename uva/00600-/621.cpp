#include<iostream>
#include<stdio.h>

#define MAX 200000

char str[MAX];

class Solver{
 public:

  void read(){
    scanf("%s",str);
  }
	
  void work(){
    if(strcmp(str,"1")==0 || strcmp(str,"4")==0 || strcmp(str,"78")==0){
      cout << "+" << endl;
    }
    else if(str[strlen(str)-1]=='5' && str[strlen(str)-2]=='3'){
      cout << "-" << endl;
    }
    else if(str[0]=='9' && str[strlen(str)-1]=='4'){
      cout << "*" << endl;
    }
    else if(str[0]=='1' && str[1]=='9' && str[2]=='0'){
      cout << "?" << endl;
    }

  }

};


main(){
  
  int cases;
  Solver solver;

  cin >> cases;

  for(int i=0;i<cases;i++){
    solver.read();
    solver.work();
  }
  
}
