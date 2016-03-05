#include<iostream>
#include<climits>

#define MAX_SIZE 80

using namespace std;

class Move{
public:
	int dr, dc;

	Move(){}
	Move(int dr, int dc): dr(dr), dc(dc) {}

};

int width, height;
int nCycle, maxLeng;
char board[MAX_SIZE][MAX_SIZE];
bool isPath[MAX_SIZE][MAX_SIZE*3];
Move vPath[MAX_SIZE][MAX_SIZE*3];

bool read(){
	
	cin >> width >> height;
	if(width==0 && height==0) return false;
	
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			cin >> board[i][j];
			isPath[i][j*3]=true;
			isPath[i][j*3+1]=false;
			isPath[i][j*3+2]=true;
		}
	}

	for(int k=0;k<height;k++)
		for(int l=0;l<width*3;l++)
			vPath[k][l] = Move(0,0);
	
	for(int m=1;m<height;m++){
		for(int n=0;n<width;n++){
			if(board[m-1][n]=='/' && board[m][n]=='/'){
				vPath[m-1][n*3+2]=Move(1,-2);
				vPath[m][n*3]=Move(-1,2);
			}
			else if(board[m-1][n]=='/' && board[m][n]=='\\'){
				vPath[m-1][n*3+2] = Move(1,0);
				vPath[m][n*3+2] = Move(-1,0);
			}
			else if(board[m-1][n]=='\\' && board[m][n]=='/'){
				vPath[m-1][n*3] = Move(1,0);
				vPath[m][n*3] = Move(-1,0);			
			}
			else if(board[m-1][n]=='\\' && board[m][n]=='\\'){
				vPath[m-1][n*3] = Move(1,2);
				vPath[m][n*3+2] = Move(-1,-2);			
			}
		}
	}

	return true;
}

bool isInside(int r, int c){
	return (0<=r && r<height && 0<=c && c<width*3);
}	

bool dfs(int nVisited, int currR, int currC, int visited[MAX_SIZE][MAX_SIZE*3]){
	/*
	for(int i=0;i<height;i++){
		for(int j=0;j<width*3;j++){
			if(!isPath[i][j]) cout << "# ";
			else if(visited[i][j]==INT_MAX) cout << "0 ";
			else cout << visited[i][j] << " ";
		}cout << endl;
	}cout << endl;
*/

	if(visited[currR][currC]!=INT_MAX){	
		if(maxLeng<nVisited) maxLeng=nVisited;
		nCycle++;
		//cout << nVisited << endl;
		return true;
	}
	visited[currR][currC] = nVisited;


	int nextR, nextC;
	
	nextR=currR, nextC=currC-1;

	if(isInside(nextR,nextC) && isPath[nextR][nextC] && 
		visited[nextR][nextC]!=nVisited-1 && visited[nextR][nextC]!=nVisited+1)
		if(dfs(nVisited+1,nextR,nextC,visited)) return true;

	nextR=currR, nextC=currC+1;

	if(isInside(nextR,nextC) && isPath[nextR][nextC] && 
		visited[nextR][nextC]!=nVisited-1 && visited[nextR][nextC]!=nVisited+1)
		if(dfs(nVisited+1,nextR,nextC,visited)) return true;


	nextR=currR+vPath[currR][currC].dr, nextC=currC+vPath[currR][currC].dc;

	if(isInside(nextR,nextC) && isPath[nextR][nextC] && 
		visited[nextR][nextC]!=nVisited && visited[nextR][nextC]!=nVisited-1 &&
		visited[nextR][nextC]!=nVisited+1)
		if(dfs(nVisited+1,nextR,nextC,visited)) return true;

	return false;
}

void work(int cases){
	
	int visited[MAX_SIZE][MAX_SIZE*3];

	for(int i=0;i<height;i++)
		for(int j=0;j<width*3;j++)
			visited[i][j] = INT_MAX;

	nCycle=0;
	maxLeng=0;

	for(int k=0;k<height;k++){
		for(int l=0;l<width*3;l++){
			if(l%3==1) continue;
			if(visited[k][l]==INT_MAX) 
				dfs(0,k,l,visited);
		}
	}

	cout << "Maze #" << cases << ":" << endl;

	if(nCycle>0)
		cout << nCycle << " Cycles; the longest has length " << maxLeng << "." << endl;
	else
		cout << "There are no cycles." << endl;

	cout << endl;
}

int main(){

	for(int i=1;read();i++)
		work(i);

	return 0;
}