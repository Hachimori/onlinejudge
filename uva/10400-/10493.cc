#include<iostream>

using namespace std;

long long N,M;

bool read(){

  cin >> N >> M;
  if(N==0 && M==0) return false;

  return true;

}

void work(){
  
  if(M==0){
    cout << N << ' ' << M << ' ' << 1 << endl;
    return;
  }
  
  if(M==1 && N==1){
    cout << N << ' ' << M << ' ' << "Multiple" << endl;
    return;
  }
  
  if(M==N){
    cout << N << ' ' << M << ' ' << N+1 << endl;
    return;
  }
  
  if(N==1){
    cout << N << ' ' << M << ' ' << "Impossible" << endl;
    return;
  }
  
  if((M*N-1)%(N-1)==0){
    cout << N << ' ' << M << ' ' << ((M*N-1)/(N-1)) << endl;
  }
  else{
    cout << N << ' ' << M << ' ' << "Impossible" << endl;
    return;
  }

  
}

int main(){

  while(read())
    work();

  return 0;
}
