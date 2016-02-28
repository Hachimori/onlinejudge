#include<iostream>
using namespace std;
const int DENO = 1005;

int nume, deno;

bool read(){
  cin >> nume >> deno;
  return !(nume==0 && deno==0);
}

void work(){
  int visited[DENO];
  memset(visited,-1,sizeof(visited));

  cout << ".";
  for(int i=1;;i++){
    if(visited[nume%deno]!=-1){
      cout << endl;
      cout << "The last " << i-visited[nume%deno] << " digits repeat forever." << endl;
      break;
    }
    if(nume%deno==0){
      cout << endl;
      cout << "This expansion terminates." << endl;
      break;
    }
    visited[nume%deno] = i;
    if(i%50==0) cout << endl;
    cout << 10*nume/deno;
    nume = 10*nume%deno;
  }
}

int main(){
  while(read()){
    work();
    cout << endl;
  }
  return 0;
}
