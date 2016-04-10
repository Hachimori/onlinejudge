#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    string dummy; 
    getline(cin,dummy);

    map<string,int> M;
    for(int i=0;i<n;i++){
      string name;
      getline(cin,name);
      int idx;
      for(idx=0;name[idx]!=' ';idx++);
      M[name.substr(0,idx)]++;
    }

    for(map<string,int>::iterator i=M.begin();i!=M.end();i++)
      cout << i->first << ' ' << i->second << endl;
  }

  return 0;
}
