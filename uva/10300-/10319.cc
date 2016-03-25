#include<iostream>
#define var first
#define neg second
using namespace std;
const int BUF = 125;

int nNode, nRow, nCol;
bool adj[BUF][BUF];

void read(){
  memset(adj,0,sizeof(adj));

  int nPath;
  cin >> nRow >> nCol >> nPath;
  
  // var[          0 ~        nRow-1]: row[i]'s variable (true if it allows east)
  // var[       nRow ~      nRow*2-1]: var[i-nRow]'s negation (true if it allows west)
  // var[     nRow*2 ~ nRow*2+nCol-1]: col[i-nRow*2]'s variable (true if it allows south)
  // var[nRow*2+nCol ~ (nRow+nCol)*2]: var[i-nRow*2-nCol]'s negation (true if it allows north)

  pair<int,int> row2var[BUF], col2var[BUF]; 
  for(int i=0;i<nRow;i++) row2var[i] = make_pair(i,i+nRow);
  for(int i=0;i<nCol;i++) col2var[i] = make_pair(i+nRow*2,i+nRow*2+nCol);

  nNode = (nRow+nCol)*2+1;
  
  // p⇒q  は"pが真なら, qも真である", "pは偽もしくはqは真である", 
  // "pはqを包含する", と言い換えられる。真理値表は以下のとおり。
  //
  //  p | q | p⇒q  
  // ------------
  //  T | T |  T  
  //  T | F |  F  
  //  F | T |  T  
  //  F | F |  T  

  // nNode-1 は、 1 を意味する特別な変数
  // 1 ⇒ x なので以下の処理をする。
  for(int i=0;i<nNode;i++)
    adj[nNode-1][i] = 1;

  for(int i=0;i<nPath;i++){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    if(c1==c2 && r1==r2) continue;
    else if(c1==c2){
      if(r1<r2){
        // x∨1 は以下の二つの implication で表される。
        // ￢x ⇒ 1
        // ￢1 ⇒ x
        // ここで、￢x ⇒ 1 だけで十分なので、￢1 ⇒ x は考えない。
        adj[col2var[c1].neg][nNode-1] = 1;
      }
      else
        adj[col2var[c1].var][nNode-1] = 1;
    }
    else if(r1==r2){
      if(c1<c2)
        adj[row2var[r1].neg][nNode-1] = 1;
      else
        adj[row2var[r1].var][nNode-1] = 1;
    }
    else{
      if(r1<r2){
        adj[col2var[c1].neg][col2var[c2].var] = 1;
        adj[col2var[c2].neg][col2var[c1].var] = 1;
        if(c1<c2){
          adj[col2var[c1].neg][row2var[r1].var] = 1;
          adj[col2var[c2].neg][row2var[r2].var] = 1;
        }
        else{
          adj[col2var[c1].neg][row2var[r1].neg] = 1;
          adj[col2var[c2].neg][row2var[r2].neg] = 1;
        }
      }
      else{
        adj[col2var[c1].var][col2var[c2].neg] = 1;
        adj[col2var[c2].var][col2var[c1].neg] = 1;
        if(c1<c2){
          adj[col2var[c1].var][row2var[r1].var] = 1;
          adj[col2var[c2].var][row2var[r2].var] = 1;
        }
        else{
          adj[col2var[c1].var][row2var[r1].neg] = 1;
          adj[col2var[c2].var][row2var[r2].neg] = 1;
        }
      }

      if(c1<c2){
        adj[row2var[r1].neg][row2var[r2].var] = 1;
        adj[row2var[r2].neg][row2var[r1].var] = 1;
        if(r1<r2){
          adj[row2var[r1].neg][col2var[c1].var] = 1;
          adj[row2var[r2].neg][col2var[c2].var] = 1;
        }
        else{
          adj[row2var[r1].neg][col2var[c1].neg] = 1;
          adj[row2var[r2].neg][col2var[c2].neg] = 1;
        }
      }
      else{
        adj[row2var[r1].var][row2var[r2].neg] = 1;
        adj[row2var[r2].var][row2var[r1].neg] = 1;
        if(r1<r2){
          adj[row2var[r1].var][col2var[c1].var] = 1;
          adj[row2var[r2].var][col2var[c2].var] = 1;
        }
        else{
          adj[row2var[r1].var][col2var[c1].neg] = 1;
          adj[row2var[r2].var][col2var[c2].neg] = 1;
        }
      }
    }
  }
}

void work(){
  for(int k=0;k<nNode;k++)
    for(int i=0;i<nNode;i++)
      for(int j=0;j<nNode;j++)
        adj[i][j] |= adj[i][k] & adj[k][j];

  for(int i=0;i<nRow;i++)
    if(adj[i][i+nRow] && adj[i+nRow][i]){
      cout << "No" << endl;
      return;
    }

  for(int i=0;i<nCol;i++)
    if(adj[i+nRow*2][i+nRow*2+nCol] && adj[i+nRow*2+nCol][i+nRow*2]){
      cout << "No" << endl;
      return;
    }

  cout << "Yes" << endl;
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
