#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s;

bool read(){
  cin >> s;
  return s!="#";
}

void work(){
  if(!next_permutation(s.begin(),s.end()))
    cout << "No Successor" << endl;
  else
    cout << s << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
