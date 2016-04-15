#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
const int ELEVATOR = 10, WAITCOST = 60, FLOOR = 105, INF = 1<<30;

int goal, nElevator, elevCost[ELEVATOR];
vector<int> elev2floor[ELEVATOR];

bool read(){
  for(int i=0;i<ELEVATOR;i++) elev2floor[i].clear();
  if(!(cin >> nElevator >> goal)) return false;
  for(int i=0;i<nElevator;i++) cin >> elevCost[i];
  string dummy; getline(cin,dummy);
  for(int i=0;i<nElevator;i++){
    string s; 
    getline(cin,s);
    stringstream in(s);
    int v;
    while(in>>v) elev2floor[i].push_back(v);
  }
  return true;
}

void work(){
  int cost[FLOOR];
  bool visited[FLOOR];
  for(int i=0;i<FLOOR;i++){
    cost[i] = INF;
    visited[i] = false;
  }
  cost[0] = 0;
  
  for(int k=0;k<FLOOR;k++){
    int minPos, minV = INF;
    for(int i=0;i<FLOOR;i++)
      if(minV>cost[i] && !visited[i]){
        minV = cost[i];
        minPos = i;
      }
    if(minV==INF) break;
    visited[minPos] = true;
    for(int i=0;i<nElevator;i++)
      if(count(elev2floor[i].begin(),elev2floor[i].end(),minPos))
        for(int j=0;j<elev2floor[i].size();j++)
          cost[elev2floor[i][j]] = min(cost[elev2floor[i][j]],cost[minPos]+WAITCOST+abs(minPos-elev2floor[i][j])*elevCost[i]);
  }

  if(goal==0)
    cout << 0 << endl;
  else if(!visited[goal])
    cout << "IMPOSSIBLE" << endl;
  else
    cout << cost[goal]-WAITCOST << endl;
}

int main(){
  while(read()) work();
  return 0;
}
