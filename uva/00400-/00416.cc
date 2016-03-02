#include<iostream>
#include<vector>

#define DARK 0
#define LIGHT 1
#define ANY 2

using namespace std;

int nSeq;
vector<int> sequence[20];
int table[][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},
		  {1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},
		  {1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},
		  {1,1,1,1,0,1,1}};

bool read(){
  cin >> nSeq;
  if(nSeq==0) return false;
  
  for(int i=0;i<nSeq;i++){
    vector<int> toPush;
    for(int j=0;j<7;j++){
      char c;
      cin >> c;
      
      if(c=='Y') toPush.push_back(LIGHT);
      else toPush.push_back(DARK);
    }
    
    sequence[i] = toPush;
  }
  
  return true;
}

bool rec(int curr, int toSet){
  if(curr==nSeq) return true;
  if(toSet==-1) return false;
  
  bool succeed = true;
  for(int i=0;i<7;i++)
    if(!(sequence[curr][i]==ANY || (sequence[curr][i]==table[toSet][i]))){
      succeed = false;
      break;
    }
  
  if(succeed && rec(curr+1,toSet-1)) return true;
  
  return false;
}

void work(){
  for(int i=0;i<7;i++){
    int curr = nSeq-1;
    while(curr>=0 && sequence[curr][i]==DARK){
      sequence[curr][i] = ANY;
      curr--;
    }
  }
  
  for(int i=9;i>=0;i--){
    if(rec(0,i)){
      cout << "MATCH" << endl;
      return;
    }
  }

  cout << "MISMATCH" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
