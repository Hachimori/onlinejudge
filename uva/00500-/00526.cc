// 526
// Edit Distance

#include<iostream>
#include<string>
#include<vector>

#define END -1
#define LEFT_UP 0
#define LEFT 1
#define UP 2
#define DELETE 0
#define INSERT 1
#define REPLACE 2
#define COPY 3

#define MAX_SIZE 85

using namespace std;

class Ope{
public:

  int id, pos;
  char c;

  Ope(){}
  Ope(int id, int pos, char c): id(id), pos(pos), c(c){}
  
};

string str1, str2;

bool read(){  
  if(getline(cin,str1)==NULL) return false;
  if(getline(cin,str2)==NULL) return false;
  return true;
}

void editDistance(){
  
  const static int INF=99999;
  int cost[MAX_SIZE][MAX_SIZE];
  int pi[MAX_SIZE][MAX_SIZE];

  
  for(int i=0;i<=str1.size();i++){
    cost[i][0]=i;
    pi[i][0]=UP;
  }
  for(int j=0;j<=str2.size();j++){
    cost[0][j]=j;
    pi[0][j]=LEFT;
  }
  pi[0][0]=END;
  

  for(int i=1;i<=str1.size();i++){
    for(int j=1;j<=str2.size();j++){
      
      int leftCost=cost[i][j-1]+1, upCost=cost[i-1][j]+1, leftUpCost=cost[i-1][j-1]+1;
      
      if(str1[i-1]==str2[j-1]) leftUpCost--;
      
      
      if(upCost<=leftCost && upCost<=leftUpCost){
	cost[i][j] = upCost;
	pi[i][j] = UP;
      }
      else if(leftCost<=leftUpCost && leftCost<=upCost){
	cost[i][j] = leftCost;
	pi[i][j] = LEFT;
      }
      else if(leftUpCost<=leftCost && leftUpCost<=upCost){
	cost[i][j] = leftUpCost;
	pi[i][j] = LEFT_UP;
      }
      
    }
  }
 
  
  vector<Ope> opeList;
  int currRow=str1.size(), currColumn=str2.size();
  
  while(pi[currRow][currColumn]!=END){

    if(pi[currRow][currColumn]==LEFT_UP){
      
      if(str1[currRow-1]==str2[currColumn-1]){
	//opeList.push_back(Ope(COPY,currColumn,' '));
      }
      else
	opeList.push_back(Ope(REPLACE,currColumn,str2[currColumn-1]));
      
      currRow--, currColumn--;
    }
    else if(pi[currRow][currColumn]==UP){
      opeList.push_back(Ope(DELETE,currColumn+1,' '));      
      currRow--;
    }
    else if(pi[currRow][currColumn]==LEFT){      
      opeList.push_back(Ope(INSERT,currColumn,str2[currColumn-1]));      
      currColumn--;
    }
    
  }

  
  cout << opeList.size() << endl;
  for(int i=(int)(opeList.size()-1),j=1;i>=0;i--,j++){
    if(opeList[i].id==DELETE)
      cout << j << " Delete " << opeList[i].pos << endl;
    else if(opeList[i].id==INSERT)
      cout << j << " Insert " << opeList[i].pos << ',' << opeList[i].c << endl;
    else if(opeList[i].id==REPLACE)
      cout << j << " Replace " << opeList[i].pos << ',' << opeList[i].c << endl;
  }

}

void work(){
  
  editDistance();
  
}

int main(){
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
