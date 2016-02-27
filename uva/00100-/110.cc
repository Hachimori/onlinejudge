#include<iostream>
#include<algorithm>
using namespace std;

int n;

void read(){
  cin >> n;
}

void rec(int cur, int v[8]){
  
  if(cur==n){
    for(int i=0;i<cur;i++) cout << "  ";
    cout << "writeln(";
    for(int i=0;i<n;i++){
      if(i) cout << ',';
      cout << (char)(v[i]+'a');
    }cout << ')' << endl;
    return;
  }

  for(int i=cur;i-1>=0;i--){
    for(int j=0;j<cur;j++) cout << "  ";
    if(i!=cur) cout << "else ";
    cout << "if " << (char)(v[i-1]+'a') << " < " << (char)(v[i]+'a');
    cout << " then" << endl;
    
    rec(cur+1,v);
    swap(v[i],v[i-1]);
  }

  for(int j=0;j<cur;j++) cout << "  ";
  cout << "else" << endl;
  rec(cur+1,v);

  for(int i=0;i+1<=cur;i++) swap(v[i],v[i+1]);
}

void work(){
  cout << "program sort(input,output);" << endl;
  cout << "var" << endl;
  for(int i=0;i<n;i++) {
    if(i) cout << ',';
    cout << (char)(i+'a');
  }cout << " : integer;" << endl;
  cout << "begin" << endl;
  cout << "  readln(";
  for(int i=0;i<n;i++) {
    if(i) cout << ',';
    cout << (char)(i+'a');
  }cout << ");" << endl;
  
  int v[8];
  for(int i=0;i<n;i++) v[i] = i;

  rec(1,v);

  cout << "end." << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
