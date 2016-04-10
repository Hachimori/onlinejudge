#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#include<algorithm>

vector<int> integer_list;
int query;


class Solver{
 public:

  void init(){
    integer_list.clear();
  }

  bool read(){
    
    int num_int;

    cin >> num_int;
    if(num_int==0) return false;

    for(int i=0;i<num_int;i++){
      int tmp;

      cin >> tmp;
      integer_list.push_back(tmp);      
    }
    
    sort(integer_list.begin(),integer_list.end());
    
    return true;
  }

  void work(){

    int min=INT_MAX;
    int sum;
    int target;
    vector<int>::reverse_iterator i_ret;
    vector<int>::reverse_iterator j_ret;

    cin >> target;

    for(i_ret=integer_list.rbegin();i_ret!=integer_list.rend();i_ret++){
      for(j_ret=i_ret+1;j_ret!=integer_list.rend();j_ret++){
	int tmp_diff;
	
	tmp_diff = abs(target - *i_ret - *j_ret); 

	if(min>tmp_diff){ 
	  min = tmp_diff;
	  sum = *i_ret + *j_ret;
	}

      }
    }
    
    
    cout << "Closest sum to " << target << " is " << sum << '.' <<  endl;

  }


};


main(){
  
  Solver solver;
  int num_query;
  
  for(int cases=1;;cases++){

    if(solver.read()==false) break;
    
    cin >> num_query;
    
    cout << "Case " << cases << ":" << endl;
    for(int i=0;i<num_query;i++) solver.work();

    solver.init();

  }

}
