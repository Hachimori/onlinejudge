#include<iostream>

#define N_MAX 51

using namespace std;

int nBlock;
int heightList[N_MAX];

bool read(){
  
  cin >> nBlock;
  if(nBlock==0) return false;
  
  for(int i=0;i<nBlock;i++)
    cin >> heightList[i];

  return true;
}

void work(int cases){
  
  int average=0, ans=0;
  for(int i=0;i<nBlock;i++)
    average+=heightList[i];
  
  average/=nBlock;

  for(int i=0;i<nBlock;i++)
    if(heightList[i]>average)
      ans+=heightList[i]-average;

  cout << "Set #" << cases << endl;
  cout << "The minimum number of moves is " << ans << "." << endl << endl;
}

int main(){

  
  for(int i=1;read();i++)
    work(i);

  return 0;
}
