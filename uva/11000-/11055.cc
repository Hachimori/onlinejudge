#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 1005;

int n, b[BUF][BUF];

bool read(){
  cin >> n;
  if(n==0) return false;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> b[i][j];
  return true;
}

void work(){
  for(int i=0;i<n;i++){
    int minV = *min_element(b[i],b[i]+n);
    for(int j=0;j<n;j++)
      b[i][j] -= minV;
  }
  for(int c=0;c<n;c++)
    for(int r=0;r+1<n;r++)
      if(b[r][c]!=b[r+1][c]){
        cout << "not homogeneous" << endl;
        return;
      }
  cout << "homogeneous" << endl;
}

int main(){
  while(read()) work();
  return 0;
}
