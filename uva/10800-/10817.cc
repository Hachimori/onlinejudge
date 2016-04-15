#include<iostream>
#include<string>
#include<vector>
#include<climits>

#define MAX_SUBJECT 8
#define MAX_BUF 7000
#define MAX_SIZE 120

using namespace std;

class Teacher{
public:
  
  int cost;
  vector<int> subjects;

  Teacher(){}
  Teacher(int c, vector<int> s): cost(c), subjects(s){}

};

int nSubject, nTeacher, nAppl;
int board[MAX_SIZE][MAX_BUF];
Teacher teacher[MAX_SIZE], appl[MAX_SIZE];

int makeIdx(int nAssigned[]){
  int ret=0;
  
  for(int i=0,p=1;i<nSubject;i++,p*=3)
    ret+=p*nAssigned[i];
  
  return ret;
}

vector<int> makeArray(int n){
  vector<int> ret;
  
  for(int i=0;i<8;i++,n/=3)
    ret.push_back(n%3);
  
  return ret;
}

void split(string buf, vector<int> &nList){
  int curr=0;
  
  while(curr<buf.size()){
    string toPush;
    
    while(curr<buf.size() && isspace(buf[curr])) curr++;
    while(curr<buf.size() && !isspace(buf[curr])){
      toPush+=buf[curr];
      curr++;
    }
    
    if(toPush.size()>0)
      nList.push_back(atoi(toPush.c_str())-1);
  }
}

bool read(){
  
  cin >> nSubject >> nTeacher >> nAppl;
  if(nSubject==0) return false;
  
  for(int i=0;i<nTeacher;i++){
    int cost;
    string buf;

    cin >> cost;
    getline(cin,buf);

    vector<int> nList;
    split(buf,nList);
    
    teacher[i] = Teacher(cost,nList);
  }
  
  for(int i=0;i<nAppl;i++){
    int cost;
    string buf;

    cin >> cost;
    getline(cin,buf);

    vector<int> nList;
    split(buf,nList);

    appl[i] = Teacher(cost,nList);
  }
  
  return true;
}

void knapsack(int board[][MAX_BUF]){
  
  for(int currId=0;currId<nAppl;currId++){

    for(int i=0;i<MAX_BUF;i++){
      if(board[currId][i]==INT_MAX) continue;
      
      if(board[currId+1][i]>board[currId][i]) board[currId+1][i]=board[currId][i];
      
      vector<int> state = makeArray(i);
      
      for(int k=0;k<appl[currId].subjects.size();k++){
	state[appl[currId].subjects[k]]++;
	if(state[appl[currId].subjects[k]]==3)
	  state[appl[currId].subjects[k]]=2;
      }
      
      int tmpArray[MAX_SUBJECT];
      for(int k=0;k<nSubject;k++)
	tmpArray[k] = state[k];
	
      int idx = makeIdx(tmpArray);
      if(board[currId+1][idx]>board[currId][i]+appl[currId].cost) 
	board[currId+1][idx]=board[currId][i]+appl[currId].cost;
    }
    
  }
  
}

void work(){
  
  int cost=0, nAssigned[MAX_SUBJECT];

  for(int i=0;i<nSubject;i++)
    nAssigned[i] = 0;
  
  for(int i=0;i<nTeacher;i++){
    for(int k=0;k<teacher[i].subjects.size();k++){
      nAssigned[teacher[i].subjects[k]]++;
      if(nAssigned[teacher[i].subjects[k]]==3)
	nAssigned[teacher[i].subjects[k]]=2;
    }
    cost+=teacher[i].cost;
  }
 
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_BUF;j++)
      board[i][j] = INT_MAX;
 
  board[0][makeIdx(nAssigned)] = cost;
  
  knapsack(board);
  
  int idx=0;
  for(int i=0,p=1;i<nSubject;i++,p*=3)
    idx+=p*2;
  
  cout << board[nAppl][idx] << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
