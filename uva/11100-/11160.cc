#include<iostream>
#include<queue>
#define BUF 10
#define WALL -1
#define GOAL 1
#define NONE 0
#define INF (1<<20)
using namespace std;

class Data{
public:
  int ar, ac, br, bc, cr, cc;

  Data(){}
  Data(int ar, int ac, int br, int bc, int cr, int cc):
    ar(ar), ac(ac), br(br), bc(bc), cr(cr), cc(cc){}
};

int size, b[BUF][BUF];
int ar, ac, br, bc, cr, cc;

void read(){
  cin >> size;

  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++){
      char ch;
      cin >> ch;

      if(ch=='#') b[i][j] = WALL;
      else if(ch=='X') b[i][j] = GOAL;
      else b[i][j] = NONE;

      if(ch=='A') ar = i, ac = j;
      if(ch=='B') br = i, bc = j;
      if(ch=='C') cr = i, cc = j;
    }
}

int visited[BUF][BUF][BUF][BUF][BUF][BUF];

int &access(Data d){
  return visited[d.ar][d.ac][d.br][d.bc][d.cr][d.cc];
}

bool isInside(int r, int c){
  return 0<=r && r<size && 0<=c && c<size;
}

int bfs(){
  const static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  int bgnR[]={   0,     0,size-1,   0};
  int endR[]={size,  size,    -1,size};
  int bgnC[]={   0,size-1,     0,   0};
  int endC[]={size,    -1,  size,size};
  int itR[]={1,1,-1,1}, itC[]={1,-1,1,1};

  queue<Data> Q;

  for(int i=0;i<BUF;i++)
  for(int j=0;j<BUF;j++)
  for(int k=0;k<BUF;k++)
  for(int l=0;l<BUF;l++)
  for(int m=0;m<BUF;m++)
  for(int n=0;n<BUF;n++)
    visited[i][j][k][l][m][n] = INF;

  Data toPush = Data(ar,ac,br,bc,cr,cc);

  access(toPush) = 0;
  Q.push(toPush);
  
  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();

    if(b[cur.ar][cur.ac]==GOAL && b[cur.br][cur.bc]==GOAL && b[cur.cr][cur.cc]==GOAL)
      return access(cur);
    
    for(int i=0;i<4;i++){
      int nar=-1, nac=-1, nbr=-1, nbc=-1, ncr=-1, ncc=-1;
	
      for(int r=bgnR[i];r!=endR[i];r+=itR[i])
	for(int c=bgnC[i];c!=endC[i];c+=itC[i])
	  if(cur.ar==r && cur.ac==c){
	    if(!isInside(cur.ar+dr[i],cur.ac+dc[i]) || b[cur.ar+dr[i]][cur.ac+dc[i]]==WALL || 
	       (cur.ar+dr[i]==nbr && cur.ac+dc[i]==nbc) || (cur.ar+dr[i]==ncr && cur.ac+dc[i]==ncc) ) 
	      nar = cur.ar, nac = cur.ac;
	    else
	      nar = cur.ar+dr[i], nac = cur.ac+dc[i];
	  }
	  else if(cur.br==r && cur.bc==c){
	    if(!isInside(cur.br+dr[i],cur.bc+dc[i]) || b[cur.br+dr[i]][cur.bc+dc[i]]==WALL || 
	       (cur.br+dr[i]==nar && cur.bc+dc[i]==nac) || (cur.br+dr[i]==ncr && cur.bc+dc[i]==ncc) ) 
	      nbr = cur.br, nbc = cur.bc;
	    else
	      nbr = cur.br+dr[i], nbc = cur.bc+dc[i];
	  }
	  else if(cur.cr==r && cur.cc==c){
	    if(!isInside(cur.cr+dr[i],cur.cc+dc[i]) || b[cur.cr+dr[i]][cur.cc+dc[i]]==WALL || 
	       (cur.cr+dr[i]==nar && cur.cc+dc[i]==nac) || (cur.cr+dr[i]==nbr && cur.cc+dc[i]==nbc) ) 
	      ncr = cur.cr, ncc = cur.cc;
	    else
	      ncr = cur.cr+dr[i], ncc = cur.cc+dc[i];
	  }
	
      Data nex = Data(nar,nac,nbr,nbc,ncr,ncc);
      if(access(nex)>access(cur)+1){
	access(nex) = access(cur)+1;
	Q.push(nex);
      }
    }
  }
 
  return -1;
}

void work(int cases){
  int ret = bfs();
  
  if(ret==-1)
    cout << "Case " << cases << ": trapped" << endl;
  else
    cout << "Case " << cases << ": " << ret << endl;
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