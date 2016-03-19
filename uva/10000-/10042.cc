#include<iostream>
#include<vector>

#define MAX_NUM 100000

using namespace std;

vector<int> primeList;

void makePrime(){

  bool prime[MAX_NUM];

  for(int i=0;i<MAX_NUM;i++)
    prime[i] = true;

  for(int i=3;i*i<MAX_NUM;i+=2)
    if(prime[i])
      for(int j=i+i;j<MAX_NUM;j+=i)
	prime[j] = false;
  
  primeList.push_back(2);
  for(int i=3;i<MAX_NUM;i+=2)
    if(prime[i])
      primeList.push_back(i);

}

int primeFactor(int n){

  for(int i=0;i<primeList.size() && primeList[i]<=n;i++)
    if(n%primeList[i]==0) return primeList[i];
  
  return n;
}

vector<int> factorList(int source){

  vector<int> factorList;
  
  while(true){
    int prime=primeFactor(source);
    
    if(prime==source){
      factorList.push_back(prime);
      break;
    }
    else{
      factorList.push_back(prime);
      source/=prime;
    }
  }

  return factorList;

}

bool valid(int source, vector<int> nList){

  int sum1=0, sum2=0;
  
  for(;source>0;source/=10)
    sum1+=source%10;
  
  for(int i=0;i<nList.size();i++){
    //cout << nList[i] << ' ';

    for(;nList[i]>0;nList[i]/=10)
      sum2+=nList[i]%10;
  }//cout << endl;
  
  return sum1==sum2;
}

void work(){
  int source;
  cin >> source;

  for(int i=source+1;;i++){   
    if(primeFactor(i)==i) continue;
 
    vector<int> factors=factorList(i);

    if(valid(i,factors)){ 
      cout << i << endl;
      break;
    }
  }

}

int main(){

  makePrime();

  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++)
    work();


  return 0;
}
