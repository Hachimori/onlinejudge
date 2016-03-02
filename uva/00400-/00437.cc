#include<iostream>
#include<algorithm>

#define MAX_SIZE 200

using namespace std;

class Box{
public:

  int x,y,z;

  Box(){}
  Box(int x, int y, int z): x(x), y(y), z(z) {}

  bool operator<(const Box &b) const {
    return x<b.x;
  }

};

int nBox;
Box boxList[MAX_SIZE];

bool read(){
  
  cin >> nBox;
  if(nBox==0) return false;

  for(int i=0;i<nBox;i++){
    int x, y, z;
    cin >> x >> y >> z;

    boxList[i*6]=Box(x,y,z);
    boxList[i*6+1]=Box(x,z,y);
    boxList[i*6+2]=Box(y,x,z);
    boxList[i*6+3]=Box(y,z,x);
    boxList[i*6+4]=Box(z,x,y);
    boxList[i*6+5]=Box(z,y,x);
    
  }

  return true;
  
}

void work(int cases){

  sort(boxList,boxList+nBox*6);
  

  int maxVal[MAX_SIZE];
  fill(maxVal,maxVal+nBox*6,-1);

  for(int i=0;i<nBox*6;i++){
    
    int currMax=boxList[i].z;
    
    for(int j=0;j<i;j++){
      if(boxList[j].x<boxList[i].x && boxList[j].y<boxList[i].y){
	currMax = max(currMax,boxList[i].z+maxVal[j]);
      }
    }

    maxVal[i] = currMax;
  }
  
  int ans=0;
  for(int i=0;i<nBox*6;i++)
    ans = max(ans,maxVal[i]);

  cout << "Case " << cases << ": maximum height = " << ans << endl;
}

int main(){
  
  for(int i=1;read();i++)
    work(i);

  return 0;
}
