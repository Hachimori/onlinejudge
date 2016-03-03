// graph
//
// 
// 任意の二人のドライバーが、同じ停留所に留まるかどうかを行列で表す。
// あるノードから始めて別のノードへ行けるということは、そのドライバーが
// 別のドライバーへ自分の持つ話題を伝えられるということである。
//
// また、あるドライバーAが別のドライバーBへ行くまでに辿った、ドライバー(C,D,E...)の
// もつ話題も別のドライバーBへ伝わる。さらに、ドライバーBの持つ話題も
// ドライバー(C,D,E....)を通じてドライバーAに伝わる。
//
// なので、その行列上でDFSをしてすべてのノードを辿れるかどうかを調べるとよい。
//
//


#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cassert>

#define MAX_LINE 25
#define MAX_DRIVER 35

using namespace std;

class Driver{
public:
  int idx, line;

  Driver(){}
  Driver(int i, int l): idx(i), line(l){}
};

int nLine, nDriver, nStop;
vector<int> line[MAX_LINE];
Driver driver[MAX_DRIVER];

bool read(){
  cin >> nLine >> nDriver >> nStop;
  if(nLine==0 && nDriver==0 && nStop==0) return false;
  
  for(int i=0;i<nLine;i++)
    line[i].clear();
  
  string buf; getline(cin,buf);
  
  for(int i=0;i<nLine;i++){
    istringstream is;

    getline(cin,buf);
    is.str(buf);
    
    int stop;
    while(is >> stop)
      line[i].push_back(stop);
    
    getline(cin,buf);
    is.clear();
    is.str(buf);
    
    int id;
    while(is >> stop >> id){
      id--;
      for(int j=0;;j++)
	if(line[i][j]==stop){
	  driver[id] = Driver(j,i);
	  break;
	}
    }
  }

  return true;
}

bool willMeet(int a, int b){
  vector<int> aLine=line[driver[a].line], bLine=line[driver[b].line];
  
  int aOrigin=driver[a].idx, bOrigin=driver[b].idx; 
  int aCurr=(driver[a].idx+1)%aLine.size(), bCurr=(driver[b].idx+1)%bLine.size();
  
  if(aLine[aOrigin]==bLine[bOrigin]) return true;
  
  while(aOrigin!=aCurr || bOrigin!=bCurr){
    if(aLine[aCurr]==bLine[bCurr]) return true;
  
    aCurr = (aCurr+1)%aLine.size();
    bCurr = (bCurr+1)%bLine.size();
  }
  
  return false;
}

void dfs(int curr, int &nVisited, bool visited[], bool adjList[][MAX_DRIVER]){
  nVisited++;
  visited[curr] = true;
  
  for(int i=0;i<nDriver;i++){
    if(!adjList[curr][i]) continue;
    if(visited[i]) continue;

    dfs(i,nVisited,visited,adjList);
  }
}

void work(){
  bool adjList[MAX_DRIVER][MAX_DRIVER];
  
  for(int i=0;i<nDriver;i++)
    for(int j=0;j<nDriver;j++){
      if(i==j) adjList[i][j] = false;
      else adjList[i][j] = willMeet(i,j);
    }
  
  bool visited[MAX_DRIVER];
  int nVisited = 0;
  
  for(int i=0;i<nDriver;i++)
    visited[i] = false;
  dfs(0,nVisited,visited,adjList);
  
  if(nVisited==nDriver) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
