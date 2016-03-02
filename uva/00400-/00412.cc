#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define MAX_DIGIT 51

using namespace std;

int nDigit;
int digitList[MAX_DIGIT];

bool read(){
  
  cin >> nDigit;
  if(nDigit==0) return false;

  for(int i=0;i<nDigit;i++)
    cin >> digitList[i];

  return true;
}

int gcd(int a, int b){ 

  //if(a<b) swap(a,b);

  if(b==0) return a;
  else return gcd(b,a%b);
  
}

void work(){

  int cnt=0;
  
  for(int i=0;i<nDigit;i++)
    for(int j=i+1;j<nDigit;j++)
      if(gcd(digitList[i],digitList[j])==1) cnt++;
  
  if(cnt==0) 
    cout << "No estimate for this data set." << endl;
  else
    printf("%.6f\n", sqrt((nDigit*(nDigit-1))/2*6/(double)(cnt)) );

}

int main(){

  while(read())
    work();

  return 0;
}
