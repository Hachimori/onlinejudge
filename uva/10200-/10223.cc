#include<iostream>
#include<vector>
#include<climits>

#define MAX_SIZE 1000

using namespace std;

long long MAX_NUM = UINT_MAX;
long long target;
long long catalanList[MAX_SIZE];

long long gcd(long long a, long long b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

void createTable(){
  
  catalanList[0] = 1;
  catalanList[1] = 1;
  
  MAX_NUM*=10;
  
  for(int i=2;;i++){
    
    vector<long long> nume,deno;
    
    for(int j=2;j<=2*i;j++)
      nume.push_back(j);
    
    for(int j=2;j<=i+1;j++)
      deno.push_back(j);

    for(int j=2;j<=i;j++)
      deno.push_back(j);
    
    for(int j=0;j<nume.size();j++){
      for(int k=0;k<deno.size();k++){
	int result = gcd(nume[j],deno[k]);

	nume[j]/=result;
	deno[k]/=result;
      }
    }
    
    catalanList[i] = 1;
    for(int j=0;j<nume.size();j++)
      catalanList[i]*=nume[j];
    
    if(catalanList[i]>MAX_NUM) break;
  }
  
}

bool read(){
  if(!(cin >> target)) return false;
  return true;
}

void work(){

  for(int i=0;;i++){
    if(catalanList[i]<=target && target<catalanList[i+1]){
      cout << i << endl;
      break;
    }
  }

}

int main(){
  
  createTable();
  
  while(read())
    work();

  return 0;
}
