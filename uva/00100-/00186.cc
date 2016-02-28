#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

#define INF 100000000
#define MAX_SIZE 500
#define MAX_QUERY 10000

using namespace std;

map<string,int> n2i;
map<int,string> i2n;

int nNode, adjList[MAX_SIZE][MAX_SIZE];
string edge[MAX_SIZE][MAX_SIZE];

int nQuery, query[MAX_QUERY][2];

void split(string &buf, vector<string> &sList){
  int curr = 0;
  
  while(curr<buf.size()){
    string toPush;
    while(buf[curr]!=',' && curr<buf.size()) toPush += buf[curr++];
    
    sList.push_back(toPush);
    curr++;
  }
}

void read(){
  string buf;

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      adjList[i][j] = INF;

  for(int i=0;i<MAX_SIZE;i++)  
    adjList[i][i] = 0;
    
  while(true){
    if(getline(cin,buf)==NULL) break;
    if(buf.size()<=1) break;

    int src,dst,cost;
    vector<string> sList;
    split(buf,sList);

    if(!n2i.count(sList[0])){
      int size = n2i.size();
      n2i[sList[0]] = size;
      i2n[size] = sList[0];
    }

    if(!n2i.count(sList[1])){
      int size = n2i.size();
      n2i[sList[1]] = size;
      i2n[size] = sList[1];
    }
    
    src = n2i[sList[0]];
    dst = n2i[sList[1]];
    cost = atoi(sList[3].c_str());
    
    if(adjList[src][dst]>cost){
      adjList[src][dst] = cost;
      adjList[dst][src] = cost;
      edge[src][dst] = sList[2];
      edge[dst][src] = sList[2];
    }
  }
  
  nQuery = 0;
  while(true){
    if(getline(cin,buf)==NULL) break;
    if(buf.empty()) break;
    
    int src, dst;
    vector<string> sList;
    split(buf,sList);
    
    if(!n2i.count(sList[0])){
      int size = n2i.size();
      n2i[sList[0]] = size;
      i2n[size] = sList[0];
    }

    if(!n2i.count(sList[1])){
      int size = n2i.size();
      n2i[sList[1]] = size;
      i2n[size] = sList[1];
    }
    
    src = n2i[sList[0]];
    dst = n2i[sList[1]];

    query[nQuery][0] = src;
    query[nQuery++][1] = dst;
  }
}

void dijkstra(int start, int goal){
  int nVisit = 0;
  bool visited[MAX_SIZE];
  int pi[MAX_SIZE], cost[MAX_SIZE];
  
  for(int i=0;i<nNode;i++){
    pi[i] = -1;
    cost[i] = INF;
    visited[i] = false;
  }

  cost[start] = 0;

  while(nVisit<nNode){
    int minPos = -1, minV = INF;
    
    for(int i=0;i<nNode;i++)
      if(minV>cost[i] && !visited[i]){
	minV = cost[i];
	minPos = i;
      }
    
    // グラフは非連結である。
    if(minPos==-1) break;
    
    visited[minPos] = true;
    nVisit++;
    
    for(int i=0;i<nNode;i++){
      if(cost[i]>cost[minPos]+adjList[minPos][i]){
	cost[i] = cost[minPos]+adjList[minPos][i];
	pi[i] = minPos;
      }
    }
  }

  cout << "From                 To                   Route      Miles" << endl;
  cout << "-------------------- -------------------- ---------- -----" << endl;
  
  int curr = goal, sum = 0;
  vector<int> path;
  while(curr!=-1){ 
    path.push_back(curr);
    curr = pi[curr];
  }

  reverse(path.begin(),path.end());

  for(int i=0;i<path.size()-1;i++){
    int src = path[i], dst = path[i+1];
    
    printf("%-20s %-20s %-10s %5d\n",
	   i2n[src].c_str(),i2n[dst].c_str(),edge[src][dst].c_str(),adjList[src][dst]);

    sum += adjList[src][dst];
  }
  
  cout << "                                                     -----" << endl;
  printf("                                          Total      %5d\n",sum);

}

void work(){
  nNode = n2i.size();
  
  for(int i=0;i<nQuery;i++){
    cout << endl << endl;
    dijkstra(query[i][0],query[i][1]);
  }
}

int main(){
  read();
  work();
  
  return 0;
}
