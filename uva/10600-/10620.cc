#include<iostream>
using namespace std;
const int BUF = 2005;

int sz, x, y, dx, dy;

bool read(){
  cin >> sz >> x >> y >> dx >> dy;
  return sz|x|y|dx|dy;
}

void work(){
  static bool visited[BUF][BUF];
  memset(visited,0,sizeof(visited));
  int mod = sz*2;
  for(int ans=0;;ans++){
    if( x%sz!=0 && y%sz!=0 && 
        ((1<=x%mod && x%mod<=sz-1)^(1<=y%mod && y%mod<=sz-1))){
      cout << "After " << ans << " jumps the flea lands at ("
           << x << ", " << y << ")." << endl;
      break;
    }
    if(visited[x%mod][y%mod]){
      cout << "The flea cannot escape from black squares." << endl;
      break;
    }
    visited[x%mod][y%mod] = true;
    x += dx;
    y += dy;
  }
}

int main(){
  while(read()) work();
  return 0;
}
