#include<iostream>
#include<string>
#include<set>
using namespace std;
const int FINGER = 10, WORD = 1005;

int nWord;
string word[WORD];
bool can[FINGER];


bool read(){
  for(int i=0;i<FINGER;i++) can[i] = true;
  
  int nCantUse;
  if(!(cin >> nCantUse >> nWord)) return false;

  for(int i=0;i<nCantUse;i++){
    int v;
    cin >> v;
    can[v-1] = false;
  }

  for(int i=0;i<nWord;i++) cin >> word[i];

  return true;
}

void work(){
  string i2s[]={"qaz","wsx","edc","rfvtgb"," "," ",
                "yhnujm","ik,","ol.","p;/"};
  int s2i[256];
  
  for(int i=0;i<FINGER;i++)
    for(int j=0;j<i2s[i].size();j++)
      s2i[i2s[i][j]] = i;

  set<string> S;
  for(int i=0;i<nWord;i++){
    for(int j=0;j<word[i].size();j++)
      if(!can[s2i[word[i][j]]])
        goto _fail;
    if(S.empty() || (*S.begin()).size()<word[i].size()){
      S.clear();
      S.insert(word[i]);
    }
    else if(!S.empty() && (*S.begin()).size()==word[i].size())
      S.insert(word[i]);
  _fail:;
  }

  cout << S.size() << endl;
  for(set<string>::iterator i=S.begin();i!=S.end();i++)
    cout << *i << endl;
}

int main(){
  while(read()) work();
  return 0;
}
