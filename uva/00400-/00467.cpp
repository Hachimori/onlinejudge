#include<iostream>
#include<stdio.h>

#define MAX 11

int cases;
int ans;
int signal[MAX];
int num_signal;
int max_signal;

class Solver{

 public:

  bool read(){
    
    int tmp;
    char c;

    for(num_signal=0;;num_signal++){
      /*
      if(scanf("%d",&signal[num_signal])==EOF) return false;
      if(scanf("%c",&c)==EOF) return false;
      
      if(c=='\n') break;
      */

      signal[num_signal]=0;

      if(scanf("%c",&c)==EOF) return false;
      if(c=='\n' && num_signal!=0) break;
      else if(c=='\n' && num_signal==0){ num_signal--; continue; }	
      else if(c<'0' || c>'9'){ num_signal--; continue; }
      else signal[num_signal] += (c-'0')*10;

      scanf("%c",&c);
      signal[num_signal] += c-'0';

      

    }
    
    return true;
    
  }
  
  void define_max(){
    
    int curr_max = signal[0];
    
    for(int i=1;i<num_signal;i++){
      
      if(curr_max < signal[i] ){ 
	curr_max = signal[i];
	max_signal = i;
      }
      
    }
    
  }
  
  void work(){

    define_max();
    
    for(int arg=signal[max_signal]*2;arg<=60*60;arg+=signal[max_signal]*2){

      for(int j=arg;j<arg+signal[max_signal]-5;j++){ /* j<=arg+signal[max_signal] ?  */

	bool flg = true;
	ans = j;

	for(int k=0;k<num_signal;k++){
	  if(k==max_signal) continue;
	  
	  if(j%(signal[k]*2) >= signal[k]-5){ 
	    flg = false; 
	    break;
	  }

	}

	if(flg == true){
	  

	  cout << "Set " << cases << " synchs again at " << ans/60 << " minute(s) and " << ans%60 << " second(s) after all turning green." << endl;
	  
	  return;

	}

      }

    }

    cout << "Set " << cases << " is unable to synch after one hour." << endl;
    
    return;

  }

};

main(){

  Solver solver;

  for( cases=1;;cases++){

    if(solver.read()==false) break;
    solver.work();

  }

}
