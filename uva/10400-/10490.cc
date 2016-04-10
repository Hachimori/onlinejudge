#include<iostream>
#include<algorithm>
using namespace std;

long long f(int n){
  long long a = 1, b = 1;
  for(int i=0;i<n-1;i++) a*=2;
  for(int i=0;i<n;i++) b*=2;
  return a*(b-1);
}

bool isPerfect(long long n){
  long long t[] = {6, 28, 496, 8128, 33550336, 8589869056LL,
                   137438691328LL, 2305843008139952128LL};
  return find(t,t+8,n)!=t+8;
}

bool isPrime(int n){
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int main(){
  int n;
  while(cin >> n,n){
    if(isPerfect(f(n)))
      cout << "Perfect: " << f(n) << "!" << endl;
    else if(isPrime(n))
      cout << "Given number is prime. But, NO perfect number is available." << endl;
    else
      cout << "Given number is NOT prime! NO perfect number is available." << endl;
  }
  return 0;
}
