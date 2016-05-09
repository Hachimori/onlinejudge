#include<iostream>
using namespace std;
const int BUF = 100005;

int leng, nTake;
string s;

bool read(){
  int nErase;
  cin >> leng >> nErase;
  if(!(leng|nErase)) return false;
  cin >> s;
  nTake = leng-nErase;
  return true;
}

bool exist(int digit, int L, int R, int cnt[10][BUF]){
  return cnt[digit][R]-(L==0 ? 0 : cnt[digit][L-1]);
}

void work(){
  static int cnt[10][BUF];
  memset(cnt,0,sizeof(cnt));

  for(int i=0;i<10;i++)
    for(int j=0;j<leng;j++){
      cnt[i][j] = j==0 ? 0 : cnt[i][j-1];
      cnt[i][j] += s[j]-'0'==i;
    }

  string ans;
  for(int i=0;ans.size()<nTake && i<leng;i++){
    char toGet;
    for(int digit=9;digit>=0;digit--){
      if(exist(digit,i,leng-(nTake-ans.size()),cnt)){
        toGet = digit+'0';
        break;
      }
    }
    while(s[i]!=toGet) i++;
    ans += s[i];
  }

  cout << ans << endl;
}


int main(){
  while(read()) work();
  return 0;
}
