#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<cstdio>
#include<cassert>

#undef NULL
#define NULL 99999
#define MAX_SIZE 11
#define MAX_NUM 2010
#define SHIFT 1005

using namespace std;

int size;
int rList[MAX_SIZE], cList[MAX_SIZE];

bool read(){
  
  cin >> size;
  if(size==0) return false;

  for(int i=0;i<size;i++)
    cin >> cList[i];
  
  for(int i=0;i<size;i++)
    cin >> rList[i];
  
  return true;
}

// num of non-NULL, nun-NULLvalue 
pair<int,int> countNum(int r, int c, int board[MAX_SIZE][MAX_SIZE]){ 
  pair<int,int> ret=make_pair(0,NULL);
  for(int i=0;i<c;i++)
    if(board[r][i]!=NULL)
      ret=make_pair(ret.first+1,board[r][i]);
  return ret;
}

bool rec(int currC, int board[MAX_SIZE][MAX_SIZE],
	 set<int> rDivList[MAX_SIZE], set<int> cDivList[MAX_SIZE], bool used[MAX_NUM]){
  
  if(currC==size) return true;

  
  for(int i=0;i<size;i++){
    
    pair<int,int> iRet,jRet;
    iRet=countNum(i,currC,board);
    if(iRet.first==2) continue;    
      
    for(int j=i+1;j<size;j++){
      jRet=countNum(j,currC,board);
      if(jRet.first==2) continue;
      
      if(iRet.first==0){
	
	set<int>::iterator iDiv,begin=cDivList[currC].begin(),end=cDivList[currC].end();
	
	for(iDiv=begin;iDiv!=end;iDiv++){
	  if(rDivList[i].find(*iDiv)==rDivList[i].end()) continue;
	  if(jRet.first==0 && 
	     rDivList[j].find(cList[currC]/(*iDiv))==rDivList[j].end()) continue;
	  if(jRet.first==1 &&
	     jRet.second*cList[currC]/(*iDiv)!=rList[j]) continue;

	  if(used[SHIFT+(*iDiv)] || used[SHIFT+cList[currC]/(*iDiv)] ||
	     (*iDiv)==cList[currC]/(*iDiv)) continue;
	  board[i][currC] = (*iDiv);
	  board[j][currC] = cList[currC]/(*iDiv);
	  used[SHIFT+(*iDiv)]=true;
	  used[SHIFT+cList[currC]/(*iDiv)]=true;

	  if(rec(currC+1,board,rDivList,cDivList,used)) return true;
	  
	  board[i][currC] = NULL;
	  board[j][currC] = NULL;
	  used[SHIFT+(*iDiv)]=false;
	  used[SHIFT+cList[currC]/(*iDiv)]=false;
	}
	
      }
      else {
	if(cDivList[currC].find(rList[i]/iRet.second)==cDivList[currC].end()) continue;
	
	if(jRet.first==0){
	  if(rDivList[j].find(cList[currC]/(rList[i]/iRet.second))==rDivList[j].end()) continue;
	  
	  if(used[SHIFT+rList[i]/iRet.second] || used[SHIFT+cList[currC]/(rList[i]/iRet.second)]||
	     rList[i]/iRet.second==cList[currC]/(rList[i]/iRet.second)) continue;
	  board[i][currC] = rList[i]/iRet.second;
	  board[j][currC] = cList[currC]/(rList[i]/iRet.second);
	  used[SHIFT+rList[i]/iRet.second]=true;
	  used[SHIFT+cList[currC]/(rList[i]/iRet.second)]=true;

	  if(rec(currC+1,board,rDivList,cDivList,used)) return true;

	  board[i][currC] = NULL;
	  board[j][currC] = NULL;
	  used[SHIFT+rList[i]/iRet.second]=false;
	  used[SHIFT+cList[currC]/(rList[i]/iRet.second)]=false;
	}
	else if(jRet.first==1){
	  if((rList[i]/iRet.second)*(rList[j]/jRet.second)!=cList[currC]) continue;
	  
	  if(used[SHIFT+rList[i]/iRet.second] || used[SHIFT+rList[j]/jRet.second] ||
	     rList[i]/iRet.second==rList[j]/jRet.second) continue;
	  board[i][currC] = rList[i]/iRet.second;
	  board[j][currC] = rList[j]/jRet.second;
	  used[SHIFT+rList[i]/iRet.second]=true;
	  used[SHIFT+rList[j]/jRet.second]=true;

	  if(rec(currC+1,board,rDivList,cDivList,used)) return true;

	  board[i][currC] = NULL;
	  board[j][currC] = NULL;
	  used[SHIFT+rList[i]/iRet.second]=false;
	  used[SHIFT+rList[j]/jRet.second]=false;
	}
	
      }
      
    }
  }
  
  return false;
}

void work(){
  
  int board[MAX_SIZE][MAX_SIZE];
  set<int> rDivList[MAX_SIZE], cDivList[MAX_SIZE];
  bool used[MAX_NUM];

  for(int i=0;i<MAX_NUM;i++)
    used[i] = false;
    
  for(int i=0;i<size;i++){
    for(int j=1;j<=rList[i];j++){
      if(rList[i]%j==0){
	rDivList[i].insert(j);
	rDivList[i].insert(-j);
      }
    }

    for(int j=1;j<=cList[i];j++){
      if(cList[i]%j==0){
	cDivList[i].insert(j);
	cDivList[i].insert(-j);
      }
    }
  }
  
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      board[i][j] = NULL;
  
  if(!rec(0,board,rDivList,cDivList,used)) assert(false);
  
   for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(j!=0) printf(" ");
      if(board[i][j]!=NULL)
	printf("%3d",board[i][j]);
      else
	printf("%3d",0);
    }
    cout << endl;
  }
}

int main(){
  
  for(int i=0;read();i++){
    work();
    cout  <<  endl;
  }

  return 0;
}
