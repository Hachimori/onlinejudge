#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int m,n,target;

bool read(){

  if(!(cin >> m >> n >> target)) return false;

  return true;
}

void work(){
  
  bool noBeer=false;
  int ansA=-1, ansB=-1;
  int minMod=INT_MAX;

  if(m>n)
    swap(n,m);

  for(int a=target/m;a>=0;a--){
    //cout << ansA << ' ' << ansB << endl;
    if((target-a*m)%n==0 && ansA+ansB<=a+(target-a*m)/n){
      ansA = a;
      ansB = (target-a*m)/n;
      noBeer=true;
    }
    else if(!noBeer && minMod>(target-a*m)%n){
      ansA = a;
      ansB = (target-a*m)/n;
      minMod = (target-a*m)%n;
    }
    else if(!noBeer && minMod==(target-a*m)%n && ansA+ansB<a+(target-a*m)/n){
      ansA = a;
      ansB = (target-a*m)/n;     
    }
  }

  for(int b=target/n;b>=0;b--){
    //cout << ansA << ' ' << ansB << endl;
    if((target-b*n)%m==0 && ansA+ansB<=b+(target-b*n)/m){
      ansB = b;
      ansA = (target-b*n)/m;
      noBeer=true;
    }
    else if(!noBeer && minMod>(target-b*n)%m){
      ansB = b;
      ansA = (target-b*n)/m;
      minMod = (target-b*n)%m;
    }
    else if(!noBeer && minMod==(target-b*n)%m && ansA+ansB<b+(target-b*n)/m){
      ansB = b;
      ansA = (target-b*n)/m;     
    }
  }

  if(noBeer)
    cout << ansA + ansB << endl;
  else 
    cout <<  ansA + ansB << ' ' << minMod <<  endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
