#include<iostream>

#define MAX_SIZE 60005

using namespace std;

int nStone[7];

bool read(){
  
  for(int i=1;i<=6;i++)
    cin >> nStone[i];

  if(nStone[1]==0 && nStone[2]==0 && nStone[3]==0 && 
     nStone[4]==0 && nStone[5]==0 && nStone[6]==0) return false;

  return true;
}

void work(int cases){
  
  int sum=0, availEven, availOdd;
  bool isAvailEven[MAX_SIZE], isAvailOdd[MAX_SIZE];

  for(int i=1;i<=6;i++)
    sum+=i*nStone[i];
  
  for(int i=0;i<=sum/2;i++){
    isAvailEven[i]=false;
    isAvailOdd[i]=false;
  }

  if(sum%2==1){
    cout << "Collection #" << cases << ":" << endl;
    cout << "Can't be divided." << endl << endl;
    return;
  }
  

  
  for(int i=0;i<=nStone[1];i++)
    if(1*i<=sum/2)
      isAvailOdd[1*i]=true;
  
  availOdd=1*nStone[1];

  for(int i=0;i<=nStone[3];i++)
    if(3*i+availOdd<=sum/2)
      isAvailOdd[3*i+availOdd]=true;
  
  if(availOdd>0)
    for(int i=0;i<=nStone[3];i++)
      if(3*i+availOdd-1<=sum/2)
	isAvailOdd[3*i+availOdd-1]=true;
  
  if(availOdd>1){
    for(int i=0;i<=nStone[3];i++)
      if(3*i+availOdd-1<=sum/2)
	isAvailOdd[3*i+availOdd-2]=true;

    availOdd=availOdd+3*nStone[3];
  }


  bool next[MAX_SIZE];  
  for(int i=0;i<=sum/2;i++)
    next[i] = isAvailOdd[i];
    
  for(int i=0;i<=sum/2;i++){
    if(isAvailOdd[i] && i+5<=sum/2 && nStone[5]>0)
      next[i+5]=true;
    if(isAvailOdd[i] && i+10<=sum/2 && nStone[5]>1)
      next[i+10]=true;
  }
  
  for(int i=0;i<=sum/2;i++)
    isAvailOdd[i] = next[i];

  
  for(int i=0;i<=nStone[5];i++)
    if(availOdd+5*i<=sum/2)
      isAvailOdd[availOdd+5*i] = true;

  

  
  for(int i=0;i<=nStone[2];i++)
    if(2*i<=sum/2)
      isAvailEven[2*i]=true;
  
  availEven=2*nStone[2];

  for(int i=0;i<=nStone[4];i++)
    if(4*i+availEven<=sum/2)
      isAvailEven[4*i+availEven]=true;
  
  if(availEven>0){
    for(int i=0;i<=nStone[4];i++)
      if(4*i+availEven-2<=sum/2)
	isAvailOdd[4*i+availEven-2]=true;

    availEven=availEven+4*nStone[4];
  }


  for(int i=0;i<=sum/2;i++)
    next[i] = isAvailEven[i];
    
  for(int i=0;i<=sum/2;i++){
    if(isAvailEven[i] && i+6<=sum/2 && nStone[6]>0)
      next[i+6]=true;
    if(isAvailEven[i] && i+12<=sum/2 && nStone[6]>1)
      next[i+12]=true;
    if(isAvailEven[i] && i+18<=sum/2 && nStone[6]>2)
      next[i+18]=true;
  }
  
  for(int i=0;i<=sum/2;i++)
    isAvailEven[i] = next[i];

  
  for(int i=0;i<=nStone[6];i++)
    if(availEven+6*i<=sum/2)
      isAvailEven[availEven+6*i] = true;

  /*
  for(int i=0;i<=sum/2;i++)
    if(isAvailOdd[i]) cout << i << ' ';
  cout << endl;

   for(int i=0;i<=sum/2;i++)
    if(isAvailEven[i]) cout << i << ' ';
  cout << endl;
  */

  for(int i=0;i<=sum/2;i++){
    if(isAvailOdd[i] && isAvailEven[sum/2-i]){      
      cout << "Collection #" << cases << ":" << endl;
      cout << "Can be divided." << endl << endl;
      return;
    }      
  }

  cout << "Collection #" << cases << ":" << endl;
  cout << "Can't be divided." << endl << endl;

}

int main(){
      
  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
