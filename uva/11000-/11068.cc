#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

double a[2], b[2], c[2];

bool read(){
  for(int i=0;i<2;i++)
    cin >> a[i] >> b[i] >> c[i];
  
  if(a[0]==0 && b[0]==0) return false;
    
  return true;
}

void work(){
  if(a[0]*b[1]==a[1]*b[0]) cout << "No fixed point exists." << endl;
  else{
    if(b[0]==0) swap(a[0],a[1]), swap(b[0],b[1]), swap(c[0],c[1]);

    double x = (c[1]-b[1]*c[0]/b[0])/(a[1]-b[1]*a[0]/b[0]);
    double y = (c[0]-a[0]*x)/b[0];

    printf("The fixed point is at %.2lf %.2lf.\n",x,y);
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
