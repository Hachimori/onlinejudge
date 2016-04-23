#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<string>
#include<vector>
#include<cctype>

#define MAX_SIZE 25
#define MAX_BUF 500

using namespace std;

class Data{
public:
  int nObj;
  double cost;

  Data(){}
  Data(int n, double c): nObj(n), cost(c) {}
  
};

int nData;
Data data[MAX_SIZE];
vector<int> query;

void split(string buf, vector<int> &nList){
  
  int cursor = 0;
  
  while(cursor<buf.size()){
    while(isspace(buf[cursor]) && cursor<buf.size()) cursor++;
  
    string toPush;
    while(!isspace(buf[cursor]) && cursor<buf.size()){
      toPush += buf[cursor];
      cursor++;
    }
    
    nList.push_back(atoi(toPush.c_str()));

    while(isspace(buf[cursor]) && cursor<buf.size()) cursor++;
  }

}

bool read(){
  if(!(cin >> data[0].cost >> nData)) return false;

  data[0].nObj = 1;
  nData++;

  for(int i=1;i<nData;i++)
    cin >> data[i].nObj >> data[i].cost;
  
 string buf;
  vector<int> nList;
  
  getline(cin,buf);
  getline(cin,buf);
  
  split(buf,nList);
  
  query = nList;
  
  return true;
}

void makeTable(double table[]){
  
  for(int i=0;i<MAX_BUF;i++)
    table[i] = INT_MAX;
  table[0] = 0;
  
  for(int i=0;i<MAX_BUF;i++){
    for(int j=0;j<nData;j++)
      if(i+data[j].nObj<MAX_BUF)
	table[i+data[j].nObj] = min(table[i+data[j].nObj],table[i]+data[j].cost);
	
  }
  
}

void work(int cases){
  
  double table[MAX_BUF];
  makeTable(table);

  
  cout << "Case " << cases << ':' << endl;
  
  for(int i=0;i<query.size();i++){
    double minVal = INT_MAX;
    for(int j=query[i];j<MAX_BUF;j++)
      minVal = min(minVal,table[j]);

    printf("Buy %d for $%.2lf\n",query[i],minVal);
  }
  
}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
