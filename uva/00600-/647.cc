#include<iostream>
using namespace std;
const int SEQ = 1005, PLAYER = 10, BUF = 100;

int nSeq, seq[SEQ];
int nPlayer, go[BUF], rest[BUF], again[BUF];

bool read(){
  memset(go,0,sizeof(go));
  memset(rest,0,sizeof(rest));
  memset(again,0,sizeof(again));

  cin >> nPlayer;
  if(nPlayer==0) return false;

  int src, dst;
  while(cin >> src >> dst, src|dst) go[src] = dst;

  while(cin >> src, src) (src<0 ?  rest[abs(src)] : again[abs(src)]) = 1;

  return true;
}


void work(){
  int player = 0, pos[PLAYER], isRest[PLAYER]={};
  
  for(int i=0;i<nPlayer;i++) pos[i] = 0;
  
  for(int seqLoop=0;seqLoop<nSeq;seqLoop++){
    if(isRest[player]){
      isRest[player] = false;
      player = (player+1)%nPlayer;
      seqLoop--;
      continue;
    }
    
    int nex = pos[player]+seq[seqLoop];
    if(nex==BUF){
      cout << player+1 << endl;
      break;
    }
    
    if(nex>BUF){
      player = (player+1)%nPlayer;
      continue;
    }

    pos[player] = nex;
    
    if(go[nex])
      pos[player] = go[nex];
    else if(rest[nex])
      isRest[player] = true;
    else if(again[nex])
      player = (player-1+nPlayer)%nPlayer;
    
    player = (player+1)%nPlayer;
  }
}


int main(){
  nSeq = 0;
  while(cin >> seq[nSeq], seq[nSeq]) nSeq++;

  while(read()) work();

  return 0;
}
