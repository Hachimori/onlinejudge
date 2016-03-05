#include<iostream>
#include<string>
#include<cctype>
using namespace std;
const int BUF = 200;

class BigInt{
public:
  int len, digit[BUF];

  BigInt(){}
  BigInt(string s){
    memset(digit,0,sizeof(digit));
    len = 0;
    for(int i=s.size()-1;i>=0;i--)
      if(isdigit(s[i]))
        digit[len++] = s[i]-'0';
  }

  BigInt operator* (BigInt bi){
    BigInt ret = string("0");
    for(int i=0;i<len;i++)
      for(int j=0;j<bi.len;j++)
        ret.digit[i+j] += digit[i]*bi.digit[j];
    for(int i=0;i<BUF;i++){
      if(ret.digit[i]>=10){
        ret.digit[i+1] += ret.digit[i]/10;
        ret.digit[i] %= 10;
      }
      if(ret.digit[i]) ret.len = i+1;
    }
    return ret;
  }
};

string s;
int n;

bool read(){
  return cin >> s >> n;
}

void work(){
  int dotFromRight = n*(s.size()-s.find('.')-1);
  
  BigInt p = s, ans = string("1");
  for(int kk=0;kk<n;kk++)
    ans = ans*p;

  string sAns = "";
  for(int i=0,cnt=0;i<ans.len || cnt<dotFromRight;i++){
    if(i<ans.len)
      sAns += (char)(ans.digit[i]+'0');
    else
      sAns += '0';
    cnt++;
    if(cnt==dotFromRight)
      sAns += '.';
  }

  while(sAns[0]=='0') sAns.erase(0,1);
  for(int i=sAns.size()-1;i>=0;i--)
    cout << sAns[i];
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
