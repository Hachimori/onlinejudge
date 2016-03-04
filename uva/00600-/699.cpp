#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<utility>
#include<fstream>

#define MAX_SIZE 1000
#define SHIFT 500
//#define cin fin

using namespace std;

//ifstream fin("test.txt");

class Graph{
public:

	vector< vector< int > > adjList;

	Graph(){
		adjList.clear();
	}

	Graph(int n){
		adjList.assign(n,vector<int>());
	}


	void insert(int source, int target){
		adjList[source].push_back(target);
	}

	vector<int> &operator[] (int n) {
		return adjList[n];
	}

	int size(){
		return adjList.size();
	}

};

Graph g;
int valList[MAX_SIZE];

int &access(int n){
	return valList[n+SHIFT];
}

void constructRec(int curr){
	
	int val;
	cin >> val; 
		
	g.adjList.push_back(vector<int>());
	valList[g.size()] = val;
	g.insert(curr,g.size());

	if(val!=-1)
		constructRec(g.size());
	
	
	cin >> val; 
	
	g.adjList.push_back(vector<int>());
	valList[g.size()] = val;
	g.insert(curr,g.size());

	if(val!=-1)
		constructRec(g.size());

}

bool read(){
	
	g = Graph();
	
	int rootVal; cin >> rootVal;
	if(rootVal==-1) return false;
	
	valList[g.size()] = rootVal;
	g.adjList.push_back(vector<int>());
	
	constructRec(0);

	return true;
}

void dfs(int currNode, int cursor, int score[MAX_SIZE]){
	
	score[cursor]+=valList[currNode];


	for(int i=0;i<g[currNode].size();i++){
		
		int nextNode = g[currNode][i];
		
		if(valList[nextNode]==-1) continue;
		
		if(i==0)
			dfs(nextNode,cursor-1,score);
		else
			dfs(nextNode,cursor+1,score);
	}

}

void work(int cases){

	int score[MAX_SIZE];
	fill(score,score+MAX_SIZE,0);

	dfs(0,SHIFT,score);


	cout << "Case " << cases << ":" << endl;

	for(int i=0;i<MAX_SIZE;i++){
		if(score[i]!=0){
			for(int j=i;score[j]!=0;j++){
				if(j==i) cout << score[j];
				else cout << " " << score[j];
			}
			cout << endl << endl;
			break;
		}
	}

}

int main(){

	for(int cases=1;read();cases++)
		work(cases);

	return 0;
}