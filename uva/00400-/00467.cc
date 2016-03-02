#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> cycleList;

void split(string str, vector<int> &intList){
  
  int cursor=0;

  while(cursor<str.length()){
    
    while(cursor<str.length() && str[cursor]==' ') cursor++;

    int sum=0;
    while(cursor<str.length() && isdigit(str[cursor])){
      sum*=10;
      sum+=str[cursor]-'0';
      cursor++;
    }

    if(sum>=10) intList.push_back(sum);
    
  }

}

bool read(){

  vector<int> tmpList;
  string str;

  if(getline(cin,str)==NULL) return false;

  split(str,tmpList);

  cycleList=tmpList;

  return true;
}

void work(int cases){
  /*
  for(int i=0;i<cycleList.size();i++)
    cout << cycleList[i] << ' ';
  cout << endl;
  */

  int maxTime=3600;
  for(int i=0;i<cycleList.size();i++)
    maxTime = min(maxTime,cycleList[i]);


  cout << "Set " << cases << " ";

  for(int i=maxTime*2;i<=3600;i++){

    bool succeed=true;

    for(int j=0;j<cycleList.size();j++){
      
      int currTime = i%(cycleList[j]*2);
      
      if(!(0<=currTime && currTime<cycleList[j]-5)){
	succeed=false;
	break;
      }
    }

    if(succeed){
      cout << "synchs again at " << (i)/60 
	   << " minute(s) and " << (i)%60 
	   << " second(s) after all turning green." << endl;
      return;
    }

  }

  cout << "is unable to synch after one hour." << endl;

}

int main(){

  for(int i=1;read();i++)
    work(i);

  return 0;
}
