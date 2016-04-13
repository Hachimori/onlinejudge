#include<iostream>
#include<vector>
#include<climits>
#include<utility>
#include<map>
#include<queue>

#define MAX_SIZE 11

using namespace std;

int nChemic;
pair<int,int> board[MAX_SIZE][MAX_SIZE];  // creation, heat amount
int currAmount[MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int nAmount;

class Element{
public:

  vector<int> chemicAmt;

  Element(){}
  Element(vector<int> c): chemicAmt(c) {}
  
  bool operator< (const Element &e ) const {
    for(int i=0;i<chemicAmt.size();i++){
      if(chemicAmt[i]<e.chemicAmt[i]) return true;
      else if(chemicAmt[i]>e.chemicAmt[i]) return false;
    }
    
    return false;
  }

};

void read(){
  
  cin >> nChemic;
  
  for(int i=0;i<nChemic;i++)
    for(int j=0;j<nChemic;j++){
      cin >> board[i][j].first >> board[i][j].second;
      board[i][j].first--;
    }

  for(int i=0;i<nChemic;i++)
    currAmount[i]=0;
    
  cin >> nAmount;

  for(int i=0;i<nAmount;i++){
    int chemic;
    cin >> chemic;

    chemic--;
    
    currAmount[chemic]++;
  }
  
}

void dijkstra(){
  
  queue< pair<Element,int> > Q;
    
  Element init;

  for(int i=0;i<=nAmount;i++)
  for(int j=0;j<=nAmount;j++)
  for(int k=0;k<=nAmount;k++)
  for(int l=0;l<=nAmount;l++)
  for(int m=0;m<=nAmount;m++)
  for(int n=0;n<=nAmount;n++)
    visited[i][j][k][l][m][n]=INT_MAX;
  
  for(int i=0;i<nChemic;i++)
    init.chemicAmt.push_back(currAmount[i]);
  
  for(int i=0;i<6-nChemic;i++)
    init.chemicAmt.push_back(0);
  
  
  Q.push(make_pair(init,0));
  

  while(!Q.empty()){
    
    pair<Element,int> curr = Q.front();
    Q.pop();
    
    /*
    for(int i=0;i<nChemic;i++){
      cout << curr.first.chemicAmt[i] << ' ';
    } cout << curr.second << endl;
    */
    
    if(visited[curr.first.chemicAmt[0]][curr.first.chemicAmt[1]][curr.first.chemicAmt[2]][curr.first.chemicAmt[3]][curr.first.chemicAmt[4]][curr.first.chemicAmt[5]]==INT_MAX){
      visited[curr.first.chemicAmt[0]][curr.first.chemicAmt[1]][curr.first.chemicAmt[2]][curr.first.chemicAmt[3]][curr.first.chemicAmt[4]][curr.first.chemicAmt[5]] = curr.second;
    }
    else if(visited[curr.first.chemicAmt[0]][curr.first.chemicAmt[1]][curr.first.chemicAmt[2]][curr.first.chemicAmt[3]][curr.first.chemicAmt[4]][curr.first.chemicAmt[5]]>curr.second){
      visited[curr.first.chemicAmt[0]][curr.first.chemicAmt[1]][curr.first.chemicAmt[2]][curr.first.chemicAmt[3]][curr.first.chemicAmt[4]][curr.first.chemicAmt[5]] = curr.second;
    }
    else continue;

    for(int i=0;i<nChemic;i++){
      for(int j=0;j<nChemic;j++){
	
	if(i!=j && curr.first.chemicAmt[i]>0 && curr.first.chemicAmt[j]>0){
	  pair<Element,int> next = curr;
	  
	  next.first.chemicAmt[i]--;
	  next.first.chemicAmt[j]--;
	  next.second+=board[i][j].second;
	  next.first.chemicAmt[board[i][j].first]++;
	  
	  Q.push(next);
	}
	else if(i==j && curr.first.chemicAmt[i]>1){
	  pair<Element,int> next = curr;

	  next.first.chemicAmt[i]--;
	  next.first.chemicAmt[i]--;
	  next.second+=board[i][i].second;
	  next.first.chemicAmt[board[i][i].first]++;
	  
	  Q.push(next);
	}

      }
    }
    
  }
  

  int minVal=INT_MAX;

  for(int i=0;i<6;i++){

    Element goal;
    for(int j=0;j<6;j++){
      if(j==i)
	goal.chemicAmt.push_back(1);
      else
	goal.chemicAmt.push_back(0);
    }
    
    if(minVal>visited[goal.chemicAmt[0]][goal.chemicAmt[1]][goal.chemicAmt[2]][goal.chemicAmt[3]][goal.chemicAmt[4]][goal.chemicAmt[5]])
      minVal=visited[goal.chemicAmt[0]][goal.chemicAmt[1]][goal.chemicAmt[2]][goal.chemicAmt[3]][goal.chemicAmt[4]][goal.chemicAmt[5]];
  }

  cout << minVal << endl;
  
}

void work(){
  /*
    
  for(int i=0;i<nChemic;i++){
    for(int j=0;j<nChemic;j++){
      cout << board[i][j].first << ' ' << board[i][j].second << "   ";
    }cout << endl;
  }cout << endl;

  for(int i=0;i<nChemic;i++){
    cout << currAmount[i] << ' ';
  }cout << endl << endl;

  */

  dijkstra();

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    char c;
    if(i!=0) cin >> c;
    read();
    work();
  }

  return 0;
}
