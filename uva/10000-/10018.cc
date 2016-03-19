#include<iostream>

using namespace std;

bool check(long long digit){
  
  int nDigit;
  int digitList[20];

  for(nDigit=0;digit!=0;nDigit++,digit/=10)
    digitList[nDigit]=digit%10;
  
  for(int i=0,j=nDigit-1;i<nDigit;i++,j--)
    if(digitList[i]!=digitList[j]) return false;

  return true;
}

long long reverse(long long digit){

  long long reversed=0;

  for(;digit!=0;digit/=10){
    reversed*=10;
    reversed+=digit%10;
  }
  
  return reversed;
}

void work(){

  long long source;
  int proc;

  cin >> source;

  for(proc=0;!check(source);proc++)    
    source+=reverse(source);  

  cout << proc << ' ' << source << endl;

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++)    
    work();
  
  return 0;
}
