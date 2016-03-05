#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<cstdio>
#define BUF 20005
#define MAX_NODE (2*BUF)
using namespace std;

int preN, length;
char pre[BUF], str[BUF];

class Edge{
public:
  int src, dst, bgn, end;

  Edge(){}
  Edge(int s, int d, int b, int e):
    src(s), dst(d), bgn(b), end(e){}
};

class Suffix{
public:
  int node;
  int bgn, end;

  Suffix(){}
  Suffix(int n, int b, int e):
    node(n), bgn(b), end(e){}
  
  void canonize(Edge adj[MAX_NODE][27]){
    if(isExplicit()) return;
    
    Edge edge = adj[node][str[bgn]-'a'];
    int span = edge.end-edge.bgn;

    while(span<=end-bgn){
      bgn = bgn+span+1;
      node = edge.dst;
      if(bgn<=end){
	edge = adj[edge.dst][str[bgn]-'a'];
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
  int nDel, todel[MAX_NODE*3][2];
  Edge adj[MAX_NODE][27];
  
  void build(){
    nDel = 0;
    nNode = 1;

    length = strlen(str);
    str[length++] = 'z'+1;
  
    Suffix active = Suffix(0,0,-1);

    for(int i=0;i<length;i++)
      update(active,i); 
  }
  
  void clean(){
    for(int i=0;i<nDel;i++) adj[todel[i][0]][todel[i][1]].src = -1;
    for(int i=0;i<nNode;i++) link[i] = -1;
  }
  
private:
  void update(Suffix &active, int chIdx){
    int parent, lastParent = -1;

    while(true){
      Edge edge;
      parent = active.node;
      
      if(active.isExplicit()){
	edge = adj[active.node][str[chIdx]-'a'];
	if(edge.src!=-1) break;
      }
      else{
	edge = adj[active.node][str[active.bgn]-'a'];
	int span = active.end-active.bgn;
	if(str[edge.bgn+span+1]==str[chIdx]) break;
	
	// split
	adj[edge.src][str[edge.bgn]-'a'].src = -1;
	adj[active.node][str[edge.bgn]-'a'] = Edge(active.node,nNode,edge.bgn,edge.bgn+active.end-active.bgn);
	todel[nDel  ][0] = active.node;
	todel[nDel++][1] = str[edge.bgn]-'a';

	link[nNode] = active.node;
	parent = nNode;

	edge.bgn += active.end-active.bgn+1;
	edge.src = nNode++;
	adj[edge.src][str[edge.bgn]-'a'] = edge;
	todel[nDel  ][0] = edge.src;
	todel[nDel++][1] = str[edge.bgn]-'a';
      }

      adj[parent][str[chIdx]-'a'] = Edge(parent,nNode++,chIdx,length);
      todel[nDel  ][0] = parent;
      todel[nDel++][1] = str[chIdx]-'a';
      if(lastParent>0) link[lastParent] = parent;
      lastParent = parent;

      if(active.node==0)
	active.bgn++;
      else
	active.node = link[active.node];
      active.canonize(adj);
    }
    
    if(lastParent>0) link[lastParent] = parent;
    active.end++;
    active.canonize(adj);
  }
};

void read(){
  scanf("%s",pre);
  preN = strlen(pre);
}

STree stree;

void work(){
  for(int i=0;i<preN;i++)
    str[i] = str[i+preN] = pre[i];
  str[preN*2] = '\0';
  
  stree.build();
  
  int curr = 0, leng = 0;
  
  while(true){
    for(int i='a';i<='z';i++){
      Edge &e = stree.adj[curr][i-'a'];
      if(e.src==-1) continue;

      if(leng+e.end-e.bgn+1<preN){
	leng += e.end-e.bgn+1;
	curr = e.dst;
	break;
      }
      else {
	int need = preN-leng;
	cout << e.bgn+need-preN+1 << endl;
	return;
      }
    }
  }
}

int main(){
  for(int i=0;i<MAX_NODE;i++) for(int j=0;j<27;j++) stree.adj[i][j].src = -1;
  for(int i=0;i<MAX_NODE;i++) stree.link[i] = -1;
  
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
    stree.clean();
  }

  return 0;
}
