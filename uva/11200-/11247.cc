#include<iostream>
#define INF (1LL<<50)
using namespace std;
typedef long long integer;

integer m, x;

bool read(){
  cin >> m >> x;
  if(m==0 && x==0) return false;
  
  return true;
}

integer get(integer num){
  return num*(100-x);
}

void work(){
  integer bound = m-1;
  integer L = m, U = INF;

  while(L!=U){
    integer mid = (L+U)/2;
    
    if(bound*100<=get(mid))
      U = mid;
    else{
      if(L==mid)
        U = mid;
      else
        L = mid;
     }
   }

  if(x==100){
    cout << "Not found" << endl;
    return;
  }
  
  for(integer i=L+100;i>=m;i--)
    if(bound*100>get(i)){
      cout << i << endl;
      return;
    }
  cout << "Not found" << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
