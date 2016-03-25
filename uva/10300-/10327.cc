#include<iostream>

#define MAX_SIZE 1005

using namespace std;

int nElement;
int eleList[MAX_SIZE];

bool read(){

  if(!(cin >> nElement)) return false;

  for(int i=0;i<nElement;i++)
    cin >> eleList[i];

  return true;
}

void work(){
  
  int sum=0;

  for(int i=0;i<nElement;i++){
    for(int j=i-1;j>=0;j--){
      if(eleList[j]>eleList[i]) sum++;
    }
  }

  cout << "Minimum exchange operations : " << sum << endl;
  
}

int main(){

  while(read())
    work();

  return 0;
}
