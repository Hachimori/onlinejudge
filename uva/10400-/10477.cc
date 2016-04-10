#include<iostream>
#include<queue>
#include<climits>
#include<cassert>

#define MAX 27
#define WALL -1

using namespace std;

class Point{
public:
	int x,y;
	int cycle;

	Point(){}
	Point(int x, int y) : x(x), y(y) {}
	Point(int x, int y, int cycle) : x(x), y(y), cycle(cycle) {}

};

int xK[8]={-1,1,2,2,1,-1,-2,-2}, yK[8] = {2,2,1,-1,-2,-2,-1,1};
int xMK[8]={-1,1,3,3,1,-1,-3,-3}, yMK[8] = {3,3,1,-1,-3,-3,-1,1};
int xMP[4]={0,1,0,-1}, yMP[4]={1,0,-1,0};
int xMP2[4]={-1,1,1,-1}, yMP2[4]={1,1,-1,-1};

int size, query;
int matrix[MAX][MAX][3];

bool dijkstra(Point start, Point goal){

	queue<Point> Q;
	Q.push(Point(start.x,start.y,0));
	Q.push(Point(start.x,start.y,1));
	Q.push(Point(start.x,start.y,2));
	matrix[start.y][start.x][0] = 0;
	matrix[start.y][start.x][1] = 0;
	matrix[start.y][start.x][2] = 0;


	while(!Q.empty()){
	
		Point curr = Q.front();
		Q.pop();
		
		
		if(curr.cycle==0){

			for(int i=0;i<8;i++){
				Point next = Point(curr.x+xK[i], curr.y+yK[i], 1);
				
				if(matrix[next.y][next.x][next.cycle]==WALL) continue;
				else if(next.x==goal.x && next.y==goal.y) {
					cout << matrix[curr.y][curr.x][curr.cycle] + 1 << endl;
					return true;
				}
				else if(matrix[next.y][next.x][next.cycle] >
					matrix[curr.y][curr.x][curr.cycle] + 1){
					  matrix[next.y][next.x][next.cycle] =
					    matrix[curr.y][curr.x][curr.cycle] + 1;
					  Q.push(next);
				}
			}

		}
		else if(curr.cycle==1){
			
			for(int j=0;j<8;j++){
				Point next = Point(curr.x+xMK[j], curr.y+yMK[j], 2);
				
				if(matrix[next.y][next.x][next.cycle]==WALL) continue;
				else if(next.x==goal.x && next.y==goal.y) {
					cout << matrix[curr.y][curr.x][curr.cycle] + 1 << endl;
					return true;
				}
				else if(matrix[next.y][next.x][next.cycle] >
					matrix[curr.y][curr.x][curr.cycle] + 1){
					  matrix[next.y][next.x][next.cycle] =
					    matrix[curr.y][curr.x][curr.cycle] + 1;
					  Q.push(next);
				}
			}
		}
		else if(curr.cycle==2){
			
			for(int l=0;l<4;l++){
				Point next = Point(curr.x+xMP2[l], curr.y+yMP2[l]);
					
				if(next.x==goal.x && next.y==goal.y) {
					cout << matrix[curr.y][curr.x][curr.cycle] + 1 << endl;
					return true;
				}
			}

			for(int k=0;k<4;k++){
				Point next = Point(curr.x+xMP[k], curr.y+yMP[k], 0);
				
				if(matrix[next.y][next.x][next.cycle]==WALL) continue;
				else if(next.x==goal.x && next.y==goal.y) {
					cout << matrix[curr.y][curr.x][curr.cycle] + 1 << endl;
					return true;
				}
				else if(matrix[next.y][next.x][next.cycle] >
					matrix[curr.y][curr.x][curr.cycle] + 1){
					  matrix[next.y][next.x][next.cycle] =
					    matrix[curr.y][curr.x][curr.cycle] + 1;
					  Q.push(next);
				}

			}
		}
		else assert(false);

	}

	return false;
}

void work(){

	for(int j=0;j<size+6;j++)
		for(int k=0;k<size+6;k++)
			for(int l=0;l<3;l++)
				matrix[j][k][l] = WALL;

	for(int i=0;i<query;i++){
		int s, g;
		Point start, goal;
		cin >> s >> g;
		
		start = Point((s-1)%size+3,(s-1)/size+3);
		goal = Point((g-1)%size+3,(g-1)/size+3);
		
		//cout << start.x << ' ' << start.y << "   " << goal.x << ' ' << goal.y << endl;
		
		for(int m=3;m<size+3;m++)
			for(int n=3;n<size+3;n++)
				for(int o=0;o<3;o++)
					matrix[m][n][o] = INT_MAX;

		if(!dijkstra(start,goal)) 
			cout << "?" << endl;

	}

}

int main(){
			
	for(int cases=1;;cases++){
		cin >> size;
		if(size==0) break;
		cin >> query;

		cout << "Set " << cases << ":" << endl;
		work();
	}

	return 0;
}
