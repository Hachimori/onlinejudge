#include<iostream>
#include<queue>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Point;
const int BUF = 1000;

int main(){
  int n;
  while(cin >> n){
    static int b[BUF][BUF];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        char ch;
        cin >> ch;
        b[i][j] = ch-'0';
      }

    queue<Point> Q;
    static int visited[BUF][BUF];

    memset(visited,-1,sizeof(visited));
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(b[i][j]==3){
          Q.push(Point(i,j));
          visited[i][j] = 0;
        }
    
    while(!Q.empty()){
      Point cur = Q.front();
      Q.pop();
      static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int nr = cur.r+dr[i], nc = cur.c+dc[i];
        if(!(0<=nr && nr<n && 0<=nc && nc<n)) continue;
        if(visited[nr][nc]==-1){
          visited[nr][nc] = visited[cur.r][cur.c]+1;
          Q.push(Point(nr,nc));
        }
      }
    }

    int ans = 0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(b[i][j]==1)
          ans = max(ans,visited[i][j]);
    cout << ans << endl;
  }
  return 0;
}
