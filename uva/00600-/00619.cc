#include<iostream>
using namespace std;
const int DIGIT = 40, NDIGIT2VAL = 30;

class BigInt{
public:
  int leng, digit[DIGIT];

  BigInt(){}
  BigInt(string s){
    leng = s.size();
    memset(digit,0,sizeof(digit));
    for(int i=0;i<s.size();i++)
      digit[s.size()-i-1] = s[i]-'0';
  }

  BigInt(int n){
    leng = 0;
    memset(digit,0,sizeof(digit));
    while(n){
      digit[leng++] = n%10;
      n /= 10;
    }
  }

  BigInt operator+ (BigInt opp) {
    for(int i=0;i+1<DIGIT;i++){
      opp.digit[i] += digit[i];
      if(opp.digit[i]) opp.leng = i+1;
      opp.digit[i+1] += opp.digit[i]/10;
      opp.digit[i] %= 10;
    }
    return opp;
  }

  BigInt operator- (BigInt opp) {
    BigInt ret = *this;
    ret.leng = 0;
    for(int i=0;i+1<DIGIT;i++){
      ret.digit[i] -= opp.digit[i];
      if(ret.digit[i]<0){
        ret.digit[i] += 10;
        ret.digit[i+1]--;
      }
      if(ret.digit[i]) ret.leng = i+1;
    }
    return ret;
  }

  BigInt operator* (BigInt opp) {
    BigInt ret = 0;
    for(int i=0;i<DIGIT;i++)
      for(int j=0;j<DIGIT;j++){
        if(i+j>=DIGIT) continue;
        ret.digit[i+j] += digit[i]*opp.digit[j];
        if(ret.digit[i+j]>=10){
          ret.digit[i+j+1] += ret.digit[i+j]/10;
          ret.digit[i+j] %= 10;
        }

      }

    ret.leng = 0;
    for(int i=0;i<DIGIT;i++)
      if(ret.digit[i]) 
        ret.leng = i+1;
    return ret;
  }

  string str() {
    string ret;
    for(int i=0;i<leng;i++){
      if(i && i%3==0) ret += ',';
      ret += digit[i]+'0';
    }
    reverse(ret.begin(),ret.end());
    return ret;
  }

  bool operator<= (BigInt opp) {
    if(leng!=opp.leng) return leng<opp.leng;
    for(int i=DIGIT-1;i>=0;i--)
      if(digit[i]!=opp.digit[i])
        return digit[i]<opp.digit[i];
    return true;
  }
};

BigInt ndigit2val[NDIGIT2VAL], powTbl[NDIGIT2VAL];

void makeTable(){
  ndigit2val[1] = 1;
  powTbl[0] = 1;
  powTbl[1] = 26;
  for(int i=2;i<NDIGIT2VAL;i++){
    powTbl[i] = powTbl[i-1]*26;
    ndigit2val[i] = powTbl[i-1]+ndigit2val[i-1];
  }
}


string s;

bool read(){
  cin >> s;
  return s!="*";
}

void work(){
  if(isdigit(s[0])){
    BigInt remain(s);
    int nDigit;
    for(int i=1;i<NDIGIT2VAL;i++)
      if(ndigit2val[i]<=remain)
        nDigit = i;
    
    string ans = string(nDigit,'a');
    remain = remain-ndigit2val[nDigit];
    for(int i=nDigit;i>=1;i--)
      while(powTbl[i-1]<=remain){
        remain = remain-powTbl[i-1];
        ans[nDigit-i]++;
      }

    printf("%-22s%s\n",ans.c_str(),BigInt(s).str().c_str());
  }
  else{
    BigInt ans = ndigit2val[s.size()];
    for(int i=s.size()-1;i>=0;i--)
      for(int j='a';j<s[i];j++)
        ans = ans+powTbl[s.size()-i-1];
    printf("%-22s%s\n",s.c_str(),ans.str().c_str());
  }
}

int main(){
  makeTable();
  while(read()) work();
  return 0;
}
