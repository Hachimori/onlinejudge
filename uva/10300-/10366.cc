#include<iostream>
#include<vector>
#include<algorithm>
#define bar(x) __bar[x+SHIFT]
#define water(x) __water[x+SHIFT]
using namespace std;
const int BUF = 4010, SHIFT = BUF/2, INF = 1<<30;

class Node{
public:
  int pre, xl, xr;
  vector<int> next;
  Node(){}
  Node(int p, int xl, int xr, vector<int> n):
    pre(p), xl(xl), xr(xr), next(n){}
};

int xLeft, xRight, __bar[BUF];
double  __water[BUF];

bool read(){
  cin >> xLeft >> xRight;
  if(xLeft==0 && xRight==0) return false;
  bar(xLeft-2) = INF;
  for(int i=xLeft;i<=xRight;i+=2)
    cin >> bar(i);
  for(int i=0;i<BUF;i++)
    __water[i] = 0;
  return true;
}

vector<int> getBottom(int cur, int nNode, Node tree[BUF]){
  Node &n = tree[cur];
  if(tree[cur].next.empty()) return vector<int>(1,cur);
  vector<int> ret;
  for(int i=0;i<tree[cur].next.size();i++){
    vector<int> t = getBottom(tree[cur].next[i],nNode,tree);
    ret.insert(ret.end(),t.begin(),t.end());
  }
  return ret;
}

void work(){
  int nNode = 0;
  double time = 0;
  Node tree[BUF];
  tree[nNode++] = Node(-1,-1,1,vector<int>());

  while(1){
    vector<int> bottom = getBottom(0,nNode,tree);
    for(int i=0;i<bottom.size();i++)
      if(tree[bottom[i]].xl<xLeft || tree[bottom[i]].xl==xRight){
        cout << (int)(time+0.5) << endl;
        return;
      }

    double minV = INF;
    for(int i=0;i<bottom.size();i++){ // 入れる水の量調べる
      Node &n = tree[bottom[i]];
      minV = min(minV,1.0*(n.xr-n.xl)*(min(bar(n.xl),bar(n.xr))-water(n.xl)));
    }
    for(int i=0;i<bottom.size();i++){ // 水を注ぐ
      Node &n = tree[bottom[i]];
      water(n.xl) += minV/(n.xr-n.xl);
    }
    time += minV*bottom.size();

    for(int i=0;i<bottom.size();i++){
      Node &n = tree[bottom[i]];
      if(min(bar(n.xl),bar(n.xr))!=water(n.xl)) continue;
      if(bar(n.xl)<bar(n.xr)){
        if(water(n.xl-2)==0){// 左に流せる余地あり。bottomの先にノード追加
          tree[nNode] = Node(bottom[i],n.xl-2,n.xl,vector<int>());
          n.next.push_back(nNode++);
        }
        else{             // 凹を埋めた。マージする
          if(n.pre==-1) continue;
          Node &pre = tree[n.pre];
          pre.xr = n.xr;
          pre.next.erase(find(pre.next.begin(),pre.next.end(),bottom[i]));
        }
      }
      else if(bar(n.xl)>bar(n.xr)){ // 右のバーが低い。
        if(water(n.xr)==0){ // 右に流せる余地あり。bottomの先にノード追加
          tree[nNode] = Node(bottom[i],n.xr,n.xr+2,vector<int>());
          n.next.push_back(nNode++);
        }
        else{             // 凹を埋めた。マージする
          if(n.pre==-1) continue;
          Node &pre = tree[n.pre];
          pre.xl = n.xl;
          pre.next.erase(find(pre.next.begin(),pre.next.end(),bottom[i]));
        }
      }
      else if(bar(n.xl)==bar(n.xr)){ // バーの高さが同じ。
        if(n.pre==-1){
          tree[nNode] = Node(bottom[i],n.xl-2,n.xl,vector<int>());
          n.next.push_back(nNode++);
          tree[nNode] = Node(bottom[i],n.xr,n.xr+2,vector<int>());
          n.next.push_back(nNode++);
          continue;
        }

        if(water(n.xr)==0){
          Node &pre = tree[n.pre];
          pre.xr = n.xr;
          n.xl = n.xr;
          n.xr += 2;
        }
        if(water(n.xl-2)==0){
          Node &pre = tree[n.pre];
          pre.xl = n.xl;
          n.xr = n.xl;
          n.xl -= 2;
        }
      }
    }
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
