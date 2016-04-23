// Greedy
//
// 
// 
// ペアを多く持つ生徒から順に他のクラスへ移す。
// しかし、違うクラスに移ってそこでペアが発生してしまう場合を
// 考慮する必要がある。
//
// そこで, posPair-negPairが最大となる生徒から順に他のクラスへ移す。
// posPair: 同じクラスにいてペアである数
// negPair: 違うクラスにいてペアである数
//
// Impossible になる場合は存在しない。
//


#include<iostream>
#include<map>
#include<vector>

#define MAX_SIZE 105

using namespace std;

// adjList[a][b] = 1;   a と b は同じクラスにいてペアである。
// adjList[a][b] = -1;　a と b は違うクラスにいてペアである。
map<int,int> adjList[MAX_SIZE];  
int nNode;

void read(){
  
  for(int i=0;i<MAX_SIZE;i++)
    adjList[i].clear();
  
  int nPair;

  cin >> nNode >> nPair;
  
  for(int i=0;i<nPair;i++){
    int pairA, pairB;
    cin >> pairA >> pairB;

    pairA--, pairB--;

    adjList[pairA][pairB] = 1;
    adjList[pairB][pairA] = 1;
  }
  
}

void work(int cases){
  
  vector<int> moved;

  for(int i=0;i<nNode/2;i++){
    
    int maxVal = -1, maxPos;
    for(int j=0;j<nNode;j++){
      int sum = 0;
      for(map<int,int>::iterator k=adjList[j].begin();k!=adjList[j].end();k++)
	sum += k->second;
      
      if(maxVal<sum){
	maxVal = sum;
	maxPos = j;
      }
    }
    
    if(maxVal>0){
      for(int k=0;k<nNode;k++){
	if(adjList[k].count(maxPos))
	  adjList[k][maxPos] = -1;
      }
      adjList[maxPos].clear();
      moved.push_back(maxPos);
    }
    else
      break;
  }
  
  cout << "Case #" << cases << ": " << moved.size() << endl;
  for(int i=0;i<moved.size();i++){
    if(i!=0) cout << ' ';
    cout << 1+moved[i];
  }cout << endl;
  
}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
