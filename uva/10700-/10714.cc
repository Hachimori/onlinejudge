#include<iostream>
using namespace std;
const int INF = 1<<30;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int len, nPos;
    cin >> len >> nPos;
    int fastest=-INF, latest=-INF;
    for(int i=0;i<nPos;i++){
      int n;
      cin >> n;
      fastest = max(fastest,min(n,len-n));
      latest = max(latest,max(n,len-n));
    }
    cout << fastest << ' ' << latest << endl;
  }
  return 0;
}
