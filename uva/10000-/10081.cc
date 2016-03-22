#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

#define MAX_VARIABLE 11
#define MAX_SIZE 105

using namespace std;

int nVariable, length, cnt;

bool read(){
  if(!(cin >> nVariable >> length)) return false;
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<=nVariable && 0<=c && c<length;
}

void rec(int currLength, long double valList[MAX_VARIABLE][MAX_SIZE]){

  const static int rMove[3]={-1,0,1};
  const static int cMove[3]={1,1,1};
  
  if(currLength==length) return;

  for(int i=0;i<=nVariable;i++){
    for(int j=0;j<3;j++){
      int nextVal=i+rMove[j];
      int nextLeng=currLength+cMove[j];

      if(!isInside(nextVal,nextLeng)) continue;
      
      valList[nextVal][nextLeng]+=valList[i][currLength];      
    }
  }

  rec(currLength+1,valList);

}

void work(){
  
  long double valList[MAX_VARIABLE][MAX_SIZE];
  
  for(int i=0;i<=nVariable;i++)
    fill(valList[i],valList[i]+length,0);
  
  for(int i=0;i<=nVariable;i++)
    valList[i][0]=1;


  rec(0,valList);


  long double allTrial = 1;
  for(int i=0;i<length;i++){
    allTrial*=(nVariable+1);
  }

  long double allSolution=0;
  for(int i=0;i<=nVariable;i++)
    allSolution+=valList[i][length-1];
  
  printf("%.5lf\n",(double)(allSolution/allTrial)*100);

}

int main(){
  
  while(read())
    work();

  return 0;

}
