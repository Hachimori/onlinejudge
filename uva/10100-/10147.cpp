#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<map>
#include<cmath>

#define MAX 752

using namespace std;

class Pair{
public:
	int source, target;
	
	Pair(){}
	Pair(int source, int target) : source(source), target(target) {}
};

class Point{
public:
	double x,y;

	double calcDistance( const Point &p ){
		return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
	}

};

class Node{
public:

	int source;
	int target;
	double weight;

	Node(){}
	Node(int source, int target, double weight): source(source), target(target), weight(weight){}

	bool operator< (const Node &n) const {
		if(weight>n.weight) return true;
		return false;
	}

};

class Graph{
public:

	vector< vector<Node> > adjList;
	vector< vector<Node>::iterator > pos;
	vector<int> visited;

	Graph(){}
	Graph(int n){
		adjList.assign(n+1,vector<Node>());
		pos.assign(n+1,vector<Node>::iterator());
	}

	void reset(int n){
		for(int i=0;i<=n;i++)
			pos[i] = adjList[i].begin(); 
		visited.assign(n+1,false);
	}

	void insert(int source, int target, double cost){
		adjList[source].push_back(Node(source,target,cost));
	}

	Node next(int n){
		if(pos[n]!=adjList[n].end()) return *pos[n]++;
		else return Node(-1,-1,-1);
	}

};

void mst(Graph &g, int numTown, int &numConnect, Pair connect[MAX]){

	int numEdge=0;
	priority_queue<Node> Q;

	g.reset(numTown);

	Q.push(Node(0,1,0));

	while(numEdge!=numTown){
	
		Node curr = Q.top();
		Q.pop();
		
		if(g.visited[curr.target]) continue;
		g.visited[curr.target] = true;

		if(curr.weight!=0.0){
			connect[numConnect] = Pair(curr.source,curr.target);
			numConnect++;
		}

		while(true){
			
			Node next = g.next(curr.target);

			if(next.target==-1) break;
			else if(g.visited[next.target]) continue;
			else Q.push(next);
			
		}
		
		numEdge++;
	}
	
}

void read(Graph &g, int &numTown){

	cin >> numTown;
	g = Graph(numTown);

	Point L[MAX];

	for(int i=1;i<=numTown;i++)
		cin >> L[i].x >> L[i].y;
	
	
	for(int j=1;j<=numTown;j++){
		for(int k=j+1;k<=numTown;k++){
			double dis = L[j].calcDistance(L[k]);
			
			g.insert(j,k,dis);
			g.insert(k,j,dis);
		}
	}
	

	int numHighway;
	cin >> numHighway;
	for(int l=0;l<numHighway;l++){
		int source, target;
		cin >> source >> target;
		g.insert(source,target,0);
		g.insert(target,source,0);
	}

}

void work(Graph &g, int &numTown){

	int numConnect=0;
	Pair connect[MAX];

	mst(g,numTown,numConnect,connect);

	if(numConnect==0) cout << "No new highways need" << endl;
	else
		for(int i=0;i<numConnect;i++)
			cout << connect[i].source << " " << connect[i].target << endl;
	
}

int main(){
	Graph g;
	int cases;
	int numTown;

	cin >> cases;

	for(int i=0;i<cases;i++){
		if(i!=0) cout << endl;
		read(g,numTown);
		work(g,numTown);
	}

	return 0;
}
