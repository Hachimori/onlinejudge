#include<iostream>
using namespace std;
const int BUF = 15;

int row, col;
char b[BUF][BUF];

bool read(){
  cin >> row >> col;
  if(row==0) return false;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
  return true;
}


void work(int cases){
  int id[BUF][BUF], cnt = 1;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      if(b[i][j]=='*') continue;
      if(i==0 || j==0 || b[i-1][j]=='*' || b[i][j-1]=='*')
        id[i][j] = cnt++;
    }
  
  cout << "puzzle #" << cases << ":" << endl;

  cout << "Across" << endl;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]!='*' && (j==0 || b[i][j-1]=='*')){
        printf("%3d.",id[i][j]);
        while(j<col && b[i][j]!='*') cout << b[i][j++];
        cout << endl;
      }
  
  cout << "Down" << endl;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]!='*' && (i==0 || b[i-1][j]=='*')){
        printf("%3d.",id[i][j]);
        for(int k=i;k<row && b[k][j]!='*';k++) cout << b[k][j];
        cout << endl;
      }  
}


int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  return 0;
}
