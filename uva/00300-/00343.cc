#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;

int cnv(char ch){
  return isdigit(ch) ? ch-'0' : ch-'A'+10;
}

int main(){
  string a, b;
  while(cin >> a >> b){
    for(int aBase=2;aBase<=36;aBase++)
      for(int bBase=2;bBase<=36;bBase++){
        bool ok = true;
        for(int i=0;i<a.size();i++) if(cnv(a[i])>=aBase) ok = false;
        for(int i=0;i<b.size();i++) if(cnv(b[i])>=bBase) ok = false;
        if(!ok) continue;
        if(strtol(a.c_str(),NULL,aBase)==strtol(b.c_str(),NULL,bBase)){
          printf("%s (base %d) = %s (base %d)\n",
                 a.c_str(),aBase,b.c_str(),bBase);
          goto _finish;
        }
      }
    printf("%s is not equal to %s in any base 2..36\n",a.c_str(),b.c_str());
  _finish:;
  }
  return 0;
}
