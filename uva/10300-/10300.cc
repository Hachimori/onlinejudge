#include<iostream>

using namespace std;

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    int sum=0;
    int nAnimal;

    cin >> nAnimal;
    for(int j=0;j<nAnimal;j++){
      int space, t, quality;
      cin >> space >> t >> quality;

      sum+=space*quality;
    }
    cout << sum << endl;
  }

  return 0;
}
