#include<iostream>
#include<string>
#include<map>
//#include<fstream>
#include<set>

//#define cin fin
#define MAX_SIZE 5

using namespace std;

//ifstream fin("tmp.txt");

int initR, initC, minMove;
int board[MAX_SIZE][MAX_SIZE];
map<long long,int> completed;

bool isInside(int r, int c){
	return (0<=r && r<MAX_SIZE && 0<=c && c<MAX_SIZE);
}

void makeCompleteRec(int curr, int holeR, int holeC, int compBoard[MAX_SIZE][MAX_SIZE]){
	
	static const int rMove[8]={2,2,1,-1,-2,-2,-1,1};
	static const int cMove[8]={-1,1,2,2,1,-1,-2,-2};
	
	if(curr==6) return;

	long long sum=0, p=1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			sum+=compBoard[i][j]*p;
			p*=3;
		}
	}

	if(completed.find(sum)!=completed.end()){ 
		if(completed[sum]<curr) return;
	}
	completed[sum] = curr;
	
	for(int k=0;k<8;k++){
		int nextR = holeR+rMove[k], nextC = holeC+cMove[k];

		if(!isInside(nextR,nextC)) continue;

		int t = compBoard[nextR][nextC];
		compBoard[nextR][nextC] = compBoard[holeR][holeC];
		compBoard[holeR][holeC] = t;

		makeCompleteRec(curr+1,nextR,nextC,compBoard);

		t = compBoard[nextR][nextC];
		compBoard[nextR][nextC] = compBoard[holeR][holeC];
		compBoard[holeR][holeC] = t;	
	}

}

void makeComplete(){
	
	int compBoard[MAX_SIZE][MAX_SIZE];

	for(int i=0;i<3;i++){
		for(int j=0;j<i;j++)
			compBoard[i][j] = 0;
		for(int k=i;k<5;k++)
			compBoard[i][k] = 1;
	}
	
	for(int l=3;l<5;l++){
		for(int m=0;m<=l;m++)
			compBoard[l][m] = 0;
		for(int n=l+1;n<5;n++)
			compBoard[l][n] = 1;
	}

	compBoard[2][2] = 2;

	makeCompleteRec(0,2,2,compBoard);

}

void read(){
	
	for(int i=0;i<5;i++){
		string str; getline(cin,str);
		for(int j=0;j<5;j++){
			if(str[j]=='1' || str[j]=='0') board[i][j] = str[j]-'0';
			else{ 
				board[i][j] = 2;
				initR=i, initC=j;
			}
		}
	}

	/*
	for(int k=0;k<5;k++){
		for(int l=0;l<5;l++)
			cout << board[k][l];
		cout << endl;
	}cout << endl;
	*/

}

void calc(int curr, int holeR, int holeC, set<long long> &visited){
	
	static const int rMove[8]={2,2,1,-1,-2,-2,-1,1};
	static const int cMove[8]={-1,1,2,2,1,-1,-2,-2};	

	if(curr==7) return;

	long long sum=0, p=1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			sum+=board[i][j]*p;
			p*=3;
		}
	}

	if(completed.find(sum)!=completed.end()){ 
		if(minMove>curr+completed[sum])
			minMove=curr+completed[sum];

		return;
	}
	if(visited.find(sum)!=visited.end()) return;
	visited.insert(sum);
	

	for(int k=0;k<8;k++){
		int nextR = holeR+rMove[k], nextC = holeC+cMove[k];

		if(!isInside(nextR,nextC)) continue;

		int t = board[nextR][nextC];
		board[nextR][nextC] = board[holeR][holeC];
		board[holeR][holeC] = t;

		calc(curr+1,nextR,nextC,visited);

		t = board[nextR][nextC];
		board[nextR][nextC] = board[holeR][holeC];
		board[holeR][holeC] = t;	
	}

}

void work(){
	
	set<long long> visited;
	
	minMove=11;
	
	calc(0,initR,initC,visited);

	if(minMove==11) cout << "Unsolvable in less than 11 move(s)." << endl;
	else cout << "Solvable in " << minMove << " move(s)." << endl;

}

int main(){

	int cases;
	cin >> cases;
	
	string str; getline(cin,str);

	makeComplete();

	for(int i=0;i<cases;i++){
		read();
		work();
	}

	return 0;
}
