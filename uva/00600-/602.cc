#include<iostream>
#include<string>
using namespace std;

int month, day, year;

bool read(){
  cin >> month >> day >> year;
  if((month|day|year)==0) return false;
  return true;
}

int gregorian(int y, int m, int d){
  if(m<3) y--, m+=12;
  y += 4800;
  m -= 3;
  return d+(153*m+2)/5+365*y+y/4-y/100+y/400-32045;
}

int julian(int y, int m, int d){
  if(m<3) y--, m+=12;
  y += 4800;
  m -= 3;
  return d+(153*m+2)/5+365*y+y/4-32083;
}

bool valid(int y, int m, int d, bool julian){
  if(m<1 || 12<m) return false;
  
  int days[2][13]={{-1,31,28,31,30,31,30,31,31,30,31,30,31},
                   {-1,31,29,31,30,31,30,31,31,30,31,30,31}};

  bool isLeapYear = (julian ? y%4==0 : (y%400==0 || (y%4==0 && y%100!=0)));
  
  return 1<=d && d<=days[isLeapYear][m];
}


void work(){
  string mon[]={"-","January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};
  string week[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", 
                 "Friday", "Saturday"};

  bool isJulian = false, isGregorian = false;
  if(year<1752) isJulian = true;
  else if(year==1752)
    if(month<9) isJulian = true;
    else if(month==9)
      isJulian = day<=2;
  
  if(year>1752) isGregorian = true;
  else if(year==1752)
    if(month>9) isGregorian = true;
    else if(month==9)
      isGregorian = day>=14;

  if(!valid(year,month,day,isJulian) || (!isJulian && !isGregorian)){
    cout << month << '/' << day << '/' << year << " is an invalid date." << endl;
    return;
  }
  
  int pos = (isJulian ? julian(year,month,day)+1 : gregorian(year,month,day)+1)%7;
 
  cout << mon[month] << ' ' << day << ", " << year << " is a " << week[pos] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
