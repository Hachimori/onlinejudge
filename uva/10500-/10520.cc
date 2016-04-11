#include<iostream>
#include<algorithm>

#define MAX_SIZE 24

using namespace std;

int size;
long long table[MAX_SIZE][MAX_SIZE];

bool read(){
  
  if(!(cin >> size)) return false;

  for(int i=0;i<=size;i++)
    for(int j=0;j<=size;j++)
      table[i][j] = -1;
  
  cin >> table[size][1];

  return true;
}

void work(){
  
  for(int column=0;column<=size;column++){
    
    for(int currColumn=column,currRow=size;currColumn>=0;currColumn--,currRow--){
 
      if(currColumn==0 && currRow==size){
	table[currRow][currColumn]=0;
	continue;
      }
      
      if(currColumn==1 && currRow==size) continue;

      if(currRow>=currColumn){
	long long sum=0, maxVal=-1;
		
	for(int k=currRow+1;k<=size;k++){
	  if(table[k][1]<0 || table[k][currColumn]<0) exit(1);
	  maxVal = max(maxVal,table[k][1]+table[k][currColumn]);
	}

	if(maxVal!=-1)
	  sum+=maxVal;
	
	maxVal=-1;
	
	for(int k=1;k<currColumn;k++){
	  if(table[currRow][k]<0 || table[size][k]<0) exit(1);
	  maxVal = max(maxVal,table[currRow][k]+table[size][k]);
	}

	if(maxVal!=-1)
	  sum+=maxVal;

	table[currRow][currColumn]=sum;
      }

    }

  }

  for(int row=size-1;row>=0;row--){
    for(int currRow=row,currColumn=size;currRow>=0;currRow--,currColumn--){

      long long maxVal = -1;
      
      for(int k=currRow;k<currColumn;k++){
	if(table[currRow][k]<0 || table[k+1][currColumn]<0) exit(1);
	maxVal = max(maxVal,table[currRow][k]+table[k+1][currColumn]);
      }
      
      table[currRow][currColumn] = maxVal;
    }    
  }
  
  /*
  for(int i=0;i<=size;i++){
    for(int j=0;j<=size;j++){
      cout << table[i][j]  << ' ';
    }cout << endl;
  }
  */

  cout << table[1][size] << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
