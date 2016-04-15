// 10831
// ������]�E���R�r�L��
//
// a �� p ���݂��ɑf��
// x^2 �� a%p
// ���������Ƃ��Aa��p��@�Ƃ��ĕ�����]�ł���Ƃ����B
//
// x^2 �� a%p �ɂ��āA
// p = 7�@�̂Ƃ�
// 
// 0^2 = 0  �� 0
// 1^2 = 1  �� 1
// 2^2 = 4  �� 4
// 3^2 = 9  �� 2 (9 mod 7)
// 4^2 = 16 �� 2 (16 mod 7)
// 5^2 = 25 �� 4 (25 mod 7)
// 6^2 = 36 �� 1 (36 mod 7)
//
// �ƂȂ�A0,1,2,4,�́A7��@�Ƃ��ĕ�����]�ł���B
//
//
// �ȉ���(a/p)�����W�����h���L���Ƃ����B
// (a/p) = 1 if(gcd(a,p)==1 && x^2��a%p ����������)
// (a/p) = 0 if(gcd(a,p)!=1)
// (a/p) = -1 if(gcd(a,p)==1 && x^2��a%p �����������Ȃ�)
//
// n>2 �ł���f���Ȃ�΃��W�����h���L���ƃ��R�r�L���͓������B
//
//
// http://www80.sakura.ne.jp/~aozora/suuron/node39.html
// http://www.absoluteastronomy.com/ref/jacobi_symbol
// http://futureboy.homeip.net/fsp/colorize.fsp?fileName=JacobiSymbol.frink

#include<iostream>
#include<cmath>
#include<cfloat>
#include<algorithm>

#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)

using namespace std;

int a,p;

bool read(){
  cin >> a >> p;
  if(a==-1 && p==-1) return false;
  
  return true;
}

// p ��2���傫���f���łȂ��Ă͂Ȃ�Ȃ�
// p ��2���傫���f���������Ȃ����Ƃ͖�蕶�ŕۏ؂���Ă���
int jacobi(int a, int p){
  
  int j = 1;

  a %= p;
  if(a<0)
    a += p;
  
  while(a!=0){
    
    while(a%2==0){
      a /= 2;
      if(p%8==3 || p%8==5) j = -j;
    }
    
    swap(a,p);
    
    if(a%4==3 && p%4==3) j = -j;
    
    a %= p;
    
  }
  
  if(p==1) return j;
  else return 0;
}

void work(){
  
  if(jacobi(a,p)!=-1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
