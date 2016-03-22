// Extended Euclid
// 10104

#include<iostream>
#include<vector>

using namespace std;

class Data{
public:

  int d,x,y;
  
  Data(){}
  Data(int d, int x, int y): d(d), x(x), y(y) {}
  
};

int A,B;

bool read(){
  if(!(cin >> A >> B)) return false;
  return true;
}

int GCD(int a, int b){
  if(b==0) return a;
  else return GCD(b,a%b);
}

Data extendGCD(int a, int b){
  
  if(b==0) return Data(a,1,0);
  
  Data ret = extendGCD(b,a%b);

  return Data(ret.d,ret.y,ret.x-a/b*ret.y);
}

void work(){
  Data data = extendGCD(A,B);
  cout << data.x << ' ' << data.y << ' ' << data.d << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
