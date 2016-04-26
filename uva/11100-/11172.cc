#include<iostream>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    int a, b;
    cin >> a >> b;
    
    if(a<b) cout << '<' << endl;
    if(a>b) cout << '>' << endl;
    if(a==b) cout << '=' << endl;
  }
  
  return 0;
}
