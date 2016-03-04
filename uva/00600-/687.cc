#include<iostream>
#include<string>

#define MAX_SIZE 5
#define MAX_BOARD 10

using namespace std;

int ans;
bool isIdentical[MAX_BOARD];
string boardList[MAX_BOARD];

bool read(){
  cin >> boardList[0];
  if(boardList[0]=="END") return false;

  for(int i=1;i<MAX_BOARD;i++)
    cin >> boardList[i];
  
  return true;
}

void rec(int curr, char state[MAX_SIZE][MAX_SIZE], bool used[MAX_BOARD]){
  

  if(curr==MAX_BOARD){
    ans++;
    return;
  }
  
  if(curr<5)
    for(int i=0;i<MAX_BOARD;i++){
      if(used[i]) continue;
      
      used[i]=true;
      
      for(int j=0;j<MAX_SIZE;j++)
	state[j][curr] = boardList[i][j];
      
      rec(curr+1,state,used);

      if(isIdentical[i]){
	for(int j=0,k=MAX_SIZE-1;j<MAX_SIZE;j++,k--)
	  state[j][curr] = boardList[i][k];
	
	rec(curr+1,state,used);
      }
      
      used[i]=false;
    }
  else
    for(int i=0;i<MAX_BOARD;i++){
      
      if(used[i]) continue;
      
      bool succeed=true;
      
      for(int j=0;j<MAX_SIZE;j++)
	if(state[curr-5][j]==boardList[i][j]){
	  succeed=false;
	  break;
	}

      if(succeed){
	used[i] = true;
	
	rec(curr+1,state,used);
	
	used[i] = false;
      }
      
      if(isIdentical[i]){
	succeed=true;
	
	for(int j=0,k=MAX_SIZE-1;j<MAX_SIZE;j++,k--)
	  if(state[curr-5][j]==boardList[i][k]){
	    succeed=false;
	    break;
	  }
	
	if(succeed){
	  used[i] = true;
	  
	  rec(curr+1,state,used);
	  
	  used[i] = false;
	}
      }
    }

}

void work(){

  bool used[MAX_BOARD];
  char state[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<MAX_BOARD;i++)
    used[i] = false;
  
  for(int i=0;i<MAX_BOARD;i++){
    
    bool succeed=true;
    for(int j=0,k=MAX_SIZE-1;j<MAX_SIZE;j++,k--)
      if(boardList[i][j]!=boardList[i][k]){
	succeed=false;
	break;
      }
	
    if(succeed)
      isIdentical[i] = false;
    else
      isIdentical[i] = true;
    
  }

  ans=0;
  
  rec(0,state,used);
  
  cout << ans/8 << endl;
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
