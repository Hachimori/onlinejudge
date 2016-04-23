#include<iostream>
#include<string>
#include<vector>
#define BUF 105
#define YET -1
#define CANT -2
#define NO -2
#define YES -3
using namespace std;

class Pi{
public:
  int pos, i, j;
  Pi(){}
  Pi(int p, int i, int j): pos(p), i(i), j(j){}
};

int cnv[3][3]={{1,1,0},
               {2,1,0},
               {0,2,2}};

int N;
char dst;
string str;

void read(){
  cin >> str >> dst;
  N = str.size();
  for(int i=0;i<N;i++) str[i] -= 'a';
  dst -= 'a';
}

bool rec(int L, int R, int ch, Pi pi[BUF][BUF][3], int order[BUF][BUF][3][BUF]){
  if(L==R) return str[L]==ch;
  if(L+1==R){
    order[L][R][ch][0] = L;
    return cnv[str[L]][str[R]]==ch;
  }
  if(pi[L][R][ch].pos!=YET) return pi[L][R][ch].pos!=CANT;
  
  pi[L][R][ch].pos = CANT;

  int minPi[BUF]; 
  minPi[0] = BUF;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(cnv[i][j]==ch)
        for(int k=L;k<R;k++)
          if(rec(L,k,i,pi,order) && rec(k+1,R,j,pi,order)){
            int t[BUF], len = 0, ok = YET;
            for(int l=0;l<k-L && ok!=NO;l++){
              if(ok==YET && minPi[len]<order[L][k][i][l]) ok = NO;
              if(ok==YET && minPi[len]>order[L][k][i][l]) ok = YES;
              t[len++] = order[L][k][i][l];
            }
            for(int l=0;l<R-(k+1)&& ok!=NO;l++){
              if(ok==YET && minPi[len]<order[k+1][R][j][l]) ok = NO;
              if(ok==YET && minPi[len]>order[k+1][R][j][l]) ok = YES;
              t[len++] = order[k+1][R][j][l];
            }
            if(ok==YET && minPi[len]<L) ok = NO;
            if(ok==YET && minPi[len]>L) ok = YES;
            t[len++] = L;

            if(ok==YES){
              for(int l=0;l<len;l++) minPi[l] = order[L][R][ch][l] = t[l];
              pi[L][R][ch] = Pi(k,i,j);
            }
          }
  
  return pi[L][R][ch].pos!=CANT;
}

void output(int L, int R, int ch, int depth, Pi pi[BUF][BUF][3], string &s){
  if(L==R) return;
  if(L+1==R) {
    s[depth] = cnv[s[depth]][s[depth+1]];
    s.erase(1+depth,1);
    for(int i=0;i<s.size();i++)
      cout << (char)(s[i]+'a');
    cout << endl;
    return;
  }
  Pi p = pi[L][R][ch];
  output(L,p.pos,p.i,depth,pi,s);
  output(p.pos+1,R,p.j,depth+1,pi,s);
  
  s[depth] = cnv[s[depth]][s[depth+1]];
  s.erase(1+depth,1);
  for(int i=0;i<s.size();i++)
    cout << (char)(s[i]+'a');
  cout << endl;  
}

void work(){
  Pi pi[BUF][BUF][3];
  static int order[BUF][BUF][3][BUF];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<3;k++)
        pi[i][j][k].pos = YET;
  
  if(!rec(0,N-1,dst,pi,order)){
    cout << "None exist!" << endl;
    return;
  }
  
  for(int i=0;i<str.size();i++)
    cout << (char)(str[i]+'a');
  cout << endl;
  output(0,N-1,dst,0,pi,str);
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
