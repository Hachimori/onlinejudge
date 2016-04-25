#include<iostream>
#include<vector>

#define INF 100000000
#define MAX_SIZE 37
#define MAX_QUERY 1000000

using namespace std;

int table[MAX_SIZE];
int nQuery, query[MAX_QUERY];

void read(){
  for(int i=0;i<36;i++)
    cin >> table[i];
  
  cin >> nQuery;
  
  for(int i=0;i<nQuery;i++)
    cin >> query[i];
}

int calcCost(int b, int t[], int n){
  int sum = 0;
  
  while(n!=0){
    sum += t[n%b];
    n/=b;
  }
  
  return sum;
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;

  
  for(int i=0;i<nQuery;i++){
    int minCost = INF;
    vector<int> minBase;
    for(int j=2;j<=36;j++){
      int t = calcCost(j,table,query[i]);

      if(minCost>t){
	minCost = t;
	minBase.clear();
	minBase.push_back(j);
      }
      else if(minCost==t)
	minBase.push_back(j);
    }
    cout << "Cheapest base(s) for number " << query[i] << ":";
    
    for(int j=0;j<minBase.size();j++)
      cout << ' ' << minBase[j];
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work(i+1);
  }
  

  return 0;
}
