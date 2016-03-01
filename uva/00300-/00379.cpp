#include<iostream>

#define WALL -1
#define MAX_SIZE 7

using namespace std;

int point[MAX_SIZE][MAX_SIZE];
bool isPeg[MAX_SIZE][MAX_SIZE];

void makeTable(){
	
	int currPot=1;

	for(int k=0;k<MAX_SIZE;k++)
		for(int l=0;l<MAX_SIZE;l++)
			point[k][l] = WALL;

	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			if(i==0 || i==1 || i==5 || i==6){
				if(2<=j && j<=4)
					point[i][j]=currPot++;
			}
			else {
				point[i][j]=currPot++;
			}
		}
	}

}

void read(){
	
	for(int i=0;i<MAX_SIZE;i++)
		for(int j=0;j<MAX_SIZE;j++)
			isPeg[i][j] = false;


	while(true){
		int pos;
		cin >> pos;
		if(pos==0) break;
	
		if(1<=pos && pos<=3) isPeg[0][pos+1]=true;
		if(4<=pos && pos<=6) isPeg[1][pos-2]=true;
		if(7<=pos && pos<=13) isPeg[2][pos-7]=true;
		if(14<=pos && pos<=20) isPeg[3][pos-14]=true;
		if(21<=pos && pos<=27) isPeg[4][pos-21]=true;
		if(28<=pos && pos<=30) isPeg[5][pos-26]=true;
		if(31<=pos && pos<=33) isPeg[6][pos-29]=true;
	}

}

bool isInside(int r, int c){
	return (0<=r && r<MAX_SIZE && 0<=c && c<MAX_SIZE);
}

void rec(){
	
	static const int rMove[4] ={1,0,-1,0};
	static const int cMove[4] ={0,1,0,-1};

	int maxHoleScore=-1,maxPegNum;
	int direction, posR, posC;

	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			if(point[i][j]!=WALL && !isPeg[i][j]){
				for(int k=0;k<4;k++){
					if(isInside(i+rMove[k],j+cMove[k]) && isInside(i+2*rMove[k],j+2*cMove[k]) &&
						isPeg[i+rMove[k]][j+cMove[k]] && isPeg[i+2*rMove[k]][j+2*cMove[k]] ){
						if(maxHoleScore<point[i][j]){
							maxHoleScore = point[i][j];
							maxPegNum = point[i+2*rMove[k]][j+2*cMove[k]];
							posR = i;
							posC = j;
							direction = k;
						}
					}
				}
			}
		}
	}
	

	if(maxHoleScore==-1) return;
	
	isPeg[posR+rMove[direction]][posC+cMove[direction]]=false;
	isPeg[posR+2*rMove[direction]][posC+2*cMove[direction]]=false;
	isPeg[posR][posC]=true;

	rec();

}

void work(){
	/*
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			if(isPeg[i][j]) cout << " +";
			else cout << " #";
		}cout << endl;
	}cout << endl;

	for(int k=0;k<MAX_SIZE;k++){
		for(int l=0;l<MAX_SIZE;l++){
			if(point[k][l]>0) cout << " " << point[k][l];
			else cout << " #";
		}cout << endl;
	}cout << endl;
	*/

	rec();

	int score=0;
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			if(isPeg[i][j]) score+=point[i][j];
		}
	}

	cout << score << endl;
}

int main(){

	int cases;
	cin >> cases;

	cout << "HI Q OUTPUT" << endl;
	
	makeTable();

	for(int i=0;i<cases;i++){
		read();
		work();
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}