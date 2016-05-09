#include<iostream>
using namespace std;

int main(){
  int nQuery;
  while(cin >> nQuery, nQuery){
    int midX, midY;
    cin >> midX >> midY;
    for(int i=0;i<nQuery;i++){
      int x, y;
      cin >> x >> y;
      if(midX==x || midY==y)
        cout << "divisa" << endl;
      else if(x<midX && y<midY)
        cout << "SO" << endl;
      else if(x<midX && y>midY)
        cout << "NO" << endl;
      else if(x>midX && y<midY)
        cout << "SE" << endl;
      else if(x>midX && y>midY)
        cout << "NE" << endl;
    }
  }
  return 0;
}
