#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define NODE 105
#define INF (1<<30)
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (EQ(x,y) || LT(x,y))
using namespace std;

int nNode;
double adj[NODE][NODE];

void read(){
  cin >> nNode;
  
  double pos[NODE][2];
  for(int i=0;i<nNode;i++)
    cin >> pos[i][0] >> pos[i][1];

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adj[i][j] = INF;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      double dist = sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+
			 (pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
      if(LE(dist,10)) adj[i][j] = dist;
    }
}

double warshall(){
  double cost[NODE][NODE];
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cost[i][j] = adj[i][j];

  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
  
  double ret = 0;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      ret = max(ret,cost[i][j]);
  
  return ret;
}

void work(int cases){
  double ans = warshall();
  
  cout << "Case #" << cases << ":" << endl;
  if(EQ(ans,INF)) cout << "Send Kurdy" << endl;
  else printf("%.4lf\n",ans);
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
