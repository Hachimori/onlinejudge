#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>
#include<cstdio>
using namespace std;

vector<string> sList;

void read(){
  sList.clear();

  string s;
  getline(cin,s);

  stringstream in(s);
  while(in >> s) sList.push_back(s);
}


void work(int cases){
  double P = -1, I = -1, U = -1;

  for(int i=0;i<sList.size();i++){
    string s = sList[i];
    int idx = 0;
    while(idx+3<s.size() && s[idx+1]=='='){
      double &val = s[idx]=='P' ? P : s[idx]=='I' ? I : U;

      idx += 2;
      string digit;
      for(;s[idx]=='.' || isdigit(s[idx]);idx++) digit += s[idx];

      val = atof(digit.c_str());
      
      if(s[idx]=='m'){ val *= 1e-3; idx++; }
      if(s[idx]=='k'){ val *= 1e+3; idx++; }
      if(s[idx]=='M'){ val *= 1e+6; idx++; }
      
      idx++;
    }
  }

  cout << "Problem #" << cases << endl;
  if(P<-0.5) printf("P=%.2lfW\n",U*I);
  if(I<-0.5) printf("I=%.2lfA\n",P/U);
  if(U<-0.5) printf("U=%.2lfV\n",P/I);
  cout << endl;
}


int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy);
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
