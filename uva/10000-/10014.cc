#include<iostream>
#include<cstdio>

#define MAX_SIZE 3015

using namespace std;

int nDigit;
double aFirst, aLast, c[MAX_SIZE];

void read(){
 
  cin >> nDigit;
  cin >> aFirst >> aLast;

  for(int i=1;i<=nDigit;i++)
    cin >> c[i];

}

void work(){
  
  double k1=0, k2=-0.5;
  double sum=0;

  for(int i=nDigit,j=1;i>=1;i--,j++,k1+=0.5,k2-=0.5)
    sum+=j*c[i];
  
  printf("%0.2f\n",(sum-aFirst*k1-aLast/2)/k2);
  
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
