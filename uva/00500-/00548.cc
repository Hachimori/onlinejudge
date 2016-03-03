// tree
//
// 
// inorder   では、子1、親、子2の順番にノードをたどる。
// postorder では、子1、子2、親の順番にノードをたどる。
// 
// なので、[left,right] の範囲において postorder[right-1] は親のidである。
// 
// 親のidがわかったら inorder の親のindexがわかるので、
// inorder の探索範囲は [left,parentIdx], [parentIdx+1,right] に分けられる。
// 
// また、左の子の数も分かるので
// postorder の探索範囲は [left,left+nChild], [left+nChild,right-1] に分けられる。
//
// 
// 例:
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
// step1: inorder範囲 [0,7]  postorder範囲 [0,7]
//        postorder[6]が親のノード。inorderは親のindexから右と左に分けて探索。
//　　　　postorderは左の子のノード数と右の子のノード数に分けて探索。
//
//        inorder範囲 [0,3]  postorder範囲 [0,3] と
//        inorder範囲 [4,7]  postorder範囲 [3,6] に分けられる。
// 
//        次の親のノードが判明したら現在の親ノードと、次の親ノードを繋げる。
//
//
// step2: inorder範囲 [0,3]  postorder範囲 [0,3]           in:   [3 2 1] 4 5 7 6
//        inorder範囲 [0,1]  postorder範囲 [0,1] と        post: [3 1 2] 5 6 7 4
//        inorder範囲 [2,3]  postorder範囲 [1,2] に分ける。
//        2は親である。
//
//
// step3: inorder範囲 [0,1]  postorder範囲 [0,1]           in:   [3] 2 1 4 5 7 6
//        探索打ち切り。                                   post: [3] 1 2 5 6 7 4
//
// step4: inorder範囲 [2,3]  postorder範囲 [1,2]           in:   3 2 [1] 4 5 7 6
//        探索打ち切り。                                   post: 3 [1] 2 5 6 7 4
//
// step5: inorder範囲 [4,7]  postorder範囲 [3,6]           in:   3 2 1 4 [5 7 6]
//        inorder範囲 [4,5]  postorder範囲 [3,4] と        post: 3 1 2 [5 6 7] 4
//        inorder範囲 [6,7]  postorder範囲 [4,5] に分ける。
//        7は親である。
//
// step6: inorder範囲 [4,5]  postorder範囲 [3,4]           in:   3 2 1 4 [5] 7 6
//        探索打ち切り。                                   post: 3 1 2 [5] 6 7 4
//        
// step7: inorder範囲 [6,7]  postorder範囲 [4,5]           in:   3 2 1 4 5 7 [6]
//        探索打ち切り。                                   post: 3 1 2 5 [6] 7 4

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
