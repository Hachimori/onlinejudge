#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int sum, diff;

void read(){
  cin >> sum >> diff;
}

void work(){
  
  int x, y;
  
  x = (sum+diff)/2;
  y = sum-x;

  if(x>=0 && y>=0 && x+y==sum && abs(x-y)==diff){    
    cout << max(x,y) << ' ' << min(x,y) << endl;
    return;
  }
    
  
  cout << "impossible" << endl;


}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
