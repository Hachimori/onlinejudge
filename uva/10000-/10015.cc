#include<iostream>
#include<vector>

#define MAX_NUM 1000000
#define MAX_PEOPLE 3510

using namespace std;

vector<int> primeList;

void makePrime(){

  bool isPrime[MAX_NUM];
  
  for(int i=0;i<MAX_NUM;i++)
    isPrime[i] = true;

  isPrime[2] = true;

  for(int i=3;i*i<MAX_NUM;i+=2)    
    if(isPrime[i])
      for(int j=i+i;j<MAX_NUM;j+=i)
	isPrime[j]=false;
      

  primeList.push_back(2);
  for(int j=3;j<MAX_NUM;j+=2)
    if(isPrime[j])
      primeList.push_back(j);


}

int nPeople;
bool visited[MAX_PEOPLE];

bool read(){
  
  cin >> nPeople;
  if(nPeople==0) return false;

  return true;
}

void work(){
  vector<int> remaining;
  for(int i=0;i<nPeople;i++)
      remaining.push_back(i);

  int cursor=0;

  for(int i=0;i<nPeople-1;i++){

    int nSkip = (primeList[i] - 1) % (nPeople - i);
    cursor = (cursor+nSkip)%remaining.size();
    remaining.erase(remaining.begin() + cursor);
  }
  
  cout << remaining[0]+1 << endl;
}

int main(){
  
  makePrime();
  
  /*
    for(int i=0;i<50;i++)
    cout << primeList[i] << endl;
  */
  
  while(read())
    work();
  
  return 0;
}
