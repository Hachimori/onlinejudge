#include<iostream>
#include<cstdlib>

using namespace std;

bool isAnswer(int n, int target){
  
  if(n*(n+1)/2<target) return false;

  if((n*(n+1)/2-target)%2==1) return false;

  if((n*(n+1)/2-target)>n*(n+1)) return false;

  return true;

}

void work(){
  
  int target;
  cin >> target;

  target = abs(target);

  int cursor;
  for(cursor=1;!isAnswer(cursor,target);cursor++){}

  cout << cursor << endl;
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
