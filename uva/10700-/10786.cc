#include<iostream>


using namespace std;

int main(){
  
  int cases;
  cin >> cases;

  for(int i=1;i<cases+1;i++){

    int nTeam, nComp , nQua;
    cin >> nTeam >> nComp >> nQua;


    cout << "League " << i << ": ";
    if(nQua==nTeam) cout << 0 << endl;
    else if(nQua==1) cout << (nTeam-1)*nComp + 2 << endl;
    else {
      cout << (nTeam-nQua)*nComp+1 << endl;
    }

  }
  
  return 0;
}
