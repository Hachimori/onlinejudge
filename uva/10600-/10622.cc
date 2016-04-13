#include<iostream>
using namespace std;
typedef long long integer;

integer n;

bool read(){
  cin >> n;
  return n!=0;
}

integer myAbs(integer num){
  return (num<0 ? -num : num);
}

void work(){
  int ans = 1;

  for(integer i=2;i*i<=myAbs(n);i++){
    integer cur = i;
    for(int j=1;cur<=myAbs(n);cur*=i,j++)
      if(n<0){
        if(j%2==1 && cur==myAbs(n)){
          ans = j;
          goto finish;
        }
      }
      else if(cur==n){
        ans = j;
        goto finish;
      }
  }
  
 finish:
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
