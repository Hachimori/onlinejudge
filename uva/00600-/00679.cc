#include<iostream>

using namespace std;

int depth, nBall;

void read(){
  cin >> depth >> nBall;
}

void work(){

  int initWidth, currWidth;

  initWidth=1;
  for(int i=0;i<depth-1;i++)
    initWidth*=2;

  currWidth=initWidth;


  int pos=1;
  
  while(nBall!=1){
    
    if(nBall%2==0){
      pos+=currWidth/2;
      currWidth/=2;
      nBall/=2;
    }
    else {
      currWidth/=2;
      nBall=(nBall+1)/2;      
    }
    
  }
  
  cout << pos+initWidth-1 << endl;
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
