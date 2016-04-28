#include<iostream>
#include<algorithm>
#define VAL 200005
#define SHIFT (VAL/2)
#define BUF (VAL*4)
#define QUERY 100005
#define SEQ 100005
#define INF (1<<20)
using namespace std;

class Tree{
public:
  int v[BUF];

  void init(int L, int R, int node, int val[VAL]){
    if(L==R){
      v[node] = val[L];
      return;
    }

    init(L,(L+R)/2,node*2+1,val);
    init((L+R)/2+1,R,node*2+2,val);

    v[node] = max(v[node*2+1],v[node*2+2]);
  }

  int get(int L, int R, int node, int Lq, int Rq){
    if(Lq<=L && R<=Rq) return v[node];
    if(R<Lq || Rq<L) return 0;

    int A = get(L,(L+R)/2,node*2+1,Lq,Rq);
    int B = get((L+R)/2+1,R,node*2+2,Lq,Rq);

    return max(A,B);
  }
};

int seq[SEQ], bgn[VAL], end[VAL], val[VAL], nQuery, query[QUERY][2];

bool read(){
  for(int i=0;i<VAL;i++){
    val[i] = 0;
    bgn[i] = INF;
    end[i] = -INF;
  }

  int nSeq;
  cin >> nSeq;
  if(nSeq==0) return false;
  cin >> nQuery;

  for(int i=0;i<nSeq;i++){
    cin >> seq[i];
    seq[i] += SHIFT;
    val[seq[i]]++;
    bgn[seq[i]] = min(bgn[seq[i]],i);
    end[seq[i]] = max(end[seq[i]],i);
  }
  
  for(int i=0;i<nQuery;i++){
    cin >> query[i][0] >> query[i][1];
    query[i][0]--;
    query[i][1]--;
  }

  return true;
}

void work(){
  static Tree tree;
  tree.init(0,VAL-1,0,val);;
  
  for(int i=0;i<nQuery;i++){
    int L = query[i][0], R = query[i][1];

    if(seq[L]==seq[R]){
      cout << R-L+1 << endl;
    }
    else{
      int v = max(end[seq[L]]-L+1,R-bgn[seq[R]]+1);
      cout << max(v,tree.get(0,VAL-1,0,seq[L]+1,seq[R]-1)) << endl;
    }
  }
}

int main(){
  while(read())
    work();

  return 0;
}
