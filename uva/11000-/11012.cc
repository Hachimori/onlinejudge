// geometry ad-hoc
//
//
// 1,全ての点を包含する立方体をつくる。
// 2,立方体の８つの頂点からそれぞれ一番近い頂点pを選ぶ。
// 3,pから一番遠い場所にある点の間の距離を求める。
// 4,距離の一番長いものを出力。

#include<iostream>
#include<algorithm>

#define INF 200000000
#define MAX_SIZE 100005

using namespace std;

class Point{
public:
  int x,y,z;

  Point(){}
  Point(int x, int y, int z): x(x), y(y), z(z){}

  int distance(Point &p){
    return abs(x-p.x)+abs(y-p.y)+abs(z-p.z);
  }
};

int nPoint;
Point point[MAX_SIZE];

void read(){
  cin >> nPoint;
  
  for(int i=0;i<nPoint;i++)
    cin >> point[i].x >> point[i].y >> point[i].z;
}

void work(int cases){
  int x[2] = {INF,-INF}, y[2] = {INF,-INF}, z[2] = {INF,-INF};
  for(int i=0;i<nPoint;i++){
    x[0] = min(x[0],point[i].x);
    y[0] = min(y[0],point[i].y);
    z[0] = min(z[0],point[i].z);
    x[1] = max(x[1],point[i].x);
    y[1] = max(y[1],point[i].y);
    z[1] = max(z[1],point[i].z);
  }

  int maxVal = -INF;
  
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++){
	Point curr = Point(x[i],y[j],z[k]);
	int minVal = INF, minId;
	
	for(int l=0;l<nPoint;l++)
	  if(minVal>curr.distance(point[l])){
	    minVal = curr.distance(point[l]);
	    minId = l;
	  }
	
	for(int l=0;l<nPoint;l++)
	  maxVal = max(maxVal,point[minId].distance(point[l]));
      }
  
  cout << "Case #" << cases << ": " << maxVal << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
