#include<iostream>
using namespace std;

string a,b;

bool read(){
  return getline(cin,a) && getline(cin,b);
}

void get(string s, int cnt[128]){
  for(int i=0;i<s.size();i++)
    cnt[s[i]]++;
}

void work(){
  int cntA[128]={0}, cntB[128]={0};
  get(a,cntA);
  get(b,cntB);
  for(int i=0;i<128;i++)
    for(int j=0;j<min(cntA[i],cntB[i]);j++)
      cout << (char)i;
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
