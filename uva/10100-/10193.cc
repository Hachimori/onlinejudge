#include<iostream>
#include<string>

using namespace std;

string buf1,buf2;

void read(){
  cin >> buf1 >> buf2;
}

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

void work(int cases){
  
  int num1=0, num2=0;
  
  for(int i=buf1.size()-1,p=1;i>=0;i--,p*=2)
    num1+=p*(buf1[i]-'0');
  
  for(int i=buf2.size()-1,p=1;i>=0;i--,p*=2)
    num2+=p*(buf2[i]-'0');

  if(gcd(num1,num2)==1)
    cout << "Pair #" << cases << ": Love is not all you need!" << endl;
  else
    cout << "Pair #" << cases << ": All you need is love!" << endl;

  
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
