#include<iostream>
#include<algorithm>
#define STONE 205
#define WEIGHT 1001
#define PICK 21
#define BUF (WEIGHT*PICK)
#define QUERY 105
#define INF (1<<30)
using namespace std;

class Data{
public:
  int nPick, gram;

  Data(){}
  Data(int n, int g): nPick(n), gram(g){}
};

class Stone{
public:
  int val, gram;
};

class Query{
public:
  int nPick, L, R;
};

int nStone, nQuery;
Stone stone[STONE];
Query query[QUERY];

void read(){
  cin >> nStone;
  
  for(int i=0;i<nStone;i++)
    cin >> stone[i].gram >> stone[i].val;

  cin >> nQuery;
  for(int i=0;i<nQuery;i++)
    cin >> query[i].nPick >> query[i].L >> query[i].R;
}

void calc(int dp[2][PICK][BUF]){
  static Data Q[2][BUF*PICK];
  int head[2] = {0,0}, tail[2] = {0,0};

  for(int i=0;i<2;i++)
    for(int j=0;j<PICK;j++)
      for(int k=0;k<BUF;k++)
	dp[i][j][k] = INF;
  dp[0][0][0] = 0;
  Q[0][tail[0]++] = Data(0,0);
  
  for(int i=0;i<nStone;i++){
    int curr = i%2, next = (i+1)%2;

    for(int j=0;j<PICK;j++)
      for(int k=0;k<BUF;k++)
	dp[next][j][k] = dp[curr][j][k];
	
    while(head[0]!=tail[0]){
      Data d = Q[0][head[0]++];
      
      int nexPick = d.nPick + 1;
      int nexGram = d.gram + stone[i].gram;
      int nexVal = dp[curr][d.nPick][d.gram]+stone[i].val;
      
      if(nexPick>=PICK || nexGram>=BUF) continue;
      if(dp[next][nexPick][nexGram]==INF)
	Q[1][tail[1]++] = Data(nexPick,nexGram);

      dp[next][nexPick][nexGram] <?= nexVal;
    }

    head[0] = 0;
    for(int j=0;j<tail[1];j++)
      Q[0][tail[0]++] = Q[1][j];
    tail[1] = 0;
  }
}

void work(){
  static int dp[2][PICK][BUF];
  calc(dp);

  for(int i=0;i<nQuery;i++){
    int ans = INF;
    for(int j=query[i].nPick*query[i].L;j<=query[i].nPick*query[i].R;j++)
      ans <?= dp[nStone%2][query[i].nPick][j];

    if(ans==INF) 
      cout << "impossible" << endl;
    else 
      cout << ans << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
