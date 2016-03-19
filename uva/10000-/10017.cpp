#include<iostream>
//#include<fstream>
#include<vector>

//#define cin fin

using namespace std;

//ifstream fin("tmp.txt");
int nTile, limit;
int tbl[][3]={{-1,2,1},{2,-1,0},{1,0,-1}};

bool read(){
     cin >> nTile >> limit;
     if(nTile==0 && limit==0) return false;
     return true;
}

void print(vector<int> state[]){
     cout << endl;
     for(int i=0;i<3;i++){
             cout << (char)(i+'A') << "=>"; 
             if(state[i].size()==0) cout << endl;
             else{
                  cout << "  ";
                  for(int j=0;j<state[i].size();j++)
                       cout << ' ' << state[i][j];
                  cout << endl;
             }         
     }         
}

void move(int &nMove, int src, int dst, int num, vector<int> state[]){
     if(nMove==limit) return;
     if(num==1) {
                nMove++;
                state[dst].push_back(state[src].back());
                state[src].pop_back();
                print(state);
                return;
     }
       
     
     move(nMove,src,tbl[src][dst],num-1,state);
     
     move(nMove,src,dst,1,state);
     
     move(nMove,tbl[src][dst],dst,num-1,state);     
}

void work(int cases){
     int nMove = 0;
     vector<int> state[3];
     
     
     for(int i=nTile;i>=1;i--) state[0].push_back(i);
          
     cout << "Problem #" << cases << endl;
     print(state);
     
     move(nMove,0,2,nTile,state);
}

int main(){
    for(int i=0;read();i++){
            work(i+1);
            cout << endl;
    }
    
    return 0;    
}
