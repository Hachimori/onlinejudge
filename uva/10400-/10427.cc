#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string itoa(int n){
  stringstream out;
  out << n;
  return out.str();
}

int main(){
  int n;
  while(cin >> n){
    n--;
    int num = 1, nTh = n, nDigit = 1, nAppear = 9;
    while(nAppear*nDigit<=nTh){
      nTh -= nAppear*nDigit;
      nAppear *= 10;
      nDigit++;
      num *= 10;
    }
    num += nTh/nDigit;
    nTh %= nDigit;
    cout << itoa(num)[nTh] << endl;
  }
  return 0;
}

