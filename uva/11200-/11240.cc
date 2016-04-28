#include<iostream>
using namespace std;
const int BUF = 30005;

class SegTree{
public:
  int v[BUF*4];

  SegTree(){ 
    memset(v,0,sizeof(v));
  }
  
  int init(int node, int L, int R, int a[BUF]){
    if(L==R) return v[node] = a[L];
    int s = init(node*2+1,L,(L+R)/2,a);
    int t = init(node*2+2,(L+R)/2+1,R,a);
    return v[node] = max(s,t);
  }

  int get(int node, int L, int R, int LQ, int RQ){
    if(R<LQ || RQ<L) return -1;
    if(LQ<=L && R<=RQ) return v[node];
    int s = get(node*2+1,L,(L+R)/2,LQ,RQ);
    int t = get(node*2+2,(L+R)/2+1,R,LQ,RQ);
    return max(s,t);
  }
  
  int update(int node, int L, int R, int Q, int chVal){
    if(R<Q || Q<L) return v[node];
    if(L==R) return v[node] = chVal;
    int s = update(node*2+1,L,(L+R)/2,Q,chVal);
    int t = update(node*2+2,(L+R)/2+1,R,Q,chVal);
    return v[node] = max(s,t);
  }
};

int nVal, val[BUF];

void read(){
  cin >> nVal;
  for(int i=0;i<nVal;i++) cin >> val[i];
}

void work(){
  SegTree segtree[2];
  segtree[0] = SegTree();
  segtree[1] = SegTree();

  int ans = 0;
  
  for(int i=nVal-1;i>=0;i--){
    int t;

    t = segtree[1].get(0,0,nVal+1,val[i]+1,nVal+1)+1;
    segtree[0].update(0,0,nVal+1,val[i],t);
    
    t = segtree[0].get(0,0,nVal+1,0,val[i]-1)+1;
    segtree[1].update(0,0,nVal+1,val[i],t);    
    
    ans = max(ans,t);
  }

  cout << ans << endl;
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
