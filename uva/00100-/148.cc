#include<iostream>
#include<string>
#include<numeric>
#include<algorithm>
#include<sstream>
#include<set>
#define WORD 2005
#define QUERY 2005
using namespace std;

int nWord, nQuery;
string word[WORD], query[QUERY], curQ;

void read(){
  for(nWord=0;;nWord++){
    getline(cin,word[nWord]);
    if(word[nWord]=="#") break;
  }

  for(nQuery=0;;nQuery++){
    getline(cin,query[nQuery]);
    if(query[nQuery]=="#") break;
  }
}

void rec(int idx, int nPush, int pushed[20], 
         int curr[256], int goal[256], set<string> &S){
  if(accumulate(curr,curr+256,0)==accumulate(goal,goal+256,0)){
    cout << curQ << " =";
    for(int i=0;i<nPush;i++)
      cout << ' ' << word[pushed[i]];
    cout << endl;
    return;
  }
  if(idx==nWord) return;
  
  bool ok = true;
  for(int i=0;i<word[idx].size();i++){
    if(curr[word[idx][i]]==goal[word[idx][i]]) ok = false;
    curr[word[idx][i]]++;
  }
  pushed[nPush] = idx;

  if(ok && !S.count(word[idx])) rec(idx+1,nPush+1,pushed,curr,goal,S);
    
  for(int i=0;i<word[idx].size();i++)
    curr[word[idx][i]]--;

  rec(idx+1,nPush,pushed,curr,goal,S);
}

void work(){
  int curr[256]={0};

  sort(word,word+nWord);

  for(int i=0;i<nQuery;i++){
    int goal[256]={0}, pushed[20];

    for(int j=0;j<query[i].size();j++)
      if(!isspace(query[i][j]))
        goal[query[i][j]]++;
    curQ = query[i];

    set<string> S;
    stringstream in(query[i]);
    string t;
    while(in>>t) S.insert(t);

    rec(0,0,pushed,curr,goal,S);
  }
}

int main(){
  read();
  work();
  
  return 0;
}