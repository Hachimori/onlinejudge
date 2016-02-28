#include<iostream>

#define MAX 10000

class Missile{
 public:
  int score;
  int height;

};

int cases;
int numMissile;
Missile missile[MAX];

bool read(){

  for(numMissile=0;;numMissile++){
    cin >> missile[numMissile].height;
    
    if(numMissile==0 && missile[numMissile].height==-1) return false;
    else if(numMissile!=0 && missile[numMissile].height==-1) return true;
  }

}

void work(){
  
  missile[0].score = 1;


  for(int i=1;i<numMissile;i++){
    
    int maxScore=0;
    for(int j=i-1;j>=0;j--){
      if(missile[i].height<missile[j].height && maxScore<missile[j].score+1){
	maxScore = missile[j].score+1;
      }
    }
    if(maxScore!=0) missile[i].score = maxScore;
    else missile[i].score = 1;
  }


  int maxScore=0;
  for(int i=0;i<numMissile;i++){
    if(maxScore<missile[i].score) maxScore = missile[i].score;
  }

  cout << "Test #" << cases << ":" << endl; 
  cout << "  maximum possible interceptions: " << maxScore << endl;

}

int main(){
  
  for(cases=1;;cases++){
    if(cases!=1) cout << endl;
    if(read()==false) break;
    work();
  }

}
