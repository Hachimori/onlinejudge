#include<iostream>
#include<cstdio>
#include<cctype>
#define STR 10005
#define MOD 131071
using namespace std;

int strLen;
char str[STR];

bool read(){
  strLen = 0;
  while(true){
    if(scanf("%c",&str[strLen])==EOF) return false;
    if(str[strLen]=='#') break;
    if(isdigit(str[strLen])) strLen++;
  }
  return true;
}

void work(){
  int sum = 0;

  for(int i=strLen-1,p=1;i>=0;i--,p=(p*2)%MOD)
    if(str[i]=='1')
      sum = (sum+p)%MOD;
  
  if(sum==0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
