#include<iostream>
#include<vector>
#include<cstdio>
#define square(x) ((x)*(x))
#define BUF 205
using namespace std;

int n;
double lb, rb, lowb, upb;
double x[BUF], y[BUF], r[BUF], _r[BUF];

void read(){
  cin >> n;
  
  for(int i=0;i<n;i++)
    cin >> x[i] >> y[i] >> _r[i];
}

void dfs(int u, bool visited[BUF], bool adj[BUF][BUF], 
         bool &left, bool &right, bool &low, bool &up){
  if(x[u]-r[u]<=  lb) left = true;
  if(x[u]+r[u]>=  rb) right = true;
  if(y[u]-r[u]<=lowb) low = true;
  if(y[u]+r[u]>= upb) up = true;
  
  visited[u] = true;
  
  for(int v=0;v<n;v++){
    if(!adj[u][v] || visited[v]) continue;
    dfs(v,visited,adj,left,right,low,up);
  }
}

bool canGo(double rad){
  for(int i=0;i<n;i++)
    r[i] = _r[i]+rad; 

  lb = lowb = rad;
  rb = upb = 1000-rad;
  
  bool adj[BUF][BUF];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      adj[i][j] = square(x[i]-x[j])+square(y[i]-y[j])<=square(r[i]+r[j]);

  bool visited[BUF];
  for(int i=0;i<n;i++) visited[i] = false;
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    bool left = false, right = false, low = false, up = false;
    dfs(i,visited,adj,left,right,low,up);
    
    if(left+right+low+up>=2) return false;
  }
  
  return true;
}

void work(){
  double L = 0, R = 500;

  while(R-L>1.0e-4){
    double mid = (L+R)/2;
    
    if(canGo(mid))
      L = mid;
    else
      R = mid;
  }

  printf("%.3lf\n",L);
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
