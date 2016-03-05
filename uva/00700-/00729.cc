#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, H;
vector<string> strList;

void store(int choseList[16]){

  string str;

  for(int i=0,cursor=0;i<N;i++){
    
    if(choseList[cursor]==i){
      str+='1';
      cursor++;
      continue;
    }

    str+='0';

  }

  strList.push_back(str);

}

void rec(int nChose, int cursor, int choseList[16]){

  if(nChose==H){
    store(choseList);
    return;
  }


  for(int i=cursor;i<N;i++){
    
    choseList[nChose] = i;
    rec(nChose+1,i+1,choseList);

    choseList[nChose] = -1;

  }

}

int main(){

  int cases;

  cin >> cases;

  for(int i=0;i<cases;i++){
    
    if(i!=0) cout << endl;

    cin >> N >> H;

    int choseList[16];    
    strList.clear();

    rec(0,0,choseList);

    sort(strList.begin(),strList.end());

    
    for(int j=0;j<strList.size();j++)
      cout << strList[j] << endl;
    
    
  }


  return 0;
}
