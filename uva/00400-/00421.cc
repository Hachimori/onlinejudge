// Geometry
//
// 最初の多角形の辺のリスト、二番目の多角形の辺のリストを
// それぞれ dst, src とする。 src を dst の最初の点に合わせて平行移動、
// 2番目の点に合わせて1番目の点を中心に回転、拡大（縮小）して
// 多角形全体が一致しているかどうか調べる。
//
// このプログラムは、いくつか回転により多角形が一致しているものの候補があったら
// 曲げる角度が小さいものを優先して決定しているが、問題にはそうしろとかかれてないと思う。

#include<iostream>
#include<cstdio>
#include<cmath>
#include<complex>
#include<cassert>
#include<utility>
#include<cfloat>
#include<climits>

#define EPS FLT_EPSILON
#define PI acos(-1.0)
#define MAX_SIZE 100
#define EQ(x,y) (fabs((x)-(y))<(FLT_EPSILON*100))

using namespace std;

int nPolygon, nVertex;
complex<double> dst[MAX_SIZE][MAX_SIZE];
complex<double> src[MAX_SIZE][MAX_SIZE];

bool read(){
  if(!(cin >> nPolygon >> nVertex)) return false;
  assert(nPolygon<MAX_SIZE && nVertex<MAX_SIZE);
  
  for(int i=0;i<nPolygon;i++)
    for(int j=0;j<nVertex;j++){
      double r;
      cin >> r;

      dst[i][j] = polar(r,PI/2-PI*2/nVertex*j);
    }
  
  for(int i=0;i<nPolygon;i++)
    for(int j=0;j<nVertex;j++){
      double x,y;
      cin >> x >> y;

      src[i][j] = complex<double>(x,y);
    }

  return true;
}

double calcDegree(complex<double> &o, complex<double> &a, complex<double> &b){
  complex<double> ret = ((b-o)/abs(b-o))/((a-o)/abs(a-o));
  return arg(ret);
}

double calcRadius(complex<double> &o, complex<double> &a, complex<double> &b){
  return abs((b-o)/(a-o));
}

void rotate(complex<double> &o, complex<double> &c, double &radius, double &angle){
  c = (c-o)*polar(radius,angle)+o;
}

void work(){

  complex<double> toSet[MAX_SIZE];
  complex<double> diff;
  bool used[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    used[i] = false;
  
  for(int curr=0;curr<nPolygon;curr++){
    double minVal = INT_MAX;
    int minPos;
    
    for(int opp=0;opp<nPolygon;opp++){
      if(used[opp]) continue;
      
      for(int start=0;start<nVertex;start++){
	
	int prev = (start-1+nVertex)%nVertex;
	int next = (start+1)%nVertex;
	
	// dest, srcの開始点がなす角度は一致してなくてはならない。
	// 高速化するため必要
	if(!EQ(calcDegree(src[curr][start],src[curr][prev],src[curr][next]),
	       calcDegree(dst[opp][0],dst[opp][nVertex-1],dst[opp][1])) ) continue;
	
	for(int i=0;i<nVertex;i++)
	  toSet[i] = src[curr][i];
	

	diff = dst[opp][0] - toSet[start];
	for(int i=0;i<nVertex;i++)
	  toSet[i] += diff;
	

	
	double angle  = calcDegree(toSet[start],toSet[next],dst[opp][1]);
	double radius = calcRadius(toSet[start],toSet[next],dst[opp][1]);
	
	
	for(int i=next,j=0;j<nVertex-1;i=(i+1)%nVertex,j++)
	  rotate(toSet[start],toSet[i],radius,angle);
	

	
	bool succeed = true;
	for(int i=0,j=start;i<nVertex;i++,j=(j+1)%nVertex)
	  if(abs(toSet[j]-dst[opp][i])>abs(dst[opp][i])*0.001){
	    succeed = false;
	    break;
	  }
	
	if(succeed) {
	  angle *= (-1);
	  if(angle<0)
	    angle += PI*2;
	  
	  if(minVal>angle){
	    minVal = angle;
	    minPos = opp;
	  }
	}
	
      }

    }
    
    used[minPos] = true;
    assert(!EQ(minVal,INT_MAX));
    printf("%d %.1lf\n",minPos+1,180*(minVal)/PI);

  }
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
