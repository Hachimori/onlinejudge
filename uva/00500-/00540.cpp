#include<iostream>
#include<string>

#define NOT_EXIST -1
#define MAX 1000000

int cases;
int num_team;
int pos_team[1001];
int queue_front[1001];
int queue_tail[1001];
int team[MAX];
int queue[1001][1001];

class Solver {

 public:

  bool read(){

    cin >> num_team;
    if(num_team==0) return false;

    for(int i=0;i<num_team;i++){
      int query;
      cin >> query;
      for(int j=0;j<query;j++){
	int num;
	cin >> num;
	team[num] = i+1;
      }
    }
    
    return true;
  }
  
  void work(){
    
    int curr_queue_front=0,curr_queue_tail=0;
    for(int i=0;i<1001;i++){
      queue_front[i]=0;
      queue_tail[i]=0;
    }
    for(int i=0;i<=num_team;i++) pos_team[i]=NOT_EXIST;

    
    cout << "Scenario #" << cases << endl;

    while(true){
      
      string command;
      
      cin >> command;

      if(command.compare("ENQUEUE")==0){
	int num;
	cin >> num;

	if(pos_team[team[num]]==NOT_EXIST){
	  queue[curr_queue_tail][queue_tail[curr_queue_tail]] = num;
	  queue_tail[curr_queue_tail]++;
	  pos_team[team[num]] = curr_queue_tail;

	  curr_queue_tail++;

	  if(curr_queue_tail==1001) curr_queue_tail=0;

	}
	else{
	  queue[pos_team[team[num]]][queue_tail[pos_team[team[num]]]] = num;
	  queue_tail[pos_team[team[num]]]++;
	}
      }
      else if(command.compare("DEQUEUE")==0){

	int num = queue[curr_queue_front][queue_front[curr_queue_front]];

	cout << queue[curr_queue_front][queue_front[curr_queue_front]] << endl;
	queue_front[curr_queue_front]++;
	
	if(queue_front[curr_queue_front]==queue_tail[curr_queue_front]){
	  
	  queue_front[curr_queue_front]=0;
	  queue_tail[curr_queue_front]=0;
	  curr_queue_front++;
	  
	  pos_team[team[num]] = NOT_EXIST;
	  
	  if(curr_queue_front==1001) curr_queue_front=0;
	}

      }
      else if(command.compare("STOP")==0) break;
      
    }

    cout << endl;
  }

};


main(){
  
  Solver solver;
  
  for(cases=1;;cases++){
    if(solver.read()==false) break;
    solver.work();
  }

}
