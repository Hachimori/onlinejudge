#include<iostream>
#define NODE 100005
using namespace std;

int nNode, gus[NODE], cost[NODE];

void read(){
  cin >> nNode;

  for(int i=0;i<nNode;i++)
    cin >> gus[i];

  for(int i=0;i<nNode;i++)
    cin >> cost[i];
}

void work(int cases){
  int sum = 0, ans = 0, cntRun = 0;
  bool toFinish = false;

  cout << "Case " << cases << ": ";

  for(int i=0;i<nNode;i=(i+1)%nNode){
    sum += gus[i];
    sum -= cost[i];
    cntRun++;
    if(sum<0){
      if(toFinish){
	cout << "Not possible" << endl;
	return;
      }
      ans = i+1; 
      sum = cntRun = 0; 
    }
    if(cntRun==nNode) {
      cout << "Possible from station " << ans+1 << endl;
      return;
    }
    if(i==nNode-1) toFinish = true;
  }
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
