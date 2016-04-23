#include<iostream>
#include<string>
using namespace std;

int calc(string s){
  int ret = 0;
  for(int i=0;i<s.size();i++)
    ret += s[i]-'0';
  return ret;
}

int calc(int n){
  int ret = 0;
  while(n){
    ret += n%10;
    n /= 10;
  }
  return ret;
}

int main(){
  string s;
  while(cin >> s, s!="0"){
    int cur = calc(s), cnt = 0;
    while(1){
      if(cur==9){
        cnt++;
        break;
      }
      if(cur%9!=0) break;
      cnt++;
      cur = calc(cur);
    }
    if(cnt==0)
      cout << s << " is not a multiple of 9." << endl;
    else
      cout << s << " is a multiple of 9 and has 9-degree "  << cnt << '.' << endl;
  }
  return 0;
}
