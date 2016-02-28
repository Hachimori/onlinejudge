#include<iostream>
#include<map>
#include<complex>
#include<sstream>
#include<cassert>
#include<algorithm>

#define MAX_SIZE 705

using namespace std;

class Point{
public:

  int x,y;

  Point(){}
  Point(int x, int y): x(x), y(y){}

  Point operator-(const Point &p){
    return Point(x-p.x,y-p.y);
  }

  bool operator<(const Point &p) const {
    if(x==p.x) return y<p.y;
    return x<p.x;
  }
};

int nPoint;
Point point[MAX_SIZE];

void read(){
  string buf;
  
  for(nPoint=0;;nPoint++){
    getline(cin,buf);
    if(buf.empty()) break;

    int x, y;
    istringstream in(buf);
    
    if(!(in >> x >> y)) assert(false);
    point[nPoint] = Point(x,y);
  }
}

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

void work(){
  int maxVal = 1;
  map< Point, int > tendCnt[MAX_SIZE];
  
  //sort(point,point+nPoint);
  
  for(int i=0;i<nPoint;i++){
    for(int j=i+1;j<nPoint;j++){

      Point toPush = Point(point[j].x-point[i].x,point[j].y-point[i].y);
      if(toPush.x==0 && toPush.y==0) continue;

      if(toPush.x!=0 && toPush.y!=0){
	int ret = gcd(abs(toPush.x),abs(toPush.y));
	
	toPush.x /= ret;
	toPush.y /= ret;

	if(toPush.x<0){
	  toPush.x *= (-1);
	  toPush.y *= (-1);
	}
      }
      else if(toPush.y==0) toPush.x = 1;
      else if(toPush.x==0) toPush.y = 1;
      
      // 挿入が成功したら, result->first = 挿入した場所, result->second = true となる。
      // 挿入に失敗したら, result->second = false となる。
      // これは、tendCnt[j][toPush]++ や, tendCnt[j][toPush] = 1 として
      // toPush を二度探させないようにさせるための処置である。
      pair< map<Point,int>::iterator, bool > result = tendCnt[j].insert(make_pair(toPush,1));
      
      int tmp;
      if(result.second) continue;
      else
	tmp = ++result.first->second;

      
      if(maxVal<tmp)
	maxVal = tmp;
    }
  }

  cout << maxVal+1 << endl;
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy);  getline(cin,dummy);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}
