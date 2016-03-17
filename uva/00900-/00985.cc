#include<iostream>
#include<queue>
using namespace std;
const int BUF = 505;
enum Dir{UP=0,RIGHT=1,DOWN=2,LEFT=3};

class Data{
public:
  int turn, r, c;
  Data(){}
  Data(int turn, int r, int c): turn(turn), r(r), c(c){}
};

int row, col, b[BUF][BUF];

bool read(){
  if(!(cin >> row >> col)) return false;

  string ch2id="NESW";
  for(int i=0;i<row*col-1;i++){
    string s;
    cin >> s;
    int mask = 0;
    for(int j=0;j<s.size();j++)
      mask |= (1<<ch2id.find(s[j]));
    b[i/col][i%col] = mask;
  }

  return true;
}


void work(){
  static int dr[]={-1,0,1,0}, dc[]={0,1,0,-1};
  queue<Data> Q;
  static int cost[4][BUF][BUF];
  memset(cost,-1,sizeof(cost));
  
  Q.push(Data(0,0,0));
  cost[0][0][0] = 0;
  
  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();
    if(cur.r==row-1 && cur.c==col-1){
      cout << cost[cur.turn][cur.r][cur.c] << endl;
      return;
    }
    for(int i=0;i<4;i++){
      if(!(b[cur.r][cur.c]&(1<<((i+4-cur.turn)%4)))) continue;
      Data nex = Data((cur.turn+1)%4,cur.r+dr[i],cur.c+dc[i]);
      if(!(0<=nex.r && nex.r<row && 0<=nex.c && nex.c<col)) continue;
      if(cost[nex.turn][nex.r][nex.c]!=-1) continue;
      Q.push(nex);
      cost[nex.turn][nex.r][nex.c] = cost[cur.turn][cur.r][cur.c]+1;
    }
  }
  cout << "no path to exit" << endl;
}


int main(){
  while(read()) work();
  return 0;
}
