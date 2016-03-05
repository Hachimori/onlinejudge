#include<iostream>
#include<string>
#include<cctype>
#define AND ')'
#define OR '>'
#define VER '|'
#define HOR '-'
#define CRS '+'
#define NOT 'o'
#define N 0
#define E 1
#define S 2
#define W 3
#define BUF 105
#define VAL 10000
using namespace std;

const static int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
int nVal, initR, initC;
char b[BUF][BUF];
string val[VAL];

bool read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      b[i][j] = ' ';
  
  for(int r=0;;r++){
    string s;  if(getline(cin,s)==NULL) return false;
    if(s=="*") break;
    for(int i=0;i<s.size();i++){
      b[r][i] = s[i];
      if(s[i]=='?') initR = r, initC = i;
    }
  }
  
  for(nVal=0;;nVal++){
    getline(cin,val[nVal]);
    if(val[nVal]=="*") break;
  }
  
  return true;
}

bool isInside(int r, int c){
  return 0<=r && r<BUF && 0<=c && c<BUF;
}

bool rec(int r, int c, int dir, string &v){
  if(isupper(b[r][c])) return v[b[r][c]-'A']-'0';
  if(b[r][c]==NOT) return !rec(r+dr[dir],c+dc[dir],dir,v);
  if(b[r][c]==AND) return rec(r+1,c-3,dir,v) && rec(r-1,c-3,dir,v);
  if(b[r][c]==OR)  return rec(r+1,c-3,dir,v) || rec(r-1,c-3,dir,v);
  if(b[r][c]==HOR || b[r][c]==VER)
                   return rec(r+dr[dir],c+dc[dir],dir,v);

  if(b[r][c]==CRS){
    if(dir==N || dir==S){
      for(int i=1;i<4;i+=2){
	int nr = r+dr[i], nc = c+dc[i];
	if(isInside(nr,nc) && b[nr][nc]==HOR )
	  return rec(nr,nc,i,v);
      }
    }
    else{
      for(int i=0;i<4;i+=2){
	int nr = r+dr[i], nc = c+dc[i];
	if(isInside(nr,nc) && b[nr][nc]==VER )
	  return rec(nr,nc,i,v);
      }
    }
  }
}

void work(){
  for(int i=0;i<nVal;i++)
    for(int j=0;j<4;j++){
      int nr = initR+dr[j], nc = initC+dc[j];
      if(isInside(nr,nc) && (b[nr][nc]==VER || b[nr][nc]==HOR)){
	cout << rec(nr,nc,j,val[i]) << endl;
	break;
      }
    }
}

int main(){
  while(read()){
    work();
    cout << endl;
  }

  return 0;
}