// DP
//
//
// E-transform は数列の全ての要素Ajを
// Aj-1 < Bj <= Aj かつ Bj%(Aj-1 - Aj)==0 となる Bj に変えることである。
//
// ある数列がEigensequenceになるかは、数列の全ての要素Ajが
// Aj-1 < Bj <= Aj かつ Bj%(Aj-1 - Aj)==0 かつ Bj==Aj となるかどうかで判定できる。
//
// Aj-2以前の数は考慮する必要がないことが重要。
//
//
// tbl[n]には、始めがstart,終わりがnとなっているEigensequenceの個数を保存。
// 
// tbl[n+i] (i: i%(n+i)==0となるi) は tbl[n]の一部であるから,
// tbl[n+i] += tbl[n]としてゆき、ボトムアップにテーブルを構築する。

#include<iostream>
#include<vector>

#define BUF 50

using namespace std;

int start, finish;

bool read(){
  cin >> start >> finish;
  if(start>=finish) return false;
  return true;
}

void work(){
  vector<int> tbl(BUF,0);
  tbl[start] = 1;
  
  for(int i=start;i<finish;i++)
    for(int j=i+1;j<=finish;j++)
      if(j%(j-i)==0)
	tbl[j] += tbl[i];
  
  cout << start << ' ' << finish << ' ' << tbl[finish] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
