#include<iostream>
#include<cstdio>
#include<string>
#define MOD 34943
using namespace std;

string str;

bool read(){
  getline(cin,str);
  return str!="#";
}

void work(){
  long long rem = 0;
  for(int i=0;i<str.size();i++)
    rem = ((rem<<8)+str[i])%MOD;
  
  int ans = MOD-(rem<<16)%MOD;
  if(ans==MOD)
    ans = 0;

  printf("%02X %02X\n",ans>>8,ans&0xff);
}

int main(){
  while(read())
    work();
  return 0;
}
