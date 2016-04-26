// ad-hoc
//
// A + A^2 + A^3 + .... + A^n を 
// ( A+A^2+...+A^(n/2) ) + A^(n/2)*(A+A^2+...+A^(n/2)) に変換する。

#include<iostream>
#define BUF 45
using namespace std;

int N, K, b[BUF][BUF];

bool read(){
  cin >> N >> K;
  if(N==0) return false;
  
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      cin >> b[i][j];
      b[i][j] %= 10;
    }

  return true;
}

void copy(int dst[][BUF], int src[][BUF]){
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      dst[i][j] = src[i][j];
}

void multiple(int A[][BUF], int B[][BUF], int ret[][BUF]){
  int t[BUF][BUF];

  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      int cnt = 0;
      for(int k=0;k<N;k++)
	cnt += A[i][k]*B[k][j];
      t[i][j] = cnt%10;
    }

  copy(ret,t);
}

void powm(int n, int m[][BUF]){
  if(n==1){
    copy(m,b);
    return;
  }

  int tmp[BUF][BUF];
  
  powm(n/2,tmp);
  
  multiple(tmp,tmp,m);

  if(n%2==1) multiple(b,m,m);
}

void rec(int n, int m[][BUF]){
  if(n==1){
    copy(m,b);
    return;
  }

  rec(n/2,m);

  int tmp[BUF][BUF];

  powm(n/2,tmp);
  
  for(int i=0;i<N;i++) tmp[i][i]++;
  
  multiple(m,tmp,m);
  
  if(n%2==1){
    powm(n,tmp);
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	m[i][j] = (m[i][j]+tmp[i][j])%10;
  }
}

void work(){
  int ans[BUF][BUF];

  rec(K,ans);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(j) cout << ' ';
      cout << ans[i][j];
    }cout << endl;
  }cout << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
