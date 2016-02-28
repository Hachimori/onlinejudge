#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int SZ = 8, QUERY = 10000;

enum State{BLACK='B',WHITE='W',NONE='-'};

char turn, b[SZ][SZ];
int nQuery;
string query[QUERY];

void read(){
  for(int i=0;i<SZ;i++)
    for(int j=0;j<SZ;j++)
      cin >> b[i][j];
  cin >> turn;
  nQuery = 0;
  while(1){
    cin >> query[nQuery];
    if(query[nQuery]=="Q") break;
    nQuery++;
  }
}


bool isInside(int r, int c){
  return 0<=r && r<SZ && 0<=c && c<SZ;
}


vector< pair<int,int> > getPos(){
  int dr[]={-1,-1,-1,0,1,1,1,0}, dc[]={-1,0,1,1,1,0,-1,-1};
  vector< pair<int,int> > ret;
  for(int r=0;r<SZ;r++)
    for(int c=0;c<SZ;c++){
      if(b[r][c]!=NONE) continue;
      for(int i=0;i<8;i++){
        int rr = r+dr[i], cc = c+dc[i];
        if(!(isInside(rr,cc) && b[rr][cc]==(turn==BLACK?WHITE:BLACK))) continue;
        while(isInside(rr,cc) && b[rr][cc]==(turn==BLACK?WHITE:BLACK)){
          rr += dr[i];
          cc += dc[i];
        }
        if(isInside(rr,cc) && b[rr][cc]==turn){
          ret.push_back(make_pair(r,c));
          break;
        }
      }
    }
  return ret;
}


void put(int r, int c){
  int dr[]={-1,-1,-1,0,1,1,1,0}, dc[]={-1,0,1,1,1,0,-1,-1};
  vector< pair<int,int> > ret;
  for(int i=0;i<8;i++){
    int rr = r+dr[i], cc = c+dc[i];
    if(!(isInside(rr,cc) && b[rr][cc]==(turn==BLACK?WHITE:BLACK))) continue;
    while(isInside(rr,cc) && b[rr][cc]==(turn==BLACK?WHITE:BLACK)){
      rr += dr[i];
      cc += dc[i];
    }
    if(isInside(rr,cc) && b[rr][cc]==turn){
      rr = r+dr[i], cc = c+dc[i];
      while(isInside(rr,cc) && b[rr][cc]==(turn==BLACK?WHITE:BLACK)){
        b[rr][cc] = turn;
        rr += dr[i];
        cc += dc[i];
      }
    }
  }
  b[r][c] = turn;

  int cntBlack = 0, cntWhite = 0;
  for(int i=0;i<SZ;i++)
    for(int j=0;j<SZ;j++){
      cntBlack += b[i][j]==BLACK;
      cntWhite += b[i][j]==WHITE;
    }
  printf("Black - %2d White - %2d\n",cntBlack,cntWhite);
}

void work(){
  for(int qIdx=0;qIdx<nQuery;qIdx++){
    string &q = query[qIdx];
    if(q=="L"){
      vector< pair<int,int> > pos = getPos();
      if(pos.empty())
        cout << "No legal move." << endl;
      else{
        for(int i=0;i<pos.size();i++){
          if(i) cout << ' ';
          cout << '(' << pos[i].first+1 << ',' << pos[i].second+1 << ')';
        }
        cout << endl;
      }
    }
    else {
      int r = q[1]-'1', c = q[2]-'1';
      vector< pair<int,int> > pos = getPos();
      if(!count(pos.begin(),pos.end(),make_pair(r,c))) turn = turn==BLACK ? WHITE : BLACK;
      put(r,c);
      turn = turn==BLACK ? WHITE : BLACK;
    }
  }

  for(int i=0;i<SZ;i++){
    for(int j=0;j<SZ;j++)
      switch(b[i][j]){
      case WHITE:
        cout << 'W';
        break;
      case BLACK:
        cout << 'B';
        break;
      case NONE:
        cout << '-';
        break;
      }
    cout << endl;
  }
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
