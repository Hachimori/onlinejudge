// WA at uva
// AC at http://acm.hrbeu.edu.cn/index.php?act=problem&proid=6076
// AC at http://acm.cs.ecnu.edu.cn/problem.php?problemid=1576
//
// sample solution seems to be wrong
// input: http://contest.mff.cuni.cz/archive/spac1992/index.html

#include<iostream>
#include<queue>
using namespace std;
const int CANT = 10000, QUERY = 10000, INF = 1<<30;

class Road{
public:
  bool vert;
  int strt, aven, block;
  Road(){}
  Road(bool vert, int strt, int aven, int block): 
    vert(vert), strt(strt), aven(aven), block(block){}
};

class Data{
public:
  int dir, strt, aven, block;
  Data(){}
  Data(int d, int s, int a, int b): dir(d), strt(s), aven(a), block(b){}

  bool operator== (const Data &d) const {
    return dir==d.dir && strt==d.strt && aven==d.aven && block==d.block;
  }
};

const int db[] = {-2,-2,2,2};
int nCant, nQuery;
Road cant[CANT][2], query[QUERY][2];

bool read(){
  nCant = 0;
  while(1){
    char ch;
    if(!(cin >> ch)) return false;
    if(ch=='#') break;
    int avenOrStrt;
    cin >> avenOrStrt;
    for(int i=0;i<2;i++){
      int block;
      cin >> block;
      if(ch=='A')
        cant[nCant][i] = Road(true,block/100,avenOrStrt,block%100);
      else
        cant[nCant][i] = Road(false,avenOrStrt,block/100,block%100);
    }
    nCant++;
  }

  nQuery = 0;
  while(1){
    for(int i=0;i<2;i++){
      char ch;
      int id1, id2;
      cin >> ch;
      if(ch=='#') return true;
      cin >> id1 >> id2;
      if(ch=='A')
        query[nQuery][i] = Road(true,id2/100,id1,id2%100);
      else
        query[nQuery][i] = Road(false,id1,id2/100,id2%100);
    }
    nQuery++;
  }
  return true;
}

bool update(Data &next, Data &curr, queue<Data> &Q, 
            int visited[4][51][51][100], bool cantS[4][51][51][100]){
  if(next.aven<0 || next.strt<0 || 
     (next.aven==49 && next.dir==3) || (next.strt==49 && next.dir==2)) return false;
  
  if(!visited[next.dir][next.strt][next.aven][next.block]){
    visited[next.dir][next.strt][next.aven][next.block] = 
      visited[curr.dir][curr.strt][curr.aven][curr.block]+1;
    if(!cantS[next.dir][next.strt][next.aven][next.block]){
      Q.push(next);
      return true;
    }
    else{
      if(next.block==1 || next.block==98) return false;
      Data nnext = curr;
      nnext.dir = (curr.dir+2)%4;
      nnext.block -= db[curr.dir]/2;
      return update(nnext,curr,Q,visited,cantS);
    }
  }
  return false;
}

void bfs(Road pt[2]){
  static int visited[4][51][51][100];
  static bool cantS[4][51][51][100];
  queue<Data> Q;
  Data init, goal;
  
  memset(visited,0,sizeof(visited));
  memset(cantS,0,sizeof(cantS));
  
  for(int i=0;i<2;i++){
    Data &d = i==0 ? init : goal;
    int direct;
    if(pt[i].vert) direct = (pt[i].block%2==0)? 0 : 2;
    else direct = (pt[i].block%2==0) ? 1 : 3;
    d = Data(direct,pt[i].strt,pt[i].aven,pt[i].block);
  }
  
  if(init==goal){
    cout << 0 << endl;
    return;
  }

  for(int i=0;i<nCant;i++){
    Road &cant1 = cant[i][0], &cant2 = cant[i][1];
    if(cant1.vert){
      int bgn = cant1.strt*100+cant1.block, end = cant2.strt*100+cant2.block;
      if(bgn>end) swap(bgn,end);
      for(int j=bgn;j<=end;j++){
        cantS[0][j/100][cant1.aven][j%100] = true;
        cantS[2][j/100][cant1.aven][j%100] = true;
        if(j%2==0){
          cantS[0][j/100][cant1.aven][j%100+1] = true;
          cantS[2][j/100][cant1.aven][j%100+1] = true;
        }
        if(j%2==1){
          cantS[0][j/100][cant1.aven][j%100-1] = true;
          cantS[2][j/100][cant1.aven][j%100-1] = true;
        }
      }
    }
    else{
      int bgn = cant1.aven*100+cant1.block, end = cant2.aven*100+cant2.block;
      if(bgn>end) swap(bgn,end);
      for(int j=bgn;j<=end;j++){
        cantS[1][cant1.strt][j/100][j%100] = true;
        cantS[3][cant1.strt][j/100][j%100] = true;
        if(j%2==0){
          cantS[1][cant1.strt][j/100][j%100+1] = true;
          cantS[3][cant1.strt][j/100][j%100+1] = true;
        }
        if(j%2==1){
          cantS[1][cant1.strt][j/100][j%100-1] = true;
          cantS[3][cant1.strt][j/100][j%100-1] = true;
        }
      }
    }
  }

  Q.push(init);
  visited[init.dir][init.strt][init.aven][init.block] = 1;
  
  while(!Q.empty()){
    Data curr = Q.front();
    Q.pop();
    //cout << curr.dir << ' ' << curr.strt << ' ' << curr.aven << ' ' << curr.block << ' ' << 
    //    visited[curr.dir][curr.strt][curr.aven][curr.block] << endl;
    //cout << "f" << endl;
    if(curr==goal){
      cout << visited[curr.dir][curr.strt][curr.aven][curr.block]-2 << endl;
      return;
    }

    if(curr.block+db[curr.dir]<0 || 99<curr.block+db[curr.dir]){
      bool updated = false;
      for(int i=0;i<4;i++){
        if(i==2) continue;
        Data next = curr;
        if(next.dir%2==0 && 99<curr.block+db[curr.dir])
          next.strt++;
        else if(next.dir%2==1 && 99<curr.block+db[curr.dir])
          next.aven++;

        next.dir = (curr.dir+i)%4;
        switch(next.dir){
        case 0:
          next.block = 98;
          next.strt--;
          break;
        case 1:
          next.block = 98;
          next.aven--;
          break;
        case 2:
          next.block = 1;
          break;
        case 3:
          next.block = 1;
          break;
        }
        updated |= update(next,curr,Q,visited,cantS);
      }
      /*
      if(!updated){
        Data next = curr;
        next.dir = (next.dir+2)%4;
        next.block -= db[next.dir]/2;
        update(next,curr,Q,visited,cantS);
        }*/
    }
    else{
      Data next = curr;
      next.block += db[curr.dir];
      update(next,curr,Q,visited,cantS);
    }
  }
}

void work(){
  for(int i=0;i<nQuery;i++)
    bfs(query[i]);
}

int main(){
  while(read())
    work();
  return 0;
}
