#include<iostream>
using namespace std;
const int INF = 1<<30;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      minX = min(minX,x2);
      maxX = max(maxX,x1);
      minY = min(minY,y2);
      maxY = max(maxY,y1);
    }

    cout << "Case " << k+1 << ": ";
    cout << (minX<=maxX || minY<=maxY ? 0 : (minX-maxX)*(minY-maxY)) << endl;
  }
  return 0;
}
