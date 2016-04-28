#include<iostream>
#include<algorithm>
#define BUF 9
using namespace std;

int row, col;
bool marked[BUF][BUF];

bool read(){
  cin >> row;
  if(row==0) return false;
  cin >> col;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;
      marked[i][j] = ch=='X';
    }
  
  return true;
}

int manhattan(int pos[BUF][2], int nPut){
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(marked[i][j]){
        bool ok = false;
        for(int k=0;k<nPut;k++)
          if(abs(i-pos[k][0])==0 || abs(j-pos[k][1])==0 || 
             abs(i-pos[k][0])==abs(j-pos[k][1])){
            ok = true;
            break;
          }

        if(!ok) return 1;
      }
  
  return 0;
}

bool dfs(int r, int c, int nPut, int limit, int pos[BUF][2]){
  if(manhattan(pos,nPut)==0) return true;
  if(nPut+1>limit) return false;
  if(c==col) return dfs(r+1,0,nPut,limit,pos);
  if(r==row) return false;
  
  pos[nPut][0] = r;
  pos[nPut][1] = c;
  if(dfs(r,c+1,nPut+1,limit,pos)) return true;
    
  if(dfs(r,c+1,nPut,limit,pos)) return true;
  
  return false;
}

int IDE(int limit){
  for(int i=0;i<limit;i++){
    int pos[BUF][2];
    if(dfs(0,0,0,i,pos)) return i;
  }
  return limit;
}

void work(int cases){
  cout << "Case " << cases << ": " << IDE(min(row,col)) << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
