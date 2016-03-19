#include<iostream>
#include<cstdlib>

#define MAX_N 3001

using namespace std;

int n;
int digitList[MAX_N];
bool isExist[MAX_N];

bool read(){
  
  if(!(cin >> n)) return false;


  for(int i=0;i<n;i++)
    isExist[i] = false;

  for(int i=0;i<n;i++)
    cin >> digitList[i];

  return true;

}

void work(){
  
  for(int i=1;i<n;i++)
    if(abs(digitList[i]-digitList[i-1])<n)
      isExist[abs(digitList[i]-digitList[i-1])]=true;
  
  for(int i=1;i<n;i++)
    if(!isExist[i]){
      cout << "Not jolly" << endl;
      return;
    }
  
  cout << "Jolly" << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
