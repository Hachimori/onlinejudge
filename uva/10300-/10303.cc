#include<iostream>
#include<vector>
using namespace std;
const int BUF = 10000;

int n;

bool read(){
  return cin >> n;
}

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

void work(){
  vector<int> nume, deno;
  for(int i=2;i<=n*2;i++) nume.push_back(i);
  for(int i=2;i<=n;i++) deno.push_back(i);
  for(int i=2;i<=n+1;i++) deno.push_back(i);
  
  for(int i=0;i<deno.size();i++)
    for(int j=0;j<nume.size();j++){
      int toDiv = gcd(deno[i],nume[j]);
      deno[i] /= toDiv;
      nume[j] /= toDiv;
    }

  int mul[BUF] = {0}, len = 1;
  mul[0] = 1;

  for(int i=0;i<nume.size();i++){
    for(int j=0;j<len;j++) mul[j] *= nume[i];
    for(int j=0;j<BUF;j++){
      if(mul[j]>=10){
        mul[j+1] += mul[j]/10;
        mul[j] %= 10;
      }
      if(mul[j]) len = j+1;
    }
  }

  for(int i=len-1;i>=0;i--)
    cout << mul[i];
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
