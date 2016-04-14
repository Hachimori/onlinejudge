/*
  ad hoc
 
  ŒfŽ¦”Â‚æ‚è
  
  In every two sacrifices, there are three possible cases: 
  1. 1 G and 1 K are sacrificed, 1 K is placed. 
  2. 2 G are sacrificed, 1 G is placed. 
  3. 2 K are sacrificed, 1 G is placed. 
  In any case, the parity of K doesn't change. 
  So the initial parity of K is the same as the final parity of K.
*/

#include<iostream>

using namespace std;

int main(){
  int nG, nK, nMove;
  while(cin >> nG >> nK >> nMove){
    if(!(nG|nK|nMove)) break;
    
    if(nK%2==1) cout << "Keka" << endl;
    else cout << "Gared" << endl;
  }

  return 0;
}
