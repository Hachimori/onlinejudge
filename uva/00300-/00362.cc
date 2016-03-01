#include<iostream>
#include<cmath>

using namespace std;

int size;

bool read(){
  
  cin >> size;
  if(size==0) return false;
  
  return true;
}

void work(int cases){
  
  cout << "Output for data set " << cases << ", " << size << " bytes:" << endl;


  int prevCarry, totalSec, totalCarry=0;


  for(totalSec=0;totalCarry<size;){
     
    int fiveSecCarry=0;
    int i;
    for(i=0;i<5 && totalCarry<size;i++,totalSec++){
      int sizeTrans;
      cin >> sizeTrans;
      
      totalCarry+=sizeTrans;
      fiveSecCarry+=sizeTrans;
    }
    
    prevCarry=fiveSecCarry;
    
    if(i==5){
      if(prevCarry==0)
	cout << "   Time remaining: stalled" << endl;
      else
	cout << "   Time remaining: " <<  ceil( ((size-totalCarry))/((double)(prevCarry)/5)  )
	     << " seconds" << endl;
    }
  }
  
  cout << "Total time: " << totalSec << " seconds" << endl << endl;

}

int main(){
  
  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
