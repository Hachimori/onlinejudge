// 全探索
// 
// 答えは101個以上必要無い。

#include<iostream>
#include<algorithm>
#include<string>

#define MAX_SIZE 100

using namespace std;

class Word{
public:
  char c;
  string digit;
  
  Word(){}
  Word(char c, string d): c(c), digit(d){}

  bool operator< (const Word &w) const {
    return c<w.c;
  }
};

int nWord;
Word word[MAX_SIZE];
string target;

bool read(){
  cin >> nWord;
  if(nWord==0) return false;
  
  for(int i=0;i<nWord;i++)
    cin >> word[i].c >> word[i].digit;
  
  cin >> target;
  
  return true;
}

bool rec(int &nPrinted, string digit, string str){
  //cout << ' ' << digit << ' ' << str << endl;
  
  if(nPrinted==100) return true;
  
  if(digit==target){
    cout << str << endl;
    nPrinted++;
    return false;
  }

  for(int idx=0;idx<nWord;idx++){
    bool succeed = true;
    int start = digit.size();

    while(start<target.size() && target[start]=='0') start++;
    
    if(target.size()-start<word[idx].digit.size()) succeed = false;

  
    for(int i=0,j=start;i<word[idx].digit.size() && j<target.size();i++,j++)
      if(word[idx].digit[i]!=target[j]){
	succeed = false;
	break;
      }

    if(succeed){
      string nextDigit = digit + string(start-digit.size(),'0') + word[idx].digit;
      string nextStr = str + word[idx].c;
      if(rec(nPrinted,nextDigit,nextStr)) return true;
    }
  }

  return false;
}

void work(int cases){
  /*
  for(int i=0;i<nWord;i++)
    cout << word[i].c << word[i].digit << endl;
  cout << target << endl;
  cout << endl;
  */
  
  sort(word,word+nWord);
  
  cout << "Case #" << cases << endl;
  
  int nPrinted = 0;
  
  rec(nPrinted,"","");
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
