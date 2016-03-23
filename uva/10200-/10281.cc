#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

int main(){
  int prevSpeed = 0, prevTime = -1;
  double dist = 0;

  string s;
  while(getline(cin,s)){
    stringstream in(s);
    
    int nexSpeed = prevSpeed, nexTime, changed = 0;
    for(int i=0;i<2;i++){
      if(!(in >> s)) break;
      if(i==0){
        int h,m,sec;
        sscanf(s.c_str(),"%d:%d:%d",&h,&m,&sec);
        nexTime = h*60*60+m*60+sec;
      }
      else{
        sscanf(s.c_str(),"%d",&nexSpeed);
        changed = 1;
      }
    }
    dist += 1.0*(nexTime-prevTime)/3600*prevSpeed;

    if(!changed)
      printf("%02d:%02d:%02d %.2lf km\n",nexTime/3600,nexTime/60%60,nexTime%60,dist);
    
    prevTime = nexTime;
    prevSpeed = nexSpeed;
  }
  return 0;
}
