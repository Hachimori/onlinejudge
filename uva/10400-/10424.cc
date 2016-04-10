#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>

using namespace std;

string str1, str2;

bool read(){
  if(getline(cin,str1)==NULL) return false;
  getline(cin,str2);

  return true;
}

int calc(string str){

  int sum=0;

  for(int i=0;i<str.length();i++){    
    if(isalpha(str[i])){
      sum += toupper(str[i])-'A'+1;
    }
  }

  while(sum>=10){

    int tmp=0;
    for(;sum>0;sum/=10)
      tmp+=sum%10;

    sum = tmp;
  }

  return sum;

}

void work(){
  
  int digit1 = calc(str1);
  int digit2 = calc(str2);
  
  if(digit2<digit1)
    printf("%.2f %%\n",(double)(100*digit2)/digit1);
  else
    printf("%.2f %%\n",(double)(100*digit1)/digit2);
}

int main(){
  
  while(read())
    work();

  return 0;
}
