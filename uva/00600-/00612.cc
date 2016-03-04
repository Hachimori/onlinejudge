#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 105;

int main(){
  int cases;
  cin >> cases;
  for(int kk=0;kk<cases;kk++){
    int len, nStr;
    cin >> len >> nStr;
    
    pair<int,string> toSort[BUF];
    for(int i=0;i<nStr;i++){
      string s;
      cin >> s;
      int cnt = 0;
      for(int j=0;j<len;j++)
        for(int k=j+1;k<len;k++)
          cnt += (s[j]>s[k]);
      toSort[i] = make_pair(cnt,s);
    }

    for(int i=0;i<nStr;i++)
      for(int j=nStr-1;j-1>=i;j--)
        if(toSort[j].first<toSort[j-1].first)
          swap(toSort[j],toSort[j-1]);

    if(kk) cout << endl;
    for(int i=0;i<nStr;i++)
      cout << toSort[i].second << endl;
  }
  return 0;
}
