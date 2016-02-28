#include<iostream>
#include<string>
using namespace std;

string a, b;

bool read(){
  if(!getline(cin,a)) return false;
  if(!getline(cin,b)) return false;
  return true;
}


int cnv(string s){
  string ch = " |n98r";
  int v[] = {0,1,10,100,1000,10000};
  int sum = 0;
  for(int i=0;i<s.size();i++)
    sum += v[ch.find(s[i])];
  return sum;
}


string cnv(int n){
  string ch = "|n98r";
  string ret;
  for(int i=0;i<ch.size();i++){
    if(n%10)
      ret += string(n%10,ch[i])+' ';
    n /= 10;
  }
  return ret;
}


void work(){
  int valA = cnv(a), valB = cnv(b);

  for(int i=1;i<=valB;i*=2,valA*=2){
    string toPrintB = cnv(i), toPrintA = cnv(valA);
    if(valB&i) toPrintB += "*";
    cout << toPrintB << string(34-toPrintB.size(),' ') << toPrintA << endl;
  }
  cout << "The solution is: " << cnv(cnv(a)*cnv(b)%100000) << endl;
}


int main(){
  while(read()) work();
  return 0;
}
