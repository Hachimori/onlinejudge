#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
const int DIGIT = 205;

class Bi{
public:
  int leng, digit[DIGIT], base;

  Bi(){}
  Bi(string s, int b){
    memset(digit,0,sizeof(digit));
    base = b;
    leng = s.size();
    for(int i=s.size()-1;i>=0;i--){
      digit[i] = isdigit(s[i]) ? s[i]-'0' : s[i]-'A'+10;
      if(digit[i]>=base) leng = -1;
    }
  }

  Bi operator+ (Bi opp) {
    for(int i=0;i<leng;i++){
      opp.digit[i] += digit[i];
      opp.digit[i+1] += opp.digit[i]/base;
      opp.digit[i] %= base;
    }
    for(int i=0;i<DIGIT;i++)
      if(opp.digit[i])
        opp.leng = i+1;
    return opp;
  }

  Bi reverse(){
    Bi ret = *this;
    for(int i=0;i<leng/2;i++)
      swap(ret.digit[i],ret.digit[leng-i-1]);
    return ret;
  }

  bool isPalin(){
    for(int i=0;i<leng/2;i++)
      if(digit[i]!=digit[leng-i-1])
        return false;
    return true;
  }
};


string s;

bool read(){
  return cin >> s;
}


void work(){
  for(int base=15;base>=2;base--){
    if(base!=15) cout << ' ';

    Bi cur(s,base);
    if(cur.leng==-1){
      cout << '?';
      continue;
    }

    bool success = false;
    for(int i=0;i<=100;i++){
      if(cur.isPalin()){
        cout << i;
        success = true;
        break;
      }
      cur = cur+cur.reverse();
    }
    if(!success) cout << '?';
  }
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
