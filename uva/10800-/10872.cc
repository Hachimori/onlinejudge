#include<iostream>
using namespace std;
typedef long long integer;

int N;

bool read(){
  cin >> N;
  return N!=0;
}

void work(int cases){
  integer cnt = 0;
  
  for(int a=N/3+(N%3!=0),k=0;a<=N/2-((N%2)==0),k<2;a++,k++){
    int L = a, R = N/2-((N%2)==0);

    integer n = (R-L+2)/2;
    integer init = (3*a-N+2)/2;
    
    //ƒ° init+3*(n-1)
    //-> (init-3)*n + 3*n*(n+1)/2
    cnt += (init-3)*n + 3*n*(n+1)/2;
  }
  
  cout << "Case " << cases << ": " << cnt << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
