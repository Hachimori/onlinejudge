#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Element{
public:

  char c;
  int freq;

  Element(){}
  Element(char c, int f): c(c), freq(f){}

  bool operator<( const Element &e ) const {
    return (freq<e.freq || (freq==e.freq && c>e.c));
  }

};

string str;

bool read(){
  if(getline(cin,str)==NULL) return false;
  return true;
}

void work(){
  
  int cFrec[128];


  for(int i=0;i<128;i++)
    cFrec[i] = 0;

  for(int i=0;i<str.length();i++)
    cFrec[str[i]]++;
  

  vector<Element> eList;

  for(int i=0;i<128;i++)
    if(cFrec[i]>0)
      eList.push_back(Element((char)i,cFrec[i]));
  
  sort(eList.begin(),eList.end());

  for(int i=0;i<eList.size();i++){
    cout << (int)eList[i].c << ' ' << eList[i].freq << endl;
  }

}

int main(){

  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work();
  }

  return 0;
}
