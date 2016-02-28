// geometry
//
// convex hull を作る際、直線上にある点も含まなくてはならない。

#include<iostream>
#include<cstdio>
#include<complex>
#include<cfloat>
#include<vector>

#define INF 1000000
#define PI acos(-1.0)
#define EPS FLT_EPSILON
#define MAX_SIZE 10000
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)-(y)>=EPS)
#define LT(x,y) ((x)-(y)<=-EPS)

using namespace std;

class Segment{
public:

  complex<double> src, dst;

  Segment(){}
  Segment(complex<double> s, complex<double> d): src(s), dst(d){}

  double angle(const complex<double> &p){
    complex<double> vec1 = dst-src, vec2 = p-src;
    
    if(EQ(abs(vec2),0)) return 2*PI;
    if(EQ(dot(vec1,vec2)/(abs(vec1)*abs(vec2)),-1)) return PI;
    
    return acos(dot(vec1,vec2)/(abs(vec1)*abs(vec2)));
  }

private:
  double dot(const complex<double> &p, const complex<double> &q){
    return real(conj(p)*q);
  }
};

int nPoint;
complex<double> point[MAX_SIZE];

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  for(int i=0;i<nPoint;i++){
    double x,y;
    cin >> x >> y;
    point[i] = complex<double>(x,y);
  }
  
  return true;
}

void findConvex( vector< complex<double> > &convex ) {
  int first = 0;
  complex<double> firstP = point[0];
 
  for(int i=0;i<nPoint;i++)
    if(firstP.real()==point[i].real() && firstP.imag()<point[i].imag()){
      firstP = point[i];
      first = i;
    }
    else if(firstP.real()>point[i].real()){
      firstP = point[i];
      first = i;
    }
  
  convex.push_back(firstP);

  bool used[MAX_SIZE];
  
  for(int i=0;i<nPoint;i++)
    used[i] = false;
  used[first] = true;
  
  Segment currSeg = Segment(firstP,complex<double>(firstP.real(),firstP.imag()+1));
  
  while(true){
    int minPos = -1;
    double minAngle = PI, minDist = INF;
    
    for(int i=0;i<nPoint;i++){
      if(used[i]) continue;
      
      if(EQ(minAngle,currSeg.angle(point[i])) && minDist>abs(currSeg.src-point[i])){
	minAngle = currSeg.angle(point[i]);
	minDist = abs(currSeg.src-point[i]);
	minPos = i;
      }
      else if(GT(minAngle,currSeg.angle(point[i]))){
	minAngle = currSeg.angle(point[i]);
	minDist = abs(currSeg.src-point[i]);
	minPos = i;
      }
    }
    
    if(minPos==-1) break;
    if(GT(minAngle,currSeg.angle(point[first]))) break;
    
    convex.push_back(point[minPos]);
    used[minPos] = true;
    currSeg = Segment(point[minPos],2.0*point[minPos]-currSeg.src);
  } 
}

void work(int cases){
  vector< complex<double> > convex;
 
  findConvex(convex);
  
  double total = 0;
  cout << "Region #" << cases << ":" << endl;
  for(int i=0;i<convex.size();i++){
    printf("(%.1lf,%.1lf)-",convex[i].real(),convex[i].imag());
    total += abs(convex[i]-convex[(i+1)%convex.size()]);
  }
  printf("(%.1lf,%.1lf)\n",convex[0].real(),convex[0].imag());
  
  printf("Perimeter length = %.2lf\n",total);
}

int main(){
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work(i+1);
  }
  
  return 0;
}
