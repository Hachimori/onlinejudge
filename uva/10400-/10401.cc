#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstdlib>

#define MAX_SIZE 20

using namespace std;

int size;
bool isAvail[MAX_SIZE][MAX_SIZE];
string str;

bool isInside(int r, int c){
  return 0<=r && r<size && 0<=c && c<size;
}

void calc(int currColumn, long long val[MAX_SIZE][MAX_SIZE]){

  if(currColumn==size) return;

  for(int currRow=0;currRow<size;currRow++){
    for(int nextRow=0;nextRow<size;nextRow++){
      
      if(abs(currRow-nextRow)<=1 || !isAvail[nextRow][currColumn+1]) continue;

      val[nextRow][currColumn+1]+=val[currRow][currColumn];
    }
  }

  calc(currColumn+1,val);

}

void work(){

  size = str.size();

  for(int i=0;i<size;i++)
    fill(isAvail[i],isAvail[i]+size,true);

  for(int i=0;i<str.size();i++){
    if(str[i]!='?'){

      const static int rMove[8]={1,1,1,0,-1,-1,-1,0};
      const static int cMove[8]={-1,0,1,1,1,0,-1,-1};
      
      for(int j=0;j<8;j++){
	int nextR;
	int nextC=i+cMove[j];
	
	if(isdigit(str[i])) nextR=str[i]-'0'-1+rMove[j];
	else nextR=str[i]-'A'+9+rMove[j];

	if(!isInside(nextR,nextC)) continue;

	isAvail[nextR][nextC]=false;
      }

      for(int j=0;j<size;j++)
	if(isdigit(str[i]) && j!=str[i]-'0'-1)
	  isAvail[j][i]=false;
	else if(isalpha(str[i]) && j!=str[i]-'A'+9)
	  isAvail[j][i]=false;

    }    
  }

  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(isAvail[i][j]) cout << "-";
      else cout << "#";
    }cout << endl;
  }cout << endl;
  */

  long long val[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<size;i++)
    fill(val[i],val[i]+size,0);

  for(int i=0;i<size;i++)
    if(isAvail[i][0])
      val[i][0] = 1;

  calc(0,val);


  long long sum=0;
  
  for(int i=0;i<size;i++)
    sum+=val[i][size-1];
  
  printf("%lld\n",sum);
}

int main(){

  while(cin >> str)
    work();

  return 0;
}
