#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    int cnt[10]={},curCnt[10]={};
    while(n){ cnt[n%10]++; n/=10; }

    long long a = 0, b = 0;
    memcpy(curCnt,cnt,sizeof(cnt));
    for(int i=1;i<=9;i++)
      while(curCnt[i]){
        a = a*10+i;
        curCnt[i]--;
        while(curCnt[0]){
          a *= 10;
          curCnt[0]--;
        }
      }

    memcpy(curCnt,cnt,sizeof(cnt));
    for(int i=9;i>=0;i--)
      while(curCnt[i]){
        b = b*10+i;
        curCnt[i]--;
      }    

    cout << b << " - " << a << " = " << b-a << " = 9 * " << (b-a)/9 << endl;
  }
  return 0;
}
