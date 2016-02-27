#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#define phone first
#define time second
#define DATA 10000
#define QUERY 10000
using namespace std;
typedef pair<string,int> Query;

class Data{
public:
  string prefix, area;
  int cost;

  Data(){}
  Data(string p, string a, int c): prefix(p), area(a), cost(c){}
};

map<string,Data> data;
int nQuery;
Query query[QUERY];

void read(){
  while(true){
    int cost;
    string prefix, s;
    cin >> prefix;
    if(prefix=="000000") break;
    getline(cin,s);

    string next;
    for(int i=0;i<s.size();i++)
      if(s[i]!=' ')
        next += s[i];
    s = next;

    for(int i=0;i<s.size();i++)
      if(s[i]=='$'){
        data[prefix] = Data(prefix,s.substr(0,i),atoi(s.substr(i+1).c_str()));
        break;
      }
  }

  nQuery = 0;
  while(true){
    char phone[30];
    int time;
    if(scanf("%s%d",phone,&time)==1) break;
    
    query[nQuery++] = Query(string(phone),time);
  }
}

bool valid(string prefix, string origin){
  if(prefix.substr(0,2)=="00" && prefix!="00"){
    return 1<=prefix.size()-2 && prefix.size()-2<=3 &&
           4<=origin.size()-prefix.size() && origin.size()-prefix.size()<=10;
  }
  else{
    return 1<=prefix.size()-1 && prefix.size()-1<=5 &&
           4<=origin.size()-prefix.size() && origin.size()-prefix.size()<=7;
  }
}

void work(){
  for(int i=0;i<nQuery;i++){
    Query &q = query[i];

    if(q.phone[0]!='0'){
      printf("%-16s%-26s%9s%5d  0.00   0.00\n",q.phone.c_str(),"Local",q.phone.c_str(),q.time); 
      continue;
    }
    
    bool found = false;
    for(int len=0;len<=q.phone.size();len++)
      if(data.count(q.phone.substr(0,len)) && valid(q.phone.substr(0,len),q.phone)){
        Data &d = data[q.phone.substr(0,len)];
        string suffix = q.phone.substr(len);

        printf("%-16s%-26s%9s%5d%6.2lf%7.2lf\n",q.phone.c_str(),d.area.c_str()
                                               ,suffix.c_str(),q.time,d.cost/100.0,q.time*d.cost/100.0);
        found = true;
        break;
      }
    
    if(!found)
      printf("%-16s%-26s%14d%13s\n", q.phone.c_str(), "Unknown", q.time, "-1.00");
  }
}

int main(){
  read();
  work();
  return 0;
}
