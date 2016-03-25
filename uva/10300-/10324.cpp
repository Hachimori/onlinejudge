#include<iostream>
#include<algorithm>

#define MAX_NUM 25

using namespace std;

int nNum, sum;
int nList[MAX_NUM];

void read(){
  
  cin >> nNum;
  
  for(int i=0;i<nNum;i++)
    cin >> nList[i];
  
}

bool rec(int curr, int nPick, int currSum, bool used[MAX_NUM]){
  
  if(nPick==nNum && currSum==sum/4) return true;
  if(currSum==sum/4){
    
    int toUse;
    
    for(int i=0;i<nNum;i++)
      if(!used[i]){
	toUse = i;
	break;
      }
    
    used[toUse] = true;
    
    if(rec(toUse+1,nPick+1,nList[toUse],used)) return true;
    
    used[toUse] = false;
    
    return false;
  }
  
  for(int i=curr;i<nNum;i++){
    
    if(used[i]) continue;
    if(currSum+nList[i]>sum/4) continue;
    
    used[i] = true;
    
    if(rec(i+1,nPick+1,currSum+nList[i],used)) return true;
    
    used[i] = false;
  }
  
  
  return false;
}

void work(){
  
  sum=0;
  for(int i=0;i<nNum;i++)
    sum+=nList[i];
  
  for(int i=0;i<nNum;i++){
    for(int j=i+1;j<nNum;j++){
      if(nList[i]<nList[j]){
	swap(nList[i],nList[j]);
      }
    }
  }
  
  /*
  for(int i=0;i<nNum;i++)
    cout << nList[i] << ' ';
  cout << endl;
  */

  if(sum%4!=0) {
    cout << "no" << endl;
    return;
  }
  
  if(nList[0]>sum/4){
    cout << "no" << endl;
    return;
  }
  
  
  bool used[MAX_NUM];
  for(int i=0;i<nNum;i++)
    used[i] = false;
  
  used[0] = true;
  
  if(rec(1,1,nList[0],used))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
