#include<iostream>
#include<complex>
#include<cstdio>
#define EPS (1e-7)
#define LE(x,y) (x<=y+EPS)
using namespace std;
const int BUF = 105;

class Bar{
public:
  double x1, x2, height;
  Bar(){}
  Bar(double x1, double x2, double height):
    x1(x1), x2(x2), height(height){}
};

int nBar[2];
Bar bar[2][BUF];

bool read(){
  for(int i=0;i<2;i++){
    if(!(cin >> nBar[i])) return false;
    double xPos = 0, height;
    for(int j=0;j<nBar[i];j++){
      double toAdd;
      cin >> height >> toAdd;
      bar[i][j] = Bar(xPos,xPos+toAdd,height);
      xPos += toAdd;
    }
  }
  return true;
}

bool overlap(Bar b1, Bar b2){
  return LE(max(b1.x1,b2.x1),min(b1.x2,b2.x2));
}

double calc(int n1, Bar b1[BUF], int n2, Bar b2[BUF]){
  double ret = 1<<30;
  for(int i=0;i<n1;i++)
    for(int j=0;j<n2;j++)
      if(overlap(b1[i],b2[j]))
        ret = min(ret,max(b1[i].height,b2[j].height));
  return ret;
}


void work(){
  printf("%.3lf\n",calc(nBar[0],bar[0],nBar[1],bar[1]));
}


int main(){
  while(read()) work();
  return 0;
}
