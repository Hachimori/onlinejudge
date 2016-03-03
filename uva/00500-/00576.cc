#include<iostream>
#include<vector>
using namespace std;

string str;

bool read(){
  getline(cin,str);
  return str!="e/o/i";
}

bool isSyllable(char ch){
  string syllable = "aiueoy";
  return syllable.find(ch)!=string::npos;
}

void work(){


  int cntSyllable = 0;
  vector<int> val;

  for(int i=0;i<str.size();i++){
    if(str[i]=='/'){
      val.push_back(cntSyllable);
      cntSyllable = 0;
    }
    if(isSyllable(str[i]) && (i==str.size()-1 || !isSyllable(str[i+1])))
      cntSyllable++;
  }
  val.push_back(cntSyllable);

  if(val[0]!=5)
    cout << 1 << endl;
  else if(val[1]!=7)
    cout << 2 << endl;
  else if(val[2]!=5)
    cout << 3 << endl;
  else
    cout << 'Y' << endl;
}

int main(){
  while(read()) work();
  return 0;
}
