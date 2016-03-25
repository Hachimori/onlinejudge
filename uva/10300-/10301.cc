#include<iostream>
#include<algorithm>
#include<map>
#define NODE 105
#define EPS (1.0e-8)
#define LT(x,y) ((x)<=(y)-EPS)
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

class Circle{
public:
  double x, y, r;
};

int nNode;
Circle circle[NODE];

bool read(){
  cin >> nNode;
  if(nNode==-1) return false;
  
  for(int i=0;i<nNode;i++)
    cin >> circle[i].x >> circle[i].y >> circle[i].r;
  
  return true;
}

bool isIntersect(Circle &c1, Circle &c2){
  double d = sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));

  if(LT(c1.r+c2.r,d) || LT(c1.r+d,c2.r) || LT(c2.r+d,c1.r))
    return false;  
  else
    return true;
}

void work(){
  Group group;
  group.build(nNode);

  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      if(isIntersect(circle[i],circle[j]))
	group.merge(i,j);

  int maxV = 0;
  map<int,int> nMember;
  for(int i=0;i<nNode;i++){
    if(nMember.count(group.find(i)))
      nMember[group.find(i)]++;
    else
      nMember[group.find(i)] = 1;
    
    maxV = max(maxV,nMember[group.find(i)]);
  }
  
  if(maxV==1)
    cout << "The largest component contains " << maxV << " ring." << endl;
  else
    cout << "The largest component contains " << maxV << " rings." << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
