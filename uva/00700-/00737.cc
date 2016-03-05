#include<iostream>
using namespace std;
const int CUBE = 1005, INF = 1<<30;

struct Cube{
  int x, y, z, sz;
};

int nCube;
Cube cube[CUBE];

bool read(){
  cin >> nCube;
  if(nCube==0) return false;
  for(int i=0;i<nCube;i++)
    cin >> cube[i].x >> cube[i].y >> cube[i].z >> cube[i].sz;
  return true;
}

void work(){
  int minX=INF, maxX=-INF, minY=INF, maxY=-INF, minZ=INF, maxZ=-INF;
  
  for(int i=0;i<nCube;i++){
    minX = min(minX,cube[i].x+cube[i].sz);
    minY = min(minY,cube[i].y+cube[i].sz);
    minZ = min(minZ,cube[i].z+cube[i].sz);
    maxX = max(maxX,cube[i].x);
    maxY = max(maxY,cube[i].y);
    maxZ = max(maxZ,cube[i].z);
  }
  
  if(minX<=maxX || minY<=maxY || minZ<=maxZ)
    cout << 0 << endl;
  else
    cout << (minX-maxX)*(minY-maxY)*(minZ-maxZ) << endl;
}

int main(){
  while(read()) work();
  return 0;
}
