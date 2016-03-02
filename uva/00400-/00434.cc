#include<iostream>
#include<algorithm>

#define MAX_SIZE 8

using namespace std;

int size;

void read(int frontHeight[MAX_SIZE], int rightHeight[MAX_SIZE]){
  
  cin >> size;

  for(int i=0;i<size;i++)
    cin >> frontHeight[i];

  for(int i=0;i<size;i++)
    cin >> rightHeight[i];
  
}

bool allCounted( bool counted[MAX_SIZE] ){

  for(int i=0;i<size;i++)
    if(!counted[i]) return false;
  
  return true;

}

void count(bool selfCounted[MAX_SIZE], bool oppCounted[MAX_SIZE], 
	   int selfHeight[MAX_SIZE], int oppHeight[MAX_SIZE], int &nMin){
  
  int maxNum=0;
  int nSelfMax=0, nOppMax=0;

  for(int i=0;i<size;i++)
    if(!selfCounted[i] && maxNum<selfHeight[i])
      maxNum = selfHeight[i];
  
  for(int i=0;i<size;i++)
    if(maxNum==selfHeight[i]){
      selfCounted[i] = true;
      nSelfMax++;
    }
  
  for(int i=0;i<size;i++)
    if(maxNum==oppHeight[i]){
      oppCounted[i] = true;
      nOppMax++;
    }
  
  nMin+=maxNum*max(nSelfMax,nOppMax);

}

void work(int frontHeight[MAX_SIZE], int rightHeight[MAX_SIZE]){

  int nMin=0, nMax=0;
  bool frontCounted[MAX_SIZE], rightCounted[MAX_SIZE];

  for(int i=0;i<size;i++){
    if(frontHeight[i]==0) frontCounted[i]=true;
    else frontCounted[i]=false;
    if(rightHeight[i]==0) rightCounted[i]=true;
    else rightCounted[i]=false;    
  }

  while(!allCounted(frontCounted) || !allCounted(rightCounted)){
    if(!allCounted(frontCounted))
      count(frontCounted,rightCounted,frontHeight,rightHeight,nMin);    
    else
      count(rightCounted,frontCounted,rightHeight,frontHeight,nMin);    
  }

  bool box[MAX_SIZE][MAX_SIZE][MAX_SIZE];
  bool frontExist[MAX_SIZE][MAX_SIZE], rightExist[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<size;j++)
      for(int k=0;k<size;k++)
	box[i][j][k]=false;
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<size;j++){
      if(i<frontHeight[j]) 
	frontExist[i][j]=true;
      else 
	frontExist[i][j]=false;

      if(i<rightHeight[j]) 
	rightExist[i][j]=true;
      else 
	rightExist[i][j]=false;	
    }  

  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(rightExist[i][j]) cout << "#";
      else cout << " ";
    }cout << endl;
  }
  */

  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<size;j++){
      for(int k=0;k<size;k++){
	if(i>0){
	  if(frontExist[i][k] && rightExist[i][j] && box[i-1][j][k]){
	    box[i][j][k]=true;
	    nMax++;
	  }	    
	}
	else{
	  if(frontExist[i][k] && rightExist[i][j]){
	    box[i][j][k]=true;
	    nMax++;
	  }
	}
      }
    }
  }
  
  cout << "Matty needs at least " << nMin << " blocks, and can add at most " << nMax-nMin  << " extra blocks." << endl;

  
}

int main(){
  
  int frontHeight[MAX_SIZE], rightHeight[MAX_SIZE];
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read(frontHeight,rightHeight);
    work(frontHeight,rightHeight);
  }

  return 0;
}
