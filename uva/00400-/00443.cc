#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX_NUM 2000000000
#define MAX_SIZE 5843

using namespace std;

int target;
int nList[MAX_SIZE];

long long myPow(double v, double n){
  long long ret=1;
  for(int i=0;i<(int)(n+0.5);i++)
    ret*=(int)(v+0.5);
  return ret;
}

void makeTable(){
  
  int currN=1;
  
  long long curr;
  
  nList[0] = 0;

  for(int i=0;i<32;i++){
    
    if(myPow(2.0,i)>MAX_NUM) break;
    
    curr=1;
    curr*=myPow(2.0,i);
    
    for(int j=0;j<32;j++){

      if(myPow(3.0,j)*curr>MAX_NUM) break;
      curr*=myPow(3.0,j);
      
      for(int k=0;k<32;k++){
	
	if(myPow(5.0,k)*curr>MAX_NUM) break;
	curr*=myPow(5.0,k);
	
	for(int l=0;l<32;l++){
	  if(myPow(7.0,l)*curr>MAX_NUM) break;
	  //cout << (long long)(myPow(7.0,l)+0.5)*curr << endl;
	  nList[currN] = myPow(7.0,l)*curr;
	  currN++;
	}
	
	curr/=myPow(5.0,k);
      }
      curr/=myPow(3.0,j);
    }
    curr/=myPow(2.0,i);
  }
  
  
  sort(&nList[0],&nList[currN]);
}

bool read(){

  cin >> target;
  if(target==0) return false;
  
  return true;
}

void work(){
  
  if(target%100==11 || target%100==12 || target%100==13){
    cout << "The " << target << "th humble number is " << nList[target] << "." << endl;
  }
  else if(target%10==1) 
    cout << "The " << target << "st humble number is " << nList[target] << "." << endl;
  else if(target%10==2)
    cout << "The " << target << "nd humble number is " << nList[target] << "." << endl;
  else if(target%10==3)
    cout << "The " << target << "rd humble number is " << nList[target] << "." << endl;
  else
    cout << "The " << target << "th humble number is " << nList[target] << "." << endl;
}

int main(){

  makeTable();
  
  while(read())
    work();
  
  return 0;
}
