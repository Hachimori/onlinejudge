#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#define MAN 105
#define GAME 500000
#define R 0
#define P 1
#define S 2
using namespace std;

class Game{
public:
  int id1, p1, id2, p2;

  Game(){}
  Game(int id1, int p1, int id2, int p2):
    id1(id1), p1(p1), id2(id2), p2(p2){}
};

int nMan, nGame;
Game game[GAME];

int convert(string s){
  if(s=="rock") return R;
  if(s=="paper") return P;
  if(s=="scissors") return S;
}

bool read(){
  int K;
  cin >> nMan;
  if(nMan==0) return false;
  cin >> K;
  
  nGame = K*nMan*(nMan-1)/2;
 
  for(int i=0;i<nGame;i++){
    int id1, id2;
    string s1, s2;
    cin >> id1 >> s1 >> id2 >> s2;
    id1--, id2--;
    int p1 = convert(s1), p2 = convert(s2);

    if(p1>p2){
      swap(id1,id2);
      swap(p1,p2);
    }
    game[i] = Game(id1,p1,id2,p2);    
  }
  
  return true;
}

void work(){
  int nWin[MAN], nLose[MAN];
  
  for(int i=0;i<nMan;i++)
    nWin[i] = nLose[i] = 0;
  
  for(int i=0;i<nGame;i++){
    int id1 = game[i].id1, id2 = game[i].id2;

    if(game[i].p1==R && game[i].p2==P){
      nWin[id2]++;
      nLose[id1]++;
    }
    if(game[i].p1==R && game[i].p2==S){
      nWin[id1]++;
      nLose[id2]++;
    }
    if(game[i].p1==P && game[i].p2==S){
      nWin[id2]++;
      nLose[id1]++;
    }
  }

  for(int i=0;i<nMan;i++)
    if(nWin[i]+nLose[i]==0)
      printf("-\n");
    else
      printf("%.3lf\n",1.0*nWin[i]/(nWin[i]+nLose[i]));
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }

  return 0;
}
