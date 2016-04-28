#include<iostream>
using namespace std;

int get(int r, int c){
  if(r<8 || c<8) return 0;
  return get(r-1,c-1) + ((r)/2-3)+((c)/2-3)-1;
}

int main(){
  while(true){
    int row, col, v;
    cin >> row >> col >> v;
    if((row|col|v)==0) break;
    
    if(v==1)
      cout << get(row,col) << endl;
    else
      cout << get(row-1,col)+(col-1)/2-3 << endl;
  }

  return 0;
}
