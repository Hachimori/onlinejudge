#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 100000000
#define BUF 25
#define N 0
#define E 1
#define S 2
#define W 3
#define BN 4
#define BE 5
#define BS 6
#define BW 7
using namespace std;

class Data{
public:
  int br, bc, pr, pc;
  
  Data(){}
  Data(int br, int bc, int pr, int pc): br(br), bc(bc), pr(pr), pc(pc){}
};

const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
int row, col;
int sr, sc, gr, gc, br, bc;
bool wall[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char c;
      cin >> c;

      if(c=='S') sr = i, sc = j;
      if(c=='B') br = i, bc = j;
      if(c=='T') gr = i, gc = j;
      wall[i][j] = (c=='#');
    }

  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

bool bfs(int pi[][BUF][BUF][BUF], int &gpr, int &gpc){
  queue<Data> Q;
  int minPush = INF, minWalk = INF;
  static int cost[BUF][BUF][BUF][BUF];

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      for(int k=0;k<row;k++)
	for(int l=0;l<col;l++){
	  pi[i][j][k][l] = -1;
	  cost[i][j][k][l] = INF;
	}
  
  cost[br][bc][sr][sc] = 0;
  Q.push(Data(br,bc,sr,sc));
  
  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();
    
    if(curr.br==gr && curr.bc==gc){
      if(minPush>cost[curr.br][curr.bc][curr.pr][curr.pc]){
	minPush = cost[curr.br][curr.bc][curr.pr][curr.pc];
	gpr = curr.pr;
	gpc = curr.pc;
      }
      continue;
    }
    
    for(int i=0;i<4;i++){
      int npr = curr.pr+dr[i], npc = curr.pc+dc[i];
      if(!isInside(npr,npc) || wall[npr][npc]) continue;

      if(curr.br==npr && curr.bc==npc){
	int nbr = npr+dr[i], nbc = npc+dc[i];
	if(!isInside(nbr,nbc) || wall[nbr][nbc]) continue;
	if(cost[nbr][nbc][npr][npc]>cost[curr.br][curr.bc][curr.pr][curr.pc]+1){
	  cost[nbr][nbc][npr][npc] = cost[curr.br][curr.bc][curr.pr][curr.pc]+1;
	  pi[nbr][nbc][npr][npc] = i+4;
	  Q.push(Data(nbr,nbc,npr,npc));
	}
      }
      else {
	if(cost[curr.br][curr.bc][npr][npc]>cost[curr.br][curr.bc][curr.pr][curr.pc]){
	  cost[curr.br][curr.bc][npr][npc] = cost[curr.br][curr.bc][curr.pr][curr.pc];
	  pi[curr.br][curr.bc][npr][npc] = i;
	  Q.push(Data(curr.br,curr.bc,npr,npc));
	}
      }
    }
  }
  
  return gpr!=-1;
}

void work(int cases){
  int pi[BUF][BUF][BUF][BUF], r = -1, c = -1;
  
  cout << "Maze #" << cases << endl;

  if(!bfs(pi,r,c)){
    cout << "Impossible." << endl;
    return;
  }

  vector<int> seq;
  int cbr = gr, cbc = gc, cpr = r, cpc = c;

  while(pi[cbr][cbc][cpr][cpc]!=-1){
    int toPush = pi[cbr][cbc][cpr][cpc];
    seq.push_back(toPush);
    if(toPush>=4){
      toPush -= 4;
      cbr -= dr[toPush];
      cbc -= dc[toPush];
    }
    cpr -= dr[toPush];
    cpc -= dc[toPush];
  }
  
  reverse(seq.begin(),seq.end());

  for(int i=0;i<seq.size();i++){
    switch(seq[i]){
    case BN: cout << 'N'; break;
    case BE: cout << 'E'; break;
    case BS: cout << 'S'; break;
    case BW: cout << 'W'; break;
    case N: cout << 'n'; break;
    case E: cout << 'e'; break;
    case S: cout << 's'; break;
    case W: cout << 'w'; break;
    }
  }
  cout << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
