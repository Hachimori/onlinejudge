#include<iostream>
#include<cmath>
using namespace std;
const int DEGREE = 25;
typedef unsigned long long integer;

int nDegree, nRepeat, kTh, coeff[DEGREE];

void read(){
  cin >> nDegree;
  nDegree++;
  for(int i=0;i<nDegree;i++) cin >> coeff[i];
  cin >> nRepeat >> kTh;
}

double solve(double a, double b, double c){
  return (-b+sqrt(b*b-4*a*c))/(2*a);
}

integer mypow(int p, int n){
  if(n==0) return 1;
  integer t = mypow(p,n/2);
  return n%2==0 ? t*t : t*t*p;
}

void work(){
  double termDbl = solve(nRepeat/2.0,nRepeat/2.0,-kTh);
  int nTerm = (int)(ceil(termDbl)+0.5);
  integer ans = 0;
  for(int i=0;i<nDegree;i++)
    ans += coeff[i]*mypow(nTerm,i);
  cout << ans << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    string dummy; getline(cin,dummy);
    read();
    work();
  }
  return 0;
}
