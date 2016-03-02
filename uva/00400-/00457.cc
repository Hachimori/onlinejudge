#include<iostream>
using namespace std;
const int BUF = 10, STATE = 40;

int nex[BUF];

void read(){
  for(int i=0;i<BUF;i++)
    cin >> nex[i];
}


void work(){
  int st[STATE]={};
  st[19] = 1;

  for(int loop=0;loop<50;loop++){
    for(int i=0;i<STATE;i++)
      cout << " .xW"[st[i]];
    cout << endl;

    int nexSt[STATE];
    for(int i=0;i<STATE;i++){
      int L = (i==0 ? 0 : st[i-1]);
      int mid = st[i];
      int R = (i==STATE-1 ? 0 : st[i+1]);
      nexSt[i] = nex[L+mid+R];
    }
    memcpy(st,nexSt,sizeof(nexSt));
  }
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
