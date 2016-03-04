#include<iostream>
#include<string>
#include<set>
using namespace std;

string vowel = "AIUEOY";
char b[2][4][4];

bool read(){
  for(int i=0;i<4;i++)
    for(int j=0;j<8;j++){
        cin >> b[j/4][i][j%4];
        if(b[j/4][i][j%4]=='#') return false;
      }
  return true;
}

void rec(int r, int c, int cntVowel, 
         string seq, set<string> &S, char board[4][4], bool visited[4][4]){
  if(seq.size()==4){
    if(cntVowel==2) S.insert(seq);
    return;
  }

  static int dr[]={-1,-1,-1,0,1,1,1,0}, dc[]={-1,0,1,1,1,0,-1,-1};
  for(int i=0;i<8;i++){
    int nr=r+dr[i], nc=c+dc[i];
    if(0<=nr && nr<4 && 0<=nc && nc<4 && !visited[nr][nc]){
      visited[nr][nc] = true;
      rec(nr,nc,cntVowel+(vowel.find(board[nr][nc])!=string::npos),seq+board[nr][nc],S,board,visited);
      visited[nr][nc] = false;
    }
  }
}

void work(){
  bool visited[4][4];
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      visited[i][j] = false;
  
  set<string> S[2];
  for(int i=0;i<2;i++)
    for(int j=0;j<4;j++)
      for(int k=0;k<4;k++){
        visited[j][k] = true;
        rec(j,k,vowel.find(b[i][j][k])!=string::npos,string(1,b[i][j][k]),S[i],b[i],visited);
        visited[j][k] = false;
      }
  
  bool noAns = true;
  for(set<string>::iterator i=S[0].begin();i!=S[0].end();i++)
    if(S[1].count(*i)){
      cout << *i << endl;
      noAns = false;
    }

  if(noAns)
    cout << "There are no common words for this pair of boggle boards." << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
