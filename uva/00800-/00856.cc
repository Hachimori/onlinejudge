#include<iostream>
using namespace std;

int main(){
  string tbl[]={"zero","one","two","three","four","five",
                "six","seven","eight","nine"};
  string s;
  for(int caze=0;cin >> s;caze++){
    if(caze) cout << endl;
    for(int i=9;i>=0;i--)
      for(int j=9;j>=0;j--)
        for(int k=9;k>=0;k--){
          string toCmp = tbl[i]+tbl[j]+tbl[k];
          if(s.size()!=toCmp.size()) continue;

          string key;
          for(int i=0;i<toCmp.size();i++)
            for(char keyCh='A';keyCh<='Z';keyCh++){
              char enciphered = 'A'+(toCmp[i]-'a'+keyCh-'A'+1)%26;
              if(enciphered==s[i]){
                key += keyCh;
                break;
              }
            }
          cout << key << " -> " << toCmp << endl;
        }
  }
  return 0;
}
