#include<iostream>
#include<algorithm>
#include<vector>

#define SIZE 55
#define INF 100000000

using namespace std;

int yS, mS;
int adjList[2][SIZE][SIZE];  // 0: young  1: middle

bool read(){
  for(int k=0;k<2;k++)
    for(int i=0;i<SIZE;i++)
      for(int j=0;j<SIZE;j++)
	adjList[k][i][j] = INF;
  
  int nEdge;
  cin >> nEdge;
  if(nEdge==0) return false;
  
  for(int i=0;i<nEdge;i++){
    int age, src, dst, cost;
    char a, edge, s, d;
    
    cin >> a >> edge >> s >> d >> cost;
    
    age = a=='M' ? 1:0 ;
    src = s-'A';
    dst = d-'A';
    
    if(edge=='B')
      adjList[age][src][dst] = adjList[age][dst][src] = cost;
    else
      adjList[age][src][dst] = cost;
  }
  
  char y, m;
  cin >> y >> m;

  yS = y-'A';
  mS = m-'A';
  
  return true;
}

void warshall(){
  int cost[2][SIZE][SIZE];
  
  for(int i=0;i<2;i++)
    for(int j=0;j<SIZE;j++)
      for(int k=0;k<SIZE;k++)
	cost[i][j][k] = adjList[i][j][k];

  for(int i=0;i<2;i++)
    for(int j=0;j<SIZE;j++)
      cost[i][j][j] = 0;
  
  for(int l=0;l<2;l++)
    for(int k=0;k<SIZE;k++)
      for(int i=0;i<SIZE;i++)
	for(int j=0;j<SIZE;j++)
	  cost[l][i][j] = min(cost[l][i][j],cost[l][i][k]+cost[l][k][j]);

  
  int minV = INF;
  vector<char> minList;
  for(int i=0;i<SIZE;i++)
    if(minV>cost[0][yS][i]+cost[1][mS][i]){
      minV = cost[0][yS][i]+cost[1][mS][i];
      minList.clear();
      minList.push_back(i+'A');
    }
    else if(minV==cost[0][yS][i]+cost[1][mS][i])
      minList.push_back(i+'A');

  if(minV==INF)
    cout << "You will never meet." << endl;
  else{
    cout << minV;
    for(int i=0;i<minList.size();i++)
      cout << ' ' << minList[i];
    cout << endl;
  }
}

void work(){
  warshall();
}

int main(){
  while(read())
    work();
  
  return 0;
}
