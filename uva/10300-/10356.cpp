#include<iostream>
#include<climits>
#include<algorithm>

#define MAX_SIZE 505

using namespace std;

int nNode;
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){

	int nEdge;
	if(!(cin >> nNode >> nEdge)) return false;

	
	for(int j=0;j<nNode;j++)
		for(int k=0;k<nNode;k++)
			adjList[j][k] = INT_MAX;

	for(int i=0;i<nEdge;i++){
		int source, target, cost;
		cin >> source >> target >> cost;
		
		adjList[source][target] = cost;
		adjList[target][source] = cost;
	}

	return true;
}

void calc(int nVisited, int cost[MAX_SIZE][MAX_SIZE], int &ans){
/*
	for(int k=0;k<nNode;k++)
		cout << cost[nVisited][k] << " ";
	cout << endl;
*/

	if(nVisited%2==0 && ans>cost[nVisited][nNode-1])
		ans=cost[nVisited][nNode-1];

	if(nVisited==nNode) return;

	for(int i=0;i<nNode;i++){
		if(cost[nVisited][i]==INT_MAX) continue;

		for(int j=0;j<nNode;j++){
			if(adjList[i][j]==INT_MAX) continue;

			if(cost[nVisited+1][j]>cost[nVisited][i]+adjList[i][j])
				cost[nVisited+1][j]=cost[nVisited][i]+adjList[i][j];
		}
	}
	
	calc(nVisited+1,cost,ans);
}

void work(int cases){
	
	int ans=INT_MAX;
	int cost[MAX_SIZE][MAX_SIZE];

	for(int i=0;i<nNode+1;i++)
		fill(cost[i],cost[i]+nNode,INT_MAX);
	
	cost[0][0] = 0;

	calc(0,cost,ans);
	

	cout << "Set #" << cases << endl;
	if(ans==INT_MAX) cout << "?" << endl;
	else cout << ans << endl;
}

int main(){

	for(int i=1;read();i++)
		work(i);

	return 0;
}