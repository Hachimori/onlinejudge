#include<iostream>
using namespace std;
const int FIB = 60;

long long fib[FIB];
int n;

void makeFib(){
  fib[0] = 1;
  fib[1] = 2;
  for(int i=2;i<FIB;i++) fib[i] = fib[i-1]+fib[i-2];
}

void read(){
  cin >> n;
}

void work(){
  bool bin[FIB]={0};
  long long sum = 0;
  while(sum!=n){
    int i=0;
    while(sum+fib[i]<=n) i++;
    bin[i-1] = true;
    sum += fib[i-1];
  }

  cout << n << " = ";
  int i = FIB-1;
  while(!bin[i]) i--;
  while(i>=0) cout << bin[i--];
  cout << " (fib)" << endl;
}

int main(){
  makeFib();
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
