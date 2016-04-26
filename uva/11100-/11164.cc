/*
  頂点Aと頂点Xを線で繋ぎ、dの領域をd1とd2に分割する。
  d1は領域aに隣接し、d2は領域cに隣接しているとする。

  以降、a,b,c,d,d1,d2,をその領域の面積とする。
  
  
  BX:XE = b:c が成り立つ。
  よって、
  d1+a:d2 = b:c ... ①
  
  CX:XF = b:a が成り立つ。
  よって、
  d2+c:d1 = b:a ... ②


  ①、②をd1とd2に関して整理すると、
       a+b
  d1 = --- d2   ... ③
       b+c
               
  ③を①に代入すると、
       a*c*(b+c)
  d2 = --------    .... ④
       b^2-a*c

  ④を③に代入すると
       a*c*(a+b)
  d1 = --------    
        b^2-a*c

  
  あとは、d1とd2を足すと、dが求められる。
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
