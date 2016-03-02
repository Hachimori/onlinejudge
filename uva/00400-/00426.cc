#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

#define MAX_SIZE 10005

using namespace std;

class Data{
public:

  int id;
  char date[100];
  double money;

  Data(){}
  Data(int id, char tmpDate[100], double money): id(id), money(money){
    strcpy(date,tmpDate);
  }

  bool operator< (const Data &d) const {
    return id<d.id;
  }
  
};

int nData;
Data dataList[MAX_SIZE];

void read(){
  
  nData=0;

  while(true){

    string str;
    getline(cin,str);

    if(str.size()==0) break;

    sscanf(str.c_str(),"%s%d%lf",dataList[nData].date,&dataList[nData].id,&dataList[nData].money);
    
    //cout << dataList[nData].date << ' ' << dataList[nData].id << ' ' << dataList[nData].money << endl;

    nData++;
  }


}

void work(){

  sort(&dataList[0],&dataList[nData]);

  for(int i=0;i<(nData+2)/3;i++){
    
    for(int j=i;j<nData;j+=(nData+2)/3){

      if(j!=i) cout << "   ";

      printf("%4d",dataList[j].id);
    
      if(j!=0 && dataList[j-1].id!=dataList[j].id-1) cout << '*';
      else cout << ' ';

      printf("%10.2lf %s",dataList[j].money,dataList[j].date);
    }
    cout << endl;
  }
  
}

int main(){

  string str;
  int cases;

  cin >> cases; getline(cin,str); getline(cin,str);

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
