#include<iostream>
#include<cmath>
using namespace std;

int main(){
  string n;
  while(cin >> n, n!="0"){
    for(int base=2;;base++){
      bool ok = true;
      for(int i=0;i<n.size();i++)
        if(base<=n[i]-'0')
          ok = false;
      if(!ok) continue;
      int sum = 0;
      for(int i=0;i<n.size();i++)
        sum = sum*base+n[i]-'0';
      int t = sqrt(sum)+.5;
      if(t*t==sum){
        cout << base << endl;
        break;
      }
    }
  }
  return 0;
}
