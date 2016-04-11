// 0.916 secs

#include<iostream>
#include<cstdio>
#define NODE 50005
using namespace std;

class Group{
public:
  int nGroup, g[NODE];
  
  Group(){}
  
  void build(int n){
    nGroup = n;
    for(int i=0;i<n;i++)
      g[i] = i;
  }
  
  int find(int n){
    return (n==g[n] ? n : g[n]=find(g[n]));
  }
  
  void merge(int a, int b){
    if(find(a)!=find(b)){
      g[find(a)] = find(b);
      nGroup--;
    }
  }
};

bool work(int cases){
  int nNode, nOpe;
  cin >> nNode >> nOpe;
  if(nNode==0 && nOpe==0) return false;
  
  Group group;
  group.build(nNode);
  
  for(int i=0;i<nOpe;i++){
    int s, t;
    scanf("%d%d",&s,&t);
    
    group.merge(s,t);
  }
  
  cout << "Case " << cases << ": " << group.nGroup << endl;
  
  return true;
}

int main(){
  for(int i=0;work(i+1);i++){}

  return 0;
}
