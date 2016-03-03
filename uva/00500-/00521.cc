// graph
//
// 
// �C�ӂ̓�l�̃h���C�o�[���A�����◯���ɗ��܂邩�ǂ������s��ŕ\���B
// ����m�[�h����n�߂ĕʂ̃m�[�h�֍s����Ƃ������Ƃ́A���̃h���C�o�[��
// �ʂ̃h���C�o�[�֎����̎��b���`������Ƃ������Ƃł���B
//
// �܂��A����h���C�o�[A���ʂ̃h���C�o�[B�֍s���܂łɒH�����A�h���C�o�[(C,D,E...)��
// ���b����ʂ̃h���C�o�[B�֓`���B����ɁA�h���C�o�[B�̎��b���
// �h���C�o�[(C,D,E....)��ʂ��ăh���C�o�[A�ɓ`���B
//
// �Ȃ̂ŁA���̍s����DFS�����Ă��ׂẴm�[�h��H��邩�ǂ����𒲂ׂ�Ƃ悢�B
//
//


#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cassert>

#define MAX_LINE 25
#define MAX_DRIVER 35

using namespace std;

class Driver{
public:
  int idx, line;

  Driver(){}
  Driver(int i, int l): idx(i), line(l){}
};

int nLine, nDriver, nStop;
vector<int> line[MAX_LINE];
Driver driver[MAX_DRIVER];

bool read(){
  cin >> nLine >> nDriver >> nStop;
  if(nLine==0 && nDriver==0 && nStop==0) return false;
  
  for(int i=0;i<nLine;i++)
    line[i].clear();
  
  string buf; getline(cin,buf);
  
  for(int i=0;i<nLine;i++){
    istringstream is;

    getline(cin,buf);
    is.str(buf);
    
    int stop;
    while(is >> stop)
      line[i].push_back(stop);
    
    getline(cin,buf);
    is.clear();
    is.str(buf);
    
    int id;
    while(is >> stop >> id){
      id--;
      for(int j=0;;j++)
	if(line[i][j]==stop){
	  driver[id] = Driver(j,i);
	  break;
	}
    }
  }

  return true;
}

bool willMeet(int a, int b){
  vector<int> aLine=line[driver[a].line], bLine=line[driver[b].line];
  
  int aOrigin=driver[a].idx, bOrigin=driver[b].idx; 
  int aCurr=(driver[a].idx+1)%aLine.size(), bCurr=(driver[b].idx+1)%bLine.size();
  
  if(aLine[aOrigin]==bLine[bOrigin]) return true;
  
  while(aOrigin!=aCurr || bOrigin!=bCurr){
    if(aLine[aCurr]==bLine[bCurr]) return true;
  
    aCurr = (aCurr+1)%aLine.size();
    bCurr = (bCurr+1)%bLine.size();
  }
  
  return false;
}

void dfs(int curr, int &nVisited, bool visited[], bool adjList[][MAX_DRIVER]){
  nVisited++;
  visited[curr] = true;
  
  for(int i=0;i<nDriver;i++){
    if(!adjList[curr][i]) continue;
    if(visited[i]) continue;

    dfs(i,nVisited,visited,adjList);
  }
}

void work(){
  bool adjList[MAX_DRIVER][MAX_DRIVER];
  
  for(int i=0;i<nDriver;i++)
    for(int j=0;j<nDriver;j++){
      if(i==j) adjList[i][j] = false;
      else adjList[i][j] = willMeet(i,j);
    }
  
  bool visited[MAX_DRIVER];
  int nVisited = 0;
  
  for(int i=0;i<nDriver;i++)
    visited[i] = false;
  dfs(0,nVisited,visited,adjList);
  
  if(nVisited==nDriver) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
