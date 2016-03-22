#include<iostream>
#include<algorithm>

#define INF 10000000
#define MAX_SIZE 1005
#define MAX_BUF 35

using namespace std;

class Burden{
public:

  int v, w;

  Burden(){}
  Burden(int v, int w): v(v), w(w) {}

};

int nBurden;
Burden burden[MAX_SIZE];

void read(){
  cin >> nBurden;

  for(int i=0;i<nBurden;i++)
    cin >> burden[i].v >> burden[i].w;
}

void knapsack(int table[][MAX_BUF]){
  for(int i=0;i<=nBurden;i++)
    for(int j=0;j<MAX_BUF;j++)
      table[i][j] = -INF;
  table[0][0] = 0;
  
  for(int curr=0;curr<nBurden;curr++)
    for(int i=0;i<MAX_BUF;i++){
      if(table[curr][i]==-INF) continue;
      
      int nextV = table[curr][i]+burden[curr].v;
      int nextW = i+burden[curr].w;
	    
      table[curr+1][i] = max(table[curr+1][i],table[curr][i]);
      if(nextW<MAX_BUF)
	table[curr+1][nextW] = max(table[curr+1][nextW],nextV);
    }
}

void work(){
  int nQuery, table[MAX_SIZE][MAX_BUF];
  
  knapsack(table);
  
  int sum=0;
  cin >> nQuery;
  
  for(int i=0;i<nQuery;i++){
    int capacity;
    cin >> capacity;

    int maxAvail=-INF;
    for(int j=0;j<=capacity;j++)
      maxAvail = max(maxAvail,table[nBurden][j]);
    
    sum += maxAvail;
  }
  
  cout << sum << endl;
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
