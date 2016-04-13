#include<iostream>

using namespace std;

int xPos1, yPos1, xPos2, yPos2;

void read(){  
  cin >> xPos1 >> yPos1 >> xPos2 >> yPos2;
}

void work(int cases){
  
  cout << "Case " << cases << ": " << 
    (xPos2+(yPos2+xPos2)*(yPos2+xPos2+1)/2)
    -(xPos1+(yPos1+xPos1)*(yPos1+xPos1+1)/2) << endl;

}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
