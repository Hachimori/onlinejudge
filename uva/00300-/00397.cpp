#include<iostream>
#include<string>
#include<stdio.h>

#define MAX 100

int num_int;
int list_num[MAX];
char list_operator[MAX];
string str;


void relax(int i){
  for(int j=i+1;j<num_int-1;j++) list_num[j] = list_num[j+1];
  for(int j=i;j<num_int-1;j++) list_operator[j] = list_operator[j+1];	
}

void output(){

  for(int i=0;i<num_int;i++){
    cout << list_num[i];
    if(i!=num_int-1)
      cout << list_operator[i];
  }
  
  cout << "=" << str << endl; 

}

class Solver{
 public:

  bool read(){

    bool finished;
    bool minus_flg;
    bool read_int;

    num_int = 0;
    finished = false;

    while(true){
      
      if(finished==true) break;

      minus_flg = false;
      read_int = false;
      list_num[num_int] = 0;

      while(true){
	char c;
	
	if(scanf("%c",&c)==EOF) return false;
	
	if(c=='-' && read_int==false) minus_flg = true;
	else if( (c=='+' || c=='-' || c=='*' || c=='/') && read_int==true){
	  list_operator[num_int] = c;
	  if(minus_flg==true) list_num[num_int]*=(-1);
	  num_int++;
	  break;
	}
	else if(c=='='){
	  if(minus_flg==true) list_num[num_int]*=(-1);
	  num_int++;
	  finished=true;
	  break;
	}
	else if(c>='0' && c<='9'){
	  list_num[num_int]*=10;
	  list_num[num_int]+=c-'0';
	  read_int=true;
	}
      }

    }

    cin >> str;
    
    /*
    while(true){
      char c;
      cin >> c;
      if(c=='\n') break;
    }*/

    return true;

  }

  void work(){
    
    bool multi_div;

    for(;num_int>1;num_int--){
      
      output();

      multi_div = false;
      for(int i=0;i<num_int;i++) 
	if(list_operator[i]=='*' || list_operator[i]=='/'){
	  multi_div = true;
	  break;
	} 

      if(multi_div==true){
	for(int i=0;i<num_int;i++){
	  if(list_operator[i]=='*'){
	    list_num[i] = list_num[i]*list_num[i+1];
	    relax(i);
	    break;
	  }
	  else if(list_operator[i]=='/'){
	    list_num[i] = list_num[i]/list_num[i+1];
	    relax(i);
	    break;
	  }
	}
      }
      else {
	for(int i=0;i<num_int;i++){
	  if(list_operator[i]=='+'){
	    list_num[i] = list_num[i]+list_num[i+1];
	    relax(i);
	    break;
	  }
	  else if(list_operator[i]=='-'){
	    list_num[i] = list_num[i]-list_num[i+1];
	    relax(i);
	    break;
	  }
	}
      }

    }

    output();

  }

};

main(){
  
  Solver solver;

  for(int i=0;;i++){
    
    if(solver.read()==false) break;
    if(i!=0) cout << endl;
    solver.work();

  }


}
