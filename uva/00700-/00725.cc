#include<iostream>

using namespace std;

bool isValid(int a, int b){
  
  bool used[10];
  
  for(int i=0;i<10;i++)
    used[i] = false;

  for(int i=0;i<5;i++){
    int mod = a%10;

    if(used[mod]) return false;
    
    used[mod] = true;
    a/=10;
  }
 
  for(int i=0;i<5;i++){
    int mod = b%10;

    if(used[mod]) return false;
    
    used[mod] = true;
    b/=10;
  }

  return true;
}

void work(int N){
  
  bool ok=false;

  for(int i=1234;i*N<=98765;i++){
    
    if(isValid(i,i*N)){
      if(i*N<10000) cout << 0;
      cout << i*N << " / ";
      if(i<10000) cout << 0;
      cout << i << " = " << N << endl;
    
      ok = true;
    }
    
  }
  
  if(!ok) cout << "There are no solutions for " << N << "." << endl;

}

int main(){

  for(int i=0;;i++){
    int N;
    cin >> N;
    if(N==0) break;
    
    if(i!=0) cout << endl;

    work(N);
  }

  return 0;
}
