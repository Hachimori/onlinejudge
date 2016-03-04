#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<utility>
#include<cassert>

#define MAX_SIZE 105

using namespace std;

class Area{
public:

  double x,y,r;

  Area(){}
  Area(double x, double y, double r): x(x), y(y), r(r) {}
  
};

int nArea;
Area areaList[MAX_SIZE];
double eventPoint[MAX_SIZE*2];

bool read(){
  
  cin >> nArea;
  if(nArea==0) return false;

  for(int i=0;i<nArea;i++){
    cin >> areaList[i].x >> areaList[i].y >> areaList[i].r;
  
    eventPoint[i*2]=areaList[i].y-areaList[i].r;
    eventPoint[i*2+1]=areaList[i].y+areaList[i].r;
  }


  return true;
}

bool myGreat(const pair<double,double> &a, const pair<double,double> &b){
  if(a.first<b.first) return true;
  else if(a.first==b.first)
    return a.second<b.second;

  return false;
}

double calcXRange(int event){
  
  vector< pair<double,double> > range;
  
  for(int i=0;i<nArea;i++)
    if(areaList[i].y-areaList[i].r<=eventPoint[event] &&
       eventPoint[event]<areaList[i].y+areaList[i].r){
      
      range.push_back( make_pair(areaList[i].x-areaList[i].r,
				 areaList[i].x+areaList[i].r) );
      
    }
  

  sort(range.begin(),range.end(),myGreat);
  
  
  double sum=0;
  
  for(int i=0;i<range.size();i++){

    double start=range[i].first;
    double end = range[i].second;

    while(i+1<range.size() && range[i+1].first<=end){
      end = max(end,range[i+1].second);
      i++;
    }
    
    sum+=end-start;
    
  }
  
  return sum;
}

void work(int cases){
  
  sort(eventPoint,eventPoint+nArea*2);
  
  
  
  double sum=0;
  
  for(int i=0;i<nArea*2-1;i++){
    double xRange = calcXRange(i);
    
    sum+=xRange*(eventPoint[i+1]-eventPoint[i]);
  }
  
  printf("%d %.2lf\n",cases,sum);
}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);
    
  return 0;
}
