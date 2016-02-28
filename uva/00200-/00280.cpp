#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_SIZE 105

using namespace std;

class Graph{
public:

	vector< vector<int> > adjList;

	Graph(){}
	Graph(int n){
		adjList.assign(n+1,vector<int>());
	}

	void insert(int source, int target){
		adjList[source].push_back(target);
	}

	vector<int> &operator[] (int n){
		return adjList[n];
	}

};

int nNode;
Graph g;

bool read(){

	cin >> nNode;
	if(nNode==0) return false;

	g = Graph(nNode);

	while(true){
		int source;
		
		cin >> source;
		if(source==0) break;

		while(true){
			int target;
			cin >> target;

			if(target==0) break;
			g.insert(source,target);
		}
		
	}

	return true;
	
}

void dfs(int curr, bool visited[MAX_SIZE]){
	
	for(int i=0;i<g[curr].size();i++){
		if(visited[g[curr][i]]) continue;
		visited[g[curr][i]] = true;

		dfs(g[curr][i],visited);
	}
	
}

void work(){

	int nQuery;
	cin >> nQuery;

	for(int i=0;i<nQuery;i++){
		int initNode;
		cin >> initNode;

		bool visited[MAX_SIZE];
		fill(visited,visited+nNode+1,false);

		dfs(initNode,visited);
		
		int nNonVisited=0;
		int nonVisitedList[MAX_SIZE];
		for(int j=1;j<nNode+1;j++){
			if(!visited[j]){
				nonVisitedList[nNonVisited] = j;
				nNonVisited++;
			}
		}

		cout << nNonVisited;
		for(int k=0;k<nNonVisited;k++){
			cout << " " << nonVisitedList[k];
		}cout << endl;
	}
	
}

int main(){

	while(read())
		work();

	return 0;
}