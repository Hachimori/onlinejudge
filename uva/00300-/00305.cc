#include<iostream>

using namespace std;

int n;

bool read(){
  cin >> n;
  if(n==0) return false;

  return true;
}

int main(){

  int table[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

  while(read())
    cout << table[n] << endl;
  
  return 0;
}
