#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
const int WORD = 25, STR = 25;

int nWord, nStr;
string word[WORD], str[STR];

bool read(){
  if(!(cin >> nWord >> nStr)) return false;
  for(int i=0;i<nWord;i++) cin >> word[i];
  string dummy; getline(cin,dummy);
  for(int i=0;i<nStr;i++) getline(cin,str[i]);
  return true;
}


void work(int cases){
  int maxCnt = 0;
  vector<string> ans;

  for(int i=0;i<nStr;i++){
    vector<string> toCmp;
    for(int j=0;j<str[i].size();j++){
      if(!isalnum(str[i][j])) continue;
      string toPush;
      while(j<str[i].size() && isalnum(str[i][j])) toPush += tolower(str[i][j++]);
      toCmp.push_back(toPush);
    }

    int cnt = 0;
    for(int j=0;j<nWord;j++)
      cnt += count(toCmp.begin(),toCmp.end(),word[j]);

    if(maxCnt<cnt){
      maxCnt = cnt;
      ans.clear();
      ans.push_back(str[i]);
    }
    else if(maxCnt==cnt)
      ans.push_back(str[i]);
  }

  cout << "Excuse Set #" << cases << endl;
  for(int i=0;i<ans.size();i++)
    cout << ans[i] << endl;
}


int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  return 0;
}
