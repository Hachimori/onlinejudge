#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum OPE{PLUS=-1,MUL=-2};

vector<long long> ope;

void read(){
  ope.clear();
  string s;
  cin >> s;
  for(int i=0;i<s.size();){
    if(s[i]=='+'){
      ope.push_back(PLUS);
      i++;
    }
    else if(s[i]=='*'){
      ope.push_back(MUL);
      i++;
    }
    else{
      int toPush = 0;
      while(i<s.size() && isdigit(s[i])){
        toPush *= 10;
        toPush += s[i++]-'0';
      }
      ope.push_back(toPush);
    }
  }
}

void calcWhile(vector<long long> &v, int o){
  while(1){
    bool update = false;
    for(int i=0;i<v.size();i++)
      if(v[i]==o){
        if(o==PLUS)
          v[i-1] += v[i+1];
        else
          v[i-1] *= v[i+1];
        update = true;
        v.erase(v.begin()+i);
        v.erase(v.begin()+i);
        break;
      }
    if(!update) break;
  }
}

void work(){
  vector<long long> ans1 = ope, ans2 = ope;
  calcWhile(ans1,MUL);
  calcWhile(ans1,PLUS);
  calcWhile(ans2,PLUS);
  calcWhile(ans2,MUL);
  cout << "The maximum and minimum are " 
       << ans2[0] << " and " << ans1[0] << "." << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
