#include<iostream>
using namespace std;
const int BUF = 28;

int nNode, nEdge, edge[BUF][2];

bool read(){
  cin >> nNode >> nEdge;
  if(nNode==0 && nEdge==0) return false;

  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t;
    edge[i][0] = s;
    edge[i][1] = t;
  }
  
  return true;
}


int rec(int cur, bool used[BUF]){
  int ret = 0;
  for(int i=0;i<nEdge;i++)
    if(!used[i]){
      used[i] = true;
      if(edge[i][0]==cur)
        ret = max(ret,rec(edge[i][1],used)+1);
      else if(edge[i][1]==cur)
        ret = max(ret,rec(edge[i][0],used)+1);
      used[i] = false;
    }
  return ret;
}


void work(){
  int maxV = 0;
  bool used[BUF]={};
  for(int i=0;i<nNode;i++)
    maxV = max(maxV,rec(i,used));
  cout << maxV << endl;
}


int main(){
  while(read()) work();
  return 0;
}
