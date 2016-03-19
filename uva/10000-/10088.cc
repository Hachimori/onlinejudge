// Pick's Theorem
// 10088
//
// 多角形の面積:             S
// 多角形内の格子点の数:     A
// 多角形の辺上の格子点の数: B
//
// とすると, S = A + B/2 - 1 がなりたつ。

#include<iostream>
#include<complex>

#define MAX_SIZE 1005

using namespace std;

typedef complex<long long> Point;


int nPoint;
Point point[MAX_SIZE];

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  for(int i=0;i<nPoint;i++){
    long long x, y;
    cin >> x >> y;

    point[i] = Point(x,y);
  }

  return true;
}

double calcArea(){
  double sum=0;
  
  for(int i=0;i<nPoint;i++)
    sum += (point[i].real()-point[(i+1)%nPoint].real())*
           (point[i].imag()+point[(i+1)%nPoint].imag());
  
  return fabs(sum)/2;
}

long long gcd(long long a, long long b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

long long nOnGrid(Point a, Point b){
  long long dx=labs(a.real()-b.real()),dy=labs(a.imag()-b.imag());
  
  return gcd(dx,dy)+1;
}

long long calcOnGrid(){
  long long sum=0;
  
  for(int i=0;i<nPoint;i++)
    sum+=nOnGrid(point[i],point[(i+1)%nPoint]);

  sum -= nPoint;
  
  return sum;
}

void work(){
  double S,A;
  long long B;
  
  S = calcArea();
  B = calcOnGrid();
  A = S-B/2.0+1;
  
  cout << (long long)(A+0.5) << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
