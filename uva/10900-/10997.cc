// ad-hoc
//
// 1/(n^i) + 1/(n^j) + 1/(n^k) 
// この式のi,j,kは整数であることと、
// nが十分に大きい数であることから、
// 0<=i,j,k<=2 の中でカナダが勝てるような数字を探すとよい。

#include<iostream>
#include<string>
#include<cmath>

#define MAX_SIZE 25

using namespace std;

class Country{
public:
  string name;
  int medal[3];

  Country(){}
  
  double score(int a, int b, int c, int nMedal){
    return (medal[0]*(1.0/pow((double)nMedal,(double)a))+
	    medal[1]*(1.0/pow((double)nMedal,(double)b))+
	    medal[2]*(1.0/pow((double)nMedal,(double)c)));
  }
};

int nCountry, canadaPos, nMedal;
Country country[MAX_SIZE];

bool read(){
  cin >> nCountry;
  if(nCountry==0) return false;
  
  canadaPos = -1;
  nMedal = 0;
  
  for(int i=0;i<nCountry;i++){
    cin >> country[i].name >> country[i].medal[0]
	>> country[i].medal[1] >> country[i].medal[2];
    
    for(int j=0;j<3;j++)
      nMedal += country[i].medal[j];

    if(country[i].name=="Canada")
      canadaPos = i;
  }

  return true;
}

void work(){
  if(canadaPos==-1) {
    cout << "Canada cannot win." << endl;
    return;
  }
  
  for(int i=0;i<=2;i++)
    for(int j=0;j<=2;j++)
      for(int k=0;k<=2;k++){
	int maxPos;
	double maxVal = -1;

	for(int l=0;l<nCountry;l++){
	  if(maxVal<country[l].score(i,j,k,nMedal)){
	    maxVal = country[l].score(i,j,k,nMedal);
	    maxPos = l;
	  }
	}
	  
	if(maxPos==canadaPos){
	  cout << "Canada wins!" << endl;
	  return;
	}
      }
  
  cout << "Canada cannot win." << endl;	
}

int main(){
  while(read())
    work();
    
  return 0;
}
