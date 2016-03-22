#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<fstream>

//#define cin fin

using namespace std;

//ifstream fin("test.txt");

class Pair{
public:
        int t1;
        int t2;

        Pair(){}
        Pair(int t1, int t2) : t1(t1), t2(t2) {}

};

class Edge{
public:
        int target;
        int color;

        Edge(){}
        Edge(int t, int c) : target(t), color(c) {}

};

class Graph{
public:

        vector< vector<Edge> > adjList;

        Graph(){}
        Graph(int n){
                adjList.assign(n+1,vector<Edge>());
        }

        void insert(int source, int target, int color){
                adjList[source].push_back(Edge(target,color));
        }

        vector<Edge> operator [] (int n) const{
                return adjList[n];
        }

};

Graph g;
int nCell, ans;
int token1, token2, token3;

bool bfs(int state[101][101]){

        queue<Pair> Q;

        Q.push(Pair(token1,token2));


        while(!Q.empty()){
                
                Pair curr = Q.front();
                Q.pop();

                for(int i=0;i<g[curr.t1].size();i++){
                        if(g[curr.t1][i].color==curr.t2){
                                int nextT1 = g[curr.t1][i].target;
                                
                                if(nextT1==token3){
                                        ans = state[curr.t1][curr.t2]+1;
                                        return true;
                                }

                                if(state[nextT1][curr.t2]>state[curr.t1][curr.t2]+1){
                                        state[nextT1][curr.t2]=state[curr.t1][curr.t2]+1;
                                        Q.push(Pair(nextT1,curr.t2));
                                }
                        }               
                }

                for(int j=0;j<g[curr.t2].size();j++){
                        if(g[curr.t2][j].color==curr.t1){
                                int nextT2 = g[curr.t2][j].target;
                                
                                if(nextT2==token3){
                                        ans = state[curr.t1][curr.t2]+1;
                                        return true;
                                }

                                if(state[curr.t1][nextT2]>state[curr.t1][curr.t2]+1){
                                        state[curr.t1][nextT2]=state[curr.t1][curr.t2]+1;
                                        Q.push(Pair(curr.t1,nextT2));
                                }
                        }               
                }
        }

        return false;
}

bool read(){
        
        cin >> nCell;
        if(nCell==0) return false;

        g = Graph(nCell);

        
        for(int i=1;i<=nCell;i++){
                for(int j=1;j<=nCell;j++){
                        int target;
                        cin >> target;

                        if(target!=0)
                                g.insert(i,target,j);
                        
                }
        }

        cin >> token1 >> token2 >> token3;

        return true;
}

void work(int cases){
/*
        for(int i=1;i<=nCell;i++){
                for(int j=0;j<g[i].size();j++){
                        cout << g[i][j].color << " ";
                }cout << endl;
        }cout << endl;
*/

        int state[101][101];

        for(int i=0;i<=nCell;i++){
                for(int j=0;j<=nCell;j++){
                        state[i][j] = INT_MAX;
                }
        }

        state[token1][token2] = 0;

        if(token1==token3 || token2==token3){
                cout << "Game #" << cases << endl;
                cout << "Minimum Number of Moves = " << 0 << endl;
                cout << endl;
                return;
        }

        if(!bfs(state)){
                cout << "Game #" << cases << endl;
                cout << "Destination is Not Reachable !" << endl;
                cout << endl;
        }
        else{
                cout << "Game #" << cases << endl;
                cout << "Minimum Number of Moves = " << ans << endl;
                cout << endl;
        }

}

int main(){

        for(int cases=1;;cases++){
                if(!read()) break;
                work(cases);
        }

        return 0;
}
