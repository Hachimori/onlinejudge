#include<iostream>
using namespace std;
const int BUF = 10005;

bool LT(string &a, string &b){
  if(a.size()<b.size()) return true;
  if(a.size()>b.size()) return false;
  return a<b;
}

string sub(string &a, string &b){
  b = string(a.size()-b.size(),'0')+b;
  for(int i=a.size()-1;i>=0;i--){
    a[i] -= b[i]-'0';
    if(a[i]<'0'){
      a[i] += 10;
      a[i-1] -= 1;
    }
  }
  int idx = 0;
  while(idx<a.size() && a[idx]=='0') idx++;
  return idx==a.size() ? "0" : a.substr(idx);
}

int main(){
  int cases;
  cin >> cases;
  for(int kk=0;kk<cases;kk++){
    string a, b;
    cin >> a >> b;
    if(LT(a,b))
      cout << '-' << sub(b,a) << endl;
    else
      cout << sub(a,b) << endl;
  }
  return 0;
}
