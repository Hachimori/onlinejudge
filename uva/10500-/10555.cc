#include<iostream>
#include<string>
#include<cassert>
using namespace std;

class Frac{
public:
  long long nume, deno;
  
  Frac(){}
  Frac(long long n, long long d){
    long long div = gcd(n,d);
    nume = n/div;
    deno = d/div;
  }

  Frac operator+ (Frac opp){
    return norm(Frac(opp.nume*deno+nume*opp.deno,deno*opp.deno));
  }

  Frac operator* (Frac opp){
    return norm(Frac(nume*opp.nume,deno*opp.deno));
  }

  Frac norm(Frac a){
    return Frac(a.nume/gcd(a.nume,a.deno),a.deno/gcd(a.nume,a.deno));
  }

  long long gcd(long long a, long long b){
    return b==0 ? a : gcd(b,a%b);
  }
};

string s;

bool read(){
  cin >> s;
  return s!="0";
}

long long myPow(long long p, int n){
  if(n==0) return 1;
  long long t = myPow(p,n/2);
  return n&1 ? t*t*p : t*t;
}

void work(){
  s = s.substr(2,s.size()-5);
  Frac ans(1,1<<30);
  for(int idx=0;idx<s.size();idx++){
    Frac t(0,1);
    for(int i=0;i<idx;i++)
      t = t+Frac(s[i]-'0',myPow(10,i+1));
    t = t+Frac(1,myPow(10,idx))*Frac(atoi(s.substr(idx).c_str()),myPow(10,s.size()-idx)-1);
    if(ans.deno>t.deno)
      ans = t;
  }
  cout << ans.nume << '/' << ans.deno << endl;
}

int main(){
  while(read()) work();
  return 0;
}
