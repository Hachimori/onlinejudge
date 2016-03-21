#include<iostream>
#include<string>

#define MAX_SIZE 100000

using namespace std;

int nInst;
string instList[MAX_SIZE];

void read(){

  nInst=0;

  while(true){
    getline(cin,instList[nInst]);
    if(instList[nInst].size()==0) break;
    nInst++;
  }

}

void calc(int currTime, int currBait, int currFish, int currInst, int nFish, int lastFish){

  if(currInst==nInst){
    cout << nFish << endl;    
    return;
  }

  if(instList[currInst]=="fish"){
    
    if(lastFish==0 && currBait>=2)
      calc(currTime+10,currBait-2,1,currInst+1,nFish+1,currTime);
    else if(currFish>=3 && currTime-lastFish>=70 && currBait>=2)
      calc(currTime+10,currBait-2,1,currInst+1,nFish+1,currTime);
    else
      calc(currTime+10,currBait,currFish+1,currInst+1,nFish,lastFish);
  }
  else if(instList[currInst]=="bait"){
    if(currBait==6)
      calc(currTime+10,currBait,currFish,currInst+1,nFish,lastFish);
    else
      calc(currTime+10,currBait+1,currFish,currInst+1,nFish,lastFish);
  }
  else 
    calc(currTime+10,currBait,currFish,currInst+1,nFish,lastFish);
    
}

void work(){

  calc(0,0,0,0,0,0);

}

int main(){

  int cases;
  cin >> cases;  string str; getline(cin,str); getline(cin,str);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}
