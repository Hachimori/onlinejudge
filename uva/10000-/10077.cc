#include<iostream>
#include<vector>
#include<queue>
#include<cfloat>

#define Left 0
#define Right 1

using namespace std;

int numerator, denominator;

bool read(){
  
  cin >> numerator >> denominator;
  if(numerator==1 && denominator==1) return false;
  
  return true;
}

void printPath(vector<int> path){
  
  for(int i=0;i<path.size();i++)
    if(path[i]==Left) cout << "L";
    else cout << "R";
  cout << endl;

}

void work(){
  
  vector<int> path;
  
  int leftNume, leftDenom, rightNume, rightDenom;
  int currNume=1, currDenom=1;
  
  if((double)numerator/denominator<1){
    while(currNume*denominator>numerator*currDenom){
      rightNume = currNume;
      rightDenom = currDenom;
      currDenom++;
      path.push_back(Left);
    }
    if(numerator==currNume && denominator==currDenom){
      printPath(path);
      return;
    }
    
    leftNume = currNume;
    leftDenom = currDenom;

    currNume+=rightNume;
    currDenom+=rightDenom;

    path.push_back(Right);
  }
  else{
    while(currNume*denominator<numerator*currDenom){
      leftNume = currNume;
      leftDenom = currDenom;
      currNume++;
      path.push_back(Right);
    }
    if(numerator==currNume && denominator==currDenom){
      printPath(path);
      return;
    }

    rightNume = currNume;
    rightDenom = currDenom;

    currNume+=leftNume;
    currDenom+=leftDenom;

    path.push_back(Left);    
  }
  

  while(currNume!=numerator || currDenom!=denominator){
    
    if(currNume*denominator>numerator*currDenom){
      
      rightNume = currNume;
      rightDenom = currDenom;

      currNume+=leftNume;
      currDenom+=leftDenom;
      path.push_back(Left);
    }
    else {

      leftNume = currNume;
      leftDenom = currDenom;

      currNume+=rightNume;
      currDenom+=rightDenom;
      path.push_back(Right);      
    }
    
  }

  printPath(path);

}

int main(){


  while(read())
    work();

  return 0;
}
