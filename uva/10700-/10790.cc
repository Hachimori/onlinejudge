#include<iostream>
using namespace std;

int main(){
  long long a, b, cases = 1;
  while(cin >> a >> b, a|b)
    cout << "Case " << cases++ << ": " << a*(a-1)/2*b*(b-1)/2 << endl;
  return 0;
}
