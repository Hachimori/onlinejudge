#include<iostream>
#include<cmath>
using namespace std;
typedef long long integer;

int N;

bool read(){
  cin >> N;
  return N!=0;
}

void work(int cases){
  int sqrtN = (int)(sqrt(N)+1.0e-8);
  integer sum = 0;
  
  for(int i=2;i<=sqrtN;i++)
    sum += (integer)N/i*i;
  
  for(int k=1;k<=sqrtN;k++){
    int L = N/(k+1)+1, R = N/k;
    if(L==sqrtN)L++;
    sum += (integer)k*R*(R+1)/2-(integer)k*L*(L-1)/2;
  }
  
  sum -= (integer)N*(N+1)/2-1;

  cout << "Case " << cases << ": " << sum << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
