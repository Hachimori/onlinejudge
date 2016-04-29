#include<iostream>
#include<cmath>
#define EPS 1e-8
using namespace std;

bool isInteger(double v){
  int vInt = (int)(v+0.5);
  return fabs(v-vInt)<EPS;
}

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int n;
    cin >> n;
    for(int a=0;a*a<=n;a++)
      for(int b=0;a*a+b*b<=n;b++){
        double c = sqrt(n-a*a-b*b);
        if(c<b-EPS) break;
        if(isInteger(c)){
          cout << a << ' ' << b << ' ' << (int)(c+0.5) << endl;
          goto success;
        }
      }
    cout << -1 << endl;
  success:;
  }
  return 0;
}
