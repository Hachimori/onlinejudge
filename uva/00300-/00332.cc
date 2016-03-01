#include<iostream>
using namespace std;

int nRepeat, nNonRepeat;
string rational;

bool read(){
  cin >> nRepeat >> rational;
  return nRepeat!=-1;
}


long long mypow(long long p, int n){
  return n==0 ? 1 : mypow(p,n-1)*p;
}


long long gcd(long long a, long long b){
  return b==0 ? a : gcd(b,a%b);
}


void work(int cases){
  nNonRepeat = rational.size()-nRepeat-2;
  if(nRepeat==0){
    long long nume = atoll(rational.substr(2).c_str());
    long long deno = mypow(10,nNonRepeat);
    long long div = gcd(nume,deno);
    cout << "Case " << cases << ": " << nume/div << '/' << deno/div << endl;
    return;
  }
  else{
    long long A = atoll(rational.substr(2).c_str());
    long long B = atoll(nNonRepeat==0 ? "0" :rational.substr(2,nNonRepeat).c_str());

    long long nume, deno;
    nume = A-B;
    deno = mypow(10,nRepeat+nNonRepeat)-mypow(10,nNonRepeat);

    long long div = gcd(nume,deno);
    cout << "Case " << cases << ": " << nume/div << '/' << deno/div << endl;
  }
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
