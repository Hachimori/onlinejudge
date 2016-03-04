#include<iostream>
#include<algorithm>

#define MAX 23

int list[MAX],ans_list[MAX];
int max_ans,num_ans;
int target,num_truck;

void store_answer(int num_selected, int arg, int curr_sum, int selected_list[MAX]){
  
  if(max_ans<curr_sum+list[arg]){
    
    for(int i=0;i<num_selected;i++)
      ans_list[i] = selected_list[i];
    
    ans_list[num_selected] = list[arg];
    max_ans = curr_sum+list[arg];
    num_ans = num_selected+1;
    
  }

}

void work_rec(int num_selected, int arg, int curr_sum, int selected_list[MAX]){
  
  if(arg==num_truck) return;

  if(list[arg]+curr_sum<target){
    
    store_answer(num_selected,arg,curr_sum,selected_list);
    
    int backup[MAX];
    for(int i=0;i<num_selected;i++)
      backup[i] = selected_list[i];
    backup[num_selected] = list[arg];
    
    work_rec(num_selected+1,arg+1,curr_sum+list[arg],backup);
    
  }
  else if(list[arg]+curr_sum==target){
    store_answer(num_selected,arg,curr_sum,selected_list);
  }

  if(max_ans==target) return;

  work_rec(num_selected,arg+1,curr_sum,selected_list);

}

class Solver{
 public:
  
  bool read(){
    
    cin >> target >> num_truck;
    if(cin.eof()) return false;
    
    for(int i=0;i<num_truck;i++){
      cin >> list[i];
    }

    return true;
  }

  void work(){

    int selected_list[MAX];
    
    max_ans = 0;
    
    work_rec(0,0,0,selected_list);

    for(int i=0;i<num_ans;i++){
      cout << ans_list[i] << ' ';
    }
    cout << "sum:" << max_ans << endl;

  }

};

main(){

  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
