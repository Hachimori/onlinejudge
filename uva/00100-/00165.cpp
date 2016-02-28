#include<iostream>
#include<stdio.h>
#include<assert.h>
#define MAX 200

int num_various,num_stamp;
int val_stamps[10000][9];
int num_combination;
bool val_stamp[MAX];

void combi(bool val[MAX], int curr_combi[9], int limit_use, int limit_range, int curr_arg, int curr_uses, int sum){

  if(limit_use == curr_uses || limit_range+1 == curr_arg){
    val[sum] = true;
    return;
  }

  combi(val,curr_combi,limit_use,limit_range,curr_arg,curr_uses+1,sum+curr_combi[curr_arg]);
  combi(val,curr_combi,limit_use,limit_range,curr_arg+1,curr_uses+1,sum+curr_combi[curr_arg]);
  combi(val,curr_combi,limit_use,limit_range,curr_arg+1,curr_uses,sum);
  

}

int make_limit(int curr_combi[9], int curr_pos){
  
  bool val[MAX];
  for(int i=0;i<MAX;i++) val[i]=false;
  for(int i=0;i<=curr_combi[curr_pos];i++) val[i]=true;
			   
  for(int i=1;i<=num_stamp;i++)
    combi(val,curr_combi,i,curr_pos,0,0,0);
    
  for(int i=1;i<MAX;i++) if(val[i]==false) return i;

}

void make_combination(int curr_combi[9], int curr_pos){

  if(curr_pos == num_various-1){
    for(int i=0;i<num_various;i++) val_stamps[num_combination][i] = curr_combi[i];
    num_combination++;
    
    return;
  }

  int limit;
  limit = make_limit(curr_combi,curr_pos);

  for(int i=curr_combi[curr_pos]+1;i<=limit;i++){
    //cout << "i  = "<< i << "    curr_combi[curr_pos-1] = " <<curr_combi[curr_pos-1] <<  endl;
    
    curr_combi[curr_pos+1]=i;
    make_combination(curr_combi,curr_pos+1);
  }
  
  return;

}

void make_value(int uses, int curr_arg, int curr_uses, int sum){

  if(num_stamp == curr_uses || num_various == curr_arg){
    val_stamp[sum] = true;
    return;
  }
  
  make_value(uses,curr_arg,curr_uses+1,sum+val_stamps[uses][curr_arg]);
  make_value(uses,curr_arg+1,curr_uses+1,sum+val_stamps[uses][curr_arg]);
  make_value(uses,curr_arg+1,curr_uses,sum);
  
}


class Solver{

 public:

  bool read(){

    cin >> num_stamp >> num_various;
    if(num_various==0 && num_stamp==0) return false;
    
    assert(!(num_various==0 && num_stamp!=0));
    assert(!(num_various!=0 && num_stamp==0));

    num_combination=0;

    return true;

  }

  void work(){

    int curr_combi[9]={1,0,0,0,0,0,0,0,0};
    int max=0;
    int pos_combination;


    make_combination(curr_combi,0);

    /*
    for(int i=0;i<num_combination;i++){
      for(int j=0;j<num_various;j++){
	cout << val_stamps[i][j] << ' ';
      }cout << endl;
    }cout << endl;
    */
    
    for(int i=0;i<num_combination;i++){
      
      for(int j=0;j<MAX;j++) val_stamp[j]=false;
      make_value(i,0,0,0);
      
      for(int j=0;;j++){
	if(val_stamp[j]==true && max<j){ 
	  max = j;
	  pos_combination = i;
	}
	else if(val_stamp[j]==false) break;
      }
    
    }
    
    
    
    for(int i=0;i<num_various;i++)
      printf("%3d",val_stamps[pos_combination][i]);
    cout << " ->";
    printf("%3d\n",max);

  }

};

main(){
  
  Solver solver;
  
  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
