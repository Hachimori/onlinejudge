#include<iostream>
#include<string>
using namespace std;

int len;
string str;

bool read(){
  int group;
  cin >> group;
  if(group==0) return false;
  cin >> str;

  len = str.size()/group;
  return true;
}

void work(){
  string ans;

  for(int i=0;i<str.size();i+=len)
    for(int j=len-1;j>=0;j--)
      ans += str[i+j];
  
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
