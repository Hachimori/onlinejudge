#include<iostream>
#include<algorithm>

using namespace std;

int dayOfMonth[2][13]={{-1,31,28,31,30,31,30,31,31,30,31,30,31},
		       {-1,31,29,31,30,31,30,31,31,30,31,30,31}};

int century, yymmdd[3];

void read(){
  cin >> century >> yymmdd[0] >> yymmdd[1] >> yymmdd[2];
}

bool isLeapYear(int y){
  return y%400==0 || (y%4==0 && y%100!=0);
}

bool isValid(int yymmdd[]){
  
  int year = yymmdd[0]+century%4;
  int month = yymmdd[1];
  int day = yymmdd[2];
  
  return (1<=month && month<=12 && 
	  1<=day && day<=dayOfMonth[isLeapYear(year)][month]);
}

void work(){
  
  sort(yymmdd,yymmdd+3);
  
  while(true){
    
    if(isValid(yymmdd)){
      
      for(int i=0;i<3;i++){
	if(i!=0) cout << ' ';
	if(yymmdd[i]<10) cout << 0;
	cout << yymmdd[i];
      }cout << endl;
      
      return;
    }
    
    if(!next_permutation(yymmdd,yymmdd+3)) break;
  }
  

  cout << -1 << endl;
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
