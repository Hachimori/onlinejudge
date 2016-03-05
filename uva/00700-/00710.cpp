#include<iostream>
#include<string>

#define MAX_SIZE 80

using namespace std;

int width, height;
char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE], next[MAX_SIZE][MAX_SIZE];

bool read(){

	cin >> width >> height;
	if(width==0 && height==0) return false;

	width+=2;
	height+=2;
	
	string str;	getline(cin,str);
	
	for(int k=0;k<height;k++)
		for(int l=0;l<width;l++)
			board[k][l] = ' ';

	for(int i=1;i<height-1;i++){
		getline(cin,str);
		for(int j=0;j<str.length();j++){
			board[i][j+1] = str[j];
		}
	}

	return true;
}

bool isInside(int r, int c){
	return (0<=r && r<height && 0<=c && c<width);
}

void paint(int curr, int goalR, int goalC){

	const static int rMove[4]={1,0,-1,0};
	const static int cMove[4]={0,1,0,-1};

	bool painted=false;

	for(int m=0;m<height;m++)
		for(int n=0;n<width;n++)
			next[m][n] = false;

	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(visited[i][j])
				for(int k=0;k<4;k++){
					for(int l=1;;l++){
						int nextR=i+l*rMove[k], nextC=j+l*cMove[k];
						if(!isInside(nextR,nextC)) break;
						
						if(nextR==goalR && nextC==goalC){
								cout << curr+1 << " segments." << endl;
								return;
						}
						
						if(board[nextR][nextC]=='X') break;
						if(!visited[nextR][nextC]) painted=true;
						next[nextR][nextC]=true;
					}
				}
		}
	}

	if(!painted){ 
		cout << "impossible." << endl;
		return;
	}

	for(int o=0;o<height;o++)
		for(int p=0;p<width;p++)
			visited[o][p] = next[o][p];

	paint(curr+1,goalR,goalC);

}

void work(int cases){
/*
	for(int x=0;x<height;x++){
		for(int y=0;y<width;y++){
			cout << board[x][y];	
		}cout << endl;
	}cout << endl;
*/

	cout << "Board #" << cases << ":" << endl;

	for(int i=1;;i++){
		int r1,c1,r2,c2;
		cin >> c1 >> r1 >> c2 >> r2;
		if(r1==0 && c1==0 && r2==0 && c2==0) break;

		cout << "Pair " << i << ": "; 

		
		for(int j=0;j<height;j++)
			for(int l=0;l<width;l++)
				visited[j][l] = false;
				
		visited[r1][c1] = true;
		paint(0,r2,c2);
	}

	cout << endl;
}

int main(){

	for(int i=1;read();i++)
		work(i);

	return 0;
}