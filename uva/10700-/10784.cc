#include<iostream>
#include<algorithm>
#include<cmath>
#include<cfloat>

using namespace std;

int main(){

  for(int cases=1;;cases++){
    
    long long N;
    cin >> N;
    
    if(N==0) break;

    
    double n_gon = (3+sqrt(9+8*N))/2;

    //cout << "N : " << N << "   n_gon : " << n_gon << endl;

    double low_nGon = floor(n_gon);
    double up_nGon = ceil(n_gon);
    

    cout << "Case " << cases << ": ";
    if(fabs(n_gon-low_nGon)<FLT_EPSILON) cout << (long long)low_nGon << endl;
    else cout << (long long)up_nGon << endl;

  }

  return 0;
}
