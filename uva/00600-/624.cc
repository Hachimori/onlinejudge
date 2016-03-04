// 0-1 knapsack
// 624

#include<iostream>
#include<vector>
#include<algorithm>

#define INF 10000000
#define MAX_SIZE 25
#define MAX_BUF 10000

using namespace std;

int nBurden, capacity, burden[MAX_SIZE];

bool read(){
  if(!(cin >> capacity >> nBurden)) return false;

  for(int i=0;i<nBurden;i++)
    cin >> burden[i];

  return true;
}

void knapsack(int pi[][MAX_BUF], bool table[][MAX_BUF]){
  for(int i=0;i<=nBurden;i++)
    for(int j=0;j<MAX_BUF;j++){
      table[i][j] = false;
      pi[i][j] = j;
    }
  pi[0][0] = 0;
  table[0][0] = true;
  
  for(int curr=0;curr<nBurden;curr++)
    for(int i=0;i<=capacity;i++){
      if(!table[curr][i]) continue;
      
      int nextW = i+burden[curr];
      
      table[curr+1][i] = true;
      pi[curr+1][i] = i;

      if(nextW<=capacity){
	table[curr+1][nextW] = true;
	pi[curr+1][nextW] = i;
      }
    }
}

void work(){
  int pi[MAX_SIZE][MAX_BUF];
  bool table[MAX_SIZE][MAX_BUF];
  
  knapsack(pi,table);
  
  int maxVal;
  for(int j=0;j<=capacity;j++)
    if(table[nBurden][j])
      maxVal = j;
  
  
  vector<int> path;
  int curr = maxVal;
  
  for(int i=nBurden;i>=1;i--){
    if(pi[i][curr]==curr) continue;
    path.push_back(i-1);
    curr = pi[i][curr];
  }
  
  for(int i=0;i<path.size();i++)
    cout << burden[path[i]] << ' ';
  cout << "sum:" << maxVal << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
