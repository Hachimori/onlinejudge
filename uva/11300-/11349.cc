#include<iostream>
using namespace std;
const int BUF = 105;
int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    long long sz, mat[BUF][BUF];
    char dummy;
    cin >> dummy >> dummy >> sz;
    for(int i=0;i<sz;i++)
      for(int j=0;j<sz;j++)
        cin >> mat[i][j];

    cout << "Test #" << k+1 << ": ";
    for(int i=0;i<sz;i++)
      for(int j=0;j<sz;j++)
        if(mat[i][j]<0 || mat[i][j]!=mat[sz-i-1][sz-j-1]){
          cout << "Non-symmetric." << endl;
          goto _fail;
        }
    cout << "Symmetric." << endl;
  _fail:;
  }
  return 0;
}
