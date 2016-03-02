#include<iostream>
#include<stdio.h>
#include<float.h>
#include<algorithm>
#define MAX 10

class Specimen_Info{
 public:

  int number;
  int weight;

  Specimen_Info(){}

  Specimen_Info(int n, int w){
    number = n, weight = w;
  }

};

class Chamber_Info{
 public:

  int num;
  Specimen_Info left;
  Specimen_Info right;

  Chamber_Info(){}

  Chamber_Info(int n, Specimen_Info l, Specimen_Info r){
    num = n, left = l, right = r;
  }

  bool operator< (Chamber_Info const &c) const {
    if(left.number<c.left.number) return true;
    else return false;
  }

};

int cases;
int num_chamber, num_specimen;
Specimen_Info list[MAX];
Chamber_Info answer[MAX];
double average;
double minimum;

void sort_weight(){

  Specimen_Info tmp;
  int maximum;
  int maximum_pos;

  for(int i=0;i<num_specimen;i++){
    
    maximum = list[i].weight;
    maximum_pos = i;
    for(int j=i+1;j<num_specimen;j++){
      if(maximum<list[j].weight){
	maximum = list[j].weight;
	maximum_pos = j;
      }
    }
    
    tmp = list[i];
    list[i] = list[maximum_pos];
    list[maximum_pos] = tmp;

  }


}

double AbsDouble(double num){
  if(num<=0) return num*(-1);
  else return num;
}

void search(int curr_chamber, int curr_specimen, double imbalance, Chamber_Info selected_list[MAX], bool selected[MAX]){

  if(curr_chamber==num_chamber){
    if(minimum>imbalance){ 
      minimum = imbalance;
      for(int i=0;i<num_chamber;i++)
	answer[i] = selected_list[i];
    }
    return;
  }
  /*
  for(int i=0;i<num_chamber;i++)
    cout << i << ":  " << selected_list[i].left.weight << "  " << selected_list[i].right.weight << endl;
  cout << endl;
  */
  if(curr_specimen==num_specimen-1){

    for(int i=0;i<num_specimen;i++){
      if(selected[i]==true) continue;
      
      Chamber_Info backup[MAX];
      for(int j=0;j<curr_chamber;j++)
	backup[j] = selected_list[j];
      
      backup[curr_chamber].num = 1;
      backup[curr_chamber].left = list[i]; 

      if(imbalance+AbsDouble(list[i].weight-average)<minimum)
	search(curr_chamber+1,curr_specimen+1,imbalance+AbsDouble(list[i].weight-average),backup,selected);
    }
  
  }
  else{
    
    for(int i=0;i<num_specimen;i++){
      if(selected[i]==true) continue;
      for(int j=num_specimen-1;j>=i+1;j--){
	if(selected[j]==true) continue;

	Chamber_Info backup[MAX];
	for(int k=0;k<curr_chamber;k++)
	  backup[k] = selected_list[k];
	
	backup[curr_chamber].num = 2;
	backup[curr_chamber].left = list[i]; 
	backup[curr_chamber].right = list[j]; 

	
	bool backup_selected[MAX];
	for(int k=0;k<num_specimen;k++)
	  backup_selected[k] = selected[k];

	backup_selected[i]=true;
	backup_selected[j]=true;

	if(imbalance+AbsDouble(list[i].weight+list[j].weight-average)<minimum)
	  search(curr_chamber+1,curr_specimen+2,imbalance+AbsDouble(list[i].weight+list[j].weight-average),backup,backup_selected);
      }
    }

  }

  return;

}

class Solver{
 public:
  
  bool read(){

    cin >> num_chamber >> num_specimen;
    if(cin.eof()) return false;


    for(int i=0;i<num_specimen;i++){
      list[i].number = i;
      cin >> list[i].weight;
    }    

    double sum=0;
    for(int i=0;i<num_specimen;i++)
      sum += list[i].weight;

    average = sum/num_chamber;
    
    return true;
  }

  void work(){
    
    Chamber_Info selected_list[MAX];
    bool selected[MAX];

    for(int i=0;i<num_specimen;i++) selected[i]=false;
    
    minimum = DBL_MAX;

    sort_weight();
    
    search(0,0,0,selected_list,selected);

    sort(&answer[0],&answer[num_chamber]);

    cout << "Set #" << cases << endl; 
    for(int i=0;i<num_chamber;i++){
      if(answer[i].num==2) 
	cout << ' ' << i << ": " << answer[i].left.weight << ' ' << answer[i].right.weight << endl;
      else if(answer[i].num==1)
	cout << ' ' << i << ": " << answer[i].left.weight << endl;
    }
    printf("IMBALANCE = %l.5f\n",minimum);
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



