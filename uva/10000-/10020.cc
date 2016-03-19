#include<iostream>
#include<algorithm>

#define MAX_NUM 100001

using namespace std;

class Stick{
public:

  int leftX;
  int rightX;

  Stick(){}
  Stick(int l, int r): leftX(l), rightX(r) {}

  bool operator< (const Stick &stick) const {
    if(leftX<stick.leftX) return true;
    else if(leftX==stick.leftX && rightX>stick.rightX) return true;

    return false;
  }

};

Stick stickList[MAX_NUM];
int nStick, coverPos;

void read(){
  
  cin >> coverPos;

  for(int i=0;;i++){
    int left, right;
    cin >> left >> right;
    
    if(left==0 && right==0) break;

    stickList[i] = Stick(left,right);
    nStick = i+1;
  }


  sort(&stickList[0],&stickList[nStick]);
}

void work(){

  /*
  for(int i=0;i<nStick;i++){
    cout << stickList[i].leftX << " " << stickList[i].rightX << endl;
  }
  cout << endl;
  */

  int currCovered=0, nUsed=0;
  Stick usedList[MAX_NUM];

  for(int i=0;currCovered<coverPos && i<nStick;i++){
    
    int cursor=i, maxDistance=currCovered;
    while(cursor<nStick && stickList[cursor].leftX<=currCovered ){
      if(maxDistance<stickList[cursor].rightX && currCovered<=stickList[cursor].rightX){
	maxDistance = stickList[cursor].rightX;
	usedList[nUsed] = stickList[cursor];
      }
      cursor++;
    }
    
    if(maxDistance==currCovered) break;
    currCovered = maxDistance;
    nUsed++;
    i = cursor-1;
    
  }

  if(currCovered<coverPos){ 
    cout << 0 << endl;
    return ;
  }

  cout << nUsed << endl;
  for(int i=0;i<nUsed;i++)
    cout << usedList[i].leftX << " " << usedList[i].rightX << endl;
  

}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
