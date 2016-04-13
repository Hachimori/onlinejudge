// 10679
//
// aho-corasick
// O(n+m+z)
//
// n: 検索する全ての単語の文字数
// m: 文章の文字数
// z: queryが文章の中に現れる数
//
//
// http://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cassert>

#define MAX_BUF 100005
#define MAX_SIZE 1005

using namespace std;

class Node{
public:
  int next[256];
  int fail;
  vector<int> out;

  Node(){
    fill(next,next+256,0);
    out = vector<int>();
  }
};

int nQuery;
char src[MAX_BUF], query[MAX_SIZE][MAX_SIZE];

void read(){
  scanf("%s",src);
  
  cin >> nQuery;

  for(int i=0;i<nQuery;i++)
    scanf("%s",query[i]);
}

void construct(int nQ, char q[][MAX_SIZE], Node ret[]){
  int nNode = 1;
  ret[0] = Node();
  
  // Phase 1
  for(int i=0;i<nQ;i++){
    int curr = 0, leng = strlen(q[i]);
    
    for(int j=0;j<leng;j++){
      if(!ret[curr].next[q[i][j]]){
	ret[nNode] = Node();
	ret[curr].next[q[i][j]] = nNode++;
	assert(nNode!=10000);
      }
      curr = ret[curr].next[q[i][j]];
    }
    ret[curr].out.push_back(i);
  }

  // Phase 2
  queue<int> Q;
  ret[0].fail = 0;

  for(int i=0;i<256;i++){
    if(!ret[0].next[i]) continue;
    int toPush = ret[0].next[i];
    Q.push(toPush);
    ret[toPush].fail = 0;
  }

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
   
    for(int i=0;i<256;i++){
      int next = ret[curr].next[i];
      if(!next) continue;
      
      Q.push(next);
      
      int v = ret[curr].fail;
      while(!ret[v].next[i] && v)
	v = ret[v].fail;

      ret[next].fail = ret[v].next[i];
    }
  }
}

void work(){
  static Node trie[10000];
  
  construct(nQuery,query,trie);
  
  int cnt[MAX_SIZE], curr = 0;
  
  
  for(int i=0;i<nQuery;i++)
    cnt[i] = 0;
  
  int leng = strlen(src);
  for(int i=0;i<leng;i++){
    while(!trie[curr].next[src[i]] && curr)
      curr = trie[curr].fail;

    int next = trie[curr].next[src[i]];

    for(int j=0;j<trie[curr].out.size();j++)
      cnt[trie[curr].out[j]]++;

    for(int j=0;j<trie[next].out.size();j++)
      cnt[trie[next].out[j]]++;
    
    curr = next;
  }

  for(int i=0;i<nQuery;i++){
    if(cnt[i]==0) cout << 'n' << endl;
    else cout << 'y' << endl;
  }
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
