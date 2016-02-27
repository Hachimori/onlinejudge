#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include<cstdlib>
#include<algorithm>

#define MAX_SIZE 305
#define MAX_QUERY 105

using namespace std;

class Person{
public:

  int parent;
  vector<int> child;

  Person(){ parent=-1; }
};

int nQuery, nNode;
map<string,int> nToId;
pair<string,string> query[MAX_QUERY];
Person person[MAX_SIZE];

void read(){
  nNode = 0;
  
  while(true){
    string child, parent;
    cin >> child >> parent;

    if(child=="no.child") break;
    
    int childId, parentId;
    if(!nToId.count(child)){
      nToId[child] = nNode++;
      person[nNode-1] = Person();
    }

    if(!nToId.count(parent)){
      nToId[parent] = nNode++;
      person[nNode-1] = Person();
    }

    childId = nToId[child];
    parentId = nToId[parent];

    person[parentId].child.push_back(childId);
    person[childId].parent = parentId;
  }
  
  nQuery = 0;

  while(true){
    if(!(cin >> query[nQuery].first >> query[nQuery].second)) break;

    if(!nToId.count(query[nQuery].first)){
      nToId[query[nQuery].first] = nNode++;
      person[nNode-1] = Person();
    }

    if(!nToId.count(query[nQuery].second)){
      nToId[query[nQuery].second] = nNode++;
      person[nNode-1] = Person();
    }

    nQuery++;
  }
  
}

int searchParent(int curr, int goal, int depth){
  if(curr==-1) return -1;
  if(curr==goal) return depth;  
  
  return searchParent(person[curr].parent,goal,depth+1);
}

pair<int,int> searchRemove(int p1, int p2){
  int visited[MAX_SIZE];
  for(int i=0;i<nNode;i++)
    visited[i] = -1;

  int nVisited1 = 0, curr = p1;
  while(curr!=-1){
    visited[curr] = nVisited1++;
    curr = person[curr].parent;
  }

  int nVisited2 = 0;
  curr = p2;
  while(curr!=-1){
    if(visited[curr]!=-1) return make_pair(min(visited[curr],nVisited2)-1,
					   abs(visited[curr]-nVisited2));
    nVisited2++;
    curr = person[curr].parent;
  }
  
  return make_pair(-1,-1);
}

void work(){
  /*
  for(int i=0;i<nNode;i++){
    cout << i << ":  " << endl;
    cout << "   parent: " << person[i].parent << endl;
    for(int j=0;j<person[i].child.size();j++){
      cout << "    " << person[i].child[j] << endl;
    }cout << endl;
  }

  for(int i=0;i<nQuery;i++)
    cout << query[i].first << ' ' << query[i].second << endl;
  cout << endl;
  */

  for(int i=0;i<nQuery;i++){
    int p1 = nToId[query[i].first], p2 = nToId[query[i].second];
    
    if(person[p1].parent!=-1 && person[p1].parent==person[p2].parent){
      cout << "sibling" << endl;
      continue;
    }
    
    if(person[p1].parent==p2){
      cout << "child" << endl;
      continue;
    }

    if(person[p2].parent==p1){
      cout << "parent" << endl;
      continue;
    }

    int ret = searchParent(p1,p2,0);
    if(ret!=-1){
      for(int j=2;j<ret;j++){
	if(j!=2) cout << ' ';
	cout << "great";
      }
      
      if(ret==2) cout << "grand child" << endl;
      else cout << " grand child" << endl;
      continue;
    }

    ret = searchParent(p2,p1,0);
    if(ret!=-1){
      for(int j=2;j<ret;j++){
	if(j!=2) cout << ' ';
	cout << "great";
      }
      
      if(ret==2) cout << "grand parent" << endl;
      else cout << " grand parent" << endl;
      continue;
    }
    
    pair<int,int> result = searchRemove(p1,p2);
    if(result.first!=-1){
      cout << result.first << " cousin";
      if(result.second!=0) cout << " removed " << result.second << endl;
      else cout << endl;
      continue;
    }
    
    cout << "no relation" << endl;
  }
}

int main(){
  read();
  work();
  
  return 0;
}
