#include<iostream>
#include<algorithm>

#define MAX_OPE 15
#define MAX_SIZE 1000005

using namespace std;

int nStone;
int nOperator;
int opeList[MAX_OPE];

bool read(){

  if(!(cin >> nStone)) return false;

  cin >> nOperator;

  for(int i=0;i<nOperator;i++)
    cin >> opeList[i];

  return true;
}

void work(){
  
  bool winAble[MAX_SIZE];

  fill(winAble,winAble+nStone+1,false);

  for(int i=1;i<nStone+1;i++){
    
    for(int j=0;j<nOperator;j++){
      if(i==opeList[j]){
	winAble[i] = true;
	break;
      }
      if(i-opeList[j]>0 && !winAble[i-opeList[j]]){
	winAble[i] = true;
	break;
      }
    }
    
  }
  

  if(winAble[nStone]) cout << "Stan wins" << endl;
  else cout << "Ollie wins" << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
