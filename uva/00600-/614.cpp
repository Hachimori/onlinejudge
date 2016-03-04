#include<iostream>
#include<cstdio>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

#define NOWALL 0
#define EASTWALL 1
#define SOUTHWALL 2
#define BOTHWALL 3

#define MAX_SIZE 15

using namespace std;

int row, column;
int startR, startC, goalR, goalC;
int board[MAX_SIZE][MAX_SIZE];

bool read(){

	cin >> row >> column >> startR >> startC >> goalR >> goalC;
	if(row==0 && column==0 && startR==0 && startC==0 && goalR==0 && goalC==0)
		return false;

	startR--;
	startC--;
	goalR--;
	goalC--;

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			cin >> board[i][j];			

	return true;
}

bool isInside(int r, int c){
	return (0<=r && r<row && 0<=c && c<column);
}

bool isWall(int direction, int r, int c){
	if(direction==LEFT) 
		return (board[r][c]==EASTWALL || board[r][c]==BOTHWALL);
	if(direction==UP)
		return (board[r][c]==SOUTHWALL || board[r][c]==BOTHWALL);
	if(direction==RIGHT)
		return (board[r][c-1]==EASTWALL || board[r][c-1]==BOTHWALL);
	if(direction==DOWN)
		return (board[r-1][c]==SOUTHWALL || board[r-1][c]==BOTHWALL);
	
	
}

bool compute(int nVisited, int currR, int currC, int visited[MAX_SIZE][MAX_SIZE]){
	
	static const int moveR[4]={0,-1,0,1}, moveC[4]={-1,0,1,0};

	visited[currR][currC]=nVisited;		

	if(currR==goalR && currC==goalC) return true;

	for(int i=0;i<4;i++){
		int nextR=currR+moveR[i], nextC=currC+moveC[i];
		
		if(!isInside(nextR,nextC)) continue;
		if(isWall(i,nextR,nextC)) continue;
		if(visited[nextR][nextC]!=-1) continue;

		if(compute(nVisited+1,nextR,nextC,visited)) return true;	
		
	}
	
	visited[currR][currC]=0;
	return false;
}

void work(int cases){
	
	int nVisited=1;
	int visited[MAX_SIZE][MAX_SIZE];

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			visited[i][j]=-1;


	compute(nVisited,startR,startC,visited);


	cout << "Maze " << cases << endl << endl;

	for(int m=0;m<column;m++){
		cout << "+---";
	}cout << "+" << endl;

	for(int k=0;k<row;k++){
		
		cout << "|";
		for(int l=0;l<column;l++){
			if(visited[k][l]==0)
				cout << "???";
			else if(visited[k][l]==-1)
				cout << "   ";
			else
				printf(" %2d",visited[k][l]);
			
			if(l==column-1 || board[k][l]==BOTHWALL || board[k][l]==EASTWALL)
				cout << "|";
			else
				cout << " ";
		} cout << endl;
		
		
		for(int n=0;n<column;n++)
			if(k==row-1 || board[k][n]==BOTHWALL || board[k][n]==SOUTHWALL)
				cout << "+---";
			else
				cout << "+   ";
		cout << "+" << endl;
	}

}

int main(){

	for(int i=1;read();i++){
		work(i);
		cout << endl << endl;
	}

	return 0;
}

