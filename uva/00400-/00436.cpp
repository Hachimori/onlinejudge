#include<iostream>
#include<string>
#include<vector>
#include<map>

#define MAX_SIZE 32

using namespace std;

int nNode;
map<string,int> nameToInt;
double adjList[MAX_SIZE][MAX_SIZE];

bool read(){

	cin >> nNode;
	if(nNode==0) return false;

	nameToInt.clear();
	for(int k=0;k<nNode;k++)
		for(int l=0;l<nNode;l++)
			adjList[k][l] = 0;

	for(int i=0;i<nNode;i++){
		string name;
		cin >> name;

		nameToInt[name] = i;
	}

	int nEdge;
	cin >> nEdge;

	for(int j=0;j<nEdge;j++){
		string source, target;
		double cost;

		cin >> source >> cost >> target;

		adjList[nameToInt[source]][nameToInt[target]] = cost;
	}

	return true;
}

bool rec(int start, int nVisited, double currMoney[MAX_SIZE]){
	
	if(currMoney[start]>1.0) return true;
	if(nVisited==nNode) return false;

	for(int i=0;i<nNode;i++){
		for(int j=0;j<nNode;j++){
			if(adjList[i][j]!=0){
				if(currMoney[j]<currMoney[i]*adjList[i][j])
					currMoney[j]=currMoney[i]*adjList[i][j];
			}
		}
	}
	
	if(rec(start,nVisited+1,currMoney)) return true;

	return false;
}

void work(int cases){
	
	cout << "Case " << cases << ": ";

	for(int i=0;i<nNode;i++){
		double currMoney[MAX_SIZE];
		
		for(int j=0;j<nNode;j++)
			currMoney[j] = 0;
		
		currMoney[i] = 1.0;

		if(rec(i,0,currMoney)){
			cout << "Yes" << endl;
			return;
		}
	}
	

	cout << "No" << endl;
}

int main(){

	for(int i=1;read();i++)
		work(i);

	return 0;
}