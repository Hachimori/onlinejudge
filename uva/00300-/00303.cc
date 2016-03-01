// geometry
// 
// 
// $BA4$F$NE@$+$iG$0U$NFsE@$rA*$S!"D>@~$r:n$k!#(B
// $B$"$H$O!"$=$ND>@~$H%Q%$%W$N8r:9H=Dj$r$7$F8r:9$7$?:G$b6a$/$N>l=j$r=PNO!#(B
// 
// $B2?8N$3$NJ}K!$,M-8z$J$N$+$H$$$&$H!"%Q%$%W$NF~$j8}$+$i8w$rH/<M$7$F!"(B
// $B8w$r$J$k$Y$/1s$/$XHt$P$9$?$a$K79$-$rJQ$($?$j;OE@$rF0$+$7$?$j$7$F(B
// $B8B3&$^$GF0$+$7$?7k2L!"$=$ND>@~$OM?$($i$l$?E@$N$&$A$NFsE@$NDL$k$+$i$G$"$k!#(B
// 
// $BJL$N%$%a!<%8$H$7$F$O!"$J$k$Y$/1s$/$KHt$P$=$&$H79$-$r>/$7$:$DJQ$($F$$$C$F!"(B
// $B%Q%$%W$N6J$,$j3Q$K$V$D$+$j!"$=$l0J>e79$1$k$H5wN%$,=L$`$N$G(B
// $B79$1$i$l$J$/$J$C$?$H$-$N3QEY$,$=$ND>@~$N8B3&$G$"$j!"$=$ND>@~$O%Q%$%W$NE@$rDL$k$3$H$,$$$($k!#(B

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
  
  // $B>eB&$N%Q%$%W$NC<E@$rDL$j!"%Q%$%W$,2<8~$-$J$i$P8r:9$7$F$$$k$H8+$J$9(B
  if(low==0 && ccw(a1,a2,b1)==0 && ccw(a1,a2,b2)==-1) return true;

  // $B2<B&$N%Q%$%W$NC<E@$rDL$j!"%Q%$%W$,>e8~$-$J$i$P8r:9$7$F$$$k$H8+$J$9(B
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
	  
	  // $BD>@~$OF~$j8}$NCf$rDL$C$F$J$/$F$O$J$i$J$$(B
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
