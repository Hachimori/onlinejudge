#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
const int COEFF = 9;

int coeff[COEFF];

bool read(){
  for(int i=0;i<COEFF;i++) 
    if(!(cin >> coeff[i]))
      return false;
  return true;
}


void work(){
  vector< pair<int,int> > ans; //(coeff,pow)
  for(int i=0;i<COEFF;i++)
    if(coeff[i])
      ans.push_back(make_pair(coeff[i],COEFF-i-1));

  for(int i=0;i<ans.size();i++){
    pair<int,int> v = ans[i];
    if(i) cout << ' ';
    if(v.first<0 && i) cout << "- ";
    else if(v.first<0 && i==0) cout << "-";
    else if(i) cout << "+ ";
    if(abs(v.first)>1 || v.second==0) cout << abs(v.first);
    if(v.second>1) cout << "x^" << v.second;
    else if(v.second==1) cout << "x";
  }
  if(ans.empty()) cout << 0;
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
