#include<iostream>
using namespace std;

string s;

bool read(){
  return getline(cin,s);
}

void work(){
  string qwerty="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
  string dvorak="`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";
  
  for(int i=0;i<s.size();i++)
    cout << dvorak[qwerty.find(s[i])];
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
