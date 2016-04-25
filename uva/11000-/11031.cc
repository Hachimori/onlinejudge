#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define BUF 10005
#define INF (1<<30)
using namespace std;

class Node{
public:
  int val, id, prev;

  Node(){}
  Node(int v, int i, int p): val(v), id(i), prev(p){}

  bool operator< (const Node &n) const {
    return val<n.val;
  }
};

int nNum, nQuery, num[BUF], query[BUF];

bool read(){
  scanf("%d%d",&nNum,&nQuery);
  if(nNum==0 && nQuery==0) return false;
  
  for(int i=0;i<nNum;i++)
    scanf("%d",&num[i]);

  for(int i=0;i<nQuery;i++)
    scanf("%d",&query[i]);
  
  return true;
}

// lower_bound
int bisect(Node seq[], int l, int r, int toCmp){
  swap(r,l);

  while(true){
    int mid = (l+r)/2;

    if(mid==r){
      if(seq[mid].val<=toCmp) 
	l = r;
      else
	r = mid;
	
      break;
    }
    else{
      if(seq[mid].val<=toCmp)
	l = mid;
      else
	r = mid;
    }
  }

  return l;
}

void LIS(Node node[], Node seq[], int &tail){
  node[0] = seq[tail] = Node(num[0],0,-1);
  tail++;
  
  for(int i=1;i<nNum;i++){
    int pos = bisect(seq,0,tail,num[i]);
    
    if(pos==tail){
      node[i] = seq[tail] = Node(num[i],i,seq[tail-1].id);
      tail++;
    }
    else if(pos==0)
      node[i] = seq[0] = Node(num[i],i,-1);
    else
      node[i] = seq[pos] = Node(num[i],i,seq[pos-1].id);
  }
}

int getLeng(int curr, Node node[], int leng[]){
  if(curr==-1) return 0;
  if(leng[curr]!=-1) return leng[curr];
  return leng[curr] = getLeng(node[curr].prev,node,leng)+1;  
}

void work(int cases){
  int tail = 0;
  Node node[BUF], seq[BUF];
  
  reverse(num,num+nNum);
  LIS(node,seq,tail);
  
  int leng[BUF];
  fill(leng,leng+nNum,-1);
  
  for(int i=0;i<nNum;i++)
    getLeng(i,node,leng);
  
  printf("Set %d:\n",cases);
  for(int i=0;i<nQuery;i++){
    printf("  Subset %d:\n",i+1);
    
    if(tail<query[i])
      printf("    Impossible\n");
    else{
      int ans[BUF], cur = 0;
      for(int j=nNum-1;j>=0;j--){
	if(leng[j]<query[i]-cur || (cur!=0 && ans[cur-1]>=num[j])) continue;
	ans[cur++] = num[j];
      }

      printf("   ");
      for(int j=0;j<query[i];j++)
	printf(" %d",ans[j]);
      printf("\n");
    }
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
