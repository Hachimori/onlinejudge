#include<iostream>
#include<string>
using namespace std;
typedef long long integer;

string s;

void read(){
  cin >> s;
}

void work(int cases){
  integer ans = 1;
  for(int i=1;i<=s.size();i++)
    ans *= i;
  
  int cnt[26] = {0};
  for(int i=0;i<s.size();i++)
    cnt[s[i]-'A']++;

  for(int i=0;i<26;i++)
    for(int j=1;j<=cnt[i];j++)
      ans /= j;

  cout << "Data set " << cases << ": " << ans << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
