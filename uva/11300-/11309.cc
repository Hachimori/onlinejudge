#include<iostream>
#include<cstdio>
using namespace std;

bool isOk(int hh, int mm){
  if(hh==0 && mm==0) return true;
  char str[5];
  if(hh) 
    sprintf(str,"%d%02d",hh,mm);
  else
    sprintf(str,"%d",mm);
  for(int i=0;i<strlen(str);i++)
    if(str[i]!=str[strlen(str)-1-i])
      return false;
  return true;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int hh,mm;
    char ch;
    cin >> hh >> ch >> mm;
    
    for(int i=(hh*60+mm+1)%1440;;i=(i+1)%1440)
      if(isOk(i/60,i%60)){
        printf("%02d:%02d\n",i/60,i%60);
        break;
      }
  }
  return 0;
}
