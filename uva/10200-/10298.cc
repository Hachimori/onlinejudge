// KMP‚É‚æ‚éüŠú‚ÌŒŸo
//
// Ú‚µ‚­‚Í ~/library/other/kmpCycleDetect.cc

#include<iostream>
#include<cstdio>

#define MAX_SIZE 1000005

using namespace std;

char str[MAX_SIZE];

bool read(){
  scanf("%s",str);
  if(strcmp(str,".")==0) return false;
  return true;
}

void work(){
  int N = strlen(str);
  static int next[MAX_SIZE];
  
  next[0] = -1;
  for(int i=0,j=-1;i<N;i++,j++,next[i]=j)
    while(j>=0 && str[i]!=str[j]) j = next[j];

  if(next[N]!=0 && N%(N-next[N])==0) cout << N/(N-next[N]) << endl;
  else cout << 1 << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
