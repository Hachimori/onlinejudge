#include<iostream>
#include<cctype>
using namespace std;

string s;

bool read(){
  cin >> s;
  return s!=".";
}

bool pickup(char ch, int remain[10]){
  ch -= '0';
  switch(ch){
  case 2:
  case 5:
    if(remain[2]){ remain[2]--; break; }
    if(remain[5]){ remain[5]--; break; }
    return false;
  case 6:
  case 9:
    if(remain[6]){ remain[6]--; break; }
    if(remain[9]){ remain[9]--; break; }
    return false;
  default:
    if(remain[ch]){ remain[ch]--; break; }
    return false;
  }
  return true;
}

bool success(string curS, int cnt[10]){
  int curCnt[10];
  for(int i=0;i<10;i++) curCnt[i] = cnt[i];
  
  for(int i=0;i<curS.size();i++)
    if(isdigit(curS[i]) && !pickup(curS[i],curCnt))
      return false;

  for(int i=curS.size();i<s.size();i++){
    if(s[i]=='.'){ curS += '.'; continue;}
    for(int j=0;j<=9;j++)
      if(pickup(j+'0',curCnt)){
        curS += j+'0';
        break;
      }
  }
  cout << curS << endl;
  return true;
}

void work(){
  int cnt[10]={};
  for(int i=0;i<s.size();i++)
    if(isdigit(s[i])) cnt[s[i]-'0']++;

  for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='.') continue;
    for(char j=s[i]+1;j<='9';j++)
      if(success(s.substr(0,i)+j,cnt))
        return;
  }
  cout << "The price cannot be raised." << endl;
}

int main(){
  while(read()) work();
  return 0;
}
