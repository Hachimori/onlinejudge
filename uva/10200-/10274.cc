#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef vector< vector<char> > State;

int row, col;
State init;

void read(){
  string dummy; getline(cin,dummy);

  cin >> row >> col;
  
  getline(cin,dummy);

  
  init = State(row,vector<char>(col));
  
  for(int i=0;i<row;i++){
    string s; getline(cin,s);
    for(int j=0;j<col;j++)
      init[i][j] = s[j];
  }
}

bool del(State &st){
  static int dr[]={1,0,-1,0}, dc[]={0,1,0,-1}; 
  State buf = st;
  bool deleted = false;
  
  for(int r=1;r<row-1;r++)
    for(int c=1;c<col-1;c++){
      if(!isdigit(buf[r][c])) continue;
      
      for(int i=0;i<4;i++){
        int nr = r+dr[i], nc = c+dc[i];
        if(buf[r][c]==buf[nr][nc]){
          st[r][c] = ' ';
          deleted = true;
          break;
        }
      }
    }

  return deleted;
}

string bfs(){
  char str[]="DLRU";
  int sr[]={row-1,0,0,0}, er[]={-1,row,row,row};
  int sc[]={0,0,col-1,0}, ec[]={col,col,-1,col};
  int ir[]={-1,1,1,1}, ic[]={1,1,-1,1};
  
  map<State,string> M;
  queue<State> Q;
  
  M[init] = "";
  Q.push(init);

  while(!Q.empty()){
    State curr = Q.front();
    Q.pop();

    for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
        if(isdigit(curr[i][j])) goto _fail;
    return M[curr];
  _fail:
    
    for(int i=0;i<4;i++){
      State next = curr;
      
      while(true){
        bool deleted = false;
        for(int r=sr[i];r!=er[i];r+=ir[i])
          for(int c=sc[i];c!=ec[i];c+=ic[i]){
            if(!isdigit(next[r][c]) && next[r][c]!='@') continue;
            
            int cr = r, cc = c;
            while(true){
              int nr = i==0||i==3 ? cr-ir[i] : cr;
              int nc = i==0||i==3 ? cc : cc-ic[i];
              
              if(next[nr][nc]==' ')
                swap(next[nr][nc],next[cr][cc]);
              else
                break;
              cr = nr;
              cc = nc;
            }
          }
        
        if(!del(next)) break;
      }
      
      if(!M.count(next)){
        M[next] = M[curr]+str[i];
        Q.push(next);
      }
    }
  }
  
  return "-1";
}

void work(){
  string ans = bfs();

  for(int i=0;i<ans.size();i++)
    cout << ans[i];
  cout << endl;
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
