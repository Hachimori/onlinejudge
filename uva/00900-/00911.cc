#include<iostream>
#include<vector>
#define BUF 105
using namespace std;

int nPow, nVar, eachP[BUF];

bool read(){
  if(!(cin >> nPow >> nVar)) return false;

  for(int i=0;i<nVar;i++)
    cin >> eachP[i];
  
  return true;
}

int gcd(int a, int b){
  return (b==0 ? a : gcd(b,a%b));
}

int calc(){
  vector<int> nume, deno;
  
  for(int i=2;i<=nPow;i++)
    nume.push_back(i);

  for(int i=0;i<nVar;i++)
    for(int j=2;j<=eachP[i];j++)
      deno.push_back(j);

  for(int i=0;i<nume.size();i++){
    for(int j=0;j<deno.size();j++){
      int div = gcd(nume[i],deno[j]);
      nume[i] /= div;
      deno[j] /= div;
    }
  }

  int ret = 1;
  for(int i=0;i<nume.size();i++)
    ret *= nume[i];

  return ret;
}

void work(){
  cout << calc() << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
