#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

#define MAX_SIZE 105

using namespace std;

int nNode;
map<string,int> nameToInt;
map<int,string> intToName;
bool adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  
  cin >> nNode;
  if(nNode==0) return false;


  nameToInt.clear();
  intToName.clear();
  for(int i=0;i<nNode;i++)
    fill(adjList[i],adjList[i]+nNode,false);
  

  for(int i=0;i<nNode;i++){
    string str;
    cin >> str;

    nameToInt[str] = intToName.size();
    intToName[nameToInt.size()-1] = str;
  }

  
  int nEdge;
  cin >> nEdge;
  
  for(int i=0;i<nEdge;i++){
    string source, target;
    cin >> source >> target;
    
    adjList[nameToInt[source]][nameToInt[target]]=true;
    adjList[nameToInt[target]][nameToInt[source]]=true;
  }

  return true;
}

void artic(int curr, int &nVisited, int discover[MAX_SIZE], int back[MAX_SIZE], bool isArtic[MAX_SIZE], bool visited[MAX_SIZE], int prev, int nEdge[MAX_SIZE]){

  discover[curr] = nVisited;
  back[curr] = discover[curr];
  visited[curr] = true;
  nVisited++;

 
  for(int i=0;i<nNode;i++){
        
    if(prev==i) continue;
    if(!adjList[curr][i]) continue;
    
    
    if(!visited[i]){
      nEdge[curr]++;
      artic(i,nVisited,discover,back,isArtic,visited,curr,nEdge);
      
      back[curr] = min(back[curr],back[i]);
      
      if(back[i]>=discover[curr])
	isArtic[curr]=true;
    }
    else if(visited[i])
      back[curr] = min(back[curr],discover[i]);
    
  }
  
  nVisited++;
}

void work(int cases){

  int discover[MAX_SIZE], back[MAX_SIZE], nEdge[MAX_SIZE];
  bool visited[MAX_SIZE], isArtic[MAX_SIZE];
  
  fill(nEdge,nEdge+nNode,0);
  fill(visited,visited+nNode,false);
  fill(isArtic,isArtic+nNode,false);
  
  int nVisited=0;

  for(int i=0;i<nNode;i++){    
    if(!visited[i]){
      artic(i,nVisited,discover,back,isArtic,visited,-1,nEdge);
      if(nEdge[i]<=1) isArtic[i]=false;
    }
  }
  
  int ans=0;
  for(int i=0;i<nNode;i++)
    if(isArtic[i]) 
      ans++;

  cout << "City map #" << cases << ": " << ans << " camera(s) found" << endl;

  vector<string> sList;
  for(int i=0;i<nNode;i++)
    if(isArtic[i])
      sList.push_back(intToName[i]);
    
  sort(sList.begin(),sList.end());

  
  for(int i=0;i<sList.size();i++)
    cout << sList[i] << endl;
  
}

int main(){

  for(int cases=1;read();cases++){

    if(cases!=1) cout << endl;

    work(cases);
  }

  return 0;
}
