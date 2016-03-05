// 2.035

#include<iostream>
#include<cstdio>
#include<string>
#define NODE 50000
using namespace std;

class Group{
public:
  int g[NODE];
  
  Group(){}
  
  void build(int n){
    for(int i=0;i<n;i++)
      g[i] = i;
  }
  
  int find(int n){
    return (n==g[n] ? n : g[n]=find(g[n]));
  }
  
  void merge(int a, int b){
    g[find(a)] = find(b);
  }
};

Group group;

void work(){
  int nNode;
  cin >> nNode;
  
  string dummy;
  getline(cin,dummy);
  
  group.build(nNode);
  int cntOk = 0, cntNo = 0;
  
  while(true){
    string str;
    if(getline(cin,str)==NULL) break;

    int s, t;
    char ch;

    if(sscanf(str.c_str(),"%c%d%d",&ch,&s,&t)!=3) break;
    s--, t--;
    
    if(ch=='c')
      group.merge(s,t);
    else
      (group.find(s)==group.find(t) ? cntOk : cntNo)++;
  }
  
  cout << cntOk << ',' << cntNo << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    work();
  }

  return 0;
}
