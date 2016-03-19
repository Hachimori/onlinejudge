#include<iostream>

#define MAX 103

using namespace std;

class Tower{
 public:

  int numTile;
  int height;
  
  Tower(){}
  Tower(int numTile, int height) : numTile(numTile) , height(height){}
  
  bool isHigher(int addTile, int addHeight , Tower &t ){
    return (addTile+numTile>t.numTile);
  }

};

bool read(int &numTile1, int &numTile2, int tiles1[MAX], int tiles2[MAX]){
  
  cin >> numTile1 >> numTile2;
  if(numTile1 == 0 && numTile2 == 0 ) return false;


  for(int i=0;i<numTile1;i++)
    cin >> tiles1[i];

  for(int i=0;i<numTile2;i++)
    cin >> tiles2[i];


  return true;
}

void work(int cases, int &numTile1, int &numTile2, int tiles1[MAX], int tiles2[MAX]){
  
  Tower tower1[MAX];
  Tower towerZero=Tower(0,0);

  for(int i=0;i<numTile2;i++){
    tower1[i] = Tower(0,0);
    //cout << tower1[i].height << ' ';
  }//cout << endl;

  for(int i=0;i<numTile1;i++){

    Tower tower2[MAX];

    for(int j=0;j<numTile2;j++){
      if(j==0 && tiles1[i]==tiles2[j] && towerZero.isHigher(1,tiles2[j],tower1[j]) ){
	tower2[j] = Tower(1,tiles2[j]);
      }
      else if(j!=0 && tiles1[i]==tiles2[j] && tower1[j-1].isHigher(1,tiles2[j],tower1[j]) 
	                                   && tower1[j-1].isHigher(1,tiles2[j],tower2[j-1]) ){
	tower2[j] = Tower(tower1[j-1].numTile+1,tower1[j-1].height+tiles2[j]);
      }
      else if( j==0 ||( j!=0 && tower1[j].isHigher(0,0,tower2[j-1]) ) ){
	tower2[j] = tower1[j];
      }
      else tower2[j] = tower2[j-1];
   
	
     // cout << tower2[j].numTile << ' ';
    }
    //cout << endl;

    for(int j=0;j<numTile2;j++)
      tower1[j] = tower2[j];
  }


  cout << "Twin Towers #" << cases << endl;
  cout << "Number of Tiles : " << tower1[numTile2-1].numTile << endl;
  cout << endl;

}

int main(){ 
  int numTile1, numTile2;
  int tiles1[MAX], tiles2[MAX];

  for(int cases=1;read(numTile1,numTile2,tiles1,tiles2);cases++)
    work(cases,numTile1,numTile2,tiles1,tiles2);
 
  return 0;
}
