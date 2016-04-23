#include<iostream>
#include<string>
using namespace std;

bool isPrime(int n){
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int cnv(char ch){
  return islower(ch) ? ch-'a'+1 : ch-'A'+27;
}

int main(){
  string s;
  while(cin >> s){
    int sum = 0;
    for(int i=0;i<s.size();i++) sum += cnv(s[i]);
    cout << (isPrime(sum) ? "It is a prime word." : "It is not a prime word.") << endl;
  }
  return 0;
}
