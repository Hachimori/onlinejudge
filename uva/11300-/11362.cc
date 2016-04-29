#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int BUF = 10005;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int nStr;
    string str[BUF];
    cin >> nStr;
    for(int i=0;i<nStr;i++) cin >> str[i];
    sort(str,str+nStr);
    for(int i=0;i+1<nStr;i++)
      if(str[i]==str[i+1].substr(0,str[i].size())){
        cout << "NO" << endl;
        goto _fail;
      }
    cout << "YES" << endl;
  _fail:;
  }
  return 0;
}
