#include<iostream>

using namespace std;

int N;

bool read(){

  cin >> N;
  if(N==0) return false;

  return true;
}

int rec(int n){
  if(n<=100) return rec(rec(n+11));
  else return n-10;
}

void work(){
  cout << "f91(" << N << ") = " << rec(N) << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
