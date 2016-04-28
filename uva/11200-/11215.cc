#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define NUM 6
#define BUF 20000
#define nume first
#define deno second
using namespace std;
typedef pair<int,int> Fract;

int nNum, num[NUM];

bool read(){
  cin >> nNum;
  if(nNum==0) return false;
  
  for(int i=0;i<nNum;i++)
    cin >> num[i];
  
  return true;
}

int gcd(int a, int b){
  while(b!=0){
    int t = b;
    b = a%b;
    a = t;
  }
  
  return a;
}

void normalize(Fract &f){
  int div = gcd(abs(f.nume),f.deno);
  
  f.nume /= div;
  f.deno /= div;
}

void rsort(Fract A[], int nNum){
  const static int BASE = 256;
  static int count[BASE];
  static Fract W[1000000];
  
  Fract *work = W, *array = A;
  
  for(int cur=0;cur<21;cur+=7){
    for(int i=0;i<128;i++) count[i] = 0;
    for(int j=0;j<nNum;j++) count[(array[j].deno>>cur)&0x7f]++;
    for(int i=1;i<128;i++) count[i] += count[i-1];
    
    for(int i=nNum-1;i>=0;i--)
      work[--count[(array[i].deno>>cur)&0x7f]] = array[i];
    
    swap(work,array);
  }

  for(int cur=0;cur<21;cur+=7){
    for(int i=0;i<BASE;i++) count[i] = 0;
    for(int j=0;j<nNum;j++) count[(array[j].nume>>cur)&0x7f]++;
    for(int i=1;i<BASE;i++) count[i] += count[i-1];
    
    for(int i=nNum-1;i>=0;i--)
      work[--count[(array[i].nume>>cur)&0x7f]] = array[i];
    
    swap(work,array);
  }
  
  int tail = 0;
  static Fract buf[1000000];
  
  int cur;
  for(cur=nNum-1;cur>=0 && array[cur].nume<0;cur--); cur=(cur+1)%nNum;
  for(int i=0;i<nNum;i++,cur=(cur+1)%nNum) buf[i] = array[cur];
  for(int i=0;i<nNum;i++) array[i] = buf[i];
}

void rec(int L, int R, Fract s[NUM][NUM][BUF], int tail[NUM][NUM]){
  if(tail[L][R]!=0) return;

  if(L==R){
    s[L][R][tail[L][R]++] = Fract(num[L],1);
    return;
  }
  
  for(int k=L;k<R;k++){
    rec(L,k,s,tail);
    rec(k+1,R,s,tail);
    
    for(int i=0;i<tail[L][k];i++)
      for(int j=0;j<tail[k+1][R];j++){
        Fract &a = s[L][k][i], &b = s[k+1][R][j], f;
        
        // add
        f.nume = a.nume*b.deno + a.deno*b.nume;
        f.deno = a.deno*b.deno;
        normalize(f);
        s[L][R][tail[L][R]++] = f;

        // sub
        f.nume = a.nume*b.deno - a.deno*b.nume;
        f.deno = a.deno*b.deno;
        normalize(f);
        s[L][R][tail[L][R]++] = f;

        // mul
        f.nume = a.nume*b.nume;
        f.deno = a.deno*b.deno;
        normalize(f);
        s[L][R][tail[L][R]++] = f;
        
        // div
        f.nume = a.nume*b.deno;
        f.deno = a.deno*b.nume;

        if(f.deno==0) continue;
        if(f.deno<0){
          f.nume *= -1;
          f.deno *= -1;
        }
        normalize(f);
        s[L][R][tail[L][R]++] = f;
      }
  }
  
  rsort(s[L][R],tail[L][R]);
  tail[L][R] = unique(s[L][R],s[L][R]+tail[L][R]) - s[L][R];
}

void work(int cases){
  int tAns = 0;
  static Fract ans[1000000];

  do{
    static Fract s[NUM][NUM][BUF];
    int tail[NUM][NUM];
    
    for(int i=0;i<nNum;i++)
      for(int j=0;j<nNum;j++)
        tail[i][j] = 0;
    
    rec(0,nNum-1,s,tail);
    
    for(int i=0;i<tail[0][nNum-1];i++)
      ans[tAns++] = s[0][nNum-1][i];

    if(tAns>500000){
      rsort(ans,tAns);
      tAns = unique(ans,ans+tAns)-ans;
    }
  } while(next_permutation(num,num+nNum));
  
  rsort(ans,tAns);
  tAns = unique(ans,ans+tAns)-ans;

  cout << "Case " << cases << ": " << tAns << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
