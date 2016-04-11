#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<cassert>

#define MAX_PATH 50
#define MAX_SIZE 1500


using namespace std;


void split(string &str, vector<string> &sList){
  
  int cursor=0;
  
  while(cursor<str.size()){
    
    while(cursor<str.size() && str[cursor]==' ')
      cursor++;

    string toPush;
    while(cursor<str.size() && str[cursor]!=' '){
      toPush+=str[cursor];
      cursor++;
    }
    
    if(toPush.size()>0)
      sList.push_back(toPush);
  }
  
}

vector< map<int,int> > adjList;    // target, capacity
string residentList[MAX_SIZE];
vector<int> resident2Club[MAX_SIZE];
int source, sink, residentIdx, clubIdx, nParty, nClub, nResident;
map<string,int> party2Int, club2Int;

void read(){

  vector<int> pt2Resident[MAX_SIZE];
  
  nResident=nParty=nClub=0;
  
  adjList.clear();
  party2Int.clear(), club2Int.clear();
  
  for(int i=0;i<MAX_SIZE;i++)
    resident2Club[i].clear();
  
  string str;
  
  while(getline(cin,str) && !str.empty()){
    
    vector<string> sList;
    
    split(str,sList);
    
    residentList[nResident] = sList[0];
    nResident++;

    int residentId = nResident-1;
    
    if(party2Int.find(sList[1])==party2Int.end()){
      party2Int[sList[1]] = nParty;
      nParty++;
    }

    int partyId = party2Int[sList[1]];

    
    pt2Resident[partyId].push_back(residentId);
    
    
    for(int i=2;i<sList.size();i++){
      
      if(club2Int.find(sList[i])==club2Int.end()){
	club2Int[sList[i]] = nClub;
	nClub++;
      }

      int clubId = club2Int[sList[i]];

      resident2Club[residentId].push_back(clubId);
      
    }
    
  }
  
  residentIdx = nParty;
  clubIdx = nParty+nResident;
 
   
  adjList.assign(nParty+nResident+nClub+3,map<int,int>());
  
  source = nParty+nResident+nClub;
  sink = nParty+nResident+nClub+1;
  
  
  for(int i=0;i<party2Int.size();i++)
    for(int j=0;j<pt2Resident[i].size();j++){
      adjList[i][pt2Resident[i][j]+residentIdx] = 1;
      
    }
  
  for(int i=0;i<nResident;i++)
    for(int j=0;j<resident2Club[i].size();j++){
      adjList[i+residentIdx][resident2Club[i][j]+clubIdx] = 1;
      
    }
  
  
  
  for(int i=0;i<club2Int.size();i++)
    adjList[i+clubIdx][sink] = 1;
 
  for(int i=0;i<party2Int.size();i++)
    adjList[source][i] = ((int)club2Int.size()-1)/2;
  
}

bool isMaxFlow(vector<int> &path){
    
  queue<int> Q;
  bool visited[MAX_SIZE];
  int pi[MAX_SIZE];
  
  fill(pi,pi+sink+1,-1);
  fill(visited,visited+sink+1,false);
  
  Q.push(source);
  
  
  while(!Q.empty()){

    int curr = Q.front();
    Q.pop();
    
    visited[curr]=true;
        
    if(curr==sink) break;
    
    
    for(map<int,int>::iterator i=adjList[curr].begin();i!=adjList[curr].end();i++){
      
      if(!visited[i->first] && i->second>0){
	pi[i->first] = curr;
	Q.push(i->first);
      }
    }
    
  }
  
  for(int i=sink;i!=-1;i=pi[i])
    path.push_back(i);

  reverse(path.begin(),path.end());
  
  return !visited[sink];
    
}

void work(){
  
  int nMatch=0;
  int prev[MAX_SIZE];

  if(nClub>nResident){
    cout << "Impossible." << endl;
    return;
  }

  for(int i=0;i<sink+1;i++)
    prev[i] = -1;
  
  while(true){
    
    vector<int> path;

    if(isMaxFlow(path)) break;
    
    int toFlow=INT_MAX;
    
    for(int i=1;i<path.size();i++)
      toFlow = min(toFlow,adjList[path[i-1]][path[i]]);
      
      
    for(int i=1;i<path.size();i++){
      adjList[path[i-1]][path[i]]-=toFlow;
      adjList[path[i]][path[i-1]]+=toFlow;
      prev[path[i]] = path[i-1];
    }
    
    nMatch++;
  }
  
  
    
  if(nMatch!=nClub) cout << "Impossible." << endl;
  else {
    for(int i=0;i<nClub;i++)
      if(prev[i+clubIdx]!=-1){
	cout << residentList[prev[i+clubIdx]-residentIdx] << ' ';

	for(map<string,int>::iterator j=club2Int.begin();j!=club2Int.end();j++){
	  if(j->second==i){
	    cout << j->first << endl;
	    break;
	  }
	}
	  
	
      }
	
      
  }
  
}

int main(){
  
  int cases;
  cin >> cases;
  
  string dummy; getline(cin,dummy);  getline(cin,dummy);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}




