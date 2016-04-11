#include<iostream>
#include<vector>
#include<cctype>
#include<cstring>
#include<cstdio>
#define BUF 10000
#define MAX_LENGTH 101000
#define MAX_NODE (2*MAX_LENGTH)
#define HASH_TABLE 220009
using namespace std;

class Edge{
public:
  int src, dst, bgn, end;

  Edge(){}
  Edge(int s, int d, int b, int e):
    src(s), dst(d), bgn(b), end(e){}
};


int M, N;
char need[MAX_LENGTH], str[MAX_LENGTH], backup[MAX_LENGTH];

class Hash{
public:
  Edge buf[HASH_TABLE];

  int getId(Edge e){
    return ((e.src<<8)+str[e.bgn])%HASH_TABLE;
  }
  
  void remove(Edge e){
    int cur = getId(e);
    while(buf[cur].src!=e.src || buf[cur].bgn!=e.bgn) 
      cur = ++cur%HASH_TABLE;

    while(true){
      buf[cur].src = -1;
      int pre = cur;
      while(true){
	cur = ++cur%HASH_TABLE;
	if(buf[cur].src==-1) return;
	
	int r = getId(buf[cur]);
	if(!(pre<r && r<=cur) && !(cur<pre && pre<r) && !(r<=cur && cur<pre))
	  break;
      }
      buf[pre] = buf[cur];
    }
  }

  void insert(Edge e){
    int cur = getId(e);
    
    while(buf[cur].src!=-1) cur = ++cur%HASH_TABLE;

    buf[cur] = e;
  }

  Edge find(int src, int ch){
    int cur = ((src<<8)+ch)%HASH_TABLE;
    
    while(true){
      if(buf[cur].src==-1) return buf[cur];
      if(buf[cur].src==src && str[buf[cur].bgn]==ch) return buf[cur];
      
      cur = ++cur%HASH_TABLE;
    }
  }
};

class Suffix{
public:
  int node;
  int bgn, end;

  Suffix(){}
  Suffix(int n, int b, int e):
    node(n), bgn(b), end(e){}
  
  void canonize(Hash &h){
    if(isExplicit()) return;
    
    Edge edge = h.find(node,str[bgn]);
    int span = edge.end-edge.bgn;

    while(span<=end-bgn){
      bgn = bgn+span+1;
      node = edge.dst;
      if(bgn<=end){
	edge = h.find(edge.dst,str[bgn]);
	span = edge.end-edge.bgn;
      }
    }
  }

  bool isExplicit(){
    return bgn>end;
  }
};

class STree{
public:
  int nNode, link[MAX_NODE];
  Hash h;
  
  void build(){
    nNode = 1;
    for(int i=0;i<HASH_TABLE;i++) h.buf[i].src = -1;
    for(int i=0;i<N*2;i++) link[i] = -1;

    N = strlen(str);
    str[N++] = '\0';
  
    Suffix active = Suffix(0,0,-1);

    for(int i=0;i<N;i++)
      update(active,i); 
  }

  Edge find(int node, int ch){
    return h.find(node,ch);
  }
  
private:
  void update(Suffix &active, int chIdx){
    int parent, lastParent = -1;

    while(true){
      Edge edge;
      parent = active.node;
      
      if(active.isExplicit()){
	edge = h.find(active.node,str[chIdx]);
	if(edge.src!=-1) break;
      }
      else{
	edge = h.find(active.node,str[active.bgn]);
	int span = active.end-active.bgn;
	if(str[edge.bgn+span+1]==str[chIdx]) break;
	
	// split
	h.remove(edge);
	h.insert(Edge(active.node,nNode,edge.bgn,edge.bgn+active.end-active.bgn));
	link[nNode] = active.node;
	parent = nNode;

	edge.bgn += active.end-active.bgn+1;
	edge.src = nNode++;
	h.insert(edge);
      }

      h.insert(Edge(parent,nNode++,chIdx,N));
      if(lastParent>0) link[lastParent] = parent;
      lastParent = parent;

      if(active.node==0)
	active.bgn++;
      else
	active.node = link[active.node];
      active.canonize(h);
    }
    
    if(lastParent>0) link[lastParent] = parent;
    active.end++;
    active.canonize(h);
  }
};

void read(){
  gets(need);
  M = strlen(need);
  N = 0;
  
  char buf[MAX_LENGTH];
  while(gets(buf)!=NULL){
    int t = strlen(buf);
    for(int i=0;i<t;i++){
      str[N] = tolower(buf[i]);
      backup[N] = buf[i];
      N++;
    }
    backup[N] = str[N] = '\n';
    N++;
  }
  backup[N] = str[N] = '\0';
}

void work(){
  static STree stree;
  stree.build();
  
  vector<pair<int,int> > ans;   // length, endPt
  for(int cur=0;cur<M;){
    if(need[cur]==' '){ cur++; continue; }
    
    int bgn = cur, end, node = 0;
    while(true){
      Edge e = stree.find(node,need[cur]);
      if(e.src==-1){
	ans.push_back(make_pair(cur-bgn,end));
	break;
      }

      int i;
      for(i=e.bgn;i<=e.end && need[cur]==str[i] && cur<M;i++,cur++);

      if(i>e.end){
	end = e.end;
	node = e.dst;
      }
      else {
	ans.push_back(make_pair(cur-bgn,i-1));
	break;
      }
    }
  }
  
  
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++){
    while(str[ans[i].second]==' '){ ans[i].second--; ans[i].first--; }
    for(int j=ans[i].second-ans[i].first+1;j<=ans[i].second;j++)
      cout << backup[j];
    cout << endl;
  }
}

int main(){
  read();
  work();
  
  return 0;
}
