#include<iostream>
using namespace std;
const int BUF = 105;

int n, adj[BUF][BUF];

bool read(){
  if(!(cin >> n)) return false;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> adj[i][j];
  return true;
}


void work(){
  int cnt = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++){
        if(!((i<j && j<k) || (i>j && j>k))) continue;
        if(adj[i][j] && adj[j][k]){
          cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
          cnt++;
        }
      }
  cout << "total:" << cnt << endl;
  cout << endl;
}


int main(){
  while(read()) work();
  return 0;
}
