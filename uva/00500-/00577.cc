#include<iostream>
#include<string>
#include<vector>
#define OPE 10000
using namespace std;

class Window{
public:
  bool zoomed;
  int id;
  int left, right, top, bottom;

  Window(){}
  Window(int id, int l, int r, int t, int b):
    id(id), left(l), right(r), top(t), bottom(b), zoomed(false){}
  
  bool clicked(int x, int y){
    return (zoomed || (left<=x && x<=right && top<=y && y<=bottom));
  }

  bool isClose(int x, int y){
    if(zoomed)
      return (0<=x && x<=24 && 0<=y && y<=24);
    else
      return (left<=x && x<=left+24 && top<=y && y<=top+24);
  }

  bool isHold(int x, int y){
    return (!zoomed && left<=x+25 && x<=right-25 && top<=y && y<=top+24);
  }

  bool isZoom(int x, int y){
    if(zoomed)
      return (1023-24<=x && x<=1023 && 0<=y && y<=24);
    else
      return (right-24<=x && x<=right && top<=y && y<=top+24);
  }
};


vector<Window> windows;

int getIdx(int select){
  for(int i=0;i<windows.size();i++)
    if(windows[i].id==select)
      return i;
}

void doDown(int x, int y, int &select, bool &hold, bool &zoom, bool &close){
  for(int i=0;i<windows.size();i++)
    if(windows[i].clicked(x,y)){
      select = windows[i].id;
      cout << "Selected window " << windows[i].id << endl;
      Window tmp = windows[i];
      windows.erase(windows.begin()+i);
      windows.insert(windows.begin(),tmp);
      
      if(windows[0].isClose(x,y))
        close = true;
      else if(windows[0].isZoom(x,y))
        zoom = true;
      else if(windows[0].isHold(x,y))
        hold = true;
      
      break;
    }
}

void doUp(int x, int y, int select, bool &zoom, bool &close){
  int idx = getIdx(select);
  
  if(close && windows[idx].isClose(x,y)){
    cout << "Closed window " << windows[idx].id << endl;
        
    windows.erase(windows.begin());
  }
  else if(zoom && windows[idx].isZoom(x,y)){
    cout << "Resized window " << windows[idx].id << " to ";

    if(windows[idx].zoomed)
      cout << windows[idx].left << ", " << windows[idx].top << ", " 
           << windows[idx].right << ", " << windows[idx].bottom << endl;
    else
      cout << "0, 0, 1023, 1023" << endl;
        
    windows[idx].zoomed = !windows[idx].zoomed;
  }
}

void doAt(int dx, int dy, int select){
  int idx = getIdx(select);
      
  windows[idx].left   += dx;
  windows[idx].right  += dx;
  windows[idx].top    += dy;
  windows[idx].bottom += dy;
  
  cout << "Moved window " << windows[idx].id << " to " 
       << windows[idx].left << ", " << windows[idx].top << ", "
       << windows[idx].right << ", " << windows[idx].bottom << endl;
}

void doCreate(int &curId, int l, int t, int r, int b){
  windows.insert(windows.begin(),Window(curId,l,r,t,b));
  
  cout << "Created window " << curId++ << " at "
       << l << ", " << t << ", " << r << ", " << b << endl;
}

void doReverse(){
  for(int i=(int)windows.size()-1;i>=0;i--){
    cout << "Window " << windows[i].id << " at "; 
    if(windows[i].zoomed)
      cout << "0, 0, 1023, 1023" << endl;
    else
      cout << windows[i].left << ", " << windows[i].top << ", "
           << windows[i].right << ", " << windows[i].bottom << endl;
  }
}

int main(){
  int select, lastX, lastY, curId = 0;
  bool hold = false, zoom = false, close = false;


  while(true){
    string ope;
    cin >> ope;

    if(ope=="DN"){
      int x, y; cin >> x >> y;
      doDown(x,y,select,hold,zoom,close);
      lastX = x, lastY = y;
    }    
    
    if(ope=="UP"){
      int x, y; cin >> x >> y;
      
      if(hold) doAt(x-lastX,y-lastY,select);
      else doUp(x,y,select,zoom,close);
      hold = false, zoom = false, close = false;
    }
    
    if(ope=="AT"){
      int x, y;  cin >> x >> y;
      if(hold) doAt(x-lastX,y-lastY,select);
      lastX = x, lastY = y;
    }
    
    if(ope=="CR"){
      int l, t, r, b;  cin >> l >> t >> r >> b;
      doCreate(curId,l,t,r,b);
    }
    if(ope=="RE"){
      doReverse();
    }
    if(ope=="ZZ") break;
  }

  return 0;
}
