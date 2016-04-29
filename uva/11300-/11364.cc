#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 25;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int nPt, pt[BUF];
    cin >> nPt;
    for(int i=0;i<nPt;i++) cin >> pt[i];
    sort(pt,pt+nPt);
    cout << 2*(pt[nPt-1]-pt[0]) << endl;
  }
  return 0;
}
