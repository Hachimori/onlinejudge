#include<iostream>
#include<cmath>
#include<cfloat>

using namespace std;

unsigned int sec;

bool read(){

  cin >> sec;
  if(sec==0) return false;

  return true;
}

void work(){
  
  double doubleRoot = sqrt((double)sec);
  unsigned int intRoot = (int)sqrt((double)sec);
  unsigned int currR, currC, currSec;

  if(fabs(doubleRoot-intRoot)<FLT_EPSILON){
    intRoot = (int)(sqrt((double)sec)+0.5);
  }
  else
    intRoot = sqrt((double)sec);
  
  //cout << intRoot << endl;
  if(intRoot*intRoot==sec){
    if(intRoot%2==0)
      cout << intRoot << ' ' << 1 << endl;
    else
      cout << 1 << ' ' << intRoot << endl;
    return;
  }

  if(intRoot%2==0){
    currR = 1;
    currC = intRoot+1;
    currSec = intRoot*intRoot+1;
    
    for(int j=0;j<intRoot;j++,currSec++,currR++){
      if(currSec==sec){
	cout << currC << ' ' << currR << endl;
	return;
      }
    }

    for(int j=0;j<intRoot;j++,currSec++,currC--){
      if(currSec==sec){
	cout << currC << ' ' << currR << endl;
	return;
      }
    }    

  }
  else {
    currR = intRoot+1;
    currC = 1;
    currSec = intRoot*intRoot+1;

    for(int j=0;j<intRoot;j++,currSec++,currC++){
      if(currSec==sec){
	cout << currC << ' ' << currR << endl;
	return;
      }
    }

    for(int j=0;j<intRoot;j++,currSec++,currR--){
      if(currSec==sec){
	cout << currC << ' ' << currR << endl;
	return;
      }
    }   
  }

}

int main(){
  
  while(read())
    work();

  return 0;
}
