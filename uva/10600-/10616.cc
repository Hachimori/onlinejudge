#include<iostream>
#include<vector>
#include<cstdlib>
#include<cassert>
#include<cstdio>

#define MAX_SIZE 205
#define MAX_PICK 15
#define MAX_MOD 50
#define SHIFT 25

using namespace std;

int nNum, nQuery;
int nList[MAX_SIZE];

long long &access(int n, long long nMod[MAX_MOD]){
  return nMod[n+SHIFT];
}

bool read(){
  
  cin >> nNum >> nQuery;
  if(nNum==0 && nQuery==0) return false;
  
  
  for(int i=0;i<nNum;i++)
    cin >> nList[i];
  
  return true;

}

long long gcd(long long a, long long b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

long long calcCombi(long long r, long long c){
  
  vector<long long> nume;
  vector<long long> deno;
  
  for(int i=r;i>r-c;i--)
    nume.push_back(i);
  
  for(int i=1;i<=c;i++)
    deno.push_back(i);

  for(int i=0;i<nume.size();i++){
    for(int j=0;j<deno.size();j++){
      long long ret = gcd(nume[i],deno[j]);

      nume[i]/=ret;
      deno[j]/=ret;
    }
  }

  long long result=1;
  for(int i=0;i<nume.size();i++)
    result*=nume[i];
  
  assert(result>0);
  
  return result;
}

void calcSum(long long &sum, int mod, int nPick, int cursor, long long currCombi,
	     int currMod, long long combination[MAX_PICK][MAX_MOD]){
  
  if(nPick==0){
    if(currMod==0)
      sum+=currCombi;

    return;
  }
  if(cursor==MAX_MOD) return;
  
  for(int i=1;i<=nPick;i++){
    
    if(combination[i][cursor]==0) continue;
    
    int nextMod;

    if(currMod+i*(cursor-SHIFT)<0)
      nextMod = -(abs(currMod+i*(cursor-SHIFT))%mod);
    else
      nextMod = (currMod+i*(cursor-SHIFT))%mod;
    
    calcSum(sum,mod,nPick-i,cursor+1,currCombi*combination[i][cursor],nextMod,combination);
    
  }
  
   calcSum(sum,mod,nPick,cursor+1,currCombi,currMod,combination);
   
  
}

long long calc(int mod, int nPick){
  
  long long nMod[MAX_MOD];
  long long combination[MAX_PICK][MAX_MOD];    // [pick][mod] = nMod[mod] C pick
  
  for(int i=0;i<MAX_MOD;i++)
    nMod[i] = 0;
  
  for(int i=0;i<nPick+1;i++)
    for(int j=0;j<MAX_MOD;j++)
      combination[i][j] = 0;
  
  for(int i=0;i<nNum;i++)
    if(nList[i]>0)
      access(nList[i]%mod,nMod)+=1;
    else
      access(-(abs(nList[i])%mod),nMod)+=1;
  
  for(int i=1;i<nPick+1;i++)
    for(int j=0;j<MAX_MOD;j++){
      if(i<=nMod[j])
	combination[i][j] = calcCombi(nMod[j],i);
      else
	combination[i][j] = 0;
    }
  
  
  long long sum=0;
  calcSum(sum,mod,nPick,0,1,0,combination);
 
  return sum;
}

void work(int cases){
  
  cout << "SET " << cases << ":" << endl;
  
  for(int currQuery=0;currQuery<nQuery;currQuery++){
    int mod, nPick;
    cin >> mod >> nPick;
    cout << "QUERY " << currQuery+1 << ": " << calc(mod,nPick) << endl;
  }

}

int main(){

  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
