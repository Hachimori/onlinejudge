#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<utility>

#define EAST 0
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define MAX_SIZE 25
#define MAX_STR 1000

using namespace std;

class Point{
public:

  int r,c;

  Point(){}
  Point(int r, int c): r(r), c(c){}
  
};

int row, column, nTarget;
string board[MAX_SIZE];
char cList[4]={'E','N','S','W'};
Point init;

bool read(){
  
  cin >> row >> column;
  if(row==0 && column==0) return false;

  getline(cin,board[0]);
  
  for(int i=0;i<row;i++){
    getline(cin,board[i]);
    
    for(int j=0;j<column;j++){
      if(board[i][j]=='X') board[i][j]='#';
      if(board[i][j]=='S') init = Point(i,j);
    }
  }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<column;
}

void availCheck(vector<Point> &target){
  
  int dr[4]={0,-1,1,0}, dc[4]={1,0,0,-1};
  bool visited[MAX_SIZE][MAX_SIZE];
  queue<Point> Q;

  Q.push(init);
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      visited[i][j] = false;
  
  
  while(!Q.empty()){

    Point curr=Q.front();
    Q.pop();

    if(visited[curr.r][curr.c]) continue;
    visited[curr.r][curr.c] = true;
    
    if(board[curr.r][curr.c]=='*')
      target.push_back(curr);
    
    for(int i=0;i<4;i++){
      
      if(!isInside(curr.r+dr[i],curr.c+dc[i])) continue;
      if(board[curr.r+dr[i]][curr.c+dc[i]]=='#') continue;
      
      Q.push(Point(curr.r+dr[i],curr.c+dc[i]));
    }
    
  }
  
}

void bfs(vector<Point> &target,
		vector<int> adjList[MAX_SIZE][MAX_SIZE], int &start){
  
  static int dr[4]={0,-1,1,0}, dc[4]={1,0,0,-1};
  bool visited[MAX_SIZE][MAX_SIZE];
  queue< pair<Point,vector<int> > > Q;

  
  Q.push( make_pair(target[start],vector<int>()) );
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      visited[i][j] = false;
  
  while(!Q.empty()){
    
    pair<Point,vector<int> > curr=Q.front();
    Q.pop();
    
    if(visited[curr.first.r][curr.first.c]) continue;
    visited[curr.first.r][curr.first.c] = true;
    
    if(board[curr.first.r][curr.first.c]=='*' ||
       board[curr.first.r][curr.first.c]=='S' ){ 
      
      for(int i=0;i<target.size();i++)
	if(target[i].r==curr.first.r && target[i].c==curr.first.c){
	  adjList[start][i] = curr.second;
	  break;
	}
    }
    
    for(int i=0;i<4;i++){
      if(!isInside(curr.first.r+dr[i],curr.first.c+dc[i])) continue;
      if(board[curr.first.r+dr[i]][curr.first.c+dc[i]]=='#') continue;
      
      curr.second.push_back(i);
      
      Q.push( make_pair(Point(curr.first.r+dr[i],curr.first.c+dc[i]),curr.second));
      
      curr.second.pop_back();
    }
    
  }
  
}

void rec(int curr, int &currDis, int &nVisited, int path[MAX_STR],
	 vector<int> adjList[MAX_SIZE][MAX_SIZE], bool visited[MAX_SIZE],
	 char ans[MAX_STR]){
  
  if(nVisited==nTarget){
    
    if(currDis+adjList[curr][0].size()>strlen(ans)) return;
    
    int k=0;
    char toCmp[MAX_STR];
    
    for(int i=0;i<nTarget;i++)
      for(int j=0;j<adjList[path[i]][path[(i+1)%nTarget]].size();j++,k++)
	toCmp[k]=cList[adjList[path[i]][path[(i+1)%nTarget]][j]];
    
    
    toCmp[k]='\0';

    if(strlen(toCmp)<strlen(ans))
      strcpy(ans,toCmp);
    else if(strlen(toCmp)==strlen(ans) && strcmp(toCmp,ans)<0)
      strcpy(ans,toCmp);
      
    return;
  }
  
  if(currDis>=strlen(ans)) return;
  
  for(int i=0;i<nTarget;i++){
    if(visited[i]) continue;
    
    visited[i] = true;
    path[nVisited] = i;
    
    currDis+=adjList[curr][i].size();
    nVisited++;
    
    rec(i,currDis,nVisited,path,adjList,visited,ans);
    
    currDis-=adjList[curr][i].size();
    nVisited--;

    visited[i] = false;
  }
  
}

void work(){
  
  vector<Point> target;
  vector<int> adjList[MAX_SIZE][MAX_SIZE];
  
  target.push_back(init);
  
  availCheck(target);
  
  if(target.size()==1){
    cout << "Stay home!" << endl;
    return;
  }
  
  for(int i=0;i<target.size();i++)
    bfs(target,adjList,i);
  
  int path[MAX_STR], nVisited=1, currDis=0;
  bool visited[MAX_SIZE];
  char ans[MAX_STR];
  
  nTarget = target.size();  
  
  for(int i=0;i<nTarget;i++)
    visited[i] = false;
  visited[0] = true;
  path[0] = 0;

  for(int i=0;i<MAX_STR;i++)
    ans[i] = 'z';
  ans[MAX_STR-1] = '\0';
  
  rec(0,currDis,nVisited,path,adjList,visited,ans);
  
  cout << ans << endl;
} 

int main(){
  
  while(read())
    work();
  
  return 0;
}
