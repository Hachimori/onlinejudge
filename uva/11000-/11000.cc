#include<iostream>
using namespace std;

int main(){
  while(1){
      int n;
      cin >> n;
      if(n==-1) break;
      
      long long a = 0, b = 1;
      for(int i=0;i<n;i++){
        long long na = b, nb = a+b;
        a = na;
        b = nb+1;
      }
      cout << a << ' ' << b << endl;
  }
  
  return 0;
}
