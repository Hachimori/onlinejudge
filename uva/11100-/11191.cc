#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#define NUM 200005
#define BUF 1024
using namespace std;

int nPrime, prime[10];

void makePrime(){
  bool isPrime[30];
  for(int i=0;i<30;i++)
    isPrime[i] = true;

  for(int i=2;i*i<30;i++)
    if(isPrime[i])
      for(int j=i*2;j<30;j+=i)
	isPrime[j] = false;

  nPrime = 0;
  for(int i=2;i<30;i++)
    if(isPrime[i])
      prime[nPrime++] = i;
}

int nNum;
long long nZero, num[NUM];

void read(){
  scanf("%d",&nNum);

  nZero = 0;
  for(int i=0;i<nNum;i++){
    scanf("%lld",&num[i]);
    if(num[i]==0){
      nNum--;
      i--;
      nZero++;
    }
  }
}

int convert(long long n){
  int ret = 0;

  for(int i=0;i<nPrime;i++){
    int cnt = 0;
    while(n%prime[i]==0){
      n /= prime[i];
      cnt++;
    }

    ret += (1<<i)*(cnt%2==1);
  }

  return ret;
}

long long myabs(long long n){
  return (n<0 ? -n : n);
}

void work(){
  long long cnt[2][BUF];
  fill(cnt[0],cnt[0]+BUF,0);
  fill(cnt[1],cnt[1]+BUF,0);

  for(int i=0;i<nNum;i++)
    cnt[(num[i]<0)][convert(myabs(num[i]))]++;
  
  long long ans1 = 0, ans2 = 0;
  
  for(int i=0;i<BUF;i++){
    if(cnt[0][i]==0 && cnt[1][i]==0) continue;
    for(int j=i;j<BUF;j++){
      if(cnt[0][j]==0 && cnt[1][j]==0) continue;
      
      if((i^j)==0){
	if(i==j){
	  ans1 += cnt[0][i]*(cnt[0][i]-1)/2 + cnt[1][i]*(cnt[1][i]-1)/2;
	}
	else{
	  //cout << i << ' ' << j << ']' << cnt[i] << endl;
	  ans1 += cnt[0][i]*cnt[0][j] + cnt[1][i]*cnt[1][j];
	}
      }
      
      int k = (i^j);
      if(k<j) continue;

      if(i==j){
	if(j==k){
	  ans2 += cnt[0][i]*(cnt[0][i]-1)*(cnt[0][i]-2)/6;
	  ans2 += cnt[1][i]*(cnt[1][i]-1)*(cnt[0][i]  )/2;
	  //ans2 += cnt[1][i]*(cnt[0][i]  )*(cnt[1][i]-1)/2;
	  //ans2 += cnt[0][i]*(cnt[1][i]  )*(cnt[1][i]-1)/2;
	}
	else{
	  ans2 += cnt[0][i]*(cnt[0][i]-1)*cnt[0][k]/2 ; 
	  ans2 += cnt[1][i]*(cnt[1][i]-1)*cnt[0][k]/2 ;
	  ans2 += cnt[1][i]*(cnt[0][i]  )*cnt[1][k]   ; 
	  //ans2 += cnt[0][i]*(cnt[1][i]  )*cnt[1][k]   ; 
	}
      }
      else{
	if(j==k){
	  ans2 += cnt[0][j]*(cnt[0][j]-1)*cnt[0][i]/2 ;
	  ans2 += cnt[1][j]*(cnt[1][j]-1)*cnt[0][i]/2 ;
	  ans2 += cnt[1][j]*(cnt[0][j]  )*cnt[1][i]   ;
	  //ans2 += cnt[0][j]*(cnt[1][j]  )*cnt[1][i]   ;
	}
	else{
	  ans2 += cnt[0][i]*cnt[0][j]*cnt[0][k];
	  ans2 += cnt[1][i]*cnt[1][j]*cnt[0][k];
	  ans2 += cnt[1][i]*cnt[0][j]*cnt[1][k];
	  ans2 += cnt[0][i]*cnt[1][j]*cnt[1][k];
	}
      }
    }
  }

  if(nZero>0){
    ans1 += nZero*(nZero-1)/2;
    ans2 += nZero*(nZero-1)*(nZero-2)/6;

    for(int i=0;i<BUF;i++){
      if(cnt[0][i]==0 && cnt[1][i]==0) continue;
      ans1 += nZero*cnt[0][i];
      ans1 += nZero*cnt[1][i];
      
      ans2 += nZero*(nZero-1)*cnt[0][i]/2;
      ans2 += nZero*(nZero-1)*cnt[1][i]/2;
      
      for(int j=i;j<BUF;j++){
	if(cnt[0][j]==0 && cnt[1][j]==0) continue;
	
	if(i==j){
	  ans2 += nZero*cnt[0][i]*(cnt[0][i]-1)/2;
	  ans2 += nZero*cnt[0][i]*(cnt[1][i]  );
	  //ans2 += nZero*cnt[1][i]*(cnt[0][i]  );
	  ans2 += nZero*cnt[1][i]*(cnt[1][i]-1)/2;
	}
	else{
	  ans2 += nZero*cnt[0][i]*cnt[0][j];
	  ans2 += nZero*cnt[0][i]*cnt[1][j];
	  ans2 += nZero*cnt[1][i]*cnt[0][j];
	  ans2 += nZero*cnt[1][i]*cnt[1][j];
	}
      }
    }
  }
  cout << ans1 << ' ' << ans2 << endl;
}

int main(){
  makePrime();
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
