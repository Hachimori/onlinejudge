// ad-hoc
// 
// 
// ��蕶���A"each vertex is an endpoint of exactly 
// one horizontal edge and one vertical edge" �Ƃ��邩��A
// ���ꂼ��̒��_�͕K�����p�`�̊p�̕����ƂȂ�B
//
// ����āA����x���W��ɂ���_�������猩�Ă����ƁA
// �ӂł��镔���ƁA�ӂłȂ����������݂Ɍ����ƍl������B
// x���W�Ń\�[�g���ē�����ӂƁAy���W�Ń\�[�g���ē�����ӂ̘a�������ƂȂ�B
// 
// ���̎��A����x���W��Ɋ�̓_�����ꂽ�瑽�p�`���\���ł��Ȃ��̂ŁA
// -1���o�͂���B
//
// ����ɉ����āA�_�̌q������O���t�ŕ\�����đS�Ă̒��_���q�����Ă��邩�ǂ���
// ���ׂ�K�v������B
// 

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#define POINT 100005

using namespace std;

class Point{
public:
  int x, y, id;

  bool operator< (const Point &p) const {
    if(x!=p.x) return x<p.x;
    return y<p.y;
  }
};

int nPoint;
Point pt[POINT];

void read(){
  cin >> nPoint;
  for(int i=0;i<nPoint;i++){
    scanf("%d%d",&pt[i].x,&pt[i].y);
    pt[i].id = i;
  }
}

void dfs(int curr, bool visited[], vector<int> adj[]){
  visited[curr] = true;

  for(int i=0;i<adj[curr].size();i++){
    if(visited[adj[curr][i]]) continue;
    dfs(adj[curr][i],visited,adj);
  }
}

void work(){
  static vector<int> adj[POINT];
  
  if(nPoint%2==1){
    cout << -1 << endl;
    return;
  }
  
  for(int i=0;i<nPoint;i++)
    adj[i].clear();
  
  int cnt = 0;
  for(int k=0;k<2;k++){
    sort(pt,pt+nPoint);
    
    for(int i=0;i<nPoint;i++){
      int j = i;
      for(;j<nPoint && pt[j].x==pt[i].x;j++)
	if((j-i)%2){ 
	  cnt += pt[j].y-pt[j-1].y;
	  adj[pt[j  ].id].push_back(pt[j-1].id);
	  adj[pt[j-1].id].push_back(pt[j  ].id);
	}

      if((j-i)%2) {
	cout << -1 << endl;
	return;
      }
      i = j-1;
    }
    
    for(int i=0;i<nPoint;i++)
      swap(pt[i].x,pt[i].y);
  }
  
  bool visited[POINT];
  for(int i=0;i<nPoint;i++) visited[i] = false;

  dfs(0,visited,adj);
  
  for(int i=0;i<nPoint;i++)
    if(!visited[i]){
      cout << -1 << endl;
      return;
    }
  
  cout << cnt << endl;
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
