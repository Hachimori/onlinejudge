#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cctype>
using namespace std;

string str;

bool read(){
  str = "";
  while(1){
    string s;
    getline(cin,s);
    if(s=="****END_OF_TEXT****") return true;
    if(s=="****END_OF_INPUT****") return false;
    str += ' '+s;
  }
}

void work(){
  for(int i=0;i<str.size();i++)
    if(string(",.:;!?\"()").find(str[i])!=string::npos)
      str[i] = ' ';
    else
      str[i] = toupper(str[i]);

  int nWord = 0;

  map<string,int> S;
  stringstream in(str);
  while(in >> str){
    if(S.count(str)) 
      S[str] += 1;
    else
      S[str] = 1;
    nWord++;
  }

  double sum = 0;
  for(map<string,int>::iterator itS=S.begin();itS!=S.end();itS++)
    sum += itS->second*(log10(nWord)-log10(itS->second))/nWord;
  
  printf("%d %.1lf %.0lf\n",nWord,sum,sum/log10(nWord)*100);
}

int main(){
  while(read()) work();
  return 0;
}
