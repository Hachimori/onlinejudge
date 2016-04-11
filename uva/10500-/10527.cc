#include<iostream>
using namespace std;

string n;

bool read(){
  cin >> n;
  return n!="-1";
}

bool canDivide(string &v, int div){
  int rem = 0;
  for(int i=v.size()-1;i>=0;i--){
    rem = rem*10+v[i];
    rem %= div;
  }
  return rem==0;
}

void div(string &v, int div){
  int rem = 0;
  string ret;
  for(int i=v.size()-1;i>=0;i--){
    rem = rem*10+v[i];
    ret += (char)(rem/div);
    rem %= div;
  }
  v = ret;
  while(v[0]==0) v = v.substr(1);
  reverse(v.begin(),v.end());
}

void work(){
  if(n.size()==1){
    cout << '1' << n << endl;
    return;
  }
  reverse(n.begin(),n.end());
  for(int i=0;i<n.size();i++) n[i] -= '0';

  int cnt[10]={0};
  for(int i=9;i>=2;i--)
    if(canDivide(n,i))
      while(canDivide(n,i)){
        div(n,i);
        cnt[i]++;
      }

  if(n.size()>1){
    cout << "There is no such number." << endl;
    return;
  }
  
  for(int i=1;i<=9;i++)
    for(int j=0;j<cnt[i];j++)
      cout << i;
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
