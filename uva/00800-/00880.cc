#include<iostream>
#include<cstdio>
#include<cmath>
#include<cfloat>

using namespace std;

bool read(){
  long long n;
  if(scanf("%lld",&n)==EOF) return false;
  
  long long cursor;

  int root = (int)(sqrt((double)(1+8*n))+0.5);
  double doubleRoot = sqrt((double)(1+8*n));

  if(fabs(root-doubleRoot)<FLT_EPSILON) cursor = (long long)(-1+(sqrt((double)(1+8*n))+0.5))/2;
  else cursor = (long long)floor((-1+(sqrt((double)(1+8*n))))/2);

  
  long long mod = n-cursor*(cursor+1)/2;
  
  if(mod==0) printf("1/%lld\n",cursor);  
  else printf("%lld/%lld\n",cursor+2-mod,mod);  
      
}

int main(){

  while(read()){}

  return 0;
}
