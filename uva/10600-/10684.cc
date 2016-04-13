#include<iostream>

#define MAX_SIZE 10005

using namespace std;

int nNum;
int nList[MAX_SIZE];

bool read(){
  
  cin >> nNum;
  if(nNum==0) return false;
  
  for(int i=0;i<nNum;i++)
    cin >> nList[i];

  return true;
}

void work(){
  
  int maxSequence[MAX_SIZE];
  int maxVal=-1;
  
  maxSequence[0] = nList[0];
  if(maxVal<nList[0])
    maxVal = nList[0];

  for(int i=1;i<nNum;i++){
    
    if(maxSequence[i-1]>0)
      maxSequence[i] = maxSequence[i-1]+nList[i];
    else
      maxSequence[i] = nList[i];
    
    if(maxVal<maxSequence[i])
      maxVal = maxSequence[i];
  }

  if(maxVal<=0)
    cout << "Losing streak." << endl;
  else
    cout << "The maximum winning streak is " << maxVal << "." << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
