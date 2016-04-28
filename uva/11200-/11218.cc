#include<iostream>
#include<algorithm>
#define COMB 2000
using namespace std;


int val[9][9][9];

bool read(){
  int nVal;
  cin >> nVal;
  if(nVal==0) return false;
  
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      for(int k=0;k<9;k++)
        val[i][j][k] = -1;
  
  for(int i=0;i<nVal;i++){
    int g[3], s;
    cin >> g[0] >> g[1] >> g[2] >> s;
    g[0]--, g[1]--, g[2]--;
    sort(g,g+3);
    
    if(0<=g[0] && g[0]<=8 && 0<=g[1] && g[1]<=8 && 0<=g[2] && g[2]<=8)
      val[g[0]][g[1]][g[2]] = max(val[g[0]][g[1]][g[2]],s);
  }

  return true;
}

void rec(int curr, bool visited[], int sum, int &ans){
  if(curr==3){
    ans = max(ans,sum);
    return;
  }
  
  for(int i=0;i<9;i++)
    if(!visited[i])
      for(int j=0;j<9;j++)
        if(!visited[j])
          for(int k=0;k<9;k++)
            if(!visited[k] && val[i][j][k]>0){
              visited[i] = visited[j] = visited[k] = true;
              rec(curr+1,visited,sum+val[i][j][k],ans);
              visited[i] = visited[j] = visited[k] = false;
            }
}

void work(int cases){
  bool visited[9];
  int ans = -1;
  
  for(int i=0;i<9;i++) visited[i] = false;
  
  rec(0,visited,0,ans);
  
  cout << "Case " << cases << ": " << ans << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
