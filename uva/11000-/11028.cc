// http://www.research.att.com/~njas/sequences/A007773

#include<iostream>
using namespace std;

int n;

bool read(){
  cin >> n;
  if(n==0) return false;
  return true;
}

void work(int cases){
  int t[] = {0, 1, 1, 1, 3, 8, 21};
  int ans;
  
  if(n<=6)
    ans = t[n];
  else
    ans = (n%2==1 ? (n*n*n-16*n+27)/6 : (n*n*n-16*n+30)/6);
  
  cout << "Case #" << cases << ": " << ans << endl; 
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
