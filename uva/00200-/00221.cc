#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

#define MAX_SIZE 106

using namespace std;

class Building{
public:

  int x,y,width,height,id;

  Building(){}
  Building(int x, int y, int w, int h, int id): x(x), y(y), width(w), height(h), id(id) {}
  
  bool operator< ( const Building  &b) const {

    if(x<b.x) return true;
    else if(x==b.x) {
      return y<b.y;
    }

    return false;
  }
  
};

int nBuilding;
Building bList[MAX_SIZE];

bool read(){

  cin >> nBuilding;
  if(nBuilding==0) return false;
  
  
  for(int i=0;i<nBuilding;i++){
    int dummy;
    cin >> bList[i].x >> bList[i].y >> bList[i].width 
	>> dummy >> bList[i].height;

    bList[i].id = i+1;
  }

  return true;

}

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
  
  if(a.first<b.first) return true;
  else if(a.first==b.first) return a.second<b.second;

  return false;
}

bool isVisible(int id){
    
  vector< pair<int,int> > segmentList;
  
  for(int i=0;i<nBuilding;i++){
    
    if(bList[i].y<bList[id].y && bList[id].height<=bList[i].height)
      segmentList.push_back(make_pair(bList[i].x,bList[i].x+bList[i].width));
      
  }


  sort(segmentList.begin(),segmentList.end(),cmp);
  
  /*
  for(int i=0;i<segmentList.size();i++)
    cout << segmentList[i].first << ' ' << segmentList[i].second << endl;
  cout << endl;
  */
  
  int currCovered=bList[id].x;

  for(int i=0;i<segmentList.size();i++){    
    if(segmentList[i].first<=currCovered && currCovered<=segmentList[i].second)
      currCovered=segmentList[i].second;
  }
  
  return currCovered<bList[id].x+bList[id].width;
}

void work(int cases){
  
  bool visible[MAX_SIZE];
  fill(visible,visible+nBuilding,true);
  
  
  for(int i=0;i<nBuilding;i++)      
    if(!isVisible(i)) 
      visible[i]=false;


  vector<Building> ansList;

  for(int i=0;i<nBuilding;i++)
    if(visible[i])
      ansList.push_back(bList[i]);
  
  sort(ansList.begin(),ansList.end());
  

  cout << "For map #" << cases << ", the visible buildings are numbered as follows:" << endl;
  
  for(int i=0;i<ansList.size();i++){
    if(i==0) cout << ansList[i].id;
    else cout << ' ' << ansList[i].id;
  }

  cout << endl;
  
  
}

int main(){

  for(int i=1;read();i++){
    cout << endl;
    work(i);
  }

  return 0;

}
