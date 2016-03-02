#include<iostream>
#include<algorithm>
using namespace std;


int minX1, maxX1, minY1, maxY1;
int minX2, maxX2, minY2, maxY2;

void read(){
  cin >> minX1 >> minY1 >> maxX1 >> maxY1;
  cin >> minX2 >> minY2 >> maxX2 >> maxY2;
}


void work(){
  int minX3, maxX3, minY3, maxY3;
  minX3 = max(minX1,minX2);
  maxX3 = min(maxX1,maxX2);
  minY3 = max(minY1,minY2);
  maxY3 = min(maxY1,maxY2);

  if(minX3>=maxX3 || minY3>=maxY3)
    cout << "No Overlap" << endl;
  else
    cout << minX3 << ' ' << minY3 << ' ' << maxX3 << ' ' << maxY3 << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
