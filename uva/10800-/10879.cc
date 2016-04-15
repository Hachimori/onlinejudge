#include<iostream>
using namespace std;

int n;

void read(){
  cin >> n;
}

void work(int cases){
  int a = -1, b = -1;
  for(int i=2;;i++){
    if(n%i==0){
      if(a!=-1) b = i;
      else a = i;
    }
    if(b!=-1) break;
  }

  cout << "Case #" << cases << ": " << n << " = " << a << " * " << n/a;
  cout << " = " << b << " * " << n/b << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
