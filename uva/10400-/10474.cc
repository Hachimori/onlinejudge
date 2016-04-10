#include<iostream>
#include<algorithm>
using namespace std;
const int NUM = 10005;

int nNum, num[NUM], nQuery, query[NUM];

bool read(){
  cin >> nNum >> nQuery;
  if(nNum==0 && nQuery==0) return false;
  for(int i=0;i<nNum;i++)
    cin >> num[i];
  for(int i=0;i<nQuery;i++)
    cin >> query[i];
  return true;
}

void work(int cases){
  cout << "CASE# " << cases << ":" << endl;
  sort(num,num+nNum);
  for(int i=0;i<nQuery;i++){
    int *pos = upper_bound(num,num+nNum,query[i]-1);
    if(*pos==query[i])
      cout << query[i] << " found at " << pos-num+1 << endl;
    else
      cout << query[i] << " not found" << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
