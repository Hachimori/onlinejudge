// ad-hoc
//
// 
// 文字列をa分割して、分割された文字列が全て同じならば、
// 元の文字列 = 分割された文字列^aということが言える。  
//
// 更に、分割された文字列をb分割して、さらに分割された文字列が全て同じならば、
// 分割された文字列 = さらに分割された文字列^b
// 元の文字列 = (さらに分割された文字列^b)^a
// がいえる。

#include<iostream>
#include<cstring>
#include<cstdio>

#define MAX_BUF 2000005

using namespace std;

char str[MAX_BUF];

bool read(){
  scanf("%s",str);
  if(strcmp(str,".")==0) return false;
  return true;
}

void work(){
  int curr = strlen(str), remain = strlen(str);
  
  for(int i=2;i<=curr;i++){
    while(curr%i==0){
      curr /= i;
      
      char *j;
      for(j=str;j-str<remain-remain/i;j++)
	if(*j!=*(j+remain/i)) break;
      
      if(j-str==remain-remain/i) remain /= i;
      else break;
    }
  }
  
  cout << strlen(str)/remain << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
