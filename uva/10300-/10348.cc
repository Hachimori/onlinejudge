#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_SUBMARINE 105
#define MAX_ISLAND 55

using namespace std;

class Point{
public:

  double x,y;

  Point(){}
  Point(double x, double y): x(x), y(y){}
  
  Point operator-(Point p){
    return Point(x-p.x,y-p.y);
  }
  
  double operator*(Point p){
    return x*p.y-y*p.x;
  }
  
};

class Segment{
public:

  Point begin, end;

  Segment(){}
  Segment(Point b, Point e): begin(b), end(e){}

};

int nSubmarine, nIsland;
Segment sList[MAX_SUBMARINE];
vector<Segment> islandList[MAX_ISLAND];

void read(){
  
  cin >> nSubmarine;

  for(int i=0;i<nSubmarine;i++)
    cin >> sList[i].begin.x >> sList[i].begin.y 
	>> sList[i].end.x >> sList[i].end.y;

  cin >> nIsland;
  for(int i=0;i<nIsland;i++){
    int nPoint;
    cin >> nPoint;

    Point prev, curr;
    cin >> prev.x >> prev.y;
    for(int j=1;j<nPoint;j++){
      cin >> curr.x >> curr.y;

      islandList[i].push_back(Segment(prev,curr));
      prev=curr;
    }      
  }
  
}

double side(Point p, Segment s){  
  Point a=p-s.begin;
  Point b=s.end-s.begin;

  return a*b;  
}

bool isIntersect(int sId, int landId){

  for(int i=0;i<islandList[landId].size();i++){
  
    if(max(sList[sId].begin.x,sList[sId].end.x)<min(islandList[landId][i].begin.x,islandList[landId][i].end.x)) continue;
    if(max(sList[sId].begin.y,sList[sId].end.y)<min(islandList[landId][i].begin.y,islandList[landId][i].end.y)) continue;
    if(max(islandList[landId][i].begin.x,islandList[landId][i].end.x)<min(sList[sId].begin.x,sList[sId].end.x)) continue;
    if(max(islandList[landId][i].begin.y,islandList[landId][i].end.y)<min(sList[sId].begin.y,sList[sId].end.y)) continue;

    if( side(sList[sId].begin,islandList[landId][i])*side(sList[sId].end,islandList[landId][i])<=0 &&
	side(islandList[landId][i].begin,sList[sId])*side(islandList[landId][i].end,sList[sId])<=0 ) return true;
	
  }
  
  return false;
}

bool isInside(int sId, int landId){
  
  int nIntersect=0;
  Segment horizon=Segment(sList[sId].begin,Point(2000,sList[sId].begin.y));
  
  for(int i=0;i<islandList[landId].size();i++)
    if(islandList[landId][i].begin.y>islandList[landId][i].end.y)
      swap(islandList[landId][i].begin,islandList[landId][i].end);
    
  for(int i=0;i<islandList[landId].size();i++){
  
    if(max(horizon.begin.x,horizon.end.x)<min(islandList[landId][i].begin.x,islandList[landId][i].end.x)) continue;
    if(max(horizon.begin.y,horizon.end.y)<min(islandList[landId][i].begin.y,islandList[landId][i].end.y)) continue;
    if(max(islandList[landId][i].begin.x,islandList[landId][i].end.x)<min(horizon.begin.x,horizon.end.x)) continue;
    if(max(islandList[landId][i].begin.y,islandList[landId][i].end.y)<min(horizon.begin.y,horizon.end.y)) continue;

    if(islandList[landId][i].begin.y<=horizon.begin.y && horizon.begin.y<islandList[landId][i].end.y) nIntersect++;
  }
  
  return nIntersect%2==1;
}

void work(){
  

  for(int i=0;i<nSubmarine;i++){

    bool finished=false;

    cout << "Submarine " << i+1 << " is ";

    for(int j=0;j<nIsland;j++)
      if(isIntersect(i,j)) {
	cout << "partially on land." << endl;
	finished=true;
	break;
      }
    
    if(finished) continue;
    
    for(int j=0;j<nIsland;j++)
      if(isInside(i,j)){
	cout << "completely on land." << endl;
	finished=true;
	break;
      }
	
    if(finished) continue;
    
    cout << "still in water." << endl;

  }
  
}

int main(){

  read();
  work();

  return 0;
}
