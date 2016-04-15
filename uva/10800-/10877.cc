#include<iostream>
#define DICE 1005
using namespace std;

enum Face {TOP, FRONT, RIGHT, BOTTOM, LEFT, BACK};

class Dice{
public:
  int face[6];
  
  Dice(){}
  
  void roll(int a, int b, int c, int d){
    int t = face[a];
    face[a] = face[b];
    face[b] = face[c];
    face[c] = face[d];
    face[d] = t;
  }
  
  void xroll(){
    roll(RIGHT,BACK,LEFT,FRONT);
  }

  void yroll(){
    roll(TOP,FRONT,BOTTOM,BACK);
  }

  void zroll(){
    roll(TOP,RIGHT,BOTTOM,LEFT);
  }

  bool operator== (const Dice &d) {
    for(int k=0;k<6;k++){
      (k&1 ? yroll() : zroll());
      for(int i=0;i<4;i++){
        xroll();
        
        bool ok = true;
        for(int j=0;j<6;j++)
          if(face[j]!=d.face[j])
            ok = false;
        if(ok) return true;
      }
    }
    return false;
  }
};

int nDice;
Dice dice[DICE];

bool read(){
  cin >> nDice;
  if(nDice==0) return false;

  for(int i=0;i<nDice;i++)
    for(int j=0;j<6;j++)
      cin >> dice[i].face[j];
  
  return true;
}

void work(){
  int cnt = 0;
  
  for(int i=0;i<nDice;i++){
    bool same = false;
    for(int j=i+1;j<nDice;j++)
      if(dice[i]==dice[j]){
        same = true;
        break;
      }

    if(!same) cnt++;
  }
    
  cout << cnt << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
