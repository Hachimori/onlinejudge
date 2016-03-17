#include<iostream>
using namespace std;
typedef long long ll;

ll N;

bool read(){
  return cin >> N;
}

void work(){
  ll K = (N+1)/2;
  ll last = 2*K*K-1;

  cout << last*3-6 << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
