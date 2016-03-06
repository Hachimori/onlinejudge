#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

bool rec(int cur, int sent2word[128], int word2sent[128], vector<string> &word, vector<string> &sList){
  if(cur==sList.size()){
    for(int i=0;i<sList.size();i++){
      if(i) cout << ' ';
      for(int j=0;j<sList[i].size();j++)
        cout << (char)sent2word[sList[i][j]];
    }
    cout << endl;
    return true;
  }

  for(int i=0;i<word.size();i++){
    if(word[i].size()!=sList[cur].size()) continue;
    int nexs2w[128], nexw2s[128];
    for(int j=0;j<128;j++)
      nexs2w[j] = sent2word[j], nexw2s[j] = word2sent[j];
    for(int j=0;j<sList[cur].size();j++){
      if(!nexs2w[sList[cur][j]] && !nexw2s[word[i][j]]){
        nexs2w[sList[cur][j]] = word[i][j];
        nexw2s[word[i][j]] = sList[cur][j];
      }
      else if(nexs2w[sList[cur][j]]!=word[i][j] || nexw2s[word[i][j]]!=sList[cur][j])
        goto _fail;
    }
    if(rec(cur+1,nexs2w,nexw2s,word,sList)) return true;
  _fail:;
  }
  return false;
}

int main(){
  vector<string> word;
  int nWord;
  cin >> nWord;
  for(int i=0;i<nWord;i++){
    string s;
    cin >> s;
    word.push_back(s);
  }

  string dummy;
  getline(cin,dummy);

  while(1){
    string s;
    if(!getline(cin,s)) break;
    stringstream in(s);
    
    vector<string> sList;
    while(in >> s) sList.push_back(s);

    int word2sent[128]={}, sent2word[128]={};
    if(!rec(0,sent2word,word2sent,word,sList)){
      for(int i=0;i<sList.size();i++){
        if(i) cout << ' ';
        cout << string(sList[i].size(),'*');
      }
      cout << endl;
    }
  }
  return 0;
}
