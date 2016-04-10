#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_Y 400000

using namespace std;

class Point{
public:

  int x, y;

  Point(){}
  Point(int x, int y) : x(x), y(y){}

  bool operator< ( const Point &p) const {
    return (y<p.y || ( y==p.y && x<p.x));
  }
  
};

int nPoint;
vector<Point> pList;
vector<int> xList[MAX_Y*2];

bool read(){
  if(!(cin >> nPoint)) return false;
  
  pList.clear();
  

  for(int i=0;i<nPoint;i++){
    Point p;
    cin >> p.x >> p.y;
    
    p = Point(p.x,p.y+MAX_Y);

    pList.push_back(p);
    xList[p.y].push_back(p.x);
  }
  
  return true;
}

void work(){
  
  for(int i=0;i<nPoint;i++){
    sort(xList[pList[i].y].begin(),xList[pList[i].y].end());
    
    
    //for(int j=0;j<xList[pList[i].y].size();j++){
    //  cout << xList[pList[i].y][j] << " " << pList[i].y << endl;
    //}

  }//cout << endl;

  int minPoint=0;
  
  for(int i=0;i<nPoint;i++){

    
    Point currP = pList[i];
    int cnt=1;
    bool succeed=false;

    while(true){
      
      if(currP.y==pList[i].y)
	for(int k=0;k<xList[currP.y+2].size();k++)
	  if(currP.x<xList[currP.y+2][k]){
	    currP = Point(xList[currP.y+2][k],currP.y+2);
	    cnt++;
	    succeed=true;
	    break;
	  }
      
      if(!succeed) break;
      succeed=false;

      if(currP.y==pList[i].y+2)
	for(int k=0;k<xList[currP.y-2].size();k++)
	  if(currP.x<xList[currP.y-2][k]){
	    currP = Point(xList[currP.y-2][k],currP.y-2);
	    cnt++;
	    succeed=true;
	    break;
	  }	

      if(!succeed) break;
      succeed=false;

    }
         
    if(minPoint<cnt)
      minPoint = cnt;

 

    currP = pList[i];
    cnt=1;
    succeed=false;
    
    while(true){

      if(currP.y==pList[i].y)
	for(int k=0;k<xList[currP.y-2].size();k++)
	  if(currP.x<xList[currP.y-2][k]){
	    currP = Point(xList[currP.y-2][k],currP.y-2);
	    cnt++;
	    succeed=true;
	    break;
	  }
      
      if(!succeed) break;
      succeed=false;

      if(currP.y==pList[i].y-2)
	for(int k=0;k<xList[currP.y+2].size();k++)
	  if(currP.x<xList[currP.y+2][k]){
	    currP = Point(xList[currP.y+2][k],currP.y+2);
	    cnt++;
	    succeed=true;
	    break;
	  }	

      if(!succeed) break;
      succeed=false;

    }     
    
    if(minPoint<cnt)
      minPoint = cnt;

  }

  cout << minPoint << endl;

  
  for(int i=0;i<nPoint;i++)
    xList[pList[i].y].clear();
  

}

int main(){

  while(read())
    work();

  return 0;
}
