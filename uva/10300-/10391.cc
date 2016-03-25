#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  set<string> strSet;
  string s;
  while(getline(cin,s)!=NULL) strSet.insert(s);

  vector<string> ans;
  for(set<string>::iterator k=strSet.begin();k!=strSet.end();k++){
    s = *k;
    for(int len=1;len<s.size();len++)
      if(strSet.count(s.substr(0,len)) && strSet.count(s.substr(len))){
        ans.push_back(s);
        break;
      }
  }

  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)
    cout << ans[i] << endl;

  return 0;
}
