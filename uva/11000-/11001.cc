#include<iostream>
#include<cmath>
#include<cfloat>

#define EPS FLT_EPSILON
#define GT(x,y) ((x)-(y)>=EPS)
#define LT(x,y) ((x)-(y)<=-EPS)
#define EQ(x,y) (fabs((x)-(y))<EPS)

using namespace std;

int total, toConsume;

bool read(){
  cin >> total >> toConsume;
  if(total==0 && toConsume==0) return false;

  return true;
}

void work(){
  
  int toDiv = 1, nDisc = -1;
  double maxVal = -1;
  
  for(;GT((double)(total)/toDiv,toConsume);toDiv++){
    if( LT(maxVal,0.3*toDiv*sqrt((double)(total)/toDiv-toConsume)) ){
      maxVal = 0.3*toDiv*sqrt((double)(total)/toDiv-toConsume);
      nDisc = toDiv;
    }
    else if(EQ(maxVal,0.3*toDiv*sqrt((double)(total)/toDiv-toConsume))){
      cout << 0 << endl;
      return;
    }
  }
  
  if(nDisc==-1) cout << 0 << endl;
  else cout << nDisc << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
