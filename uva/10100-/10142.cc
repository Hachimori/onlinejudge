#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
const int MAN = 25, VOTE = 1005, INF = 1<<20;

string name[MAN];
int nMan, nRank, rank[VOTE][MAN]; // rank[rankId][idx] := idx th choice

void read(){
  cin >> nMan;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nMan;i++) getline(cin,name[i]);
  nRank = 0;
  while(1){
    string str;
    if(!getline(cin,str) || str.empty()) return;
    stringstream in(str);
    for(int i=0;i<nMan;i++){
      in >> rank[nRank][i];
      rank[nRank][i]--;
    }
    nRank++;
  }
}


void work(){
  int nKilled = 0;
  bool killed[MAN]={};
  while(1){
    int cnt[MAN]={};

    for(int i=0;i<nRank;i++)
      for(int j=0;j<nMan;j++)
        if(!killed[rank[i][j]]){
          cnt[rank[i][j]]++;
          break;
        }

    for(int i=0;i<nMan;i++)
      if(cnt[i]>nRank/2){
        cout << name[i] << endl;
        return;
      }

    int minV = INF;
    vector<int> toKill;
    for(int i=0;i<nMan;i++)
      if(!killed[i] && minV>cnt[i]){
        minV = cnt[i];
        toKill.clear();
        toKill.push_back(i);
      }
      else if(!killed[i] && minV==cnt[i])
        toKill.push_back(i);
    
    if(toKill.size()+nKilled==nMan){
      for(int i=0;i<toKill.size();i++)
        cout << name[toKill[i]] << endl;
      break;
    }

    nKilled += toKill.size();
    for(int i=0;i<toKill.size();i++)
      killed[toKill[i]] = true;
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
