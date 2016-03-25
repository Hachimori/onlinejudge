#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

map<int,string> digit2hhmm;
map<string,int> n2i, hhmm2digit;

void makeTable(){
  string name[] = {"UTC", "GMT", "BST", "IST", "WET", "WEST", "CET", "CEST", "EET", "EEST", "MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT", "MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT", "ACST", "ACDT", "AWST"};
  int digit[] = {0, 0, 60, 60, 0, 60, 60, 120, 120, 180, 180, 240, -240, -180, -210, -150, -300, -240, -360, -300, -420, -360, -480, -420, -600, -540, -480, 600, 660, 570, 630, 480};

  for(int i=0;i<32;i++)
    n2i[name[i]] = digit[i];

  int cur = 1;
  hhmm2digit["midnight"] = 0;
  digit2hhmm[0] = "midnight";
  for(int k=0;k<2;k++){
    if(k==1){
      hhmm2digit["noon"] = cur;
      digit2hhmm[cur++] = "noon";
    }
    for(int mm=1;mm<60;mm++)
        if(k==0){
          char toPush[20];
          sprintf(toPush,"%d:%02d a.m.",12,mm);
          hhmm2digit[string(toPush)] = cur;
          digit2hhmm[cur++] = string(toPush);
        }
        else{
          char toPush[20];
          sprintf(toPush,"%d:%02d p.m.",12,mm);
          hhmm2digit[string(toPush)] = cur;
          digit2hhmm[cur++] = string(toPush);
        }
    for(int hh=1;hh<=11;hh++)
      for(int mm=0;mm<60;mm++)
        if(k==0){
          char toPush[20];
          sprintf(toPush,"%d:%02d a.m.",hh,mm);
          hhmm2digit[string(toPush)] = cur;
          digit2hhmm[cur++] = string(toPush);
        }
        else{
          char toPush[20];
          sprintf(toPush,"%d:%02d p.m.",hh,mm);
          hhmm2digit[string(toPush)] = cur;
          digit2hhmm[cur++] = string(toPush);
        }
  }
}

int timev;
string self, opp;

void read(){
  string times;
  cin >> times;
  if(times=="noon")
    timev = hhmm2digit[times];
  else if(times=="midnight")
    timev = hhmm2digit[times];
  else {
    string ampm;
    cin >> ampm;
    times += " "+ampm;
    timev = hhmm2digit[times];
  }
  cin >> self >> opp;
}

void work(){
  cout << digit2hhmm[(24*60+timev-n2i[self]+n2i[opp])%(24*60)] <<endl;
}

int main(){
  makeTable();
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
