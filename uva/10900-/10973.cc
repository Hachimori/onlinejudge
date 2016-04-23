// ����m�[�h����L�тĂ���C�ӂ�2�̃G�b�W�ɒ��ڂ���B
// 
// ���̓�̃G�b�W�ɐL�тĂ�����2���_���G�b�W�Ōq�����Ă�����cnt++
// 
// src<dst�̂Ƃ��݂̂ɃG�b�W���q���悤�ɂ���ƎO�p�`���d������
// �����邱�Ƃ͂Ȃ��Ȃ�B
//
// ��蕶�� "You are assured that there is no edge in this graph that is 
// the member of more than 2 triangles." �Ƃ���A�O�p�`�̐���
// ����قǑ����͂Ȃ��Ǝv����̂ŁAbruteforce��I�������B


#include<iostream>
#include<algorithm>
#include<cstdio>
#define NODE 3005
using namespace std;

int nNode, nEdge, tail[NODE];
short adj[NODE][NODE];
bool connect[NODE][NODE];

void read(){
  scanf("%d%d",&nNode,&nEdge);
  
  for(int i=0;i<nNode;i++){
    tail[i] = 0;
    for(int j=i;j<nNode;j++)
      connect[i][j] = false;
  }

  for(int i=0;i<nEdge;i++){
    int src, dst;
    scanf("%d%d",&src,&dst);
    src--, dst--;
    if(src>dst) swap(src,dst);
    adj[src][tail[src]++] = dst;
    connect[src][dst] = connect[dst][src] = true;
  }
}

void work(){
  int ans = 0;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<tail[i];j++)
      for(int k=j+1;k<tail[i];k++)
	ans += connect[adj[i][j]][adj[i][k]];

  printf("%d\n",ans);
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
