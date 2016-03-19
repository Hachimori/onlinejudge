#include<iostream>
#include<algorithm>
#include<climits>
#include<utility>
#include<vector>

#define END -1
#define MAX_SIZE 505

using namespace std;

class Dice{
public:
  
  int col[7];
  
  Dice(){}
  
  int otherside(int n){
    if(n%2==0) return col[n-1];
    else return col[n+1];
  }
  
  int& operator[](int n) {
    return col[n];
  }
  
};

int nDice;
Dice dList[MAX_SIZE];
int board[MAX_SIZE][7];
pair<int,int> pi[MAX_SIZE][7];  //dice id, face id

bool read(){
  
  cin >> nDice;
  if(nDice==0) return false;
  
  for(int i=0;i<nDice;i++)
    for(int j=1;j<=6;j++)
      cin >> dList[i][j];
  
  return true;
}

void work(int cases){
  
  /*
  for(int i=0;i<nDice;i++){
    for(int j=0;j<6;j++)
      cout << dList[i][j] << ' ';
    cout << endl;
  }cout << endl;
  */
  
  
  for(int i=1;i<=6;i++){
    board[0][i] = 1;
    pi[0][i] = make_pair(END,END);
  }
  
  int ansVal=1;
  pair<int,int> ansPos=make_pair(0,1);
  
  for(int diceId=1;diceId<nDice;diceId++){
    for(int faceId=1;faceId<=6;faceId++){
      
      int maxVal=INT_MIN; 
      pair<int,int> maxPos;
      
      for(int topDice=0;topDice<diceId;topDice++){
	for(int topFace=1;topFace<=6;topFace++){
	  
	  if(dList[topDice].otherside(topFace)==dList[diceId][faceId] && 
	     maxVal<board[topDice][topFace]+1){
	    
	    maxVal = board[topDice][topFace]+1;
	    maxPos = make_pair(topDice,topFace);
	  }
	  
	}
      }
      
      if(maxVal==INT_MIN){
	board[diceId][faceId] = 1;
	pi[diceId][faceId] = make_pair(END,END);
      }
      else{
	board[diceId][faceId] = maxVal;
	pi[diceId][faceId] = maxPos;
      }

      if(ansVal<board[diceId][faceId]){
	ansVal = board[diceId][faceId];
	ansPos = make_pair(diceId,faceId);
      }
    }
    
  }
  
  vector< pair<int,int> > ansSeq;
  
  for(pair<int,int> i=ansPos;i.first!=END;i=pi[i.first][i.second])
    ansSeq.push_back(i);
  

  cout << "Case #" << cases << endl;

  cout << ansVal << endl;
  for(int i=ansSeq.size()-1;i>=0;i--){
    cout << ansSeq[i].first+1 << ' ';
    
    switch(ansSeq[i].second){
    case 1:
      cout << "front" << endl;
      break;
    
    case 2:
      cout << "back" << endl;
      break;

    case 3:
      cout << "left" << endl;
      break;

    case 4:
      cout << "right" << endl;
      break;

    case 5:
      cout << "top" << endl;
      break;

    case 6:
      cout << "bottom" << endl;
      break;

    }
    
  }
  
}

int main(){
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work(i+1);
  }

  return 0;
}
