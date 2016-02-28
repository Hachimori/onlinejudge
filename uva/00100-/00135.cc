#include<iostream>
#define BUF 1000
using namespace std;

int N, K;

bool read(){
  if(!(cin >> K)) return false;
  N = K*K-K+1;
  return true;
}

void work(){
  bool b[BUF][BUF];
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      b[i][j] = false;
  
  b[1][1] = true;
  for(int i=1;i<=K;i++)
    for(int j=(i-1)*(K-1)+2;j<=i*(K-1)+1;j++)
      b[i][j] = b[j][i] = true;

  for(int i=1;i<=K-1;i++)
    for(int j=1;j<=K-1;j++){
      int s = i*(K-1)+2;
      int t = j*(K-1)+2;
      for(int k=0;k<=K-2;k++)
        b[s+(k+(i-1)*(j-1))%(K-1)][t+k] = true;
    }

  for(int i=1;i<=N;i++){
    bool fst = true;
    for(int j=0;j<BUF;j++){
      if(b[i][j]){
        if(fst) fst = false;
        else cout << ' ';
        cout << j;
      }
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}