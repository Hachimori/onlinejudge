#include<iostream>
#include<climits>

#define MAX_DATA 20005

using namespace std;

class Data{
public:
  
  int score, beginPos, endPos;

  Data(){}
  Data(int score, int beginPos, int endPos) : 
    score(score), beginPos(beginPos), endPos(endPos){}
  
};

int nData;
Data dataList[MAX_DATA];

void read(){

  int nValue;
  int value[MAX_DATA];

  cin >> nValue;
  nValue--;
  for(int i=0;i<nValue;i++)
    cin >> value[i];

  
  // Make Data
  nData=0;
  for(int i=0;i<nValue;i++){
    int sum=value[i], begin, end;
    
    if(value[i]>0){
      begin = i;
      while(i+1<nValue && value[i+1]>0){
	sum+=value[i+1];
	i++;
      }
    }
    else{
      begin = i;
      while(i+1<nValue && value[i+1]<0){
	sum+=value[i+1];
	i++;
      }
    }

    dataList[nData]=Data(sum,begin,i+1);
    nData++;

  }
  
}

void work(int cases){
  /*
  for(int i=0;i<nData;i++){
    cout << "score : " <<dataList[i].score << "  begin : " 
	 << dataList[i].beginPos << "  end : " << dataList[i].endPos << endl;
  }cout << endl;
  */

  Data table[MAX_DATA];
  
  table[0] = dataList[0];
  if(nData>=2) table[1] = dataList[1];

  for(int i=2;i<nData;i++){
    if(dataList[i].score<0){
      table[i] = dataList[i];
      continue;
    }

    if(table[i-2].score+table[i-1].score>=0)
      table[i] = Data(table[i-2].score+table[i-1].score+dataList[i].score,table[i-2].beginPos,dataList[i].endPos);
    else
      table[i] = dataList[i];
  }


  Data bestData=Data(-1,-1,-1);
  for(int i=0;i<nData;i++){    
    if(bestData.score<table[i].score)
      bestData = table[i];
    else if(bestData.score==table[i].score && bestData.endPos-bestData.beginPos<table[i].endPos-table[i].beginPos)
      bestData = table[i];
  }

  if(bestData.score<0){
    cout << "Route " << cases << " has no nice parts" << endl;
  }
  else {
    cout << "The nicest part of route " << cases 
	 << " is between stops " << bestData.beginPos+1 << " and " << bestData.endPos+1 << endl;
  }
  
}

int main(){

  int cases;
  cin >> cases;
  
  for(int i=1;i<=cases;i++){
    read();
    work(i);
  }

  return 0;
}
