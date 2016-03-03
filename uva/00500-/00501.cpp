#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

int add_element,get_element;
int arg,curr_num_element;
vector<int> sorted_elements;
queue<int> elements;
queue<int> gets;

class Solver{

 public:
  
  void init(){
    
    curr_num_element = 0;
    arg = 0;
    sorted_elements.clear();
    
    while(!elements.empty()) elements.pop();
    while(!gets.empty()) gets.pop(); 
    
  }

  void read(){
    
    int t;

    cin >> add_element >> get_element;

    for(int i=0;i<add_element;i++){
      cin >> t;
      elements.push(t);
    }
    
    for(int i=0;i<get_element;i++){
      cin >> t;
      gets.push(t);
    }

  }
  
  void Get(){
    
    sort(sorted_elements.begin(),sorted_elements.end());

    cout << sorted_elements[arg] << endl;
    
    arg++;
    
    return;

  }

  void Add(int n){

    sorted_elements.push_back(n);
    
    curr_num_element++;

  }

  void work(){
    
    while(!gets.empty()){
      // cout << "ok" << endl;
      if(curr_num_element == gets.front() ){
	Get();
	gets.pop(); 
      }
      else{ 
	Add(elements.front());
	elements.pop();
      }

    }
    
    return;

  }

};

main(){
  
  Solver solver;
  int cases;
  
  cin >> cases;

  for(int i=0;i<cases;i++){
    
    if(i!=0) cout << endl;
    
    solver.init();
    solver.read(); 
    solver.work();
    
  }

}
