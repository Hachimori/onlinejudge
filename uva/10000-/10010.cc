#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

#define MAX_SIZE 55

using namespace std;

int row, column;
string board[MAX_SIZE];

void read(){

  cin >> row >> column;
  
  getline(cin,board[0]);

  for(int i=0;i<row;i++)
    getline(cin,board[i]);
 
}

bool isInside(int r, int c){
  return (0<=r && r<row && 0<=c && c<column);
}

void work(){  

  static int rMove[8]={1,1,1,0,-1,-1,-1,0};
  static int cMove[8]={-1,0,1,1,1,0,-1,-1};
  
  int nQuery;
  cin >> nQuery;

  string str; getline(cin,str);

  for(int i=0;i<nQuery;i++){
    getline(cin,str);
    
    int minR=MAX_SIZE, minC=MAX_SIZE;
    int apparentR, apparentC;

    for(int r=0;r<row;r++){
      for(int c=0;c<column;c++){
	
	for(int j=0;j<8;j++){

	  int k=0;
	  
	  int tmpMinR=MAX_SIZE, tmpMinC=MAX_SIZE;

	  for(int currR=r,currC=c;k<str.length();k++,currR+=rMove[j],currC+=cMove[j]){
	    if(!isInside(currR,currC)) break;
	    if(toupper(str[k])!=toupper(board[currR][currC])) break;

	    tmpMinR=min(tmpMinR,currR);
	    tmpMinC=min(tmpMinC,currC);
	  }
	  
	  if(k==str.length()){
	    if(minR>tmpMinR){
	      minR=tmpMinR;
	      minC=tmpMinC;
	      apparentR = r;
	      apparentC = c;
	    }
	    else if(minR==tmpMinR && minC>tmpMinC){
	      minR=tmpMinR;
	      minC=tmpMinC;
	      apparentR = r;
	      apparentC = c;
	    }
	  }

	}
	
      }
    }

    cout << apparentR+1 << ' ' << apparentC+1 << endl;
  }

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
