#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int SEGMENT = 10000;

class Data{
public:
  double pos, rate;
  bool isBgn;
  
  Data(){}
  Data(double pos, double rate, bool isBgn): 
    pos(pos), rate(rate), isBgn(isBgn){}

  bool operator< (const Data &data) const {
    return pos<data.pos;
  }
};

int nSegment;
double bgn[SEGMENT], end[SEGMENT], rate[SEGMENT];

void read(){
  cin >> nSegment;
  for(int i=0;i<nSegment;i++){
    double dummy;
    cin >> bgn[i] >> dummy >> end[i] >> dummy >> rate[i];
    if(bgn[i]>end[i]) swap(bgn[i],end[i]);
  }
}

void work(){
  int nData = nSegment*2;
  Data data[SEGMENT];
  for(int i=0;i<nSegment;i++){
    data[i*2  ] = Data(bgn[i],rate[i],true);
    data[i*2+1] = Data(end[i],rate[i],false);
  }
  sort(data,data+nData);

  double curRate = 1.0;
  printf("%d\n",nData+1);
  printf("-inf %.3lf %.3lf\n",data[0].pos,curRate);
  for(int i=0;i+1<nData;i++){
    curRate *= data[i].isBgn ? data[i].rate : 1/data[i].rate;
    printf("%.3lf %.3lf %.3lf\n",data[i].pos,data[i+1].pos,curRate);
  }
  printf("%.3lf +inf %.3lf\n",data[nData-1].pos,1.);
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
