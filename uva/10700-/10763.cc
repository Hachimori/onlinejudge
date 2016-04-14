#include<iostream>
#include<set>
using namespace std;

int main(){
  int n;
  while(cin >> n,n){
    multiset<pair<int,int> > S;
    for(int i=0;i<n;i++){
      int a, b;
      cin >> a >> b;
      if(S.count(make_pair(b,a)))
        S.erase(S.find(make_pair(b,a)));
      else
        S.insert(make_pair(a,b));
    }
    cout << (S.empty()?"YES":"NO") << endl;
  }
  return 0;
}
