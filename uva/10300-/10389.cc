#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#define INF (1<<30)
#define NODE 1000
using namespace std;

class Node{
public:
  double x, y;
  int rail;

  Node(){}
  Node(double x, double y, int r): x(x), y(y), rail(r){}
};

int nNode;
Node node[NODE];

void read(){
  for(int i=0;i<2;i++){
    int x, y; cin >> x >> y;
    node[i] = Node(x,y,-i-1);
  }
  nNode = 2;
  
  string dummy; getline(cin,dummy);
  
  int nRail = 0;
  while(true){
    string s; getline(cin,s);
    if(s.empty()) break;
    
    stringstream in(s);
    while(true){
      int x, y; 
      if(!(in >> x >> y)) goto finish;
      if(x==-1 && y==-1) break;
      node[nNode++] = Node(x,y,nRail);
    }
    nRail++;
  }
 finish:;
}

void work(){
  static double adj[NODE][NODE];

  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      Node &a = node[i], &b = node[j];
      adj[i][j] = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/1000.0;
      
      adj[i][j] /= (a.rail==b.rail && abs(i-j)==1 ? 40 : 10);
    }
  
  
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        if(adj[i][j]>adj[i][k]+adj[k][j])
          adj[i][j] = adj[i][k]+adj[k][j];
  
  cout << (int)(adj[0][1]*60+0.5) << endl;
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
