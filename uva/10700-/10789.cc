#include<iostream>
using namespace std;

bool isPrime(int n){
  if(n<=1) return false;
  for(int i=2;i*i<=n;i++)
    if(n%i==0)
      return false;
  return true;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    string s;
    cin >> s;
    int cnt[128]={0};
    for(int j=0;j<s.size();j++)
      cnt[s[j]]++;

    cout << "Case " << i+1 << ": ";
    int nAns = 0;
    for(int j=0;j<128;j++)
      if(isPrime(cnt[j])){
        cout << (char)j;
        nAns++;
      }
    if(nAns==0)
      cout << "empty";
    cout << endl;
  }
  return 0;
}
