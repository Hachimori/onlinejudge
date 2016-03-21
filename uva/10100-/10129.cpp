/* Oct 14                       */
/* 10129  Play on Words		*/
/* Accepted                     */

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>

#define MAX 27

using namespace std;

class Graph{
public:

        vector< vector<int> > adjList;
        vector< vector<int>::iterator > pos;
        vector<int> visited;

        Graph(){}
        Graph(int n){
                adjList.assign(n+1,vector<int>());
                pos.assign(n+1,vector<int>::iterator());
        }
        
        void reset(int n){
                for(int i=0;i<=n;i++)
                        pos[i] = adjList[i].begin();
                visited.assign(n+1,false);
        }

        void insert(int source, int target){
                adjList[source].push_back(target);
        }

        int next( int n ){
                if(pos[n]!=adjList[n].end()) return *pos[n]++;
                else return -1;
        }

};

bool judge(Graph &g, int numLetter){
        
        int numEdge[MAX];

        g.reset(numLetter);

        for(int i=0;i<numLetter;i++)
                numEdge[i] = g.adjList[i].size();

        for(int j=0;j<numLetter;j++){
                
                while(true){
                        int next=g.next(j);

                        if(next==-1) break;
                        else {
                                numEdge[next]--;
                        }
                }
        }

        int NonZero=0;

        for(int k=0;k<numLetter;k++){
                if(numEdge[k]!=0) NonZero+=abs(numEdge[k]);
        }

        if(NonZero>2) return false;
        return true;
}

void dfs_rec(Graph &g, int arg){
        
        g.visited[arg] = true;

        while( true ){
                int next = g.next(arg);
                
                if(next==-1) break;
                else if(g.visited[next]==true) continue;
                else dfs_rec(g,next);
        }

}

bool dfs(Graph &g, int numLetter){
        
        for(int i=0;i<numLetter;i++){

                bool flg=true;
                
                g.reset(numLetter);
                dfs_rec(g,i);
                
                for(int j=0;j<numLetter;j++)
                        if(g.visited[j]==false)
                                flg = false;
                
                if(flg == true) return true;
        }
        
        return false;
}

void read(Graph &g, int &numLetter){

        int numWord;
        map<int,int> letterList;

        cin >> numWord;

        g = Graph(MAX);

        for(int i=0,counter=0;i<numWord;i++){
                string word;

                cin >> word;
                

                int endWord = word.length()-1;

                if(letterList.find(word[0])==letterList.end()){
                        letterList[word[0]] = counter;
                        counter++;
                }
                if(letterList.find(word[endWord])==letterList.end()){
                        letterList[word[endWord]] = counter;
                        counter++;
                }

                g.insert(letterList[word[0]],letterList[word[endWord]]);
        
        }

        numLetter = letterList.size();
}

void work(Graph &g, int numLetter){

        if(dfs(g,numLetter)==false){ 
                cout << "The door cannot be opened." << endl;
                return;
        }
        
        if(judge(g,numLetter)==false){
                cout << "The door cannot be opened." << endl;
                return;
        }

        cout << "Ordering is possible." << endl;
        
}

int main(){

        Graph g;
        int cases,numLetter;
        
        cin >> cases;
        
        for(int i=0;i<cases;i++){
                read(g,numLetter);
                work(g,numLetter);
        }

        return 0;
}
