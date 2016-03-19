#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>

#define MAX_SIZE 1000

using namespace std;

class Data{
public:

  int year, month, day;

  Data(){}
  Data(int y, int m, int d): year(y), month(m), day(d) {}
  
  bool exceed(int exceedY, Data d){
    if(year+exceedY<d.year) return false;
    else if(year+exceedY==d.year){
      if(month<d.month) return false;
      else if(month==d.month) {
	if(day<=d.day) return false;	
      }
    }

    return true;
  }

};

Data initDay;
int nOffence;
Data offenceDay[MAX_SIZE];
int demeritList[MAX_SIZE];

void read(){
  
  string str;
  int init;
  
  cin >> init; getline(cin,str);
  
  initDay = Data(init/10000,(init/100)%100,init%100);
  
  nOffence=0;
  
  while(true){
    getline(cin,str);

    if(str.size()==0) break;
    
    int data, demerit;
    sscanf(str.c_str(),"%d%d",&data,&demerit);
    
    offenceDay[nOffence] = Data(data/10000,(data/100)%100,data%100);
    demeritList[nOffence] = demerit;
    nOffence++;
  }
  
}

void rec(int currMerit, int currDemerit, int currOffence, Data currDate){

  cout << currDate.year << "-";
  if(currDate.month<10) cout << "0";
  cout << currDate.month << "-";
  if(currDate.day<10) cout << "0";
  cout << currDate.day;
  
  if(currMerit>=5 && currOffence==nOffence){
    cout << ' ' << currMerit << " merit point(s)." << endl;
    return ;
  }

  if(currMerit==0 && currDemerit==0){
    
    cout << " No merit or demerit points." << endl;
    
    if(currOffence<nOffence && currDate.exceed(2,offenceDay[currOffence])){

      currDate = offenceDay[currOffence];
      currDemerit = demeritList[currOffence];
      currOffence++;      
      
      if(currMerit*2>currDemerit){
	currMerit-=(currDemerit+1)/2;
	currDemerit=0;
      }
      else{
	currDemerit-=currMerit*2;
	currMerit=0;
      }
      
      rec(currMerit,currDemerit,currOffence,currDate);

    }
    else {
      currDate.year+=2;
      rec(currMerit+1,currDemerit,currOffence,currDate);
    }

  }
  else if(currMerit>0){
    
    cout << ' ' << currMerit << " merit point(s)." << endl;
    
    if(currOffence<nOffence && currDate.exceed(2,offenceDay[currOffence])){

      currDate = offenceDay[currOffence];
      currDemerit += demeritList[currOffence];
      currOffence++;      
      
      if(currMerit*2>currDemerit){
	currMerit-=(currDemerit+1)/2;
	currDemerit=0;
      }
      else{
	currDemerit-=currMerit*2;
	currMerit=0;
      }

      rec(currMerit,currDemerit,currOffence,currDate);
    }
    else {
      currDate.year+=2;
      rec(currMerit+1,currDemerit,currOffence,currDate);
    }
    
  }
  else if(currDemerit>0){

    cout << ' ' << currDemerit << " demerit point(s)." << endl;
    
    if(currOffence<nOffence && currDate.exceed(1,offenceDay[currOffence])){
	
      currDate = offenceDay[currOffence];
      currDemerit += demeritList[currOffence];
      currOffence++;      
      
      if(currMerit*2>currDemerit){
	currMerit-=(currDemerit+1)/2;
	currDemerit=0;
      }
      else{
	currDemerit-=currMerit*2;
	currMerit=0;
      }

      rec(currMerit,currDemerit,currOffence,currDate);
    }
    else {

      currDate.year++;
      int minDem;

      if(currDemerit-2>=0) minDem = min(currDemerit-2,currDemerit/2);
      else minDem = 0;
      
      rec(currMerit,minDem,currOffence,currDate);

    }
  }
  
}

void work(){
  /*
  for(int i=0;i<nOffence;i++){
    cout << offenceDay[i].year << ' ' << offenceDay[i].month << ' ';      
    cout << offenceDay[i].day << ' ' << demeritList[i] << endl;
  }cout << endl;
  */
  
  
  rec(0,0,0,initDay);

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
