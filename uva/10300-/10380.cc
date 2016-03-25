#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstdio>
#define MAN 55
#define NODE 1300
#define INF (1<<20)
using namespace std;

int nNode, nMan, id, SRC, DST, cap[NODE][NODE], nRule, rule[MAN][MAN];
char str[MAN][MAN][4];

void read(){
  cin >> nMan >> id;
  id--;

  nRule = 0;
  for(int i=0;i<nMan;i++)
    for(int j=i+1;j<nMan;j++)
      if(i!=j){
        rule[i][j] = nMan+nRule;
        rule[j][i] = nMan+nRule;
        nRule++;
      }

  nNode = nRule+nMan+2;
  SRC = nNode-2;
  DST = nNode-1;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      cap[i][j] = 0;
  
  for(int i=0;i<nMan;i++)
    for(int j=0;j<nMan;j++)
      if(i!=j)
	cap[i][rule[i][j]] = 2;     // ‚»‚ê‚¼‚ê‚Ì‘Iè‚Í‡‚É‚ÄÅ‘å“ñ‰ñŸ‚Ä‚é

  for(int i=0;i<nMan;i++)
    cap[SRC][i] = 0;
  cap[SRC][id] = (nMan-1)*2;

  for(int i=0;i<nRule;i++)
    cap[i+nMan][DST] = 2;     // ‡‚Í2‰ñ‚Ì‚İs‚í‚ê‚é

  for(int i=0;i<nMan;i++){
    for(int j=0;j<=i;j++)
      scanf("%s",str[i][j]);

    for(int j=i+1;j<nMan;j++){
      scanf("%s",str[i][j]);
      
      for(int k=0;k<2;k++){
	if(str[i][j][k]=='0'){
	  cap[SRC][j]--;
	  cap[j][rule[i][j]]--;
	  cap[rule[i][j]][DST]--;
	}
	if(str[i][j][k]=='1'){
	  cap[SRC][i]--;
	  cap[i][rule[i][j]]--;
	  cap[rule[i][j]][DST]--;
	}
      }
    }
  }
}

int aug(int pi[]){
  queue<int> Q;
  
  for(int i=0;i<nNode;i++) pi[i] = -1;
  pi[SRC] = -2;
  Q.push(SRC);
  
  while(!Q.empty() && pi[DST]==-1){
    int curr = Q.front();
    Q.pop();
    
    for(int i=0;i<nNode;i++){
      int next;
      if(i==0) next = id;
      else if(i==id) next = 0;
      else next = i;
      //if(curr==SRC )cout << "B" << curr << ' ' << i << ' ' << (int) cap[curr][i] << endl;
      if(cap[curr][next]<=0 || pi[next]!=-1) continue;
      //if(curr==SRC)cout << "A " << curr << ' ' << i << ' ' << (int)cap[curr][i] << endl;
      

      pi[next] = curr;
      Q.push(next);
    }
  }
  
  return pi[DST]!=-1;
}

int maxFlow(int limit){
  for(int i=0;i<nMan;i++)
    if(i!=id)
      cap[SRC][i] += limit;

  int pi[NODE];
  while(aug(pi)){
/*
    char amt = INF;
    for(int i=DST;pi[i]>=0;i=pi[i]) amt = min(amt,cap[pi[i]][i]);

    for(int i=DST;pi[i]>=0;i=pi[i]){
      cap[pi[i]][i] -= amt;
      cap[i][pi[i]] += amt;
    }
*/
    
    for(int z=0;z<nNode;z++){
      if(cap[z][DST]<=0 || pi[z]==-1) continue;
      
      int bot = cap[z][DST];
      for(int v=z,u=pi[v];u>=0;v=u,u=pi[v])
	bot <?= cap[u][v];
      if(bot<=0) continue;
      
      cap[z][DST] -= bot;
      cap[DST][z] += bot;
      for(int v=z,u=pi[v];u>=0;v=u,u=pi[v]){
	cap[u][v] -= bot;
	cap[v][u] += bot;
      }
    }
  }
  
  /*
    for(int i=0;i<nMan;i++)
    cout << "cap:" << (int)cap[SRC][i] << ' ' << endl;
  cout << endl;
  */
  for(int i=0;i<nRule;i++)
    if(cap[i+nMan][DST]>0)
      return -INF;

  
  // id ‚ªŸ‚Á‚½‰ñ” - max(‘¼‚Ìl‚ª”ƒ‚Á‚½‰ñ”)
  int ret = (nMan-1)*2-cap[SRC][id], score = ret;
  
  for(int i=0;i<nMan;i++){
    if(i==id) continue;
    int sum = 0;
    for(int j=0;j<nMan;j++)
      if(i!=j)
	sum += 2-cap[i][rule[i][j]];

    ret = min(ret,score-sum);
  }
  
  //cout << ret << ' ' << score << ' ' << limit << endl;
  return ret; 
}

void print(int ans){
  cout << "Player " << id+1 << " can win with " << ans << " point(s)." << endl;
  cout << endl;
  
  for(int i=0;i<nMan;i++)
    for(int j=i+1;j<nMan;j++){
      if(str[i][j][0]=='-'){
	switch(cap[i][rule[i][j]]){
	case 2:
	  str[i][j][0] = '0';
	  str[j][i][0] = '1';
	  break;
	case 1:
	  if(str[i][j][1]=='-' || str[i][j][1]=='0'){
	    str[i][j][0] = '1';
	    str[j][i][0] = '0';
	    cap[i][rule[i][j]]++;
	  }
	  else {
	    str[i][j][0] = '0';
	    str[j][i][0] = '1';
	  }
	  break;
	case 0:
	  str[i][j][0] = '1';
	  str[j][i][0] = '0';
	  cap[i][rule[i][j]]++;
	  break;
	default:
	  //cout << ":::" << endl;
	  break;
	}
      }
      else if(str[i][j][0]=='1')
	cap[i][rule[i][j]]++;

      if(str[i][j][1]=='-'){
	switch(cap[i][rule[i][j]]){
	case 2:
	  str[i][j][1] = '0';
	  str[j][i][1] = '1';
	  break;
	case 1:
	case 0:
	  str[i][j][1] = '1';
	  str[j][i][1] = '0';
	  cap[i][rule[i][j]]++;
	  break;
	default:
	  //cout << ":::" << endl;
	  break;
	}
      }
    }
      
  for(int i=0;i<nMan;i++){
    int sum = 0;
    for(int j=0;j<nMan;j++){
      cout << str[i][j] << ' ';
      if(i!=j) sum += str[i][j][0]-'0'+str[i][j][1]-'0';
    }
    cout << ": " << sum << endl;
  }
}

void work(){
  static char backup[NODE][NODE];
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      backup[i][j] = cap[i][j];
  
  int L = 0, R = 2*nMan;
  
  while(L!=R){
    int mid = (R+L)/2, ret = maxFlow(mid);

    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
	cap[i][j] = backup[i][j];

    if(ret==-INF){
      if(L==mid) 
	L++;
      else 
	L = mid;
    }
    else 
      R = mid;
  }
  
  int ret = maxFlow(L);
  
  if(ret>=0)
    print(ret);
  else
    cout << "Player " << id+1 << " can't win!" << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }

  return 0;
}
