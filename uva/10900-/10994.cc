//$B!!2rK!(B
//$B!!(B
//$B!!(Blow $B$H(B up $B$,M?$($i$l$?$H$-!"(B
//
//$B!!&2(Blow->up f(i) $B$G$O$J$/!"(B
//    $B&2(B0->up f(i) - $B&2(B0->low f(i) + f(low) $B$r7W;;!#(B
//  
//
//$B!!&2(B0->A f(i)$B!!$r7W;;$9$k:]!"(B
//  A = a*1000 + b*100 + c*10 + d$B!!$J$i$P!"(B
//
//  $B&2(B0->A f(i) = $B&2(B0->(a*1000) f(i) + $B&2(B0->(b*100) f(i)
//                  + $B&2(B0->(c*10) f(i) + $B&2(B0->d f(i) $B!!$H$J$k!#(B
// 
//  
//  $B&2(B0->A f(i)$B!!$K4X$7$FK!B'$,$"$k!#Nc$($P!"(B
//  
//  $B&2(B0->10 f(i) = 46 
//  $B&2(B0->100 f(i) = 496 
//  $B&2(B0->1000 f(i) = 4996 
//  $B&2(B0->10000 f(i) = 49996 
//
//   ...
//
//  $B&2(B0->20 f(i) = 93 
//  $B&2(B0->200 f(i) = 993 
//  $B&2(B0->2000 f(i) = 9993
//  $B&2(B0->20000 f(i) = 99993 
//
//  ...
//
//  $B&2(B0->30 f(i) = 141 
//  $B&2(B0->300 f(i) = 1491 
//  $B&2(B0->3000 f(i) = 14991
//  $B&2(B0->30000 f(i) = 149991 
//
//  $B$N$h$&$K!"(B $B&2(B0->a*10 f(i) $B$N?tCM$K(B9$B$,A^F~$5$l$F$$$/!#(B
//
//
// $B$?$@$7!"(B
//
//  $B&2(B0->90 f(i) = 450
//  $B&2(B0->900 f(i) = 4500
//  $B&2(B0->9000 f(i) = 45000
//  $B&2(B0->90000 f(i) = 450000
//
// $B$G$"$k!#(B



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
