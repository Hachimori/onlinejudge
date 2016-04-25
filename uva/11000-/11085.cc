#include<iostream>
#include<vector>
#include<algorithm>
#define INF 100000
using namespace std;

class Point{
public:
  int r, c;

  Point(){}
  Point(int r, int c): r(r), c(c){}

  bool disturb(Point p){
    return (r==p.r || c==p.c || abs(r-p.r)==abs(c-p.c));
  }
};

vector<vector<Point> > goal;

void makeTable(int c, vector<Point> &put){
  if(c==8){
    goal.push_back(put);
    return;
  }

  for(int r=0;r<8;r++){
    bool ok = true;
    for(int i=0;i<c;i++)
      if(put[i].disturb(Point(r,c))){
	ok = false;
	break;
      }
    if(ok){
      put.push_back(Point(r,c));
      makeTable(c+1,put);
      put.pop_back();
    }
  }
}

vector<Point> init;

bool read(){
  init.clear();
  
  for(int c=0;c<8;c++){
    int r;
    if(!(cin >> r)) return false;
    r--;
    init.push_back(Point(r,c));
  }

  return true;
}

void work(int cases){
  int minV = INF;
  
  for(int i=0;i<goal.size();i++){
    int sum = 0;
    for(int j=0;j<goal[i].size();j++)
      sum += goal[i][j].r!=init[j].r;
    minV = min(minV,sum);
  }
  
  cout << "Case " << cases << ": " << minV << endl;
}

int main(){
  vector<Point> put;
  makeTable(0,put);
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
