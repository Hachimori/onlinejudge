#include<iostream>
using namespace std;

int josephus(int n,int k,int s){
  long long x = k*s ;
  while(x>n) x = ((x-n)*k-1)/(k-1);
  return x;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    int n;
    cin >> n;
    for(int j=0;;j++){
      int t = josephus(n,2,n);
      if(t==n){
        cout << "Case " << i+1 << ": " << j << ' ' << t << endl;
        break;
      }
      n = t;
    }
  }
  return 0;
}
