#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#define MAX 1000

int chk;

class Graph{
  
 public:

  vector<vector<int> > adjList;
  vector<vector<int>::iterator> pos;
  vector<int> visited;
  int adjArray[MAX][MAX];


  Graph(){};

  Graph(int n){
    adjList.resize(n);
    pos.resize(n);
    visited.resize(n);

    for(int i=0;i<n;i++) visited[i]=false;
  }
  
  void insert(int source , int target){
    adjList[source].push_back(target);
  }

  int next(int u){
    if(pos[u]!=adjList[u].end()) return *pos[u]++;
    else return -1;
  }

  void reset(){
    for(int i=0;i<adjList.size();i++) pos[i]=adjList[i].begin();
  }



};

void Input_Output(void);
int eof=0,n_node;
char c[3];

void dfs_rec(Graph &g,int u){
  
  g.visited[u]=true;

  while(1){   
    int tmp = g.next(u); 
    if(tmp==-1) break;
    else if(g.visited[tmp]==false)  dfs_rec(g,tmp); 
  }

}
 
int dfs(Graph g){

  int count=0;
  g.reset();

  for(int i=0;i<n_node;i++){
    if(g.visited[i]==false){
      dfs_rec(g,i);
      count++;
    }
  }

  return count;

} 



main()
{
  int t;
  string line;

  getline(cin,line);
  t = atoi(line.c_str());

  getline(cin,line);

  for(int i=0;i<t;i++){
    if(i!=0) cout << endl;
    Input_Output();
  }

}

void Input_Output(void){

  int num_letter;
  Graph g;
  string str;

  getline(cin,str);

  
  n_node = (int)(str[0]-'A'+1);
  
  g = Graph(n_node);

  while(1){

    getline(cin,str);
    
    if(str.size()==0) break;
    if(cin.eof()) break;
          
    int source=(int)(str[0]-'A');
    int target=(int)(str[1]-'A');

    g.insert(source,target);
    g.insert(target,source);

  }


  cout << dfs(g) << endl;

  return;
}
