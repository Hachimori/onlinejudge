#include<iostream>
#include<vector>

#define MAX_SIZE 30

using namespace std;

long long table[MAX_SIZE];
int n;

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

void createTable(){
  
  table[0] = 0;
  table[1] = 0;
  table[2] = 0;
  table[3] = 1;

  long long bracketingTable[MAX_SIZE];

  bracketingTable[0]=0;
  bracketingTable[1]=0;
  bracketingTable[2]=1;
  bracketingTable[3]=3;
  
  for(int i=3;i<MAX_SIZE-1;i++){
    
    vector<int> divided;
    vector<int> divisor;

    for(int j=2*i;j>=1;j--)
      divided.push_back(j);

    for(int j=i;j>=1;j--)
      divisor.push_back(j);
    
    for(int j=i+1;j>=1;j--)
      divisor.push_back(j);
    
    
    for(int j=0;j<divided.size();j++){
      for(int k=0;k<divisor.size();k++){
	int ret=gcd(divided[j],divisor[k]);

	divided[j]/=ret;
	divisor[k]/=ret;
      }
    }

    long long catran=1;

    for(int j=0;j<divided.size();j++)
      catran*=divided[j];
    i++;
    bracketingTable[i]=(3*(2*i-3)*bracketingTable[i-1]-(i-3)*bracketingTable[i-2])/i;
    i--;
    
    
    table[i+1] = bracketingTable[i+1]-catran;
  }
  
}

bool read(){
  if(!(cin >> n)) return false;
  return true;
}

void work(){
  cout << table[n] << endl;
}

int main(){

  createTable();

  while(read())
    work();

  return 0;
}
