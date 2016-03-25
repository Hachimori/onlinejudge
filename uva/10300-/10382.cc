#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

#define MAX_SIZE 10005

using namespace std;

class Sprin{
public:

  double pos;
  double rad;
  
  Sprin(){}
  Sprin(double pos, double rad): pos(pos), rad(rad){}
};

int nCircle, minNum;
Sprin sprinList[MAX_SIZE];
double coverWidth, height;

bool read(){
  
  if(!(cin >> nCircle >> coverWidth >> height)) return false;
  
  for(int i=0;i<nCircle;i++)
    cin >> sprinList[i].pos >> sprinList[i].rad;
  
  return true;
}

bool compare(const pair<double,double> a, const pair<double,double> b){

  if(a.first<b.first) return true;
  else if(a.first==b.first) return a.second<b.second;
  
  return false;
}

void work(){
  
  vector< pair<double,double> > segmentList;

  for(int i=0;i<nCircle;i++){
    
    double b=-2*sprinList[i].pos; 
    double c=sprinList[i].pos*sprinList[i].pos+
             (height*height)/4-(sprinList[i].rad*sprinList[i].rad);
    
    if(b*b-4*c<=0) continue;
    
    double begin=(-b-sqrt(b*b-4*c))/2, end=(-b+sqrt(b*b-4*c))/2;
    
    segmentList.push_back(make_pair(begin,end));

  }

  sort(segmentList.begin(),segmentList.end(),compare);

  /*
  for(int i=0;i<segmentList.size();i++){
    cout << segmentList[i].first << ' ' << segmentList[i].second << endl;
  }cout << "----" << endl << endl;
  */

  minNum=0;
  double currPos = 0.0;
  
  //greedy
  for(int i=0;i<segmentList.size();i++){
    int nextCursor=-1;
    double maxVal=currPos;
    //cout << currPos << endl;
    if(coverWidth<=currPos)
      break;

    for(int j=i;j<segmentList.size();j++){
      if(segmentList[j].first<=currPos && currPos<=segmentList[j].second) {
	nextCursor=j;
	
	if(maxVal<segmentList[j].second)
	  maxVal=segmentList[j].second;
      }
    }
    
    if(maxVal==currPos) {
      cout << "-1" << endl;      
      return;
    }
    
    i=nextCursor;
    minNum++;
    currPos=maxVal; 
  }
  
  if(coverWidth<=currPos) cout << minNum << endl;
  else cout << "-1" << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
