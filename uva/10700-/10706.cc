#include<iostream>
#include<string>
#include<sstream>
#include<cassert>
using namespace std;

long long g(long long n){
  if(n<10) return n*(n+1)/2;
  if(n<100){ n-=10; return n*n+10*n+45; }
  if(n<1000){ n-=100; return n*(n-1)*3/2+192*n+9045; }
  if(n<10000){ n-=1000; return 2*n*n+2891*n+1395495; }
  if(n<100000){ n-=10000; return n*(n-1)*5/2+38894*n+189414495; }
  assert(false);
}

int getLen(int n){
  return n ? getLen(n/10)+1 : 0;
}

string itoa(int n){
  stringstream out;
  out << n;
  return out.str();
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    long long n;
    cin >> n;
    for(int i=0;;i++)
      if(g(i)>=n){
        n -= g(i-1);
        break;
      }
    for(int i=1;;i++){
      int len = getLen(i);
      if(n<=len){
        string istr = itoa(i);
        cout << istr[n-1] << endl;
        break;
      }
      n -= len;
    }
  }
  return 0;
}
