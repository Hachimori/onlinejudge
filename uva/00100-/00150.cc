#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Date{
public:
  int y, m, d, w;

  Date(){}
  Date(int y, int m, int d, int w): y(y), m(m), d(d), w(w){}

  void move(bool newOne){
    int days[2][13]={{-1,31,28,31,30,31,30,31,31,30,31,30,31},
                     {-1,31,29,31,30,31,30,31,31,30,31,30,31}};
    bool leap;
    
    if(newOne)
      leap = (y%400==0 || (y%4==0 && y%100!=0));
    else
      leap = (y%4==0);
    
    w = (w+1)%7;
    d++;
    if(d-1==days[leap][m]){
      m++;
      d = 1;
      if(m==13){
        y++;
        m = 1;
      }
    }
  }

  bool operator< (Date &da) const {
    if(y!=da.y) return y<da.y;
    if(m!=da.m) return m<da.m;
    if(d!=da.d) return d<da.d;
    return w<da.w;
  }
};

class Finder{
public:
  bool newOne;
  
  Finder(){}
  Finder(bool n): newOne(n){}
  
  bool operator() (pair<Date,Date> a, pair<Date,Date> b) const {
    if(newOne) 
      return a.first<b.first;
    else 
      return a.second<b.second;
  }
};

vector< pair<Date,Date> > dates;
string mStr[]={"January", "February", "March", "April",
               "May", "June", "July", "August", "September",
               "October", "November", "December"};
string wStr[]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", 
               "Saturday", "Sunday"};
map<string,int> m2i, w2i;

bool isLeap(int y){
  return y%400==0 || (y%4==0 && y%100!=0);
}

void makeTbl(){
  Date newCal = Date(1582,10,14,3), oldCal = Date(1582,10,4,3);
  while(true){
    if(newCal.y==2300) break;
    dates.push_back(make_pair(newCal,oldCal));
    newCal.move(true);
    oldCal.move(false);
  }

  for(int i=0;i<12;i++)
    m2i[mStr[i]] = i+1;

  for(int i=0;i<7;i++)
    w2i[wStr[i]] = i;
}

int zeller(int y, int m, int d){
  if(m<3){y--; m+=12;}
  return (y+y/4-y/100+y/400+(13*m+8)/5+d+6)%7;
}

string week, mon;
int day, year;

bool read(){
  cin >> week >> day >> mon >> year;
  return week!="#";
}

void work(){
  int w = w2i[week], d = day, m = m2i[mon], y = year;

  // This is old date, so change it new one
  if((m==2 && d==29 && !isLeap(y)) || zeller(y,m,d)!=w){
    pair<Date,Date> toFind = make_pair(Date(y,m,d,-1),Date(y,m,d,-1));
    Date t = lower_bound(dates.begin(),dates.end(),toFind,Finder(false))->first;
    cout << wStr[t.w] << ' ' << t.d << ' ' << mStr[t.m-1] << ' ' << t.y << endl;
  }
  else{// Otherwise, change it new one
    pair<Date,Date> toFind = make_pair(Date(y,m,d,-1),Date(y,m,d,-1));
    Date t = lower_bound(dates.begin(),dates.end(),toFind,Finder(true))->second;
    cout << wStr[t.w] << ' ' << t.d << "* " << mStr[t.m-1] << ' ' << t.y << endl;
  }
}

int main(){
  makeTbl();
  while(read())
    work();

  return 0;
}