#include<iostream>
using namespace std;

int main(){
  int row, col;
  while(cin >> row >> col,row|col){
    if(min(row,col)==1)
      cout << max(row,col) << " knights may be placed on a " << row << " row " << col << " column board." << endl;
    else if(min(row,col)==2)
      cout << max(row,col)/4*4+ min(2,max(row,col)%4)*2 << " knights may be placed on a " << row << " row " << col << " column board." << endl;
    else{
      cout << row*col/2+row*col%2 << " knights may be placed on a " << row << " row " << col << " column board." << endl;
    }
  }
  return 0;
}
