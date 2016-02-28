#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<cassert>
#include<cstdio>
#include<queue>
#include<map>

#define MAX_SIZE 1000

using namespace std;

class Station{
public:

  char line, c;

  Station(){}
  Station(char line, char c): line(line), c(c) {}

  bool operator< ( const Station &s ) const {
    if(line<s.line) return true;
    else if(line==s.line) return c<s.c;
    
    return false;
  }

};

class Element{
public:

  int cost;
  vector<int> path;

  Element(){}
  Element(int c, vector<int> p): cost(c), path(p) {}
  
  bool operator<(const Element &e) const {
    return cost>e.cost;
  }
  
};

int nLine, nStation=0;
map< Station, int > station2int;
map< int, Station > int2station;
vector<int> adjList[MAX_SIZE];

void read(){
  
  cin >> nLine;

  string str;
  getline(cin,str);


  for(int i=0;i<nLine;i++){
    getline(cin,str);
    
    char line = str[0];
    int prev;

    assert(str[2]!='=');

    for(int cursor=2;cursor<str.size();cursor++){
      
      if(str[cursor]!='='){
      
	if(station2int.find(Station(line,str[cursor]))==station2int.end()){
	  station2int[Station(line,str[cursor])] = nStation;
	  int2station[nStation] = Station(line,str[cursor]);
	  
	  nStation++;
	}
	
	int curr = station2int[Station(line,str[cursor])];

	if(cursor!=2){
	  adjList[curr].push_back(prev);
	  adjList[prev].push_back(curr);
	}

	prev = curr;
      }
      else {
	
	if(station2int.find(Station(str[cursor+1],str[cursor+2]))==station2int.end()){
	  station2int[Station(str[cursor+1],str[cursor+2])] = nStation;
	  int2station[nStation] = Station(str[cursor+1],str[cursor+2]);
	  
	  nStation++;
	}
	
	int curr = station2int[Station(str[cursor+1],str[cursor+2])];
	
	assert(cursor!=2);
	
	adjList[prev].push_back(curr);
	adjList[curr].push_back(prev);
	
	cursor+=2;
      }
      
    }
    
  }
  
}

void dijkstra(int start, int goal){
  
  int cost[MAX_SIZE];
  priority_queue< Element > Q; // cost, path
  Element ans;
  vector<int> init;
  
  
  init.push_back(start);
  for(int i=0;i<=nStation;i++)
    cost[i] = INT_MAX;
  
  Q.push(Element(0,init));
  
  
  while(!Q.empty()){
    
    Element curr = Q.top();
    Q.pop();
    
    /*
    for(int i=0;i<curr.path.size();i++){
      cout << "   " << int2station[curr.path[i]].line << ' ' << int2station[curr.path[i]].c ;
    }cout << endl;
    */

    if(curr.path.back()==goal){
      ans = curr;      
      break;
    }
    
    if(cost[curr.path.back()]<=curr.cost) continue;
    cost[curr.path.back()] = curr.cost;
    
    for(int i=0;i<adjList[curr.path.back()].size();i++){
      
      Element next = curr;
      
      Station prevStation = int2station[curr.path.back()];
      Station currStation = int2station[adjList[curr.path.back()][i]];
      

      if(prevStation.line!=currStation.line){

	if(curr.path.size()>2){
	  
	  Station prev2 = int2station[curr.path[curr.path.size()-2]];

	  if(prevStation.line!=prev2.line)
	    next.path.pop_back();
	  else
	    next.cost+=3;
	}
	else
	  next.cost+=3;
      }
      else
	next.cost++;
      
    next.path.push_back(adjList[curr.path.back()][i]);
      
      Q.push(next);
    }
    
    
  }
  
  char prevLine=0;

  printf("%3d: ",ans.cost);
  for(int i=0;i<ans.path.size();i++){
    
    Station curr = int2station[ans.path[i]];

    if(prevLine!=curr.line){

      if(i!=0) cout << '=';

      cout << curr.line << curr.c;
      prevLine = curr.line;
    }
    else
      cout << curr.c;
  }
  cout << endl;
  
}

void work(){
    
  while(true){
    string str;
    cin >> str;

    if(str=="#") break;
    
    assert(str.size()==4);
    
    int start = station2int[Station(str[0],str[1])];
    int goal = station2int[Station(str[2],str[3])];
    
    dijkstra(start,goal);
  }
  
}

int main(){
  
  read();
  work();

  return 0;
}
