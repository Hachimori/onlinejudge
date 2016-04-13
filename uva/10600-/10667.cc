#include<iostream>
#include<stack>
#define pos first
#define height second
using namespace std;
const int BUF = 105;
typedef pair<int,int> Data;

int sz;
bool wall[BUF][BUF];

void read(){
  memset(wall,0,sizeof(wall));
  cin >> sz;
  int nWall;
  cin >> nWall;
  for(int i=0;i<nWall;i++){
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int r=r1-1;r<=r2-1;r++)
      for(int c=c1-1;c<=c2-1;c++)
        wall[r][c] = true;
  }
}

void work(){
  int val[BUF][BUF];
  for(int r=0;r<sz;r++){
    for(int c=0;c<sz;c++)
      if(wall[r][c])
        val[r][c] = 0;
      else
        val[r][c] = (r==0 ? 0 : val[r-1][c])+1;

    val[r][sz] = -1;
  }

  int maxV = 0;
  for(int r=0;r<sz;r++){
    stack<Data> S; // (pos,height)
    S.push(Data(-1,-1));
    for(int c=0;c<=sz;c++){
      if(S.top().height>=val[r][c]){
        while(1){
          Data t = S.top();
          S.pop();
          maxV = max(maxV,t.height*(c-t.pos));
          if(S.empty() || S.top().height<val[r][c]){
            S.push(Data(t.pos,val[r][c]));
            break;
          }
        }
      }
      else
        S.push(Data(c,val[r][c]));
    }
  }

  cout << maxV << endl;
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
