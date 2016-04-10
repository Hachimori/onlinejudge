#include<iostream>
using namespace std;
const int BUF = 10;

int row, col;
string b[BUF];

void read(){
  cin >> row >> col;
  for(int i=0;i<row;i++)
    cin >> b[i];
}

bool isInside(int r, int c){
  return 0<=r && r<row && 0<=c && c<col;
}

void work(){
  string toGo = "IEHOVA#";
  int dr[]={-1,0,0}, dc[]={0,1,-1};

  int curR, curC;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]=='@')
        curR = i, curC = j;
  
  string move[3]={"forth","right","left"};
  for(int i=0;i<toGo.size();i++)
    for(int j=0;j<3;j++){
      int nr = curR+dr[j], nc = curC+dc[j];
      if(isInside(nr,nc) && b[nr][nc]==toGo[i]){
        if(i) cout << ' ';
        cout << move[j];
        curR = nr, curC = nc;
        break;
      }
    }
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
