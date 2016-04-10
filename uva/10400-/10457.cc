// $BLdBjJ8$G$O!"F;O)$rEO$k:]$K<V$N%9%T!<%I$rD4@0$7$J$/$F$O$J$i$J$$(B
// $B$H$$$&$h$&$J5-=R$,$"$k$,!"$3$3$G$O8+J}$r>/$7JQ$($F!"(B
// $B0lHV:G=i$K<V$N%9%T!<%I$N>e8B$H2<8B$r$-$a$F!"B.EY@)8B$N0z$C$+$+$i$J$$(B
// $BF;O)$N$_DL2a2DG=$H$7!"$3$NLdBj$NL\E*$r<V$N%9%T!<%I$N>e8B$H2<8B$r5a$a$k(B
// $B$H$$$&$b$N$K2!$79~$a$k!#:G=*E*$J%3%9%H$r2<8B$H>e8B$N:9(B+init+stop$B$H$9$k!#(B
//
// init,stop: $BF~NO$GM?$($i$l$kDj?t(B
//
// 
// $B$^$:!"HO0O$N:GBgCM$rFsJ,K!$G5a$a$k!#%9%T!<%I$N2<8B$r$=$l$^$G$K8=$l$?(B
// $BB.EY@)8B$N:G>.CM$H$7!">e8B$r$=$N:GBgCM$H$9$k!#<V$,M?$($i$l$?(B
// $BHO0O$GDL2a$G$-$?$i>e8B$r8:$i$7!"DL2a$G$-$J$1$l$P2<8B$rA}$d$9!#(B
//
// $B$3$N$h$&$K$7$F5a$a$i$l$k$N$,HO0O$N:GBgCM$G$"$j!"<!$K$3$NHO0O$r(B
// $B69$a$F$$$/!#(B
// 
// 
// $B$^$:%9%T!<%I$NHO0O$N2<8B$O(Bfor$B%k!<%W$G7h$a$F$$$/!"(B
// $B>e8B$O2<8B$NCM(B+($B0JA0$K5a$a$?HO0O(B)$B$N(Bupper_bound$B$G$b$H$a$k!#(B
//
// $B$J$<!"$3$N$h$&$K@_Dj$9$k$N$+$H$$$&$H!"0JA0$K5a$a$?HO0O$h$j(B
// $B69$/$7$J$$$H!"$=$NHO0O$r99?7$G$-$J$$$N$G!#(B
//
// bfs$B$GDL2a2DG=$J$i$P=y!9$K>e8B$r69$a$F$$$/!#(B
//
// 
// $BHO0O$,=y!9$K>.$5$/$J$C$F$$$/$N$G!"(Bbfs$B$r$9$k2s?t$,>/$J$/$J$C$F$f$-!#(B
// $B2r$K6a$E$$$F$f$/!#(B

#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
#define NODE 205
#define EDGE 1000
#define QUERY 10
using namespace std;

class Edge{
public:
  int dst, fix;

  Edge(){}
  Edge(int d, int f): dst(d), fix(f){}
};

int nNode, nQuery;
vector<Edge> adj[NODE];
pair<int,int> query[QUERY];   // src, dst
int init, stop;

bool read(){
  int nEdge;
  if(!(cin >> nNode >> nEdge)) return false;
  
  for(int i=0;i<nNode;i++)
    adj[i].clear();

  for(int i=0;i<nEdge;i++){
    int src, dst, fix;
    cin >> src >> dst >> fix;
    src--, dst--;
    
    adj[src].push_back(Edge(dst,fix));
    adj[dst].push_back(Edge(src,fix));
  }
  
  cin >> init >> stop;
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i].first >> query[i].second;
    query[i].first--, query[i].second--;
  }
  
  return true;
}

bool bfs(int src, int dst, int low, int up){
  static bool visited[NODE];
  queue<int> Q;
  
  fill(visited,visited+nNode,false);
  Q.push(src);
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    
    if(curr==dst) return true;
    
    for(int i=0;i<adj[curr].size();i++){
      int next = adj[curr][i].dst, fix = adj[curr][i].fix;
      if(visited[next]) continue;
      if(!(low<=fix && fix<=up)) continue;
      visited[next] = true;
      Q.push(next);
    }
  }

  return false;
}

int calcUpperBound(pair<int,int> query, int fix[], int nFix){
  int l = 0, r = nFix-1;
 
  while(l!=r){
    int mid = (l+r)/2;
    if(bfs(query.first,query.second,fix[l],fix[mid]))
      r = mid;
    else{
      if(l==mid)
	l = mid+1;
      else
	l = mid;
    }
  }
  
  return fix[l];
}

void work(){
  set<int> S;
  for(int i=0;i<nNode;i++)
    for(int j=0;j<adj[i].size();j++)
      S.insert(adj[i][j].fix);

  int fix[EDGE], nFix = 0;
  for(set<int>::iterator i=S.begin();i!=S.end();i++)
    fix[nFix++] = *i;
  
  for(int i=0;i<nQuery;i++){
    int ans = calcUpperBound(query[i],fix,nFix);
    
    for(int lBound=0;lBound<nFix;lBound++){
      int l = lBound, r = upper_bound(fix,fix+nFix,fix[lBound]+ans)-fix-1;
      
      while(l<=r && bfs(query[i].first,query[i].second,fix[l],fix[r])){
	ans = min(ans,fix[r]-fix[l]);
	r--;
      }
    }
    
    cout << ans+init+stop << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
