#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cassert>
#define NODE 100005
using namespace std;
typedef pair<int,int> Range;


bool isInside(Range &r, int n){
  return r.first<=n && n<=r.second;
}

int nNode, src, dst;
vector<Range> adj[NODE];

void read(){
  int nRange;
  scanf("%d%d",&nNode,&nRange);

  for(int i=0;i<nNode;i++)
    adj[i].clear();
  
  for(int i=0;i<nRange;i++){
    int s;
    Range r;
    scanf("%d%d-%d",&s,&r.first,&r.second);
    if(r.first>r.second) swap(r.first,r.second);
    adj[s].push_back(r);
  }
  
  scanf("%d%d",&src,&dst);
  
  for(int i=0;i<nNode;i++){
    sort(adj[i].begin(),adj[i].end());
    vector<Range> toPush;
    int maxV = -1;
    for(int j=0;j<adj[i].size();j++){
      int cur = j+1;
      if(adj[i][j].second<=maxV) continue;
      while(cur<adj[i].size()){
	if(isInside(adj[i][cur],adj[i][j].second)) adj[i][j].second = adj[i][cur].second;
	else break;
	cur++;
      }
      toPush.push_back(adj[i][j]);
      maxV = adj[i][j].second;
      j = cur-1;
    }
    adj[i] = toPush;
  }
  
  for(int i=0;i<nNode;i++){
    if(adj[i].size()==0)
      adj[i] = vector<Range>(1,Range(0,nNode-1));
    else{
      vector<Range> toPush;
      
      if(0<=adj[i][0].first-1) toPush.push_back(Range(0,adj[i][0].first-1));
      for(int j=0;j+1<adj[i].size();j++){
	int bgn, end;
	bgn = adj[i][j  ].second+1;
	end = adj[i][j+1].first-1;
	if(bgn>end) continue;
	toPush.push_back(Range(bgn,end));
      }
      if(adj[i].back().second+1<=nNode-1) toPush.push_back(Range(adj[i].back().second+1,nNode-1));
      
      adj[i] = toPush;
    }
  }
  
  /*
  for(int i=0;i<nNode;i++){
    for(int j=0;j<adj[i].size();j++)
      cout << adj[i][j].first << ',' << adj[i][j].second << "  ";
    cout << endl;
  }
  */
  
  /*
  for(int i=0;i<nNode;i++)
    for(int j=0;j<adj[i].size();j++)
      for(int k=j+1;k<adj[i].size();k++)
	if(max(adj[i][j].first,adj[i][k].first)<=
	   min(adj[i][j].second,adj[i][k].second))
	  assert(false);
  */
}

int bfs(){
  static int visited[NODE];
  vector<Range> avail;
  queue<int> Q;
  
  Q.push(src);
  fill(visited,visited+nNode,-1);
  avail.push_back(Range(src,src));
  
  visited[src] = 0;
  
  while(!Q.empty() && visited[dst]==-1){
    int cur = Q.front();
    Q.pop();
    
    if(adj[cur].size()==0) continue;

    vector<Range> next;
    avail.insert(avail.end(),adj[cur].begin(),adj[cur].end());
    sort(avail.begin(),avail.end());
    
    for(int i=0;i<avail.size();i++){
      int idx = i+1;
      int maxV = avail[i].second;
      
      for(int j=avail[i].first;j<=avail[i].second;j++)
	if(visited[j]==-1){
	  visited[j] = visited[cur]+1;
	  Q.push(j);
	}
      
      while(idx<avail.size()){
	if(isInside(avail[idx],avail[i].second)){ 
	  for(int j=maxV;j<=avail[idx].second;j++)
	    if(visited[j]==-1){
	      visited[j] = visited[cur]+1;
	      Q.push(j);
	    }
	  avail[i].second = avail[idx].second;
	  maxV = avail[i].second;
	}
	else break;
	idx++;
      }
	
      next.push_back(avail[i]);
      i = idx-1;
    }
    
    avail = next;
  }

  return visited[dst];
}

void work(int cases){
  int ret = bfs();
  
  cout << "Case #" << cases << ": ";
  if(ret==-1) cout << "Impossible" << endl;
  else cout << ret << endl;
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
