// Geometry
//
// 点と点をつないでダイクストラ
// 点と点を繋ぐ際、壁にぶつかるかどうか調べる必要がある。
// 

#include<iostream>
#include<complex>
#include<cfloat>
#include<algorithm>
#include<cstdio>

#define EPS FLT_EPSILON
#define START 0
#define GOAL 1
#define INF 1000
#define MAX_SIZE 100
#define MAX_POINT 200

using namespace std;

class Segment{
public:
  complex<double> src, dst;
  
  Segment(){}
  Segment(complex<double> s, complex<double> d): src(s), dst(d) {}
  
  bool isIntersect(const Segment &s){
    if( min(src.real(),dst.real()) > max(s.src.real(),s.dst.real()) ) return false;
    if( min(src.imag(),dst.imag()) > max(s.src.imag(),s.dst.imag()) ) return false;
    if( min(s.src.real(),s.dst.real()) > max(src.real(),dst.real()) ) return false;
    if( min(s.src.imag(),s.dst.imag()) > max(src.imag(),dst.imag()) ) return false;
    
    return (0>=cross(src,dst,s.src)*cross(src,dst,s.dst) && 
	    0>=cross(s.src,s.dst,src)*cross(s.src,s.dst,dst) );
  }
  
private:
  double cross(complex<double> o, complex<double> p, complex<double> q){
    return cross(p-o,q-o);
  }
  
  double cross(complex<double> p, complex<double> q){
    return imag(conj(p)*q);
  }
  
  double dot(complex<double> p, complex<double> q){
    return real(conj(p)*q);
  }
};

int nSegment, nPoint;
complex<double> point[MAX_POINT];
Segment sList[MAX_SIZE];

bool read(){
  int nWall;
  cin >> nWall;

  if(nWall==-1) return false;

  nSegment = 0;
  point[START] = complex<double>(0,5);
  point[GOAL] = complex<double>(10,5);

  nPoint = 2;
  
  for(int i=0;i<nWall;i++){
    double x,y1,y2; 
    cin >> x >> y1;
      
    sList[nSegment] = Segment(complex<double>(x,-INF),complex<double>(x,y1));
    point[nPoint++] = sList[nSegment].src;
    point[nPoint++] = sList[nSegment].dst;
    point[nPoint-1] = complex<double>(sList[nSegment].dst.real(), 
				      sList[nSegment].dst.imag()+EPS);
    
    cin >> y1 >> y2; 
    sList[nSegment+1] = Segment(complex<double>(x,y1),complex<double>(x,y2));
    point[nPoint++] = sList[nSegment+1].src;
    point[nPoint-1] = complex<double>(sList[nSegment+1].src.real(), 
				      sList[nSegment+1].src.imag()-EPS);
    point[nPoint++] = sList[nSegment+1].dst;
    point[nPoint-1] = complex<double>(sList[nSegment+1].dst.real(), 
				      sList[nSegment+1].dst.imag()+EPS);

    cin >> y1;
    sList[nSegment+2] = Segment(complex<double>(x,y1),complex<double>(x,INF));
    point[nPoint++] = sList[nSegment+2].src;
    point[nPoint-1] = complex<double>(sList[nSegment+2].src.real(), 
				      sList[nSegment+2].src.imag()-EPS);
    point[nPoint++] = sList[nSegment+2].dst;


    nSegment += 3;
  }

  return true;
}

void dijkstra(double adjList[][MAX_POINT]){
  double cost[MAX_POINT];
  bool visited[MAX_POINT];
  
  for(int i=0;i<nPoint;i++){
    cost[i] = INF;
    visited[i] = false;
  }

  cost[START] = 0;

  for(int i=0;i<nPoint;i++){
    int minPos=-1; 
    double minVal=INF;
    for(int j=0;j<nPoint;j++)
      if(minVal>cost[j] && !visited[j]){
	minVal = cost[j];
	minPos = j;
      }
    
    if(minPos==-1) break;
    visited[minPos] = true;
    
    for(int j=0;j<nPoint;j++)
      if(cost[j]>minVal+adjList[minPos][j])
	cost[j] = minVal+adjList[minPos][j];
  }

  printf("%.2lf\n",cost[GOAL]);
}

void work(){
  double adjList[MAX_POINT][MAX_POINT];
  
  for(int i=0;i<nPoint;i++){
    for(int j=i+1;j<nPoint;j++){
      bool succeed = true;
      
      for(int k=0;k<nSegment;k++)
	if(sList[k].isIntersect(Segment(point[i],point[j]))){
	  succeed = false;
	  break;
	}

      if(succeed){
	adjList[i][j] = abs(point[i]-point[j]);
	adjList[j][i] = abs(point[i]-point[j]);
      }
      else {
	adjList[i][j] = INF;
	adjList[j][i] = INF;
      }
    }
  }
  
  dijkstra(adjList);
  
}

int main(){
  while(read())
    work();
  
  return 0;
}
