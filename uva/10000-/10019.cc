#include<iostream>

using namespace std;

void work(){

  int target;
  cin >> target;
  
  int backup=target;
  int b1=0,b2=0;

  for(;target!=0;target/=2)
    b1+=target%2;

  target=backup;
  for(;target!=0;target/=10){
    
    int digit=target%10;
    for(;digit!=0;digit/=2)
      b2+=digit%2;
  }

  cout << b1 << ' ' << b2 << endl;
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++)
    work();

  return 0;
}
