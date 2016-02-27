#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
#define BUF 10000
using namespace std;

class Query{
public:
  int day, mon;
};

class Event{
public:
  string name;
  int day, mon, prior, id;
  int within, star;

  bool operator< (const Event &e) const {
    if(within!=e.within) return within<e.within;
    if(star!=e.star) return star>e.star;
    return id<e.id;
  }
};

int year, nQuery, nEvent;
Query query[BUF];
Event event[BUF];

void read(){
  nQuery = nEvent = 0;

  cin >> year;
  
  while(true){
    string s;
    cin >> s;
    if(s=="#") break;

    if(s=="A"){
      Event &e = event[nEvent++];
      e.id = nEvent;
      cin >> e.day >> e.mon >> e.prior;
      getline(cin,e.name);
      
      int bgn=0, end=e.name.size()-1;
      for(;e.name[bgn]==' ';bgn++);
      for(;e.name[end]==' ';end--);
      e.name = e.name.substr(bgn,end-bgn+1);
    }
    
    if(s=="D"){
      Query &q = query[nQuery++];
      cin >> q.day >> q.mon;
    }
  }
}

void work(){
  int days[][13]={{-1,31,28,31,30,31,30,31,31,30,31,30,31},
                  {-1,31,29,31,30,31,30,31,31,30,31,30,31}};
  
  for(int k=0;k<nQuery;k++){
    Query &q = query[k];

    vector<Event> toPrint;
    for(int i=0;i<nEvent;i++){
      int mon = q.mon, day = q.day;
      for(int j=0;j<=event[i].prior;j++){
        if(mon==event[i].mon && day==event[i].day){
          Event e = event[i];
          e.within = j;
          e.star = (j==0 ? 8 : e.prior-j+1);
          toPrint.push_back(e);
          break;
        }
        
        day++;
        if(day==days[year%4==0][mon]+1){
          day = 1;
          mon++;
          if(mon==13) mon = 1;
        }
      }
    }
    sort(toPrint.begin(),toPrint.end());

    if(k) cout << endl;
    printf("Today is:%3d%3d\n",q.day,q.mon);
    for(int i=0;i<toPrint.size();i++){
      Event &e = toPrint[i];
      if(e.star==8)
        printf("%3d%3d *TODAY* %s\n",e.day,e.mon,e.name.c_str());
      else
        printf("%3d%3d %-7s %s\n",e.day,e.mon,string(e.star,'*').c_str(),e.name.c_str());
    }
  }
}

int main(){
  read();
  work();
  
  return 0;
}
