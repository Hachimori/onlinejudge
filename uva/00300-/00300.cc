#include<iostream>
#include<string>
#include<utility>

using namespace std;

int day, year;
string month;
pair<string,int> tableH[5001*365+1];
pair<int,string> tableT[5001*365+1];

string monthList[19]={"pop","no","zip","zotz","tzec"
		      ,"xul","yoxkin","mol","chen","yax","zac","ceh","mac",
		      "kankin","muan","pax","koyab","cumhu","uayet"};

void dayAdjust(int &m, int &d, int &y, int i){
  
  y++;      
  
  m=y%13;
  d=y%20;
  
  m++;
  /*
  m%=14;
  m++;

  if(d%=20){ 
    m++;
    d=0;
    dayAdjust(m,d,y,i);
  }
  */

}

void makeTable(){
  
  int currMon=0, currDay=0;
  
  for(int i=0;i<365*5001+1;i++){
    tableH[i] = make_pair(monthList[currMon],currDay);
    
    currDay++;
    

    if(currDay==20){ 
      currDay=0;
      currMon++;
    }
    if(currMon==18 && currDay==5){ 
      currDay=0;
      currMon=0;
    }
    
  }
  /*
  for(int i=0;i<365;i++){
    cout << " currDay " << i << "   Month: " << tableH[i].first <<
      " day " << tableH[i].second << endl;
  }
  */

  currMon=1,currDay=0;
  string dayList[20]={"imix","ik","akbal","kan","chicchan","cimi",
		      "manik","lamat","muluk","ok","chuen","eb","ben",
		      "ix","mem","cib","caban","eznab","canac","ahau"};  
  int currYear=0;
  
  for(int i=0;i<365*5001+1;i++){
    tableT[i] = make_pair(currMon,dayList[currDay]);
    
    currDay++;
    currMon++;

    if(currDay==20) currDay=0;    
    if(currMon==14) currMon=1;
    
  }
  
  /*
  for(int i=0;i<50000;i++) {
    cout << " currDay " << i << "   Month: " << tableT[i].first <<
      " day " << tableT[i].second << endl;
      }
  */
}

void read(){
  
  char c;

  cin >> day >> c >> month >> year;

  //cout << day << ' ' << month << ' ' << year << endl;
}

void work(){

  int sum=0;
  int monthPassed;
  
  for(int i=0;;i++){
    if(monthList[i]==month){
      monthPassed=i;
      break;
    }
  }

  sum+=year*365+day+(monthPassed)*20;
  
  cout << tableT[sum].first << ' ' << tableT[sum].second << ' ' << sum/260 << endl;
}

int main(){

  int cases;
  cin >> cases;

  makeTable();

  cout << cases << endl;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
