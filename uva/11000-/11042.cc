#include<iostream>
#include<complex>
#define LIMIT (1<<30)
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
typedef complex<double> Vector;

Vector init;

void read(){
  int x, y;
  cin >> x >> y;

  init = Vector(x,y);
}

Vector vPow(Vector p, int n){
  Vector ret = p;
  for(int i=0;i<n-1;i++)
    ret *= p;
  return ret;
}

void work(){
  if(EQ(init.imag(),0)){
    cout << 1 << endl;
    return;
  }
  
  for(int i=2;;i+=2){
    Vector ret = vPow(init,i);
    if(abs(ret)>LIMIT) break;
    if(EQ(ret.imag(),0)){
      cout << i << endl;
      return;
    }
  }

  cout << "TOO COMPLICATED" << endl;
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
