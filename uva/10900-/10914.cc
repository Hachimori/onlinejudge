#include<iostream>
#include<numeric>
#include<algorithm>
#define RANGE 10000005
#define PRIME 5000005        // almost odd prime��2��񐔂Ɏ��̂�5000000�܂ł̑f���̐������߂�Ɨǂ�  
#define NUM_PRIME 400005     // 0-5000000�Ԃ̑f���̐���348513��
#define NUM_VAL 800005       // 0-10000000�Ԃ�almost odd prime�̐���73058��
using namespace std;

int nPrime, prime[NUM_PRIME];
int nVal;

// first�ɂ�0����10000000�܂ł�almost odd prime������A
// second�ɂ�0����10000000�܂ł� almost odd prime(N_i�Ƃ���)�̖񐔂̑��a - 2*N_i  ������
pair<int,long long> val[NUM_VAL]; 

void makePrime(){
  static bool isPrime[PRIME];
  fill(isPrime,isPrime+PRIME,true);
  
  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
	isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<PRIME;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

int mypow(int p, int n){
  if(n==1) return p;
  int t = mypow(p,n/2);
  return (n%2==0 ? t*t : t*t*p);
}

// p * (2^n) �̖񐔂̘a
// 
// a������, r������Ƃ������䐔��̘a: a*(r^n-1)/(r-1)
// �ɂ��B
int calcDivisor(int p, int n){
  return (p+1)*(mypow(2,n+1)-1);
}

void makeAbun(){
  nVal = 0;
  for(int i=1;i<nPrime;i++)
    for(int p=prime[i]*2,j=1;p<RANGE;p*=2,j++)
      val[nVal++] = make_pair(p,calcDivisor(prime[i],j)-2*p);
  
  sort(val,val+nVal);

  for(int i=1;i<nVal;i++)
    val[i].second += val[i-1].second;
}

int n;

bool read(){
  cin >> n;
  return n!=0;
}

void work(){
  cout << n << ' ' << (upper_bound(val,val+nVal,make_pair(n,(1LL<<50)))-1)->second << endl;
}

int main(){
  makePrime();
  makeAbun();
  
  while(read())
    work();
  
  return 0;
}
