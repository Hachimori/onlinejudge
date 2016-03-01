#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<utility>
#include<vector>

#define MAX_SIZE 500

using namespace std;

int nNode;
map<string,int> nameToInt;
map<int,string> intToName;
bool adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  
  int nEdge;
  cin >> nEdge;
  if(nEdge==0) return false;
  

  nNode=0;
  nameToInt.clear();
  intToName.clear();

  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      adjList[i][j] = false;


  for(int i=0;i<nEdge;i++){
    int nConnect;
    cin >> nConnect;
    
    string source;
    cin >> source;
    
    if(nameToInt.find(source)==nameToInt.end()){
      nameToInt[source] = nNode;
      intToName[nNode] = source;
      nNode++;
    }

    for(int j=0;j<nConnect-1;j++){
      string target;
      cin >> target;

      if(nameToInt.find(target)==nameToInt.end()){
	nameToInt[target] = nNode;
	intToName[nNode] = target;
	nNode++;
      }

      adjList[nameToInt[source]][nameToInt[target]] = true;
      source = target;
      
    }

  }

  return true;
}

void floyd(){
  
  for(int i=0;i<nNode;i++){
    
    bool next[MAX_SIZE][MAX_SIZE];

    for(int j=0;j<nNode;j++){
      for(int k=0;k<nNode;k++){
	if(adjList[j][k] || (adjList[j][i] && adjList[i][k]) )
	  next[j][k]=true;
	else
	  next[j][k]=false;
      }
    }
    
    for(int j=0;j<nNode;j++)
      for(int k=0;k<nNode;k++)
	adjList[j][k] = next[j][k];
  }
  
}

void work(int cases){

  int nQuery;
  cin >> nQuery;

  for(int i=0;i<nQuery;i++){
    string source, target;
    cin >> source >> target;

    adjList[nameToInt[source]][nameToInt[target]] = true;    
  }

  floyd();
  
  vector< pair<int,int> > ansList;
  
  for(int i=0;i<nNode;i++)
    for(int j=i+1;j<nNode;j++)
      if(!adjList[i][j] && !adjList[j][i])
	ansList.push_back( make_pair(i,j) );      

  cout << "Case " << cases << ", "; 
  
  if(ansList.size()==0) 
    cout << "no concurrent events." << endl;
  else {
    cout << ansList.size() << " concurrent events:" << endl;
    
    for(int i=0;i<min(2,(int)(ansList.size()));i++){
      if(i!=0) cout << ' ';
      cout << "(" << intToName[ansList[i].first] << "," << intToName[ansList[i].second] << ")";
    }
    cout << endl;
  }

}

int main(){

  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
