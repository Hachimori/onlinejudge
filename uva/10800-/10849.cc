#include<iostream>
#define QUERY 10000
using namespace std;

int size, nQuery, pos[QUERY][4];

void read(){
  cin >> nQuery >> size;

  for(int i=0;i<nQuery;i++)
    for(int j=0;j<4;j++)
      cin >> pos[i][j];
}

void work(){
  for(int k=0;k<nQuery;k++){
    if((pos[k][0]+pos[k][1])%2!=(pos[k][2]+pos[k][3])%2)
      cout << "no move" << endl;
    else if(pos[k][0]==pos[k][2] && pos[k][1]==pos[k][3])
      cout << 0 << endl;
    else if(abs(pos[k][0]-pos[k][2])==abs(pos[k][1]-pos[k][3]))
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
