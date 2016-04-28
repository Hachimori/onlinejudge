#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    int r, c;
    cin >> r >> c;
    
    if(r==c)
      cout << ((r+1)/2)*((r+1)/2+1)/2 << endl;
    else
      cout << ((r+1)/2)*((c+1)/2) << endl;
  }

  return 0;
}
