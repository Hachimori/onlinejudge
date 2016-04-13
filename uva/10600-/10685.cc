#include<iostream>
#include<map>
#include<string>
#define NODE 5005
#define QUERY 5005
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

int nNode, nQuery, query[QUERY][2];
map<string,int> n2i;

bool read(){
  cin >> nNode >> nQuery;
  if(nNode==0 && nQuery==0) return false;
  
  n2i.clear();

  for(int i=0;i<nNode;i++){
    string name;
    cin >> name;
    int size = n2i.size();
    n2i[name] = size;
  }
  
  for(int i=0;i<nQuery;i++){
    string s, t;
    cin >> s >> t;
    query[i][0] = n2i[s];
    query[i][1] = n2i[t];
  }
  
  return true;
}

Group group;

void work(){
  group.build(nNode);
  
  for(int i=0;i<nQuery;i++)
    group.merge(query[i][0],query[i][1]);
  
  int maxVal = 0;
  map<int,int> nMember;
  for(int i=0;i<nNode;i++){
    if(!nMember.count(group.find(i)))
      nMember[group.find(i)] = 1;
    else
      nMember[group.find(i)]++;

    maxVal = max(maxVal,nMember[group.find(i)]);
  }

  cout << maxVal << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
