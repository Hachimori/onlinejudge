#include<iostream>

#define MAX_SIZE 1000

using namespace std;

int bigSize, smallSize;
char bigBoard[MAX_SIZE][MAX_SIZE];
char smallBoard[MAX_SIZE][MAX_SIZE];

bool read(){

  cin >> bigSize >> smallSize;
  if(bigSize==0 && smallSize==0) return false;

  for(int i=0;i<bigSize;i++)
    for(int j=0;j<bigSize;j++)
      cin >> bigBoard[i][j];
    
  for(int i=0;i<smallSize;i++)
    for(int j=0;j<smallSize;j++)
      cin >> smallBoard[i][j];      

  return true;
}

void work(){

  int cnt1,cnt2,cnt3,cnt4;
  cnt1 = cnt2 = cnt3 = cnt4 = 0;

  for(int i=0;i<=bigSize-smallSize;i++){
    for(int j=0;j<=bigSize-smallSize;j++){
      
      bool same=true;

      for(int k=0,m=0;k<smallSize;m++,k++)
	for(int l=0,n=0;l<smallSize;n++,l++)
	  if(bigBoard[i+k][j+l]!=smallBoard[m][n])
	    same=false;
      
      if(same) cnt1++;
    }
  }

  
  for(int i=0;i<=bigSize-smallSize;i++){
    for(int j=0;j<=bigSize-smallSize;j++){
      
      bool same=true;

      for(int k=smallSize-1,m=0;k>=0;m++,k--)
	for(int l=0,n=0;l<smallSize;n++,l++)
	  if(bigBoard[i+l][j+k]!=smallBoard[m][n])
	    same=false;
      
      if(same) cnt2++;
    }
  }
  

  for(int i=0;i<=bigSize-smallSize;i++){
    for(int j=0;j<=bigSize-smallSize;j++){
      
      bool same=true;
      
      for(int k=smallSize-1,m=0;k>=0;k--,m++)
	for(int l=smallSize-1,n=0;l>=0;l--,n++)
	  if(bigBoard[i+k][j+l]!=smallBoard[m][n])
	    same=false;
      
      if(same) cnt3++;
    }
  }  

  
  for(int i=0;i<=bigSize-smallSize;i++){
    for(int j=0;j<=bigSize-smallSize;j++){
      
      bool same=true;
      
      for(int k=0,m=0;k<smallSize;k++,m++)
	for(int l=smallSize-1,n=0;l>=0;l--,n++)
	  if(bigBoard[i+l][j+k]!=smallBoard[m][n])
	    same=false;
      
      if(same) cnt4++;
    }
  }  

  cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << ' ' << cnt4 << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
