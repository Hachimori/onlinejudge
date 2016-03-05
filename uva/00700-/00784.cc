#include<iostream>
#include<queue>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Point;
const int BUF = 35;

int nRow;
Point init;
string b[BUF];

void read(){
  for(nRow=0;;nRow++){
    getline(cin,b[nRow]);
    if(b[nRow].find('*')!=string::npos)
      init = Point(nRow,b[nRow].find('*'));
    if(b[nRow][0]=='_') break;
  }
}

void work(){
  int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  queue<Point> Q;
  b[init.r][init.c] = '#';
  Q.push(init);
  while(!Q.empty()){
    Point cur = Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      Point nex = Point(cur.r+dr[i],cur.c+dc[i]);
      if(b[nex.r][nex.c]==' '){
        b[nex.r][nex.c] = '#';
        Q.push(nex);
      }
    }
  }
  for(int i=0;i<=nRow;i++)
    cout << b[i] << endl;
}

int main(){
  int cases;
  cin >> cases;
  string dummy;
  getline(cin,dummy);
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
