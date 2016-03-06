#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int BUF = 1005;

int main(){
  int nWord = 0;
  vector<int> words[BUF];
  string word;

  while(1){
    getline(cin,word);
    if(word=="#") break;
    vector<int> cnt(26,0);
    for(int i=0;i<word.size();i++) cnt[word[i]-'a']++;
    words[nWord++] = cnt;
  }

  string letter;
  while(1){
    getline(cin,letter);
    if(letter=="#") break;

    vector<int> cnt(26,0);
    for(int i=0;i<letter.size();i++)
      if(letter[i]!=' ')
        cnt[letter[i]-'a']++;
    
    int ans = 0;
    for(int i=0;i<nWord;i++){
      for(int j=0;j<26;j++)
        if(cnt[j]<words[i][j])
          goto _fail;
      ans++;
    _fail:;
    }
    cout << ans << endl;
  }
  return 0;
}
