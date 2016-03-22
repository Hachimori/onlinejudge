#include<iostream>
using namespace std;


long long mypow(long long p, long long n){
  long long ret = 1;
  for(int i=0;i<n;i++) ret *= p;
  return ret;
}


int main(){
  long long n;
  while(cin >> n){
    long long S2 = n*(n+1)*(2*n+1)/6;      // ƒ°i^2
    long long ALL2 = mypow(n*(n+1)/2,2);   // (n*(n+1)/2)^2
    cout << S2 << ' ' << ALL2-S2 << ' ';

    long long S3 = mypow(n*(n+1)/2,2);     // ƒ°i^3
    long long ALL3 = mypow(n*(n+1)/2,3);   // (n*(n+1)/2)^3
    cout << S3 << ' ' << ALL3-S3 << ' ';
    
    long long S4 = n*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30;  // ƒ°i^4
    long long ALL4 = mypow(n*(n+1)/2,4);              // (n*(n+1)/2)^4
    cout << S4 << ' ' << ALL4-S4 << endl;
  }
  return 0;
}
