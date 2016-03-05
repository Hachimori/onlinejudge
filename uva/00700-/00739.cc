#include<iostream>
#include<string>
using namespace std;

int main(){
  string chList[7] = {"AEIOUYWH","BPFV","CSKGJQXZ","DT","L","MN","R"};
  int ch2v[128];
  for(int i=0;i<7;i++)
    for(int j=0;j<chList[i].size();j++)
      ch2v[chList[i][j]] = i;

  cout << string(9,' ') << "NAME" << string(34-9-4,' ') << "SOUNDEX CODE" << endl;
  string s;
  while(cin >> s){
    string ans;
    ans += s[0];
    int prev = ch2v[s[0]];
    for(int i=1;i<s.size();i++){
      if(ch2v[s[i]]!=0 && prev!=ch2v[s[i]])
        ans += (char)(ch2v[s[i]]+'0');
      prev = ch2v[s[i]];
    }
    ans += string(max(0,4-(int)ans.size()),'0');
    ans = ans.substr(0,4);
    cout << string(9,' ') << s << string(34-9-s.size(),' ') << ans << endl;
  }
  cout << string(19,' ') << "END OF OUTPUT" << endl;
  return 0;
}
