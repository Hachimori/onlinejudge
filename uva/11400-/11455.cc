#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int v[4];
    for(int i=0;i<4;i++) cin >> v[i];
    sort(v,v+4);

    if(v[0]+v[1]+v[2]<v[3])
      cout << "banana" << endl;
    else if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3])
      cout << "square" << endl;
    else if(v[0]==v[1] && v[2]==v[3])
      cout << "rectangle" << endl;
    else
      cout << "quadrangle" << endl;
  }
  return 0;
}
