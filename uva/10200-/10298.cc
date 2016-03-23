// ad-hoc
//
// 
// $BJ8;zNs$r(Ba$BJ,3d$7$F!"J,3d$5$l$?J8;zNs$,A4$FF1$8$J$i$P!"(B
// $B85$NJ8;zNs(B = $BJ,3d$5$l$?J8;zNs(B^a$B$H$$$&$3$H$,8@$($k!#(B  
//
// $B99$K!"J,3d$5$l$?J8;zNs$r(Bb$BJ,3d$7$F!"$5$i$KJ,3d$5$l$?J8;zNs$,A4$FF1$8$J$i$P!"(B
// $BJ,3d$5$l$?J8;zNs(B = $B$5$i$KJ,3d$5$l$?J8;zNs(B^b
// $B85$NJ8;zNs(B = ($B$5$i$KJ,3d$5$l$?J8;zNs(B^b)^a
// $B$,$$$($k!#(B

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
