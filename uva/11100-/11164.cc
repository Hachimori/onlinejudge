/*
  ���_A�ƒ��_X����Ōq���Ad�̗̈��d1��d2�ɕ�������B
  d1�͗̈�a�ɗאڂ��Ad2�͗̈�c�ɗאڂ��Ă���Ƃ���B

  �ȍ~�Aa,b,c,d,d1,d2,�����̗̈�̖ʐςƂ���B
  
  
  BX:XE = b:c �����藧�B
  ����āA
  d1+a:d2 = b:c ... �@
  
  CX:XF = b:a �����藧�B
  ����āA
  d2+c:d1 = b:a ... �A


  �@�A�A��d1��d2�Ɋւ��Đ�������ƁA
       a+b
  d1 = --- d2   ... �B
       b+c
               
  �B���@�ɑ������ƁA
       a*c*(b+c)
  d2 = --------    .... �C
       b^2-a*c

  �C���B�ɑ�������
       a*c*(a+b)
  d1 = --------    
        b^2-a*c

  
  ���Ƃ́Ad1��d2�𑫂��ƁAd�����߂���B
*/


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double A, B, C;

bool read(){
  cin >> A >> B >> C;
  return A>=-1.0e-8;
}

void work(int cases){
  cout << "Set " << cases << ":" << endl;
  
  if(B*B-A*C<1.0e-8){
    cout << "Poor King!" << endl;
    return;
  }

  double d1 = (A*C*(B+C))/(B*B-A*C);
  double d2 = (A*C*(A+B))/(B*B-A*C);

  printf("%.4lf\n",d1+d2);
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
