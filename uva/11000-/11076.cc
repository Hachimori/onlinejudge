#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;

int nNum, num[10];

bool read(){
  for(int i=0;i<10;i++) num[i] = 0;
  
  cin >> nNum;
  if(nNum==0) return false;
  
  for(int i=0;i<nNum;i++){
    int n;
    cin >> n;
    num[n]++;
  }
  
  return true;
}

int gcd(int a, int b){
  return (b==0 ? a : gcd(b,a%b));
}

ull combi(int cnt[]){
  vector<int> nume, deno;
  
  for(int i=1;i<=nNum-1;i++) nume.push_back(i);
  for(int i=0;i<=9;i++)
    if(cnt[i]>0)
      for(int j=1;j<=cnt[i];j++)
	deno.push_back(j);
  
  for(int i=0;i<nume.size();i++){
    for(int j=0;j<deno.size();j++){
      int div = gcd(nume[i],deno[j]);
      nume[i] /= div, deno[j] /= div;
    }
  }

  ull ret = 1;
  for(int i=0;i<nume.size();i++) ret *= nume[i];
  
  return ret;
}

void work(){
  ull ans = 0;
  
  for(int i=0;i<=9;i++){
    if(num[i]==0) continue;
    num[i]--;
    ull toMul = combi(num);
    for(ull p=1,j=0;j<nNum;p*=10,j++) ans += p*toMul*i;
    num[i]++;
  }

  cout << ans << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
