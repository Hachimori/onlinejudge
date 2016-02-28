#include<iostream>
#include<vector>
#include<string>

#define MAX_SIZE 10000
#define MAX_CHAR 256
#define MAX_NODE 30

using namespace std;

int nStr;
string strList[MAX_SIZE];

bool read(){

  nStr=0;

  while(true){
    
    if(!(cin >> strList[nStr])) return false;
    
    if(strList[nStr]=="#") break;
    nStr++;
  }

  return true;
}

void createAdj(int &nNode, int cToNode[MAX_CHAR], char nodeToChar[MAX_NODE], bool adjList[MAX_NODE][MAX_NODE]){
  
  for(int j=0;j<strList[0].size();j++)
    if(cToNode[strList[0][j]]==-1){
      cToNode[strList[0][j]] = nNode;
      nodeToChar[nNode] = strList[0][j];
      nNode++;
    }  
  
  for(int i=1;i<nStr;i++){
    
    for(int j=0;j<strList[i].size();j++)
      if(cToNode[strList[i][j]]==-1){
	cToNode[strList[i][j]] = nNode;
	nodeToChar[nNode] = strList[i][j];
	nNode++;
      }
    
    for(int j=0;j<strList[i-1].size() && j<strList[i].size();j++){
      if(strList[i-1][j]!=strList[i][j]){
	
	adjList[cToNode[strList[i-1][j]]][cToNode[strList[i][j]]] = true;
	break;
      }
    }
    
  }
  
} 

void topSort(int curr, int nNode, bool adjList[MAX_NODE][MAX_NODE], bool visited[MAX_NODE], vector<int> &nodeList){
  
  visited[curr]=true;

  for(int i=0;i<nNode;i++){
    if(!adjList[curr][i]) continue;
    if(visited[i]) continue;
    
    topSort(i,nNode,adjList,visited,nodeList);
  }
  
  nodeList.push_back(curr);

}

void work(){
  
  int nNode=0;
  int cToNode[MAX_CHAR];
  char nodeToChar[MAX_NODE];
  bool adjList[MAX_NODE][MAX_NODE];
  
  for(int i=0;i<MAX_CHAR;i++)
    cToNode[i] = -1;
  
  for(int i=0;i<MAX_NODE;i++)
    for(int j=0;j<MAX_NODE;j++)
      adjList[i][j] = false;

  createAdj(nNode,cToNode,nodeToChar,adjList);
  

  bool visited[MAX_NODE];
  for(int i=0;i<MAX_NODE;i++)
    visited[i] = false;

  vector<int> nodeList;

  for(int i=0;i<nNode;i++){
    if(!visited[i])
      topSort(i,nNode,adjList,visited,nodeList);
  }
  
  for(int i=(int)(nodeList.size())-1;i>=0;i--){
    cout << nodeToChar[nodeList[i]];
  }cout << endl;
  
}

int main(){
  
  while(read())
    work();

  return 0;
}
