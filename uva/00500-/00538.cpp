#include<iostream>
#include<string>
#include<map>

#define MAX 23

class Operation{
 public:

  int source, target, cost;

  Operation(){}

  Operation(int s, int t, int c){
    source = s, target = t, cost = c;
  }

};

Operation list[MAX];
int cases;
int num_people, num_connection;
int curr_money[MAX];
map<string,int> name_list;
map<int,string> num_list;

bool check_money(){
  
  for(int i=0;i<num_people;i++){
    if(curr_money[i]!=0) return false;
  }

  return true;
}

class Solver{
 public:

  void init(){
    num_list.clear();
    name_list.clear();
  }

  bool read(){
    
    cin >> num_people >> num_connection;
    if(num_people==0 && num_connection==0) return false;

    for(int i=0;i<num_people;i++) 
      curr_money[i]=0;

    for(int i=0;i<num_people;i++){
      string name;
      cin >> name;

      name_list[name] = i;
      num_list[i] = name;
    }

    for(int i=0;i<num_connection;i++){
      int cost;
      string source,target;
      
      cin >> source >> target >> cost;
      
      curr_money[name_list[source]]-=cost;
      curr_money[name_list[target]]+=cost;
    }


    return true;

  }

  void work(){
    
    int num_operation=0;

    if(check_money()==false){
      
      for(int i=1;i<num_people;i++){
	if(curr_money[i]!=0){
	  if(curr_money[i]<0){
	    list[num_operation] = Operation(0,i,curr_money[i]*(-1));
	    num_operation++;
	  }
	  else if(curr_money[i]>0){
	    list[num_operation] = Operation(i,0,curr_money[i]);
	    num_operation++;
	  }
	 
	}
      }

    }

    cout << "Case #" << cases << endl;
    for(int i=0;i<num_operation;i++){
      cout << num_list[list[i].source] << " " << num_list[list[i].target] << " " << list[i].cost << endl;
    }
    cout << endl;
    
  }
  
};

main(){
  
  Solver solver;
  
  for(cases=1;;cases++){
    solver.init();
    if(solver.read()==false) break;
    solver.work();
  }

}
