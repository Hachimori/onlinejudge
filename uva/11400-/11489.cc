#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    string s;
    cin >> s;
    
    int cnt[3]={}, sumVal = 0;
    for(int i=0;i<s.size();i++){
      cnt[(s[i]-'0')%3]++;
      sumVal += s[i]-'0';
    }

    int nTake = cnt[0];
    if(sumVal%3>0) nTake += min(1,cnt[sumVal%3]);

    cout << "Case " << k+1 << ": " << (nTake%2==0 ? "T" :  "S") << endl;
  }
  return 0;
}
