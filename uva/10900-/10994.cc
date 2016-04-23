//　解法
//　
//　low と up が与えられたとき、
//
//　Σlow->up f(i) ではなく、
//    Σ0->up f(i) - Σ0->low f(i) + f(low) を計算。
//  
//
//　Σ0->A f(i)　を計算する際、
//  A = a*1000 + b*100 + c*10 + d　ならば、
//
//  Σ0->A f(i) = Σ0->(a*1000) f(i) + Σ0->(b*100) f(i)
//                  + Σ0->(c*10) f(i) + Σ0->d f(i) 　となる。
// 
//  
//  Σ0->A f(i)　に関して法則がある。例えば、
//  
//  Σ0->10 f(i) = 46 
//  Σ0->100 f(i) = 496 
//  Σ0->1000 f(i) = 4996 
//  Σ0->10000 f(i) = 49996 
//
//   ...
//
//  Σ0->20 f(i) = 93 
//  Σ0->200 f(i) = 993 
//  Σ0->2000 f(i) = 9993
//  Σ0->20000 f(i) = 99993 
//
//  ...
//
//  Σ0->30 f(i) = 141 
//  Σ0->300 f(i) = 1491 
//  Σ0->3000 f(i) = 14991
//  Σ0->30000 f(i) = 149991 
//
//  のように、 Σ0->a*10 f(i) の数値に9が挿入されていく。
//
//
// ただし、
//
//  Σ0->90 f(i) = 450
//  Σ0->900 f(i) = 4500
//  Σ0->9000 f(i) = 45000
//  Σ0->90000 f(i) = 450000
//
// である。



#include<iostream>

using namespace std;

int low, up;
int table[10][2];

void makeTable(){

  table[0][0] = 0;
  table[0][1] = 0;
  
  table[1][0] = 4;
  table[1][1] = 6;
  
  table[2][0] = 9;
  table[2][1] = 3;
  
  table[3][0] = 14;
  table[3][1] = 1;
  
  table[4][0] = 19;
  table[4][1] = 0;

  table[5][0] = 24;
  table[5][1] = 0;

  table[6][0] = 29;
  table[6][1] = 1;

  table[7][0] = 34;
  table[7][1] = 3;

  table[8][0] = 39;
  table[8][1] = 6;
  
  table[9][0] = 45;
  table[9][1] = 0;
}

bool read(){
  cin >> low >> up;
  if(low<0 && up<0) return false;

  return true;
}

int getFirstDigit(int n){
  int t = n;
  
  if(t==0) return 0;
  
  while(t%10==0) t/=10;
  
  return t%10;
}

long long calcSum(int n){
  
  long long ret = 0;

  for(long long p=1;n>0;p*=10,n/=10){
    
    if(p==1)
      ret += (n%10)*(n%10+1)/2;
    else {
      long long toPlus = 0;
      
      if(n%10!=9 && n%10!=0)
	for(long long pp=10;pp<=p/10;pp*=10)
	  toPlus += pp*9;

      toPlus += p*table[n%10][0];
      toPlus += table[n%10][1];

      ret += toPlus;
    }

  }
  
  return ret;
}

void work(){
  
  long long sumL, sumR;
  int firstDigit = getFirstDigit(low);

  sumL = calcSum(low);
  sumR = calcSum(up);
  
  cout << sumR-sumL+firstDigit << endl;
}

int main(){
  
  makeTable();
  
  while(read())
    work();
    
  return 0;
}
