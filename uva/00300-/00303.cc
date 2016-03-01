// geometry
// 
// 
// 全ての点から任意の二点を選び、直線を作る。
// あとは、その直線とパイプの交差判定をして交差した最も近くの場所を出力。
// 
// 何故この方法が有効なのかというと、パイプの入り口から光を発射して、
// 光をなるべく遠くへ飛ばすために傾きを変えたり始点を動かしたりして
// 限界まで動かした結果、その直線は与えられた点のうちの二点の通るからである。
// 
// 別のイメージとしては、なるべく遠くに飛ばそうと傾きを少しずつ変えていって、
// パイプの曲がり角にぶつかり、それ以上傾けると距離が縮むので
// 傾けられなくなったときの角度がその直線の限界であり、その直線はパイプの点を通ることがいえる。

#include<iostream>
#include<complex>
#include<algorithm>
#include<cstdio>

#define EPS (1.0e-7)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define INF 100000000
#define MAX_SIZE 25

using namespace std;

typedef complex<double> Point;

class Segment{
public:
  Point bgn, end;

  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

int nSeg, nPoint;
Point point[2][MAX_SIZE];
Segment seg[2][MAX_SIZE];

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  for(int i=0;i<nPoint;i++){
    double x,y;
    cin >> x >> y;

    point[0][i] = Point(x,y);
    point[1][i] = Point(x,y-1);
  }
    
  for(int i=0;i<nPoint-1;i++){
    seg[0][i] = Segment(point[0][i],point[0][i+1]);
    seg[1][i] = Segment(point[1][i],point[1][i+1]);
  }

  nSeg = nPoint-1;
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

Point calcIntersect(Segment &a, Segment &b){
  Point d1 = Point(a.end-a.bgn), d2 = Point(b.end-b.bgn);

  if(EQ(cross(d1,d2),0)) return b.bgn;

  return a.bgn + d1*cross(b.bgn-a.bgn,d2)/cross(d1,d2);
}

bool isIntersect(Segment &a, Segment &b, int low){
  Point a1, a2, b1, b2;
  
  a1 = a.bgn, a2 = a.end;
  b1 = b.bgn, b2 = b.end;
  
  if(min(a1.real(),a2.real())>max(b1.real(),b2.real())) return  false;
  if(min(a1.imag(),a2.imag())>max(b1.imag(),b2.imag())) return  false;
  if(min(b1.real(),b2.real())>max(a1.real(),a2.real())) return  false;
  if(min(b1.imag(),b2.imag())>max(a1.imag(),a2.imag())) return  false;
  
  // 上側のパイプの端点を通り、パイプが下向きならば交差していると見なす
  if(low==0 && ccw(a1,a2,b1)==0 && ccw(a1,a2,b2)==-1) return true;

  // 下側のパイプの端点を通り、パイプが上向きならば交差していると見なす
  if(low==1 && ccw(a1,a2,b1)==0 && ccw(a1,a2,b2)== 1) return true;

  return (0>ccw(a1,a2,b1)*ccw(a1,a2,b2) && 0>ccw(b1,b2,a1)*ccw(b1,b2,a2));
}

void work(){
  int nDiv = 500;
  double maxX = -INF;
  Segment entrance = Segment(point[0][0],point[1][0]);
   
  if(nSeg==1){
    cout << "Through all the pipe." << endl;
    return;
  }
  
  for(int i=0;i<2;i++){
    for(int j=0;j<nPoint;j++){
      for(int k=0;k<2;k++){
	for(int l=j+1;l<nPoint;l++){
	  Point src = point[i][j], dst = point[k][l];
	  Segment toShot = Segment(src-(dst-src)*1000.0,src+(dst-src)*1000.0);
	  
	  // 直線は入り口の中を通ってなくてはならない
	  if(0<ccw(toShot.bgn,toShot.end,entrance.bgn)*
	       ccw(toShot.bgn,toShot.end,entrance.end)) continue;

	  bool crossed = false;
	  double minX = INF;
	  for(int l=0;l<2;l++)
	    for(int m=0;m<nSeg;m++){	      
	      if(isIntersect(toShot,seg[l][m],l)){
		minX = min(minX,calcIntersect(toShot,seg[l][m]).real());
		crossed = true;
	      }
	    }
	  
	  maxX = max(maxX,minX);
	  if(!crossed){
	    cout << "Through all the pipe." << endl;
	    return;
	  }
	}
      }
    }
  }

  printf("%.2lf\n",maxX);
}

int main(){
  while(read())
    work();
  
  return 0;
}
