#include<iostream>
#include<utility>
#include<vector>

#define MAX_SIZE 101

using namespace std;

int size, query;
vector< pair<int,int> > table;  // dx, dy
char board[MAX_SIZE][MAX_SIZE];

void makeTable(){
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=1;j<MAX_SIZE;j++)
      if(i*i+j*j<MAX_SIZE*MAX_SIZE)
	table.push_back( make_pair(i,j) );
  
}

bool read(){
  
  cin >> size;
  if(size==0) return false;
  
  cin >> query;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      cin >> board[i][j];
  
  return true;
}

void calc(){
  
  char target;
  int currR,currC;
  int dr,dc;
  bool success;
  int ans=0;
  
  cin >> target;
  
  for(vector< pair<int,int> >::iterator i=table.begin();i!=table.end();i++){
    
    if(i->first*i->first+i->second*i->second>size*size)
      continue;
    
    for(int r=0;r<size-i->first-i->second;r++){
      for(int c=i->first;c<size-i->second;c++){
	
	success=true;
	currR=r,currC=c;
	dr=i->first, dc=i->second;

	for(int j=0;j<4;j++){
	  currR+=dr;
	  currC+=dc;
	 
	  if(board[currR][currC]!=target) {
	    success = false;
	    break;
	  }

	  int tmp = dr;
	  dr = dc;
	  dc = -tmp;
	}
	
	if(success) ans++;
      }
    }
    
  }
  
  cout << target << ' ' << ans << endl;
}

void work(){
  
  for(int i=0;i<query;i++)
    calc();
    
}

int main(){
  
  makeTable();
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }
  
  return 0;
}
