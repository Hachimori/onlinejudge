// ad-hoc
//
// 
// Œ´—‚Í‚í‚©‚ç‚È‚¢‚ªA‚ ‚é”—ñ‚ğ“ñ‚Â‚É•ª‚¯‚Ä•Ğ•û‚Í“ñ”{A
// ‚à‚¤•Ğ•û‚Í“ñ”{‚µ‚Ä‚P‚ğ‘«‚µ‚ÄA“ñ‚Â‚Ì”—ñ‚ğ‚­‚Á‚Â‚¯‚é‚Æ‚æ‚¢B

#include<iostream>
#include<vector>
using namespace std;

int N;

bool read(){
  cin >> N;
  if(N==0) return false;
  return true;
}

void make(int n, vector<int> &ret){
  if(n==1){
    ret.push_back(0);
    return;
  }
  if(n==2){
    ret.push_back(0),ret.push_back(1);
    return;
  }
  if(n==3){
    ret.push_back(0),ret.push_back(2),ret.push_back(1);
    return;
  }
  if(n==4){
    ret.push_back(0),ret.push_back(2);
    ret.push_back(1),ret.push_back(3);
    return;
  }
  
  vector<int> a, b;

  make((n+1)/2,a);
  make(    n/2,b);

  for(int i=0;i<a.size();i++) ret.push_back(a[i]*2);
  for(int i=0;i<b.size();i++) ret.push_back(b[i]*2+1);
}

void work(){
  vector<int> ans;
  make(N,ans);

  cout << N << ':';
  for(int i=0;i<ans.size();i++)
    cout << ' ' << ans[i];
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
