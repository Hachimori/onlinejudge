#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string s;

bool read(){
  return getline(cin,s);
}


void work(){
  int val[26], delta[26]={};
  for(int i=0;i<26;i++) val[i] = i+1;

  string curS;
  for(int i=0;i<s.size();i++) if(!isspace(s[i])) curS += s[i];

 _doit:
  for(int i=0;i<curS.size();i++){
    char ch  = curS[i];
    if(!isalpha(ch)) continue;
    if(i-2>=0 && curS[i-1]=='+' && curS[i-2]=='+') {
      val[ch-'a']++;
      curS.erase(curS.begin()+i-2);
      curS.erase(curS.begin()+i-2);
      goto _doit;
    }
    if(i-2>=0 && curS[i-1]=='-' && curS[i-2]=='-') {
      val[ch-'a']--;
      curS.erase(curS.begin()+i-2);
      curS.erase(curS.begin()+i-2);
      goto _doit;
    }
    if(i+2<curS.size() && curS[i+1]=='+' && curS[i+2]=='+') {
      delta[ch-'a']++;
      curS.erase(curS.begin()+i+1);
      curS.erase(curS.begin()+i+1);
      goto _doit;
    }
    if(i+2<curS.size() && curS[i+1]=='-' && curS[i+2]=='-') {
      delta[ch-'a']--;
      curS.erase(curS.begin()+i+1);
      curS.erase(curS.begin()+i+1);
      goto _doit;
    }
  }

  bool used[26]={};
  int value = 0;
  for(int i=0;i<curS.size();i++){
    if(!isalpha(curS[i])) continue;
    used[curS[i]-'a'] = true;
    if(i==0 || curS[i-1]=='+')
      value += val[curS[i]-'a'];
    else
      value -= val[curS[i]-'a'];
  }

  cout << "Expression: " << s << endl;
  cout << "    value = " << value << endl;
  for(int i=0;i<26;i++)
    if(used[i])
      cout << "    " << (char)(i+'a') << " = " << val[i]+delta[i] << endl;
}


int main(){
  while(read()) work();
  return 0;
}
