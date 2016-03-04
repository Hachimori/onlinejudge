#include<iostream>
using namespace std;
const int RECT = 30;

struct Rect{
  char ch;
  int x, y;
};

int nRect;
Rect rect[RECT];

bool read(){
  cin >> nRect;
  if(nRect==0) return  false;
  for(int i=0;i<nRect;i++)
    cin >> rect[i].ch >> rect[i].x >> rect[i].y;
  return true;
}


bool isOk(Rect r[4]){
  int distH = abs(r[0].x-r[1].x), distV = abs(r[1].y-r[2].y);
  if(!(r[0].x+distH==r[1].x && r[0].y==r[1].y)) return false;
  if(!(r[1].y-distV==r[2].y && r[1].x==r[2].x)) return false;
  if(!(r[2].x-distH==r[3].x && r[2].y==r[3].y)) return false;
  if(!(r[3].y+distV==r[0].y && r[3].x==r[0].x)) return false;
  return true;
}


void work(int cases){
  cout << "Point set " << cases << ":";

  int cnt = 0;
  for(int i=0;i<nRect;i++)
    for(int j=0;j<nRect;j++)
      if(i!=j && rect[i].x<rect[j].x && rect[i].y==rect[j].y)
        for(int k=0;k<nRect;k++)
          if(i!=k && j!=k && rect[j].x==rect[k].x && rect[j].y>rect[k].y)
            for(int l=0;l<nRect;l++){
              if( i==l || j==l || k==l) continue;
              Rect r[4]={rect[i],rect[j],rect[k],rect[l]};
              if(isOk(r)){
                if(cnt%10==0) cout << endl;
                cout << ' ' << r[0].ch << r[1].ch << r[2].ch << r[3].ch;
                cnt++;
              }
            }

  
  if(cnt==0){
    cout << " No rectangles" << endl;
    return;
  }
  cout << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
