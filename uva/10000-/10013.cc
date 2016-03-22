#include<iostream>

#define MAX_SIZE 1000002

using namespace std;

int nDigit;
int a[MAX_SIZE], b[MAX_SIZE];

void read(){

  cin >> nDigit;
  
  for(int i=0;i<nDigit;i++)
    cin >> a[i] >> b[i];
      
}

void work(){
  
  for(int i=nDigit-1;i>=0;i--){
    if(a[i]+b[i]>=10){
      a[i-1]++;
      a[i] = (a[i]+b[i])%10;
    }
    else {
      a[i] = (a[i]+b[i]);
    }
  }
  
  for(int i=0;i<nDigit;i++)
    cout << a[i];
  cout << endl; 

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
