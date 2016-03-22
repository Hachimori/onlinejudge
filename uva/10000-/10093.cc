#include<iostream>
#include<string>
#include<cctype>
using namespace std;


string val;

bool read(){
  return cin >> val;
}


int ch2v(char ch){
  if(isdigit(ch)) return ch-'0';
  if(isupper(ch)) return ch-'A'+10;
  if(islower(ch)) return ch-'a'+36;
}


int calcMod(string v, int base, int mod){
  int rem = 0;
  for(int i=0;i<v.size();i++){
    if(ch2v(v[i])>=base) return -1;
    rem = (rem*base+ch2v(v[i]))%mod;
  }
  return rem;
}


void work(){
  for(int base=2;base<=62;base++)
    if(calcMod(val,base,base-1)==0){
      cout << base << endl;
      return;
    }
  cout << "such number is impossible!" << endl;
}


int main(){
  while(read()) work();
  return 0;
}
