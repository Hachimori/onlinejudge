#include<iostream>
#include<queue>
using namespace std;
const int BUF = 55;

enum mapType{NONE,MIRROR,WALL};
enum mirrorType{SLASH,BSLASH,YET};

class Data{
public:
  int r, c, dir;
  Data(){}
  Data(int r, int c, int dir): r(r), c(c), dir(dir){}
};


int dr[]={-1,0,1,0}, dc[]={0,1,0,-1}, typeDir2nexDir[2][4]={{1,0,3,2},{3,2,1,0}};
int row, col, b[BUF][BUF];

bool read(){
  cin >> col >> row;
  if(row==-1 && col==-1) return false;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;
      if(ch=='*') b[i][j] = WALL;
      if(ch=='.') b[i][j] = NONE;
      if(ch=='/' || ch=='\\') b[i][j] = MIRROR;
    }
      
  return true;
}


bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}


bool canGo(int r, int c, int dir, int mirror[BUF][BUF]){
  queue<Data> Q;
  bool visited[BUF][BUF][4]={};
  Q.push(Data(r,c,dir));

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();
    
    int nr = cur.r+dr[cur.dir], nc = cur.c+dc[cur.dir];
    while(isInside(nr,nc) && b[nr][nc]==NONE){
      nr += dr[cur.dir];
      nc += dc[cur.dir];
    }
    
    if(!isInside(nr,nc)) return true;

    if(visited[nr][nc][cur.dir]) continue;
    visited[nr][nc][cur.dir] = true;

    if(b[nr][nc]==MIRROR){
      if(mirror[nr][nc]==YET){
        Q.push(Data(nr,nc,(cur.dir+1)%4));
        Q.push(Data(nr,nc,(cur.dir+3)%4));
      }
      else{
        int nexDir = typeDir2nexDir[mirror[nr][nc]][cur.dir];
        Q.push(Data(nr,nc,nexDir));
      }
    }
  }

  return false;
}


bool dfs(int r, int c, int dir, int mirror[BUF][BUF]){
  if(!canGo(r,c,dir,mirror)) return false;
  
  int nr = r+dr[dir], nc = c+dc[dir];
  while(isInside(nr,nc) && b[nr][nc]==NONE){
    nr += dr[dir];
    nc += dc[dir];
  }
  
  if(!isInside(nr,nc)) return true;

  if(b[nr][nc]==MIRROR){
    if(mirror[nr][nc]==YET){
      for(int type=SLASH;type<=BSLASH;type++){
        mirror[nr][nc] = type;
        if(dfs(nr-dr[dir],nc-dc[dir],dir,mirror)) return true;
        mirror[nr][nc] = -1;
      }
    }
    else
      return dfs(nr,nc,typeDir2nexDir[mirror[nr][nc]][dir],mirror);
  }
  return false;
}


void work(){
  int mirror[BUF][BUF];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      mirror[i][j] = YET;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(b[i][j]!=WALL){
        if(i==0){ dfs(-1,j,2,mirror); goto _finish;}
        else if(j==0){ dfs(i,-1,1,mirror); goto _finish;}
        else if(i==row-1){ dfs(row,j,0,mirror); goto _finish;}
        else if(j==col-1){ dfs(i,col,3,mirror); goto _finish;}
      }
    }

 _finish:;
   for(int i=0;i<row;i++){
    for(int j=0;j<col;j++)
      if(b[i][j]==WALL)
        cout << '*';
      else if(b[i][j]==NONE)
        cout << '.';
      else if(mirror[i][j]==SLASH)
        cout << '/';
      else
        cout << '\\';
    cout << endl;
  }  
}


int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
