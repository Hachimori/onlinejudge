#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#define MAX 81

class Graph{
 public:

  char visited[MAX][MAX];
  int num_line;

  Graph(){num_line=0;}

};

void dfs_rec(Graph &g, int y, int x){
  
  int goto_x[4]={0,1,0,-1},goto_y[4]={1,0,-1,0};
 
  for(int i=0;i<4;i++){
    if(goto_y[i]+y>=0 && goto_y[i]+y< g.num_line &&
       goto_x[i]+x>=0 && goto_x[i]+x< strlen(g.visited[y])&&
       g.visited[goto_y[i]+y][goto_x[i]+x]==' '){
      g.visited[goto_y[i]+y][goto_x[i]+x]='#';
      dfs_rec(g,goto_y[i]+y,goto_x[i]+x);
    }
  }

  return;

}

void dfs(Graph &g){
  
  
  bool flg=false;

  for(int i=0;i<g.num_line;i++){
    for(int j=0;j<strlen(g.visited[i]);j++){
      if(g.visited[i][j]=='*'){
	g.visited[i][j]='#';
	dfs_rec(g,i,j);
	flg=true;
	break;
      }
    }
    if(flg==true) break;
  }

  return;
}



void Input(void);
void Work(Graph);

main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){ 
    if(i!=0) cout << endl;
    Input();
  }
}

void Input(void){

  Graph g;

  for(int i=0;;i++){
   gets(g.visited[i]);
    g.num_line++;
   if(g.visited[i][0]=='_') break;
  }

  Work(g);

  return;

}

void Work(Graph g){

  dfs(g);
  
  for(int i=0;i<g.num_line;i++){
    printf("%s\n",g.visited[i]);
  }

  return;
  
}
