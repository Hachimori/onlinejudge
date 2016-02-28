#include<iostream>
#include<vector>
#include<climits>

#define MAX_ROW 11
#define MAX_COLUMN 101

using namespace std;

class Cell{
public:
  
  int currWeight;
  vector<int> path;

  Cell(){}
  
  bool isBetter( Cell &c ){
    if(currWeight<c.currWeight) return true;
    else if(currWeight==c.currWeight){
      for(int i=0;i<path.size();i++){
	if(path[i]<c.path[i]) return true;
	else if(path[i]>c.path[i]) return false;
      }
    }
    
    return false;
  }
  
  void init(){
    currWeight=INT_MAX;
    path.clear();
  }
  
};

int row, column;
Cell cells[MAX_ROW][MAX_COLUMN];
int weight[MAX_ROW][MAX_COLUMN];

bool read(){
  
  if(!(cin >> row >> column)) return false;

  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      cin >> weight[i][j];
  

  return true;
}

int rowRet(int r){
  if(r==row) return 0;
  if(r==-1) return row-1;
  return r;
}

void work(){
  
  const static int rMove[3]={-1,0,1};
  
  for(int i=0;i<row;i++)
    for(int j=0;j<column;j++)
      cells[i][j].init();

  for(int i=0;i<row;i++){
    cells[i][0].currWeight=weight[i][0];
    cells[i][0].path.push_back(i);
  }

  for(int i=1;i<column;i++){
    for(int j=0;j<row;j++){
      
      for(int k=0;k<3;k++){
	int nextC=i-1, nextR=rowRet(j+rMove[k]);
	
	if(cells[nextR][nextC].path.size()>0){
	  cells[nextR][nextC].currWeight+=weight[j][i];
	  cells[nextR][nextC].path.push_back(j);

	  if(cells[nextR][nextC].isBetter(cells[j][i]))
	    cells[j][i] = cells[nextR][nextC];
	  
	  cells[nextR][nextC].currWeight-=weight[j][i];
	  cells[nextR][nextC].path.pop_back();
	}
	
      }
      
    }
  }

  
  Cell bestCell;
  bestCell.init();

  for(int i=0;i<row;i++)
    if(cells[i][column-1].isBetter(bestCell))
      bestCell = cells[i][column-1];

  for(int i=0;i<bestCell.path.size();i++){
    if(i==0) cout << bestCell.path[i]+1;
    else cout << ' ' << bestCell.path[i]+1;
  }cout << endl;
  cout << bestCell.currWeight << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
