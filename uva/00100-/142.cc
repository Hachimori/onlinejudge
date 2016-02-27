#include<iostream>
#include<vector>
#define BUF 100
using namespace std;

class Window{
public:
  int low, high, left, right;
  
  Window(){}
  Window(int low, int high, int left, int right):
    low(low), high(high), left(left), right(right){}

  bool contains(int x, int y){
    return low<=y && y<=high && left<=x && x<=right;
  }
};

class Icon{
public:
  int x, y;
  bool hidden;

  Icon(){}
  Icon(int x, int y, bool h): x(x), y(y), hidden(h){}
};

int main(){
  int nWindow = 0, nIcon = 0;
  Window window[BUF];
  Icon icon[BUF];

  while(true){
    char ch;
    cin >> ch; 
    if(ch=='#') break;
    
    if(ch=='R'){
      int low, left, high, right;
      cin >> left >> low >> right >> high;
      window[nWindow] = Window(low,high,left,right);

      for(int i=0;i<nIcon;i++)
        if(window[nWindow].contains(icon[i].x,icon[i].y))
          icon[i].hidden = true;
      nWindow++;
    }
    
    if(ch=='I'){
      int x, y;
      cin >> x >> y;
      icon[nIcon] = Icon(x,y,false);
      for(int i=0;i<nWindow;i++)
        if(window[i].contains(icon[nIcon].x,icon[nIcon].y))
          icon[nIcon].hidden = true;
      nIcon++;
    }

    if(ch=='M'){
      int x, y;
      cin >> x >> y;

      bool finish = false;
      for(int i=nWindow-1;i>=0;i--)
        if(window[i].contains(x,y)){
          cout << (char)(i+'A') << endl;
          finish = true;
          break;
        }
      if(finish) continue;

      int minV = (1<<20);
      vector<int> iList;
      for(int i=0;i<nIcon;i++){
        if(icon[i].hidden) continue;
        int dx = x-icon[i].x, dy = y-icon[i].y;
        
        if(minV>dx*dx+dy*dy){
          iList.clear();
          iList.push_back(i);
          minV = dx*dx+dy*dy;
        }
        else if(minV==dx*dx+dy*dy)
          iList.push_back(i);
      }

      for(int i=0;i<iList.size();i++)
        printf("%3d",iList[i]+1);
      cout << endl;
    }
  }
  return 0;
}