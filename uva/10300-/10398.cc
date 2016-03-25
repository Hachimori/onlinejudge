#include<iostream>
#include<cfloat>
#include<cmath>

#define LIMIT 1000000000

using namespace std;

double init, incAmount;
int nTh;

double func(double a){  
  return a*a*a*a*a-a*a*a*a-1;  
}

void calcInc(){
  
  double left=0, right=2;
  
  while(!(right-left<DBL_EPSILON*3)){
    
    double middle = left+(right-left)/2;
    
    if(func(left)*func(middle)<0)
      right = middle;    
    else
      left = middle;
  }
  
  incAmount = (right+left)/2;
  
}

bool read(){
  if(!(cin >> init >> nTh)) return false;
  return true;
}

void work(){
  
  if(init==0){
    cout << 0 << endl;
    return;
  }
  
  long long ans=init*pow(incAmount,nTh-1);
  long long nDigit;

  if(nTh>1) nDigit=log10(init)+(long long)((nTh-1))*log10(incAmount)+1;
  else nDigit = log10(init)+1;
  
  if(nDigit<=10 && (long long)(ans)<LIMIT) cout << (long long)(ans) << endl;
  else
    cout << nDigit << endl;

}

int main(){
  
  calcInc();

  while(read())
    work();
  
  return 0;
}
