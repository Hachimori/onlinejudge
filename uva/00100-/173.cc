#include<iostream>
#include<string>
#include<sstream>
#define BUF 30
using namespace std;

int initA, initB;
bool adj[BUF][BUF];

bool read(){
  string s;
  getline(cin,s);
  if(s=="#") return false;

  memset(adj,false,sizeof(adj));

  stringstream in(s);
  while(true){
    char src;
    in >> src;
    char dst; in >> dst;  // ':'
    while(true){
      in >> dst;
      if(dst=='.') goto _finish;
      if(dst==';') break;
      adj[src-'A'][dst-'A'] = adj[dst-'A'][src-'A'] = true;
    }
  }
 _finish:

  char ach, bch;
  in >> ach >> bch;

  initA = ach-'A';
  initB = bch-'A';

  return true;
}

void work(){
  int curA = initA, curB = initB;
  bool visitedA[BUF], visitedB[BUF];

  memset(visitedA,false,sizeof(visitedA));
  memset(visitedB,false,sizeof(visitedB));

  if(initA==initB){
    cout << "Both annihilated in node " << (char)('A'+initA) << endl;
    return;
  }

  while(true){
    visitedA[curA] = visitedB[curB] = true;

    int nexA = -1, nexB = -1;

    for(int i=curA,j=0;j<BUF;i=(i+1)%BUF,j++)
      if(adj[curA][i] && !visitedA[i] && !visitedB[i]){
        nexA = i;
        break;
      }

    for(int i=curB,j=0;j<BUF;i=(i+BUF-1)%BUF,j++)
      if(adj[curB][i] && !visitedB[i]){
        nexB = i;
        break;
      }

    
    if(nexA==nexB && nexA!=-1){
      cout << "Both annihilated in node " << (char)('A'+nexA) << endl;
      break;
    }
    
    bool finish = false;
    if(nexA==-1){
      cout << "Paskill trapped in node " << (char)('A'+curA);
      finish = true;
    }
    
    if(nexB==-1){
      if(finish) cout << ' ';
      cout << "Lisper trapped in node " << (char)('A'+curB);
      finish = true;
    }
    
    if(nexB!=-1 && visitedA[nexB]){
      if(finish) cout << ' ';
      if(nexA==-1 && curA==nexB)
        cout << "Both annihilated in node " << (char)('A'+curA);
      else
        cout << "Lisper destroyed in node " << (char)('A'+nexB);
      finish = true;
    }

    if(finish){
      cout << endl;
      break;
    }

    curA = nexA, curB = nexB;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}

