#include<iostream>
#include<complex>
#include<cmath>
#include<algorithm>

#define INF 100000000
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define PI acos(-1.0)
#define MAX_SIZE 55

using namespace std;

typedef complex<double> Point;

int nGon, leng[MAX_SIZE];
Point point[MAX_SIZE], center = Point(0,0);

bool read(){
  cin >> nGon;
  if(nGon==0) return false;
  
  for(int i=0;i<nGon;i++)
    cin >> leng[i];
  
  for(int i=0;i<nGon;i++)
    point[i] = polar(1.0,2*PI*i/nGon)*Point(0.0,1.0);
  
  return true;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);
  
  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

bool isValid(int chose[], int nChose){
  for(int i=0;i<nChose;i++)
    if(ccw(point[chose[i]],point[chose[(i+1)%nChose]],center)<=0) return false;
  
  return true;
}

void rec(int curr, int nChose, int chose[], int curMin, int &limit, int &maxV){
  if(curMin<=maxV) return;
  
  if(nChose==limit){
    if(isValid(chose,nChose)) maxV = curMin;
    return;
  }
  
  for(int i=curr;i<nGon;i++){
    chose[nChose] = i;
    rec(i+1,nChose+1,chose,min(curMin,leng[i]),limit,maxV);
  }
}

void work(){
  int toSet = -1;
  
  for(int i=3;i<=4;i++){
    int chosen[MAX_SIZE];
    rec(0,0,chosen,INF,i,toSet);
  }

  int sum = 0;
  for(int i=0;i<nGon;i++)
    if(toSet<leng[i])
      sum += leng[i]-toSet;

  cout << sum << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}

