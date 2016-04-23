#include<iostream>
#include<numeric>
#include<algorithm>

#define INF 100000000
#define SIZE 155

using namespace std;

int nNode;
int cost[SIZE][SIZE];

void read(){
  int nEdge;
  
  cin >> nNode >> nEdge;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cost[i][j] = 0;
  
  for(int i=0;i<nEdge;i++){
    int src, dst, c;
    cin >> src >> dst >> c;
    
    src--, dst--;
    
    cost[src][dst] += c;
    cost[dst][src] += c;
  }
}

int minCut(){
  int belong[SIZE], minV = INF;

  for(int i=0;i<nNode;i++)
    belong[i] = i;

  while(nNode>1){
    bool merged[SIZE];
    int weight[SIZE];
    
    for(int i=0;i<nNode;i++){
      merged[belong[i]] = false;
      weight[i] = cost[belong[0]][belong[i]];
    }
    merged[belong[0]] = true;

    int prev = belong[0];
    for(int i=0;i<nNode-1;i++){
      int curr = -1;
      
      for(int j=0;j<nNode;j++)
	if(!merged[belong[j]] && (curr<0 || weight[j]>weight[curr]))
	  curr = j;

      merged[belong[curr]] = true;
      
      if(i==nNode-2){
	minV = min(minV,weight[curr]);
	
	for(int j=0;j<nNode;j++)
	  cost[belong[j]][prev] = cost[prev][belong[j]] += cost[belong[curr]][belong[j]];
	
	belong[curr] = belong[--nNode];
	break;
      }

      for(int j=0;j<nNode;j++)
	if(!merged[belong[j]])
	  weight[j] += cost[belong[curr]][belong[j]];
      
      prev = belong[curr];
    }
  }

  return minV;
}

void work(int cases){
  cout << "Case #" << cases << ": " << minCut() << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}