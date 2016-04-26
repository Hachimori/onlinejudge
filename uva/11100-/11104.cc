// DP(LCS) + ad-hoc
//
//
// 問題の意味: 
// 文字列aと文字列bは、それぞれの文字列の半分の長さ以上の
// 共通文字列があれば1番目のいとこにあたる(意訳)。
//
// 文字列cと文字列dは、cの1番目のいとこであり、dのn番目のいとこ
// となる文字列eがあるならばn+1番目のいとこである。
//
// 与えられる２つの文字列がの何番目のいとこにあたるかを求める。
//
// 
// 解法:
// 解釈の仕方としては、文字列aを "aのいとこでなおかつbに似ている文字列"
// に変換していく。というように考える。
// 
// bに似せるには、bのいくつかの字をそのまま持ってくるといいのだが、
// いくつ持ってくるかが問題となる。
// ここで、aのいとこであるためには、aと等しい共通文字列の長さが２つの
// 文字列の半分以上でなくてはならない、という点に着目する。
//
// aの現在の文字数分、bの字をaにくっつけたものをaのいとことする。
// こうすることで、aとaのいとこの共通文字数は "aの文字数" となり、
// aのいとこの文字数のちょうど半分であるから、いとこの条件を満たしている。
// かつ、くっつけた文字はbからとってきたものであるから、
// aの文字数ぶんだけbに似せることができる。
//
// これを、マッチ数がBの長さの半分以上となるまで繰り返す。

#include<iostream>
#include<string>
#include<algorithm>

#define BUF 105

using namespace std;

string A, B;

bool read(){
  cin >> A >> B;
  if(A=="0" && B=="0") return false;
  if(A.size()>B.size()) swap(A,B);
  return true;
}

int lcs(){
  int n = A.size(), m = B.size(), b[BUF][BUF];
  
  for(int i=0;i<=n;i++)
    b[i][0] = 0;
  for(int i=0;i<=m;i++)
    b[0][m] = 0;
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(A[i-1]==B[j-1])
	b[i][j] = b[i-1][j-1]+1;
      else
	b[i][j] = max(b[i-1][j-1],max(b[i-1][j],b[i][j-1]));
    }
  }
  
  return b[n][m];
}

void work(){
  int nMatch = lcs(), ans = 1;
  int n = A.size(), m = B.size();
  
  while(nMatch*2<m){
    ans++;
    nMatch += n;
    n *= 2;
  }
  cout << ans << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
