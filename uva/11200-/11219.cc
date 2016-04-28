#include<iostream>
using namespace std;

class Date{
public:
  int y, m, d;

  bool operator< (const Date &date) const {
    if(y!=date.y) return y<date.y;
    if(m!=date.m) return m<date.m;
    return d<date.d;
  }

  bool operator<= (const Date &date) const {
    if(y!=date.y) return y<date.y;
    if(m!=date.m) return m<date.m;
    return d<=date.d;
  }
};

Date d[2];

void read(){
  char ch;
  for(int i=0;i<2;i++)
    cin >> d[i].d >> ch >> d[i].m >> ch >> d[i].y;
}

void work(int cases){
  cout << "Case #" << cases << ": ";
  
  if(d[0]<d[1]){
    cout << "Invalid birth date" << endl;
    return;
  }

  int cnt = -1;
  while(d[1]<=d[0]){
    d[1].y++;
    cnt++;
  }

  if(cnt>130)
    cout << "Check birth date" << endl;
  else
    cout << cnt << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
