#include<iostream>
#include<limits.h>
#include<algorithm>

#define MAX 500
    
int num_house;
int street_numbers[MAX];

class Solver{
 public:

  void read(){


    cin >> num_house;

    for(int i=0;i<num_house;i++)
      cin >> street_numbers[i];
    

    sort( street_numbers, street_numbers + num_house );

  }

  void work(){

    int min = INT_MAX;
    int sum;

    for(int i=0;i<num_house;i++){
      sum=0;

      if(i!=0)
	for(int j=i-1;j>=0;j--){
	  sum+=street_numbers[i]-street_numbers[j];
	}
      
      if(i!=num_house-1)
	for(int j=i+1;j<num_house;j++){
	  sum+=street_numbers[j]-street_numbers[i];
	}
      
     
      if(min>sum)
	min = sum;
 
    }

    cout << min << endl;

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

