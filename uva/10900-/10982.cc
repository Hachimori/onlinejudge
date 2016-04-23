// Greedy
//
// 
// 
// �y�A�𑽂������k���珇�ɑ��̃N���X�ֈڂ��B
// �������A�Ⴄ�N���X�Ɉڂ��Ă����Ńy�A���������Ă��܂��ꍇ��
// �l������K�v������B
//
// ������, posPair-negPair���ő�ƂȂ鐶�k���珇�ɑ��̃N���X�ֈڂ��B
// posPair: �����N���X�ɂ��ăy�A�ł��鐔
// negPair: �Ⴄ�N���X�ɂ��ăy�A�ł��鐔
//
// Impossible �ɂȂ�ꍇ�͑��݂��Ȃ��B
//


#include<iostream>
#include<map>
#include<vector>

#define MAX_SIZE 105

using namespace std;

// adjList[a][b] = 1;   a �� b �͓����N���X�ɂ��ăy�A�ł���B
// adjList[a][b] = -1;�@a �� b �͈Ⴄ�N���X�ɂ��ăy�A�ł���B
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
