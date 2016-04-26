#include<iostream>
#include<cmath>
#define PI acos(-1.0)
using namespace std;

int main(){
  int a, b, v, A, s;

  while(cin >> a >> b >> v >> A >> s){
    if(!(a|b|v|a|s)) break;
    
    double vx = v*cos(A*PI/180), vy = v*sin(A*PI/180);
    double x = vx*s/2, y = vy*s/2;
    
    cout << (int)(x/a+0.5) << ' ' << (int)(y/b+0.5) << endl;
  }
  
  return 0;
}
