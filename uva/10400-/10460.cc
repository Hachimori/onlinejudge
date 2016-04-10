// ad-hoc
//
//
// 次にどこに文字を挿入するかによって、indexの範囲を決めることができる。
//
// abcd について考える。
//   a ->  ba とすると、範囲は 1-12となり 、
//   a ->  ab とすると、範囲は 13-24となり、
//
//  ba -> cba とすると、範囲は 1-4となり、
//  ba -> bca とすると、範囲は 5-8となり、
//  ba -> bac とすると、範囲は 9-12となる。
//
//
// indexの範囲は以下の通り。
//  !目標の文字数
//  -------------
//  !現在の文字数
//
//
// これは、文字を挿入する場所が (現在の文字数+1) 箇所あり、
// 文字を挿入した後は、(現在の文字数+2) 箇所あり、
// その次は、(現在の文字数+3) あるので、
// 
// (現在の文字数+1)*(現在の文字数+2)*(現在の文字数+3)....
//
//   !目標の文字数
// = -------------
//   !現在の文字数
//
// となるからである、
//
//
// また、文字を挿入する場所は (現在の文字数+1) 箇所あるので、
// 文字を挿入するそれぞれの場所iに対するindexの範囲は、
//
// /        !目標の文字数*i　　　　　　　　　     !目標の文字数*(i+1)　　     \
// |  --------------------------------  ～  --------------------------------  |
// \  !現在の文字数 * (現在の文字数+1)　　  !現在の文字数 * (現在の文字数+1)  /
//                                                                            
// である。

#include<iostream>
#include<climits>
#include<string>

using namespace std;

int idx;
string str;

void read(){
  cin >> str >> idx ;
}

void rec(int currIdx, int nInserted, string currStr){
  if(str.size()-nInserted>=16){
    currStr = str[nInserted] + currStr;
    rec(currIdx,nInserted+1,currStr);
    return;
  }
  if(nInserted==str.size()){
    cout << currStr << endl;
    return;
  }
  
  long long section = 1;
  for(int i=currStr.size()+1;i<=str.size();i++)
    section *= i;
  section /= (currStr.size()+1);
  
  string::iterator j = currStr.begin();
  for(int i=1;i<=currStr.size()+1;i++,j++){
    if(idx<section*i+currIdx){
      currStr.insert(j,str[nInserted]);
      rec(currIdx+section*(i-1),nInserted+1,currStr);
      break;
    }
    
  }
  
}

void work(){
  string s;
  s += str[0];
  idx--;
  
  rec(0,1,s);
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
