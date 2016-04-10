#include<iostream>

int num_friend,num_box;
long long sum;

class Solver{
 public:
  
  void read(){

    cin >> num_friend >> num_box;

    sum = 0;

    for(int i=0;i<num_box;i++){
      
      long long tmp_sum=1;

      int inside_box;
      cin >> inside_box;

      for(int j=0;j<inside_box;j++){
	int multiple;
	cin >> multiple;
	
	tmp_sum*=multiple;
	tmp_sum=tmp_sum%num_friend;
      }
      
      sum+=tmp_sum;
      sum = sum%num_friend;
    }

    cout << sum%num_friend << endl;

  }


};

main(){

  int cases;
  Solver solver;

  cin >> cases;

  for(int i=0;i<cases;i++) solver.read();

}
