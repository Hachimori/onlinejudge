#include<stdio.h>

#define MAX_SIZE 205

int dfs(int r, int c, char board[][MAX_SIZE], int visited[][MAX_SIZE], int size){
  static int dr[] = {-1,-1,0,0,1,1}, dc[] = {-1,0,-1,1,0,1};
  int i;
  int nextR, nextC;
  
  if(c==size-1) return 1;
  
  visited[r][c] = 1;
  
  for(i=0;i<6;i++){
    nextR = r+dr[i];
    nextC = c+dc[i];
    if(!(0<=nextR && nextR<size && 0<=nextC && nextC<size)) continue;
    if(visited[nextR][nextC]) continue;
    if(board[nextR][nextC]=='b') continue;
    
    if(dfs(nextR,nextC,board,visited,size)) return 1;
  }
  
  return 0;
}

int main(){
  int i, j, cases = 1;
  int size, wWin, visited[MAX_SIZE][MAX_SIZE];
  char board[MAX_SIZE][MAX_SIZE];

  while(1){
    scanf("%d",&size);
    if(size==0) break;
    
    for(i=0;i<size;i++)
      scanf("%s",board[i]);
    
    for(i=0;i<size;i++)
      for(j=0;j<size;j++)
	visited[i][j] = 0;

    wWin = 0;
    for(i=0;i<size;i++){
      if(visited[i][0]) continue;
      if(dfs(i,0,board,visited,size)){
	wWin = 1;
	break;
      }
    }

    if(wWin) printf("%d W\n",cases++);
    else printf("%d B\n",cases++);
  }

  return 0;
}
