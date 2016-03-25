#include<iostream>
#include<vector>
#include<algorithm>
#define ROW 45
#define COL 10
#define BUF ((1<<COL)+5)
#define INF (1<<20)
using namespace std;

int row, col;
bool cover[ROW][COL];

void read(){
  cin >> row >> col;

  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
      char ch;
      cin >> ch;
      cover[i][j] = (ch=='*');
    }
}

void generate(int idx, int nPut, int pre, int cur, vector< pair<int,int> > &next){
  if(idx==col){
    next.push_back(make_pair(cur,nPut));
    return;
  }

  if(pre&(1<<idx))
    generate(idx+1,nPut+1,pre,cur&~(1<<idx),next);
  else if(cur&(1<<idx)){
    generate(idx+1,nPut,pre,cur,next);

    generate(idx+1,nPut+1,pre,cur&~(1<<idx)&~(1<<(idx+1)),next);
  }
  else
    generate(idx+1,nPut,pre,cur,next);
}

void work(){
  int dp[ROW][BUF];

  for(int i=0;i<=row;i++)
    for(int j=0;j<BUF;j++)
      dp[i][j] = INF;
  dp[0][0] = 0;

  for(int r=0;r<row;r++)
    for(int pre=0;pre<BUF;pre++){
      if(dp[r][pre]==INF) continue;
      
      int cur = 0;
      for(int c=0;c<col;c++)
        if(cover[r][c])
          cur |= (1<<c);

      vector<pair<int,int> > next;
      generate(0,0,pre,cur,next);
      
      for(int i=0;i<next.size();i++){
        int nPut = dp[r][pre]+next[i].second;
        dp[r+1][next[i].first] = min(dp[r+1][next[i].first],nPut);
      }
    }
  
  cout << dp[row][0] << endl;
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
