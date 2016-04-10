/* 5 0 0 0 0 1 2 　の入力で　0+0+0+0+1=2　となってしまう　*/

#include<iostream>
#include<algorithm>
#include<vector>

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

#define MAX_SIZE 105
#define SHIFT 32000
#define MAX_RANGE 64005

using namespace std;

int nNumber, target;
int nList[MAX_SIZE];
bool visited[MAX_SIZE][MAX_RANGE];

void read(){
	
	cin >> nNumber;
	
	for(int i=0;i<nNumber;i++)
		cin >> nList[i];
	
	cin >> target;

}

bool calc(int nVisited, int currNum, vector<int> &currPath){
	
	if(nVisited==nNumber)		
		return visited[nVisited][target+SHIFT];
	

	for(int i=0;i<4;i++){
		
		if(i==PLUS){
			if(abs(currNum+nList[nVisited])>SHIFT) continue;
			if(!visited[nVisited+1][currNum+nList[nVisited]+SHIFT]){
				visited[nVisited+1][currNum+nList[nVisited]+SHIFT] = true;
				currPath.push_back(PLUS);
				if(calc(nVisited+1,currNum+nList[nVisited],currPath)) return true;
				currPath.pop_back();
			}
		}

		if(i==MINUS){
			if(abs(currNum-nList[nVisited])>SHIFT) continue;
			if(!visited[nVisited+1][currNum-nList[nVisited]+SHIFT]){
				visited[nVisited+1][currNum-nList[nVisited]+SHIFT] = true;
				currPath.push_back(MINUS);
				if(calc(nVisited+1,currNum-nList[nVisited],currPath)) return true;
				currPath.pop_back();
			}
		}

		if(i==DIV){
			if(nList[nVisited]==0 || abs(currNum)%nList[nVisited]!=0) continue;
			if(!visited[nVisited+1][currNum/nList[nVisited]+SHIFT]){
				visited[nVisited+1][currNum/nList[nVisited]+SHIFT] = true;
				currPath.push_back(DIV);
				if(calc(nVisited+1,currNum/nList[nVisited],currPath)) return true;
				currPath.pop_back();
			}
		}

		if(i==MUL){
			if(abs(currNum*nList[nVisited])>SHIFT) continue;
			if(!visited[nVisited+1][currNum*nList[nVisited]+SHIFT]){
				visited[nVisited+1][currNum*nList[nVisited]+SHIFT] = true;
				currPath.push_back(MUL);
				if(calc(nVisited+1,currNum*nList[nVisited],currPath)) return true;
				currPath.pop_back();
			}
		}	

	}
	
	return false;
}

void work(){
	
	vector<int> pathList;
	
	if(nNumber==1){
		if(nList[0]==target) cout << nList[0] << "=" << nList[0] << endl;
		else cout << "NO EXPRESSION" << endl;
		return;
	}
	
	for(int k=0;k<nNumber+1;k++)
		fill(visited[k],visited[k]+MAX_RANGE,false);

	for(int i=0;i<nNumber;i++){
		if(calc(1,nList[i],pathList)){

			for(int j=0;j<nNumber;j++){
				if(j==0) cout << nList[0];
				else{ 
					if(pathList[j-1]==PLUS) cout << "+";
					if(pathList[j-1]==MINUS) cout << "-";
					if(pathList[j-1]==MUL) cout << "*";
					if(pathList[j-1]==DIV) cout << "/";
					cout << nList[j];
				}
			}cout << "=" << target << endl;
			
			return;

		}
	}
	
	cout << "NO EXPRESSION" << endl;

}

int main(){

	int cases;
	cin >> cases;

	for(int i=0;i<cases;i++){
		read();
		work();
	}

	return 0;
}