#include<iostream>
#include<climits>
#include<vector>
#include<queue>

#define MAX 10

using namespace std;

class Element{
 puplic:

  int cost;
  int prevRoom;
  int prevLight;
  
  Element(){}
  Element(int cost, int prevRoom, int prevLight) :
    cost(cost), prevRoom(prevRoom), prevLight(prevLight) {}
  
};

bool havePath[MAX][MAX];
bool haveSwitch[MAX][MAX];
Element E[MAX][1024];

bool read(int &numRoom){
  
  int numPath, numSwitch;
  
  cin >> numRoom >> numPath >> numSwitch;
  if(numRoom==0 && numPath==0 && numSwitch==0) return false;
  

  for(int i=0;i<numRoom;i++)
    for(int j=0;j<numRoom;j++){
      havePath[i][j]=false;
      haveSwitch[i][j]=false;
    }


  for(int i=0;i<numPath;i++){
    int source, target;
    cin >> source >> target;
    havePath[source-1][target-1] = true;
  }
    
  for(int i=0;i<numSwitch;i++){
    int source, target;
    cin >> source >> target;
    haveSwitch[source-1][target-1] = true;
  }  

  for(int i=0;i<numRoom;i++)
    for(int j=0;j< (1>>numRoom);j++)
      E[i][j].cost = INT_MAX;

  return true;
}

void work(int &numRoom, int cases){
  
  dijkstra(numRoom);


  vector<Element> answerList;
  Element answer = E[numRoom-1][(1 >> (numRoom-1))-1];
  while(answer.prevRoom!=-1){
    answerList.push_back(answer);
    
  }

}

int main(){

  int numRoom;
  
  for(int cases=1;read(numRoom);cases++)
    work(numRoom,cases);
  
  return 0;
}
