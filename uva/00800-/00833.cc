#include<iostream>
#include<complex>
#include<algorithm>

#define LEFT 0
#define RIGHT 1
#define MAX_SIZE 1000

using namespace std;

class Segment{
public:
  double tend;
  int dropPos;
  complex<int> src, dst;

  Segment(){}
  Segment(complex<int> s, complex<int> d): src(s), dst(d){}

  void calc(){
    tend = (double)(src.imag()-dst.imag())/(src.real()-dst.real());
    
    if(tend<0)
      dropPos = RIGHT;
    else
      dropPos = LEFT;
  }
};

int nSegment, nDrop;
Segment sList[MAX_SIZE];
complex<int> drop[MAX_SIZE];

void read(){
  cin >> nSegment;
  for(int i=0;i<nSegment;i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1<x2)
      sList[i] = Segment(complex<int>(x1,y1),complex<int>(x2,y2));
    else
      sList[i] = Segment(complex<int>(x2,y2),complex<int>(x1,y1));

    sList[i].calc();
  }
  
  cin >> nDrop;
  for(int i=0;i<nDrop;i++){
    int x,y;
    cin >> x >> y;

    drop[i] = complex<int>(x,y);
  }
}

bool calcDrop(complex<int> &curr){
  int maxPos = -1;
  double maxHeight = -1;
  
  for(int i=0;i<nSegment;i++){
    if(!(sList[i].src.real()<curr.real() && curr.real()<sList[i].dst.real())) continue;
    
    if(sList[i].tend*(curr.real()-sList[i].src.real())+sList[i].src.imag()>=curr.imag()) continue;
    
    if(maxHeight<sList[i].tend*(curr.real()-sList[i].src.real())+sList[i].src.imag()){
      maxHeight = sList[i].tend*(curr.real()-sList[i].src.real()+sList[i].src.imag());
      maxPos = i;
    }
  }
  
  if(maxPos==-1) return false;
  
  if(sList[maxPos].dropPos==LEFT) curr = sList[maxPos].src;
  else curr = sList[maxPos].dst;

  return true;
}

void work(){
  /*
  for(int i=0;i<nSegment;i++)
    cout << sList[i].src.real() << ' ' << sList[i].dst.real() << endl;
  */
  for(int i=0;i<nDrop;i++){
    complex<int> curr = drop[i];
    while(calcDrop(curr));
    
    cout << curr.real() << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}
