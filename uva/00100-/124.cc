#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define MAX_NODE 21

using namespace std;

char node[MAX_NODE];
int nNode, charVal[200];
vector< vector<int> > greaterList;
vector<string> ansList;

bool read(){
  
  string str;
  if(getline(cin,str)==NULL) return false;

  nNode=0;
  for(int cursor=0;cursor<str.length();nNode++){
    
    while(cursor<str.length() && str[cursor]==' ') cursor++;
    
    if(cursor<str.length()) node[nNode] = str[cursor];
    charVal[node[nNode]] = nNode;
    cursor++;
    
  }
  

  greaterList.assign(nNode,vector<int>());
  
  
  getline(cin,str);
  for(int cursor=0;cursor<str.length();){
    
    char smaller, bigger;

    while(cursor<str.length() && str[cursor]==' ') cursor++;
    if(cursor<str.length()) smaller = str[cursor];
    cursor++;

    while(cursor<str.length() && str[cursor]==' ') cursor++;
    if(cursor<str.length()) bigger = str[cursor];
    cursor++;
    
    
    greaterList[charVal[bigger]].push_back(charVal[smaller]);
  }


  return true;
}

bool validMove(int curr, int next, bool visited[MAX_NODE]){

  for(int i=0;i<greaterList[next].size();i++)
    if(!(greaterList[next][i]==curr || visited[greaterList[next][i]]) )
       return false;
  
  return true;
}

void dfs(int curr, int nVisited, bool visited[MAX_NODE], char pi[MAX_NODE]){
  
  if(nVisited+1==nNode){

    string ans;

    for(int i=0;i<nNode-1;i++)
      ans+=pi[i];
    ans+=node[curr];
    
    ansList.push_back(ans);

    return;
  }

  

  for(int i=0;i<nNode;i++){

    if(curr==i || visited[i]) continue;
    if(!validMove(curr,i,visited)) continue;
    

    visited[curr] = true;
    pi[nVisited] = node[curr];

    dfs(i,nVisited+1,visited,pi);
    visited[curr] = false;
  }

}

void work(){
  
  char pi[MAX_NODE];
  bool visited[MAX_NODE];

  ansList.clear();
  for(int i=0;i<nNode;i++)
    visited[i] = false;
  
  for(int i=0;i<nNode;i++){
    if(!validMove(-1,i,visited)) continue;
    dfs(i,0,visited,pi);
  }

  
  sort(ansList.begin(),ansList.end());

  for(int i=0;i<ansList.size();i++)
    cout << ansList[i] << endl;
  

}

int main(){
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
