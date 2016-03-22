#include<iostream>
#include<cmath>
#include<vector>
#include<cassert>
#include<climits>
#include<string>
#include<queue>
#include<map>

#define RADIUS 6378
#define MAX 101
#define PI 3.141592653589793238462643383279502884197169399375105820974944592

using namespace std;

class Node{
 public:

  int target;
  int cost;

  Node(){}
  Node(int target, int cost) : target(target), cost(cost) {}

  bool operator< ( const Node &n ) const {
    if(cost>n.cost) return true;
    else return false;
  }

};

class Point{
 public:

  double x,y,z;

  Point(){}
  Point(double x, double y, double z) : x(x), y(y), z(z) {}

  double calcDistance( Point &p){
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z));
  }

};

class Graph{
 public:

  vector< vector<Node> > adjList;
  vector< vector<Node>::iterator > pos;
  vector<int> visited;
  vector<int> distance;

  Graph(){}
  Graph(int n){
    adjList.assign(n+1,vector<Node>());
    pos.assign(n+1,vector<Node>::iterator());
  }

  void reset(int n){
    for(int i=0;i<=n;i++)
      pos[i] = adjList[i].begin();
		
    visited.assign(n+1,false);
    distance.assign(n+1,INT_MAX);
  }
	
  void insert(int source, int target, int cost){
    adjList[source].push_back(Node(target,cost));
  }

  Node next(int n){
    if(pos[n]!=adjList[n].end()) return *pos[n]++;
    else return Node(-1,-1.0);
  }

};

double calcGeodetic( double distance ){
  double degree = acos((RADIUS*RADIUS*2-distance*distance)/(RADIUS*RADIUS*2));
  return degree*RADIUS;
}

int numNode;
int numQuery;
map<string,int> nameList;

void dijkstra(Graph &g, int start){
	
  priority_queue<Node> Q;
	
  g.distance[start] = 0;
  Q.push(Node(start,g.distance[start]));

  while(!Q.empty()){
    Node curr = Q.top();
    Q.pop();
    if(g.visited[curr.target]) continue;
		
    g.visited[curr.target] = true;

    while(true){
      Node next = g.next(curr.target);

      if(next.target==-1) break;
      else if(g.distance[next.target]>g.distance[curr.target] + next.cost){
	g.distance[next.target] = g.distance[curr.target]+next.cost;
	Q.push(Node(next.target,g.distance[next.target]));
      }
    }

  }
	
}

bool read(Graph &g){
	
  Point P[MAX];
  int numEdge;

  cin >> numNode >> numEdge >> numQuery;
  if(numNode==0 && numEdge==0 && numQuery==0) return false;

  g = Graph(numNode);
  nameList.clear();

  for(int i=0;i<numNode;i++){
    string city;
    double xDegree, yDegree;

    cin >> city >> yDegree >> xDegree;
    P[i] = Point(RADIUS*cos(PI*yDegree/180)*sin(PI*xDegree/180),RADIUS*cos(PI*yDegree/180)*cos(PI*xDegree/180),RADIUS*sin(PI*yDegree/180));
    nameList[city] = i; 
  }
  /*
  for(int i=0;i<numNode;i++){
    cout << P[i].x << " " << P[i].y << " " << P[i].z << endl;
  }cout << endl;
  */

  for(int j=0;j<numEdge;j++){
    string source, target;
    cin >> source >> target;

    int nSource = nameList[source];
    int nTarget = nameList[target];

    double distance = P[nSource].calcDistance(P[nTarget]);
    int geodicD = (int)(calcGeodetic(distance)+0.5);

    g.insert(nSource,nTarget,geodicD);
    
  }

  return true;
}

void work(Graph &g, int cases){
	
  int distanceList[MAX][MAX];

  for(int i=0;i<numNode;i++){
    g.reset(numNode);

    dijkstra(g,i);
		
    for(int j=0;j<numNode;j++)
      distanceList[i][j] = g.distance[j];
  }
	

  cout << "Case #" << cases << endl;
  for(int k=0;k<numQuery;k++){
    string source, target;
    cin >> source >> target;

    int nSource = nameList[source];
    int nTarget = nameList[target];

    if(distanceList[nSource][nTarget]!=INT_MAX) cout << distanceList[nSource][nTarget] << " km" << endl;
    else cout << "no route exists" << endl;
  }

}

int main(){

  Graph g;

  for(int cases=1;;cases++){
    if(!read(g)) break;

    if(cases!=1) cout << endl;

    work(g,cases);
  }

  return 0;
}


