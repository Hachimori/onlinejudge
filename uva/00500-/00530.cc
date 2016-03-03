#include<iostream>
#include<list>

using namespace std;

int nElement, nChose;

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

bool read(){
  cin >> nElement >> nChose;

  if(nElement==0 && nChose==0) return false;
  return true;
}

void work(){

  if(nChose==0){
    cout << 1 << endl;
    return;
  }
  
  list<int> divided;
  list<int> divisor;

  for(int i=nElement;i>max(nChose,nElement-nChose);i--)
    divided.push_back(i);

  for(int i=2;i<=min(nChose,nElement-nChose);i++)
    divisor.push_back(i);

  
  for(list<int>::iterator i=divided.begin();i!=divided.end();i++){
    for(list<int>::iterator j=divisor.begin();j!=divisor.end();j++){

      int ret = gcd(*i,*j);
      
      *i/=ret;
      *j/=ret;

      if(*j==1){
	j = divisor.erase(j);
	j--;
      }


    }
  }
  

  int result=1;
  for(list<int>::iterator i=divided.begin();i!=divided.end();i++)    
    result*=*i;

  cout << result << endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
