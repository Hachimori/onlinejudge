#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

vector<int> coeff, xList;

bool read(){
  coeff.clear();
  xList.clear();

  string s;
  if(!getline(cin,s)) return false;
  stringstream in(s);
  
  int v;
  while(in >> v) coeff.push_back(v);

  in.clear();
  getline(cin,s);
  in.str(s);

  while(in >> v) xList.push_back(v);

  return true;
}


int mypow(int p, int n){
  int ret = 1;
  for(int i=0;i<n;i++) ret *= p;
  return ret;
}


void work(){
  for(int i=0;i<xList.size();i++){
    int sum = 0;
    for(int j=0;j<coeff.size();j++)
      sum += coeff[j]*mypow(xList[i],coeff.size()-j-1);
    if(i) cout << ' ';
    cout << sum;
  }cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
