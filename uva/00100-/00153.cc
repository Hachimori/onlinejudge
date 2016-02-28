// dynamic programming
// 
// 
// �Ō���̐������珇�Ɍv�Z���āA��������ɑS�̂̃X�R�A�����߂�B
// �e�[�u���ɕۑ�����l�́A���̕�����̏��񂪉��Ԗڂ��A
// ���̕���������ʂ���ёւ��邱�Ƃ��ł��邩�B
//
//
// baca�̃X�R�A�̌v�Z�����Ă݂�B
// 
//    a �̎������� 1, ���ʂ�̕��ёւ����ł��邩 1
//   ca �̎������� 2, ���ʂ�̕��ёւ����ł��邩 2
//  aca �̎������� 2, ���ʂ�̕��ёւ����ł��邩 3
// baca �̎������� 8, ���ʂ�̕��ёւ����ł��邩 12
//
//
// �ǂ̂悤�Ɏ��������v�Z����̂��Ƃ����ƁA
//
// baca�̎������́A
//
// a��擪�Ƃ���������̕��ёւ�: aabc, aacb, abac, abca, acab, acba
// b��擪�Ƃ���������̕��ёւ�: baac, baca, bcaa
//
// ��9�ʂ肾���Abcaa��baca�̌�ɂ��镶����Ȃ̂ł���͏�����A
// �S����8�ʂ�ƂȂ�B
//
// ������镶����̐��͈�O�̃e�[�u���̒l�A (���ёւ���-������)
// �Ƃ��ċ��߂邱�Ƃ��ł���B 
//
//
// ���Ȃ݂ɁA�@aabc: 1
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
