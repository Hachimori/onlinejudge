#include<iostream>
using namespace std;

int row, col;

bool read(){
  if(!(cin >> row >> col)) return false;
  return true;
}

void work(){
  cout << row*col-1 << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
