#include<iostream>
#include<algorithm>

#define COLOR 4
#define BUF 8

using namespace std;

int nType, nColor[COLOR];
int dp[BUF][BUF][BUF][BUF][4][4][COLOR][COLOR];

void read(){
  cin >> nType;

  for(int i=0;i<COLOR;i++)
    nColor[i] = 0;

  for(int i=0;i<nType;i++)
    cin >> nColor[i];
}

int rec(int nC[], int putF, int putB, int front, int back){
  if(dp[nC[0]][nC[1]][nC[2]][nC[3]][putF][putB][front][back]!=-1)
    return dp[nC[0]][nC[1]][nC[2]][nC[3]][putF][putB][front][back];
  
  int cnt = 0, col;
  for(int i=0;i<4;i++)
    if(nC[i]>0){
      cnt++;
      col = i;
    }
  
  if(cnt==1){
    if(col!=back && col!=front && nC[col]<4 && nC[col]!=putB && nC[col]!=putF){ 
      dp[nC[0]][nC[1]][nC[2]][nC[3]][putF][putB][front][back] = 1;
      return 1;
    }
    else{ 
      dp[nC[0]][nC[1]][nC[2]][nC[3]][putF][putB][front][back] = 0;
      return 0;
    }
  }
  
  int sum = 0;

  for(int i=0;i<4;i++){
    if(i==front) continue;
      
    for(int k=1;k<=min(nC[i],3);k++){
      if(k==putF) continue;

      nC[i] -= k;
      
      sum += rec(nC,k,putB,i,back);
      
      nC[i] += k;
    }
  }
  
  dp[nC[0]][nC[1]][nC[2]][nC[3]][putF][putB][front][back] = sum;
  return sum;
}

void makeTable(){
  for(int i=0;i<BUF;i++)
  for(int j=0;j<BUF;j++)
  for(int k=0;k<BUF;k++)
  for(int l=0;l<BUF;l++)
  for(int m=0;m<4;m++)
  for(int n=0;n<4;n++)
  for(int o=0;o<COLOR;o++)
  for(int p=0;p<COLOR;p++)
    dp[i][j][k][l][m][n][o][p] = -1;

  for(int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  for(int k=0;k<COLOR;k++)
  for(int l=0;l<COLOR;l++)
    if(k!=l && i!=j)
      dp[0][0][0][0][i][j][k][l] = 1;
    else
      dp[0][0][0][0][i][j][k][l] = 0;
  
  int tmpColor[]={7,7,7,7};
  
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(i==j) continue;
      for(int k=1;k<=3;k++)
	for(int m=1;m<=3;m++){
	  if(k==m) continue;

	  tmpColor[i] -= k;
	  tmpColor[j] -= m;

	  rec(tmpColor,k,m,i,j);

	  tmpColor[i] += k;
	  tmpColor[j] += m;
	}
    }
  }
}

void work(){
  int nMarble = 0;
  for(int i=0;i<nType;i++)
    nMarble += nColor[i];
  if(nMarble==0){
    cout << 1 << endl;
    return;
  }

  if(nType==1){
    cout << 0 << endl;
    return;
  }  
  
  int sum = 0;
  
  for(int i=0;i<nType;i++){
    for(int j=0;j<nType;j++){
      if(i==j) continue;
      for(int k=1;k<=min(nColor[i],3);k++)
	for(int m=1;m<=min(nColor[j],3);m++){
	  if(k==m) continue;
	
	  nColor[i] -= k;
	  nColor[j] -= m;
	  sum += rec(nColor,k,m,i,j);
	  nColor[i] += k;
	  nColor[j] += m;
	}
    }
  }
  
  cout << sum << endl;
}

int main(){
  makeTable();
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
