#include<iostream>
using namespace std;

int N;

bool read(){
  if(!(cin >> N)) return false;
  return true;
} 

void work(){
  int cnt = 0, nEmpty = 0;
  
  while(N>0){
    cnt += N;
    
    nEmpty += N;
    N = nEmpty/3;
    nEmpty %= 3;

    if(N==0 && nEmpty==2){
      nEmpty = 0;
      N++;
    }
  }

  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
