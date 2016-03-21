#include<iostream>
#include<cstdio>
#define NODE 10005
#define SF 1
#define SE 2
#define AF 3
#define AE 4
using namespace std;

class Point{
public:
  int idx;
  bool belong;
  
  Point(){}
  Point(int idx, bool belong): idx(idx), belong(belong){}
};

class Group{
public:
  Point g[NODE];
  
  Group(){}
  
  void build(int n){
    for(int i=0;i<n;i++)
      g[i] = Point(i,true);
  }
  
  int find(int n){
    return (n==g[n].idx ? n : g[n].idx=find(g[n].idx));
  }
  
  void merge(int a, int b){
    g[find(a)].idx = find(b);
  }
  
  void change(int n, int id){
    for(int i=0;i<n;i++)
      if(find(i)==id)
	g[i].belong = !g[i].belong;
  }
};

bool work(){
  int nNode;
  if(!(cin >> nNode)) return false;
  
  Group group;
  group.build(nNode);
  
  while(true){
    int ope, s, t;
    scanf("%d%d%d",&ope,&s,&t);
    if((ope|s|t)==0) break;
    
    switch(ope){
    case SF:
      if(group.find(s)==group.find(t) && group.g[s].belong!=group.g[t].belong)
	printf("-1\n");
      else{
	if(group.find(s)!=group.find(t) && group.g[s].belong!=group.g[t].belong)
	  group.change(nNode,group.find(s));
	group.merge(s,t);
      }
      break;
    case SE:
      if(group.find(s)==group.find(t) && group.g[s].belong==group.g[t].belong)
	printf("-1\n");
      else {
	if(group.find(s)!=group.find(t) && group.g[s].belong==group.g[t].belong)
	  group.change(nNode,group.find(s));
	group.merge(s,t);
      }
      break;
    case AF:
      printf("%d\n",(group.find(s)==group.find(t) && group.g[s].belong==group.g[t].belong));
      break;
    case AE:
      printf("%d\n",(group.find(s)==group.find(t) && group.g[s].belong!=group.g[t].belong));
      break;
    }
  }
  
  return true;
}

int main(){
  while(work());

  return 0;
}
