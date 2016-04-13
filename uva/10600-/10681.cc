#include<iostream>
#include<queue>
#include<utility>
#define CITY 105
#define DAY 205
#define pos first
#define day second
using namespace std;
typedef pair<int,int> Data;

int nCity, init, goal, day;
bool adj[CITY][CITY];

bool read(){
  int nEdge;
  cin >> nCity >> nEdge;
  if(nCity==0 && nEdge==0) return false;

  for(int i=0;i<nCity;i++)
    for(int j=0;j<nCity;j++)
      adj[i][j] = false;
  
  for(int i=0;i<nEdge;i++){
    int s, t;
    cin >> s >> t; 
    s--, t--;

    adj[s][t] = adj[t][s] = true;
  }
  
  cin >> init >> goal >> day; 
  init--, goal--;
  
  return true;
}

bool bfs(){
  bool visited[CITY][DAY];
  queue<Data> Q;
  
  for(int i=0;i<nCity;i++)
    for(int j=0;j<=day;j++)
      visited[i][j] = false;
  Q.push(Data(init,0));
  
  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();

    if(curr.pos==goal && curr.day==day) return true;
    if(curr.day==day) continue;

    for(int i=0;i<nCity;i++){
      if(!adj[curr.pos][i] || visited[i][curr.day+1]) continue;
      
      visited[i][curr.day+1] = true;
      Q.push(Data(i,curr.day+1));
    }
  }

  return false;
}

void work(){
  if(bfs())
    cout << "Yes, Teobaldo can travel." << endl;
  else
    cout << "No, Teobaldo can not travel." << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
