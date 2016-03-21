#include<iostream>
#define MAX_SIZE 1000000

using namespace std;

class Point{
public:

	int x, y;

	Point(){}
	Point(int x, int y): x(x), y(y) {}

};

int n;
Point pList[MAX_SIZE];

void createTable(){

	static const int xMove[6]={-1,-1,0,1,1,0};
	static const int yMove[6]={1,0,-1,-1,0,1};

	
	pList[0] = Point(0,0);

	
	int nVisited=1;

	for(int depth=1;;depth++){
		
		Point curr=Point(0,1);
		for(int i=0;i<depth-1;i++)
			curr.x+=xMove[4], curr.y+=yMove[4];

		pList[nVisited] = curr;
		nVisited++;
		if(nVisited==MAX_SIZE) return;

		for(int j=0;j<6;j++){
			int nMove = depth;
			if(j==0) nMove--;
			
			for(int k=0;k<nMove;k++){
				curr.x+=xMove[j];
				curr.y+=yMove[j];

				pList[nVisited] = curr;
				nVisited++;		
				if(nVisited==MAX_SIZE) return;
			}
		}
	}


}

bool read(){
	if(!(cin >> n)) return false;
	return true;
}

void work(){	
	cout << pList[n-1].x << " " << pList[n-1].y << endl;
}

int main(){

	createTable();

	while(read())
		work();

	return 0;
}