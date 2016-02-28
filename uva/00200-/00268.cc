#include<iostream>
#include<vector>
using namespace std;
const int BUF = 205;

vector<int> tbl[BUF];

bool betterThan(vector<int> &a, vector<int> &b){
  if(a[0]==-1) return false;
  if(b[0]==-1) return true;
  int aIdx = a.size()-1, bIdx = b.size()-1;
  while(a[aIdx]==0) aIdx--;
  while(b[bIdx]==0) bIdx--;
  if(aIdx>bIdx) return false;
  if(aIdx<bIdx) return true;
  for(int i=aIdx;i>=0;i--) 
    if(a[i]!=b[i])
      return a[i]<b[i];
  return false;
}

vector<int> calc(int a0, int a1, int base){
  int ai = a0, aiPlus1 = a1, carry = a0*2>=base;
  vector<int> ret;
  while(1)
    for(int i=0;i<base;i++)
      if((carry+aiPlus1*2)%base==i){
        ret.push_back(ai);
        if(i==a0 && carry+aiPlus1*2==i){  ret.push_back(aiPlus1); return ret;}
        carry = carry+aiPlus1*2>=base;
        ai = aiPlus1;
        aiPlus1 = i;
        break;
      }
}

vector<int> getAns(int base){
  vector<int> ans;
  ans.push_back(-1);
  for(int a0=0;a0<base;a0++)
    for(int a1=0;a1<base;a1++){
      if(a0==0 && a1==0) continue;
      if(a0*2%base!=a1) continue;
      vector<int> ret = calc(a0,a1,base);
      if(betterThan(ret,ans)) ans = ret;
    }
  return ans;
}

void makeTable(){
  for(int i=0;i<BUF;i++)
    tbl[i] = getAns(i);
}


int _base;

bool read(){
  return cin >> _base;
}

void work(){
  cout << "For base " << _base << " the double-trouble number is" << endl;
  for(int i=tbl[_base].size()-1;i>=0;i--)
    cout << tbl[_base][i] << ' ';
  cout << endl;
}

int main(){
  makeTable();
  for(int i=0;read();i++) work();
  return 0;
}
