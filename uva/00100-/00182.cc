#include<iostream>
#include<string>
using namespace std;

int pos;
string s;

bool read(){
  cin >> s >> pos;
  if(s=="0000000000" && pos==0) return false;
  pos--;
  return true;
}

int pow10[10];

int rec(int idx, int numAtPos){
  if(idx==s.size()) return 0;
  if(idx==pos){
    if(numAtPos==s[idx])
      return rec(idx+1,numAtPos);
    else if(numAtPos<s[idx])
      return idx<2 ? pow10[s.size()-idx-2] : pow10[s.size()-idx-1];
    else if(numAtPos>s[idx])
      return 0;
  }
  if(idx==2) return rec(idx+1,numAtPos);
  int ret = 0;
  for(int i=0;i<s[idx];i++){
    int npow = s.size()-idx-1;
    if(idx<pos && pos==2) npow--;
    else{
      if(idx<2) npow--;
      if(idx<pos) npow--;
    }
    ret += pow10[npow];
  }
  return ret+rec(idx+1,numAtPos);
}

void work(){
  pow10[0] = 1;
  for(int i=1;i<s.size();i++) pow10[i] = pow10[i-1]*10;
  for(int i=0;i<s.size();i++) s[i] -= '0';
  
  int numAtPos;
  for(int i=0;i<=9;i++){
    if(pos==2 && i!=s[pos]){
      printf("%11d\n",0);
      continue;
    }
    numAtPos = i;
    if(i==0 && s[2]==0)
      printf("%11d\n",rec(0,numAtPos)-1);
    else
      printf("%11d\n",rec(0,numAtPos));
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  return 0;
}
