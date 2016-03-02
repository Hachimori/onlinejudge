#include<iostream>
#include<stdio.h>
#include<string>
#include<assert.h>

#define PARENTHESIS -1

class Info_Matrix{
 public:

  int row,column;

  Info_Matrix(){}

  Info_Matrix(int r, int c){
    row = r, column = c;
  }

};

int length;
int total_multiple;
bool visited[10000];
Info_Matrix list[200];
Info_Matrix operation[10000];

void relax(int pos, int row, int column){
  
  operation[pos-1] = Info_Matrix(row,column);

  for(int i=pos;i+3<length;i++)
    operation[i] = operation[i+3];

  length-=3;
}

bool Search(){

  while(true){
    if(length==1) return true;

    for(int i=0;i<length-1;i++){
      if(operation[i].row!=PARENTHESIS && operation[i+1].row!=PARENTHESIS){
	
	if(operation[i].column!=operation[i+1].row){
	  return false;
	}
	else{
	  total_multiple += operation[i].column * operation[i].row * operation[i+1].column;

	  relax(i,operation[i].row,operation[i+1].column);

	}

      }
    }
    
  }

}

class Solver{

 public:
  
  void read_matrix(){
    int num_matrix;
    char letter[4];

    cin >> num_matrix;

    for(int i=0;i<num_matrix;i++){
      cin >> letter;
      
      cin >> list[letter[0]].row >> list[letter[0]].column;
    }
  
  }

  bool read_query(){

    char c;

    if(cin.eof()) return false;

    for(int i=0;;i++){
      if(scanf("%c",&c)==EOF) return false;
      if(c=='\n'){ 
	length = i;
	break;
      }
      else if(c=='(' || c==')') operation[i]=Info_Matrix(PARENTHESIS,PARENTHESIS);
      else if(c>='A' && c<='Z') operation[i]=list[c];
      else assert(0);
    }

    return true;
  }


  void work(){

    bool judge;

    total_multiple=0;

    judge = Search();

    if(judge==false) cout << "error" << endl;
    else cout << total_multiple << endl;

  }

};

main(){

  string str;
  Solver solver;

  solver.read_matrix();

  getline(cin,str);

  while(true){
    if(solver.read_query()==false) break;
    solver.work();
  }
  
}
