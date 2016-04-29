#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string M[]={"","January", "February", "March", "April", "May", 
            "June", "July", "August", "September", "October", 
            "November", "December"};

int nDay[2][13]={{-1,31,28,31,30,31,30,31,31,30,31,30,31},
                 {-1,31,29,31,30,31,30,31,31,30,31,30,31}};

void clean(string s, int &y, int &m, int &d){
  y = atoi(s.substr(0,4).c_str());
  m = find(M,M+13,s.substr(5,s.size()-8))-M;
  d = atoi(s.substr(s.size()-2).c_str());
}

bool isLeap(int y){
  return y%400==0 || (y%4==0 && y%100!=0);
}

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    string s;
    int toGo;
    cin >> s >> toGo;

    int y, m, d;
    clean(s,y,m,d);

    for(int i=0;i<toGo;i++){
      d++;
      if(nDay[isLeap(y)][m]<d){
        d = 1;
        m++;
        if(m==13){
          m = 1;
          y++;
        }
      }
    }
    
    printf("Case %d: %d-%s-%02d\n",k+1,y,M[m].c_str(),d);
  }
  return 0;
}
