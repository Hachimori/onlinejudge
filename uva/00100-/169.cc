#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cctype>
using namespace std;
typedef vector<int> State;
typedef pair<int,int> Range;

string str;

bool read(){
  str = "";

  while(true){
    string s;
    getline(cin,s);
    if(s=="#") return false;

    for(int i=0;i<s.size();i++)
      if(islower(s[i]))
        str += s[i];

    if(s[s.size()-1]!='-') break;
  }

  return true;
}

void shift(int &ptr, int leng, State &st){
  st[str[ptr]]--;
  st[str[ptr+leng]]++;
  ptr++;
}

bool isWord(int idx, int leng, State &st){
  if(idx==0) return st[str[idx+leng]]==0;
  if(idx+leng==str.size()) return st[str[idx-1]]==0;
  return str[idx-1]==str[idx+leng] && st[str[idx+leng]]==0;
}

// sentence 上に現れる word を、出現回数とともに返す。
map<State,int> getWord(){
  map<State,int> word;

  for(int leng=2;leng<=min(250,(int)str.size()-1);leng++){
    State curr(256,0);
    for(int i=0;i<leng;i++) curr[str[i]]++;
    
    for(int i=0;i+leng<=str.size();shift(i,leng,curr)){
      if(!isWord(i,leng,curr)) continue;
      
      if(word.count(curr))
        word[curr]++;
      else
        word[curr] = 1;
    }
  }

  return word;
}

// sentence 上に二回以上現れる word が存在する位置を(始点,終点)のリストで返す。
vector<Range> getRange(map<State,int> &word){
  vector<Range> range;

  for(int leng=2;leng<=min(250,(int)str.size()-1);leng++){
    State curr(256,0);
    for(int i=0;i<leng;i++) curr[str[i]]++;
    
    for(int i=0;i+leng<=str.size();shift(i,leng,curr)){
      if(!isWord(i,leng,curr)) continue;
      if(word[curr]>=2)
        range.push_back(Range(i,i+leng));
    }
  }

  return range;
}

bool sorter(Range a, Range b){
  if(max(a.first,b.first)<min(a.second,b.second))
    return a.second<b.second;
  return a.first<b.first;
}

void work(){
  map<State,int> word = getWord();
  vector<Range> range = getRange(word);
  
  set<State> pushed;
  vector<Range> ans;

  for(int i=0;i<range.size();i++){
    for(int j=0;j<range.size();j++){
      if(i==j) continue;
      Range a = range[i], b = range[j];

      if(max(a.first,b.first)<min(a.second,b.second)){
        State toPush(256,0);
        for(int k=a.first;k<a.second;k++)
          toPush[str[k]]++;
          
        if(!pushed.count(toPush)){
          for(int k=0;k<=i;k++){
            Range c = range[k];
            if(c.second-c.first==a.second-a.first){
              State toPush2(256,0);              
              for(int l=c.first;l<c.second;l++)
                toPush2[str[l]]++;

              if(toPush==toPush2){
                ans.push_back(c);
                break;
              }
            }
          }
          pushed.insert(toPush);
        }
        break;
      }
    }
  }
  sort(ans.begin(),ans.end(),sorter);

  for(int i=0;i<ans.size();i++){
    for(int j=ans[i].first;j<ans[i].second;j++)
      cout << str[j];
    cout << endl;
  }
  cout << "*" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
