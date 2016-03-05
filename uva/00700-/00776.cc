#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>

#define MAX_SIZE 1000

using namespace std;

int row, column;
char board[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void split(string str, vector<char> &cList){
  
  int cursor=0;

  while(cursor<str.length()){
    
    while(cursor<str.length() && str[cursor]==' ') cursor++;
    
    if(cursor<str.length()) cList.push_back(str[cursor]);
    cursor++;    
  }
  
}

bool read(){

  row=0,column=0;

  while(true){

    string str;
    
    if(getline(cin,str)==NULL) return false;    
    if(str=="%") break;

    vector<char> cList;
    split(str,cList);
     

    for(int i=0;i<cList.size();i++)
      board[row][i]=cList[i];
       
    row++;
    column=cList.size();

  }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<column;
}

void bfs(int currR, int currC, int nGroup, int visited[MAX_SIZE][MAX_SIZE]){
  
  static const int rMove[8]={1,1,1,0,-1,-1,-1,0};
  static const int cMove[8]={-1,0,1,1,1,0,-1,-1};

  visited[currR][currC] = nGroup;

  for(int i=0;i<8;i++){
    int nextR=currR+rMove[i], nextC=currC+cMove[i];
    
    if(!isInside(nextR,nextC)) continue;
    if(visited[nextR][nextC]!=-1) continue;

    if(board[nextR][nextC]==board[currR][currC])
      bfs(nextR,nextC,nGroup,visited);
  }

}

void work(){
  
  for(int i=0;i<row;i++)
    fill(visited[i],visited[i]+column,-1);


  int nGroup=1;

  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      if(visited[i][j]==-1){	
	bfs(i,j,nGroup,visited);
	nGroup++;
      }
    }
  }
  
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      
      int maxVal=-1;
      for(int k=0;k<row;k++)
	if(maxVal<visited[k][j])
	  maxVal = visited[k][j];
      
      if(j!=0)
	printf(" %*d",(int)log10((double)maxVal)+1,visited[i][j]);
      else
	printf("%*d",(int)log10((double)maxVal)+1,visited[i][j]);

    }cout << endl;
  }cout << "%" << endl;

}

int main(){

  while(true){
    if(!read()) {
      work();
      break;
    }
    work();
  }

  return 0;
}
