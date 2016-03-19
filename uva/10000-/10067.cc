#include<iostream>
#include<queue>
#include<climits>

#define MAX_WHEEL 4
#define MAX_NUM 10

using namespace std;

class Element{
public:

  int num[MAX_WHEEL];
  
  Element(){}
  Element(int a, int b, int c, int d){  
    num[0]=a, num[1]=b, num[2]=c, num[3]=d; 
  }

};

int source[MAX_WHEEL], target[MAX_WHEEL];
int nBadList;
int badList[10000][MAX_WHEEL];

void read(){
  
  for(int i=0;i<MAX_WHEEL;i++)
    cin >> source[i];

  for(int i=0;i<MAX_WHEEL;i++)
    cin >> target[i];
  
  cin >> nBadList;
  for(int i=0;i<nBadList;i++)
    for(int j=0;j<MAX_WHEEL;j++)
      cin >> badList[i][j];
  
}

void bfs(){
  
  queue<Element> Q;
  int visited[MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM];
  
  for(int i=0;i<MAX_NUM;i++)
    for(int j=0;j<MAX_NUM;j++)
      for(int k=0;k<MAX_NUM;k++)
	for(int l=0;l<MAX_NUM;l++)
	  visited[i][j][k][l]=10000;
  
  for(int i=0;i<nBadList;i++)
    visited[badList[i][0]][badList[i][1]][badList[i][2]][badList[i][3]]=-1;
  
  Q.push(Element(source[0],source[1],source[2],source[3]));
  visited[source[0]][source[1]][source[2]][source[3]] = 0;
  
  while(!Q.empty()){
    
    Element curr=Q.front();
    Q.pop();

    if(curr.num[0]==target[0] && curr.num[1]==target[1] &&
       curr.num[2]==target[2] && curr.num[3]==target[3])      
      break;
    
       

    for(int i=0;i<MAX_WHEEL;i++){
      Element next=curr;
      
      next.num[i]=(next.num[i]+1)%MAX_NUM;
      
      if(visited[next.num[0]][next.num[1]][next.num[2]][next.num[3]]>
	 visited[curr.num[0]][curr.num[1]][curr.num[2]][curr.num[3]]+1){
	visited[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=
	  visited[curr.num[0]][curr.num[1]][curr.num[2]][curr.num[3]]+1;
	Q.push(next);
      }
      
     
      next.num[i]=(next.num[i]+MAX_NUM-1)%MAX_NUM;
      next.num[i]=(next.num[i]+MAX_NUM-1)%MAX_NUM;
      
      if(visited[next.num[0]][next.num[1]][next.num[2]][next.num[3]]>
	 visited[curr.num[0]][curr.num[1]][curr.num[2]][curr.num[3]]+1){
	visited[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=
	  visited[curr.num[0]][curr.num[1]][curr.num[2]][curr.num[3]]+1;
	Q.push(next);
      }
    }
        
  }
  
  if(visited[target[0]][target[1]][target[2]][target[3]]==10000 ||
       visited[target[0]][target[1]][target[2]][target[3]]==-1){
    cout << -1 << endl;
  }
  else 
    cout << visited[target[0]][target[1]][target[2]][target[3]] << endl;
  
}

void work(){
  
  bfs();

}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
