#include<iostream>
#include<string>
#include<algorithm>

#define MAX 30000
#define WALL -1

char solution[MAX];
char list_solution[MAX][MAX];
int num_list;
string input,target;

void Search_rec(int arg_input, int curr_queue_front, int arg_target, int arg_solution, char queue[MAX]){

  if(arg_solution==input.length()*2){
    list_solution[num_list] = solution;
    num_list++;
    return;
  }

  if(arg_input<input.length()){
    char tmp_queue[MAX];
    solution[arg_solution]='i';

    for(int i=0;i<curr_queue_front;i++) tmp_queue[i] = queue[i];
    tmp_queue[curr_queue_front] = input[arg_input];

    Search_rec(arg_input+1,curr_queue_front+1,arg_target,arg_solution+1,tmp_queue);
    
  }


  if(curr_queue_front>0 && queue[curr_queue_front-1]==target[arg_target]){    
    solution[arg_solution]='o';
    

    Search_rec(arg_input,curr_queue_front-1,arg_target+1,arg_solution+1,queue);
  }

  return;

}

bool word_check(){
  
  if(input.length()!=target.length()) return false;
  else{

    string a = input;
    string b = target;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<input.length();i++) 
      if(a[i]!=b[i]) return false; 

  }

  return true;

}

class Solver{
 public:

  bool read(){
    getline(cin,input);
    getline(cin,target);

    if(cin.eof()) return false;

    return true;
  }

  void work(){

    char queue[MAX];
    num_list=0;
    for(int i=0;i<input.length()+1;i++) queue[i] = WALL;

    if(word_check()==true) Search_rec(0,0,0,0,queue);
    else {
      cout << '[' << endl << ']' << endl;
      return;
    }

    cout << '[' << endl;
    for(int i=0;i<num_list;i++){      
      for(int j=0;j<input.length()*2;j++){
	if(j==0) cout << list_solution[i][j];
	else cout << ' ' << list_solution[i][j];
      }cout << endl;
    }
    cout << ']' << endl;  
    
  }

};

main(){

  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
