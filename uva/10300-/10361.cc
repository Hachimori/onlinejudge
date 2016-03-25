#include<iostream>
#include<string>

using namespace std;

string source;
string source2;

void read(){
  getline(cin,source);
  getline(cin,source2);
}

void work(){

  int cursor=0;
  string s1, s2, s3, s4, s5;

  while(cursor<source.length() && source[cursor]!='<'){
    s1+=source[cursor];
    cursor++;
  }
  cursor++;
  
  while(cursor<source.length() && source[cursor]!='>'){
    s2+=source[cursor];
    cursor++;
  }
  cursor++;  

  while(cursor<source.length() && source[cursor]!='<'){
    s3+=source[cursor];
    cursor++;
  }
  cursor++;    

  while(cursor<source.length() && source[cursor]!='>'){
    s4+=source[cursor];
    cursor++;
  }
  cursor++;    
  
  while(cursor<source.length()){
    s5+=source[cursor];
    cursor++;
  }

  cout << s1 << s2 << s3 << s4 << s5 << endl;
  cursor=0;
  while(source2[cursor]!='.'){ 
    cout << source2[cursor];
    cursor++;
  }
  cout << s4 << s3 << s2 << s5 << endl;

}

int main(){

  int cases;
  
  cin >> cases;
  getline(cin,source);

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
