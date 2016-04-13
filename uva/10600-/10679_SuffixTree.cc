#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX_LENGTH 100010
#define MAX_NODE (2*MAX_LENGTH)
#define HASH_TABLE 220009
#define QUERY 1005
#define Q_LENGTH 1005
using namespace std;

class Edge{
public:
  int src, dst, bgn, end;

  Edge(){}
  Edge(int s, int d, int b, int e):
    src(s), dst(d), bgn(b), end(e){}
};

int length, nQuery;
char str[MAX_LENGTH], query[QUERY][Q_LENGTH];

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
    for(int i=0;i<length*2;i++) link[i] = -1;

    length = strlen(str);
    str[length++] = '\0';
  
    Suffix active = Suffix(0,0,-1);

    for(int i=0;i<length;i++)
      update(active,i); 
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

      h.insert(Edge(parent,nNode++,chIdx,length));
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
  scanf("%s",str);

  cin >> nQuery;
  for(int i=0;i<nQuery;i++)
    scanf("%s",query[i]);
}


void work(){
  static STree stree;
  stree.build();

  for(int k=0;k<nQuery;k++){
    int qLen = strlen(query[k]), curNode = 0, curIdx = 0;

    while(curIdx<qLen){
      Edge e = stree.h.find(curNode,query[k][curIdx]);
      if(e.src==-1) break;
      int i = 0;
      for(i=e.bgn;i<=e.end && curIdx<qLen && query[k][curIdx]==str[i];
	  i++,curIdx++);
      
      if(i<=e.end) break;
      curNode = e.dst;
    }

    if(curIdx==qLen) 
      printf("y\n");
    else
      printf("n\n");
  }
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
