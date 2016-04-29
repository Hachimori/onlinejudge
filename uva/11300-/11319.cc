#include<iostream>
#include<cmath>
#define EPS (1e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LE(x,y) (x<=y+EPS)
using namespace std;
const int BUF = 1500, SUB = 7;

unsigned long long b[BUF];

void read(){
  for(int i=0;i<BUF;i++) cin >> b[i];
}

unsigned long long mypow(int p, int n){
  if(n==0) return 1;
  unsigned long long t = mypow(p,n/2);
  return n%2==0 ? t*t : t*t*p;
}

void work(){
  double mat[SUB][SUB+1];

  for(int i=0;i<SUB;i++)
    for(int j=0;j<=SUB;j++)
      mat[i][j] = j==SUB ? b[i] : mypow(i+1,j);

  for(int r=0;r<SUB;r++){
    for(int c=r+1;c<=SUB;c++) mat[r][c] /= mat[r][r];
    mat[r][r] = 1;

    for(int rr=0;rr<SUB;rr++)
      if(r!=rr){
        for(int c=r+1;c<=SUB;c++)
          mat[rr][c] -= mat[rr][r]*mat[r][c];
        mat[rr][r] = 0;
      }
  }

  int a[SUB];
  for(int i=0;i<SUB;i++){
    double v = mat[i][SUB];
    if(!(LE(0,v) && LE(v,1000) && EQ(v,(int)(v+0.5)))){
      cout << "This is a smart sequence!" << endl;
      return;
    }
    a[i] = (int)(v+0.5);
  }
   
  for(int i=0;i<BUF;i++){
    unsigned long long toCmp = 0;
    for(int j=0;j<SUB;j++)
      toCmp += a[j]*mypow(i+1,j);
    if(toCmp!=b[i]){
      cout << "This is a smart sequence!" << endl;
      return;
    }
  }

  for(int i=0;i<SUB;i++){
    if(i) cout << ' ';
    cout << a[i];
  }cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
