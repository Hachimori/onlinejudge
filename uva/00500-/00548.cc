// tree
//
// 
// inorder   �ł́A�q1�A�e�A�q2�̏��ԂɃm�[�h�����ǂ�B
// postorder �ł́A�q1�A�q2�A�e�̏��ԂɃm�[�h�����ǂ�B
// 
// �Ȃ̂ŁA[left,right] �͈̔͂ɂ����� postorder[right-1] �͐e��id�ł���B
// 
// �e��id���킩������ inorder �̐e��index���킩��̂ŁA
// inorder �̒T���͈͂� [left,parentIdx], [parentIdx+1,right] �ɕ�������B
// 
// �܂��A���̎q�̐���������̂�
// postorder �̒T���͈͂� [left,left+nChild], [left+nChild,right-1] �ɕ�������B
//
// 
// ��:
//
//      4
//    /   \
//   2     7
//  / \   / \
// 3  1  5   6
//
// inorder:   3 2 1 4 5 7 6
// postorder: 3 1 2 5 6 7 4
//
// 
// step1: inorder�͈� [0,7]  postorder�͈� [0,7]
//        postorder[6]���e�̃m�[�h�Binorder�͐e��index����E�ƍ��ɕ����ĒT���B
//�@�@�@�@postorder�͍��̎q�̃m�[�h���ƉE�̎q�̃m�[�h���ɕ����ĒT���B
//
//        inorder�͈� [0,3]  postorder�͈� [0,3] ��
//        inorder�͈� [4,7]  postorder�͈� [3,6] �ɕ�������B
// 
//        ���̐e�̃m�[�h�����������猻�݂̐e�m�[�h�ƁA���̐e�m�[�h���q����B
//
//
// step2: inorder�͈� [0,3]  postorder�͈� [0,3]           in:   [3 2 1] 4 5 7 6
//        inorder�͈� [0,1]  postorder�͈� [0,1] ��        post: [3 1 2] 5 6 7 4
//        inorder�͈� [2,3]  postorder�͈� [1,2] �ɕ�����B
//        2�͐e�ł���B
//
//
// step3: inorder�͈� [0,1]  postorder�͈� [0,1]           in:   [3] 2 1 4 5 7 6
//        �T���ł��؂�B                                   post: [3] 1 2 5 6 7 4
//
// step4: inorder�͈� [2,3]  postorder�͈� [1,2]           in:   3 2 [1] 4 5 7 6
//        �T���ł��؂�B                                   post: 3 [1] 2 5 6 7 4
//
// step5: inorder�͈� [4,7]  postorder�͈� [3,6]           in:   3 2 1 4 [5 7 6]
//        inorder�͈� [4,5]  postorder�͈� [3,4] ��        post: 3 1 2 [5 6 7] 4
//        inorder�͈� [6,7]  postorder�͈� [4,5] �ɕ�����B
//        7�͐e�ł���B
//
// step6: inorder�͈� [4,5]  postorder�͈� [3,4]           in:   3 2 1 4 [5] 7 6
//        �T���ł��؂�B                                   post: 3 1 2 [5] 6 7 4
//        
// step7: inorder�͈� [6,7]  postorder�͈� [4,5]           in:   3 2 1 4 5 7 [6]
//        �T���ł��؂�B                                   post: 3 1 2 5 [6] 7 4

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

#define INF 1000000
#define MAX_SIZE 10005

using namespace std;

class Node{
public:

  int parent;
  vector<int> child;

  Node(){}
};

int nNode;
vector<int> inOrder, postOrder;

bool read(){
  istringstream is;
  string buf;
  
  inOrder.clear();
  postOrder.clear();
  
  if(getline(cin,buf)==NULL) return false;
  is.str(buf);
  
  int num;
  while(is >> num) inOrder.push_back(num);
  
  getline(cin,buf);
  is.clear();
  is.str(buf);
  while(is >> num) postOrder.push_back(num);

  nNode = inOrder.size();
  
  return true;
}

void rec(int inL, int inR, int postL, int postR, Node adjList[], int prevParent){
  if(inL==inR) return;
  if(inL+1==inR){
    if(prevParent!=-1)
      adjList[prevParent].child.push_back(inL);
    adjList[inL].parent = prevParent;
    return;
  }

  int parentId = postOrder[postR-1];
  int parentIdx, nLeftChild=0;
  
  for(int i=inL;i<inR;i++)
    if(inOrder[i]==parentId){
      parentIdx = i;
      break;
    }
    else
      nLeftChild++;
 
  if(prevParent!=-1)
    adjList[prevParent].child.push_back(parentIdx);
  adjList[parentIdx].parent = prevParent;
  
  
  rec(inL,parentIdx, postL,postL+nLeftChild, adjList,parentIdx);
  
  rec(parentIdx+1,inR, postL+nLeftChild,postR-1, adjList,parentIdx);
  
}

void dfs(int curr, int cost, int &minCost, int &minVal, Node adjList[]){
  if(adjList[curr].child.size()==0){
    if(minCost>cost + inOrder[curr]){
      minCost = cost + inOrder[curr];
      minVal = inOrder[curr];
    }
    else if(minCost==cost+inOrder[curr] && minVal>inOrder[curr])
      minVal = inOrder[curr];
    
    return;
  }
  
  for(int i=0;i<adjList[curr].child.size();i++)
    dfs(adjList[curr].child[i],cost+inOrder[curr],minCost,minVal,adjList);

}

void work(){
  Node adjList[MAX_SIZE];
  
  rec(0,nNode,0,nNode,adjList,-1);
  
  int start, minCost = INF, minVal = INF;
  for(int i=0;i<nNode;i++)
    if(adjList[i].parent==-1){
      start = i;
      break;
    }

  dfs(start,0,minCost,minVal,adjList);
  
  cout << minVal << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
