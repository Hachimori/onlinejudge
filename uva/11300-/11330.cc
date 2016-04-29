#include<iostream>
using namespace std;
const int BUF = 20005;

int nColor, colorCnt[BUF], color2idx[BUF][2], colors[BUF];

void read(){
  cin >> nColor;
  nColor *= 2;
  memset(colorCnt,0,sizeof(colorCnt));
  memset(colors,0,sizeof(colors));
  memset(color2idx,0,sizeof(color2idx));
  for(int i=0;i<nColor;i++){
    int v;
    cin >> v;
    colors[i] = v;
    color2idx[v][colorCnt[v]++] = i;
  }
}

void work(){
  int ans = 0;
  for(int i=0;i<nColor;i+=2){
    int self = colors[i], opp = colors[i+1];
    if(self==opp) continue;
    if(color2idx[self][0]!=i) swap(color2idx[self][0],color2idx[self][1]);
    if(color2idx[opp][0]!=i+1) swap(color2idx[opp][0],color2idx[opp][1]);
    swap(colors[color2idx[self][1]],colors[color2idx[opp][0]]);
    swap(color2idx[self][1],color2idx[opp][0]);
    ans++;
  }
  cout << ans << endl;
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
