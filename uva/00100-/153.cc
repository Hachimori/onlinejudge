// dynamic programming
// 
// 
// 最後方の数字から順に計算して、それを元に全体のスコアを求める。
// テーブルに保存する値は、その文字列の順列が何番目か、
// その文字列を何通り並び替えることができるか。
//
//
// bacaのスコアの計算をしてみる。
// 
//    a の辞書順は 1, 何通りの並び替えができるか 1
//   ca の辞書順は 2, 何通りの並び替えができるか 2
//  aca の辞書順は 2, 何通りの並び替えができるか 3
// baca の辞書順は 8, 何通りの並び替えができるか 12
//
//
// どのように辞書順を計算するのかというと、
//
// bacaの辞書順は、
//
// aを先頭とした文字列の並び替え: aabc, aacb, abac, abca, acab, acba
// bを先頭とした文字列の並び替え: baac, baca, bcaa
//
// の9通りだが、bcaaはbacaの後にくる文字列なのでこれは除かれ、
// 全部で8通りとなる。
//
// 除かれる文字列の数は一つ前のテーブルの値、 (並び替え数-辞書順)
// として求めることができる。 
//
//
// ちなみに、　aabc: 1
//             aacb: 2
//             abac: 3
//             abca: 4
//             acab: 5
//             acba: 6
//             baac: 7
//             baca: 8
//             bcaa: 9
//             caab: 10
//             caba: 11
//             cbaa: 12


#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

#define MAX_SIZE 35
#define MAX_CHAR 256

using namespace std;

class Data{
public:
  
  long long score, nPermu;
  
  Data(){}
  Data(long long s, long long n): score(s), nPermu(n){}
};

string str;

bool read(){
  cin >> str;
  if(str=="#") return false;
  return true;
}

long long gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

long long calcFact(int numeFact, vector<int> &denoFact){
  vector<int> nume, deno;
  
  for(int i=2;i<=numeFact;i++)
    nume.push_back(i);

  for(int i=0;i<denoFact.size();i++)
    for(int j=2;j<=denoFact[i];j++)
      deno.push_back(j);
  
  for(int i=0;i<nume.size();i++){
    for(int j=0;j<deno.size();j++){
      long long ret = gcd(nume[i],deno[j]);

      nume[i] /= ret;
      deno[j] /= ret;
    }
  }
  
  long long ret = 1;
  for(int i=0;i<nume.size();i++)
    ret *= nume[i];

  return ret;
}

void work(){
  int nChar[MAX_CHAR];
  Data table[MAX_SIZE];
  
  for(int i=0;i<MAX_CHAR;i++)
    nChar[i] = 0;

  reverse(str.begin(),str.end());
  
  nChar[str[0]]++;
  table[0] = Data(1,1);
  
  for(int i=1;i<str.size();i++){
    nChar[str[i]]++;
    
    long long sum = 0;
    for(int j='a';j<=str[i];j++){
      if(nChar[j]==0) continue;
      nChar[j]--;
      
      vector<int> denoFact;
      for(int k='a';k<='z';k++)
	if(nChar[k]>1)
	  denoFact.push_back(nChar[k]);
      
      sum += calcFact(i,denoFact);
      nChar[j]++;
    }
    
    vector<int> denoFact;
    for(int j='a';j<='z';j++)
      if(nChar[j]>1)
	denoFact.push_back(nChar[j]);
    
    table[i] = Data(sum-(table[i-1].nPermu-table[i-1].score),calcFact(i+1,denoFact));
    
    /*
    for(int j=0;j<=i;j++)
      cout << str[j];
    cout << endl;
    cout << table[i].score << ' ' << table[i].nPermu << endl;
    */
  }
  
  printf("%10lld\n",table[str.size()-1].score);
}

int main(){
  while(read())
    work();
  
  return 0;
}
