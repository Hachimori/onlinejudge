#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

string str;
vector<string> word;

bool read(){
  if(getline(cin,str)==NULL) return false;
  word.clear();

  stringstream in(str);
  string w;
  while(in>>w) word.push_back(w);

  return true;
}

int convert(string s){
  int ret = 0;
  for(int i=0;i<s.size();i++){
    ret *= 32;
    ret += s[i]-'a'+1;
  }
  return ret;
}

void work(){
  vector<int> val;
  for(int i=0;i<word.size();i++) val.push_back(convert(word[i]));

  int ans = *min_element(val.begin(),val.end());
  while(1){
    int next = -1;
    for(int i=0;i<val.size();i++)
      for(int j=i+1;j<val.size();j++)
        if(ans/val[i]%val.size()==ans/val[j]%val.size())
          next = max(next,min((ans/val[i]+1)*val[i],(ans/val[j]+1)*val[j]));
    if(next==-1) break;
    ans = next;
  }

  cout << str << endl;
  cout << ans << endl << endl;
}

int main(){
  while(read()) 
    work();
  return 0;
}
