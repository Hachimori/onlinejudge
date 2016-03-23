#include<iostream>

#define MAX_SIZE 20

using namespace std;

char mines[MAX_SIZE][MAX_SIZE];
char touch[MAX_SIZE][MAX_SIZE];

int size;

void read(){

    cin >> size;
    for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	    cin >> mines[i][j];

    for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	    cin >> touch[i][j];

}

bool isInside(int r, int c){
    return (0<=r && r<size && 0<=c && c<size);
}

void work(){
    
    static const int rMove[8]={1,1,1,0,-1,-1,-1,0};
    static const int cMove[8]={-1,0,1,1,1,0,-1,-1};
    char result[MAX_SIZE][MAX_SIZE];

    bool mineTouch=false;

    for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	    if(touch[i][j]=='.') result[i][j]='.';
	    else if(touch[i][j]=='x'){
		
		if(mines[i][j]=='*') mineTouch=true;

		int cntMine=0;
		for(int k=0;k<8;k++){
		    int nextR = i+rMove[k], nextC = j+cMove[k];
		    
		    if(!isInside(nextR,nextC)) continue;
		    
		    if(mines[nextR][nextC]=='*') cntMine++;
		}

		result[i][j]=cntMine+'0';
	    }
    
    
    if(mineTouch)	
	for(int i=0;i<size;i++)
	    for(int j=0;j<size;j++)
		if(mines[i][j]=='*') result[i][j]='*';
    
    
    for(int i=0;i<size;i++){
	for(int j=0;j<size;j++)
	    cout << result[i][j];
	cout << endl;
    }

}

int main(){

    int cases;
    cin >> cases;
    
    for(int i=0;i<cases;i++){
	if(i!=0) cout << endl;
	read();
	work();
    }

    return 0;
}
