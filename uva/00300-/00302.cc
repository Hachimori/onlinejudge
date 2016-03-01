#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<climits>
#include<stack>
#include<queue>

#define MAX_ROUTE 2000
#define MAX_SIZE 50

using namespace std;

int nStreet;
pair<int,int> initJunc;
vector< pair<int,int> > adjList[MAX_SIZE];   // target, street number

bool read(){
  
  nStreet=0;
  for(int i=0;i<MAX_SIZE;i++)
      adjList[i].clear();
  
  bool isFirst=true;
  int start,end,id;
  
  while(true){
    
    cin >> start >> end;
    if(isFirst && start==0 && end==0) return false;
    else if(start==0 && end==0) break;
    
    cin >> id;
    
    if(isFirst){
      initJunc.first = start;
      initJunc.second = end;
    }
      
    adjList[start].push_back( make_pair(end,id) );
    adjList[end].push_back( make_pair(start,id) );
    nStreet++;
    
    isFirst=false;
  }
  
  return true;
}

bool isAllavail(int curr){
  
  queue<int> Q;
  bool visited[MAX_ROUTE];
  int nVisited=0;
  
  for(int i=0;i<MAX_ROUTE;i++)
    visited[i] = false;
  
  Q.push(curr);

  
  while(!Q.empty()){
    
    int next = Q.front();
    Q.pop();
    
    for(vector<pair<int,int> >::iterator i=adjList[next].begin();
	i!=adjList[next].end();i++){
      
      int nextNode=i->first;
      int nextEdge=i->second;
      
      if(visited[nextEdge]) continue;
      visited[nextEdge] = true;
      nVisited++;
      
      Q.push(nextNode);
    }
    
  }
  
  return nStreet==nVisited;
}

void findEuler(int curr, int &cursor, int route[MAX_ROUTE], bool used[MAX_ROUTE], stack< pair<int,int> > &S){

  for(vector<pair<int,int> >::iterator i=adjList[curr].begin();
      i!=adjList[curr].end();i++){
    
    int nextStreet = i->second;
    int nextJunc = i->first;
    
    if(used[nextStreet]) continue;
    
    used[nextStreet] = true;
    S.push( make_pair(curr,nextStreet) );
    
    findEuler(nextJunc,cursor,route,used,S);
    
    return;
  }
  
  if(S.size()==0) return;
  pair<int,int> nextStreet = S.top();
  S.pop();
  
  route[cursor] = nextStreet.second;
  cursor++;
  
  findEuler(nextStreet.first,cursor,route,used,S);
}

bool myGreater(const pair<int,int> &a, const pair<int,int> &b){
  return a.second<b.second;
}

void work(){
  
  for(int i=0;i<MAX_SIZE;i++)
    sort(adjList[i].begin(),adjList[i].end(),myGreater);
  
  for(int i=0;i<MAX_SIZE;i++)
    if(adjList[i].size()%2==1){
      cout << "Round trip does not exist." << endl;
      return;
    }
  
  int toStart = min(initJunc.first,initJunc.second);
  
  int route[MAX_ROUTE], cursor=0;
  bool used[MAX_ROUTE];
  stack< pair<int,int> > S;
  
  for(int i=0;i<MAX_ROUTE;i++)
    used[i] = false;

  if(toStart==-1){
    toStart = initJunc.first;
  }
  findEuler(toStart,cursor,route,used,S);
 
  for(int i=nStreet-1;i>=0;i--){
    if(i==nStreet-1)
      cout << route[i];
    else
      cout << ' ' << route[i];
  }cout << endl;

}

int main(){
  
  while(read()){
    work();
    cout << endl;
  }

  return 0;
}
