#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<fstream>

#define MAX 1005
#define UP 60
#define DOWN 20
#define STRAIGHT 30
//#define cin fin

using namespace std;

//ifstream fin("test.txt");

class Point{
public:

        int x,y;

        Point(){}
        Point(int x, int y) : x(x), y(y) {}

};

class Node{
public:
        Point target;
        int weight;

        Node(){}
        Node(Point t, int w) : target(t), weight(w) {}

        bool operator< ( const Node &n ) const {
                return (weight<n.weight);
        }

};

int length;
int wind[10][MAX];
int xMove[3] = {1,1,1};
int yMove[3] = {1,0,-1};

bool isValid(int x, int y){
        if(x==length && y==0) return true;
        return (0<=y && y<10 && 0<=x && x<length);
}

void read(){
        
        int mile;
        cin >> mile;

        length = mile/100;

        for(int i=9;i>=0;i--)
                for(int j=0;j<length;j++)
                        cin >> wind[i][j];      

}

void work(){
        
        int ans = INT_MAX;
        vector< vector<int> > distance;

        distance.assign(10,vector<int>());
        for(int j=0;j<10;j++)
                distance[j].assign(length,INT_MAX);

        priority_queue<Node> Q;

        Q.push(Node(Point(0,0),-wind[0][0]));

        while(!Q.empty()){
                Node curr = Q.top();
                Q.pop();

                for(int i=0;i<3;i++){
                        int nextX = curr.target.x+xMove[i];
                        int nextY = curr.target.y+yMove[i];
                        int nextCost;
                        
                        if(!isValid(nextX,nextY)) continue;
                        
                        if(nextX==length && nextY==0){
                                if(i==0) nextCost = UP;
                                if(i==1) nextCost = STRAIGHT;
                                if(i==2) nextCost = DOWN;
                        }
                        else{
                                if(i==0) nextCost = UP-wind[nextY][nextX];
                                if(i==1) nextCost = STRAIGHT-wind[nextY][nextX];
                                if(i==2) nextCost = DOWN-wind[nextY][nextX];
                        }

                        if(nextX==length && nextY==0 && ans>curr.weight+nextCost){
                                ans = curr.weight+nextCost;
                        }
                        else if( distance[nextY][nextX] > curr.weight+nextCost){
                                distance[nextY][nextX] = curr.weight+nextCost;
                                Q.push(Node(Point(nextX,nextY),distance[nextY][nextX]));
                        }
                }

        }
/*
        for(int y=9;y>=0;y--){
                for(int z=0;z<length;z++){
                        cout << distance[y][z] << " ";
                }cout << endl;
        }cout << endl;
*/

        cout << ans << endl;
        cout << endl;
}

int main(){

        int cases;
        cin >>cases;

        for(int i=0;i<cases;i++){
                read();
                work();
        }

        return 0;

}
