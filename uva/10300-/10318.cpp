#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<climits>

#define MAX_SIZE 5
#define MAX_PANEL 3
//#define cin fin

using namespace std;

//ifstream fin("tmp.txt");

class Board{
public:
	
	int r, c;
	bool isDark[MAX_SIZE][MAX_SIZE];

	Board(){}
	Board(int r, int c): r(r), c(c) {}

	bool isInside(int row, int column){
		return (0<=row && row<r && 0<=column && column<c);
	}

	void push(int row, int column, bool change[MAX_PANEL][MAX_PANEL]){
		
		const static int rMove[9]={-1,-1,-1,0,1,1,1,0,0};
		const static int cMove[9]={-1,0,1,1,1,0,-1,-1,0};

		const static int rPos[9]={0,0,0,1,2,2,2,1,1};
		const static int cPos[9]={0,1,2,2,2,1,0,0,1};

		for(int i=0;i<9;i++){
			int nextR=row+rMove[i], nextC=column+cMove[i];
			if(!isInside(nextR,nextC)) continue;

			if(change[rPos[i]][cPos[i]])
				isDark[nextR][nextC] = !isDark[nextR][nextC];
		}
		
	}

	void print(){

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(isDark[i][j]) cout << "#";
				else cout << "-";
			}cout << endl;
		}cout << endl;
	}

	bool operator== (const Board &b) const {
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(isDark[i][j]!=b.isDark[i][j]) return false;
		
		return true;
	}

	bool operator< ( const Board &b ) const  {
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(isDark[i][j] && !b.isDark[i][j]) return true;
				else if(!isDark[i][j] && b.isDark[i][j]) return false;
			}
		}
		return false;
	}

};

int row, column, nPress;
vector<int> ans;
bool change[MAX_PANEL][MAX_PANEL];

bool read(){
	
	cin >> row >> column;
	if(row==0 && column==0) return false;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			char c;
			cin >> c;

			if(c=='*') change[i][j] = true;
			else change[i][j] = false;
		}

	return true;

}

void makeTableRec(int currR, int currC, Board &b, vector<int> &pushList,  map<Board, vector<int> > &M){

	if(currR==row){/*
		b.print();
		for(int i=0;i<pushList.size();i++)
			cout << pushList[i] << " ";
		cout << endl;
		*/
		return;
	}
	if(currC==column) {
		makeTableRec(currR+1,0,b,pushList,M);
		return;
	}

	
	b.push(currR,currC,change);
	pushList.push_back(currR*column+currC+1);
	M[b] = pushList;
	makeTableRec(currR,currC+1,b,pushList,M);

	b.push(currR,currC,change);
	pushList.pop_back();
	M[b] = pushList;
	makeTableRec(currR,currC+1,b,pushList,M);


}

void makeTable( map<Board, vector<int> > &M ) {

	vector<int> pushList;
	Board b=Board(row,column);
	
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			b.isDark[i][j] = false;

	makeTableRec(row/2,column/2,b,pushList,M);
}

void search(int currR, int currC, Board &b, vector<int> &pushList, map< Board, vector<int> > &M){

	if(M.find(b)!=M.end()){ 
		//b.print();
		if(nPress>pushList.size()+M[b].size()){
			ans = pushList;
			ans.insert(ans.end(),M[b].begin(),M[b].end());
			nPress=pushList.size()+M[b].size();
		}
		return;
	}

	if(currR==row/2 && currC==column/2) return;	

	if(currC==column) {
		search(currR+1,0,b,pushList,M);
		return;
	}
	
	b.push(currR,currC,change);
	pushList.push_back(currR*column+currC+1);

	search(currR,currC+1,b,pushList,M);

	b.push(currR,currC,change);
	pushList.pop_back();

	search(currR,currC+1,b,pushList,M);

	return;
}

void work(int cases){
	
	vector<int> pushList;
	map< Board, vector<int> > M;
	
	makeTable(M);

	nPress=INT_MAX;
	
	Board b=Board(row,column);

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			b.isDark[i][j] = true;

	cout << "Case #" << cases << endl;

	search(0,0,b,pushList,M);

	if(nPress!=INT_MAX){
		for(int k=0;k<ans.size();k++)
			if(k==0) cout << ans[k];
			else cout << " " << ans[k];
		cout << endl;
	}
	else 
		cout << "Impossible." << endl;
	
}

int main(){

	for(int i=0;read();i++)
		work(i+1);

	return 0;
}