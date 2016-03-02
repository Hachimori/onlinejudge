#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  string as, bs;
  char ch;
  while(cin >> as >> ch >> bs){
    cout << as << ' ' << ch << ' ' << bs << endl;
    double a = atof(as.c_str()), b = atof(bs.c_str());
    if(a>INT_MAX) cout << "first number too big" << endl;
    if(b>INT_MAX) cout << "second number too big" << endl;
    if(ch=='+' && a+b>INT_MAX)
      cout << "result too big" << endl;
    if(ch=='*' && a*b>INT_MAX)
      cout << "result too big" << endl;
  }
  return 0;
}
