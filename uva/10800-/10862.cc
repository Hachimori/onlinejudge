#include<iostream>
#include<algorithm>
#define TABLE 2002
#define BUF 1003
using namespace std;

class BI{
public:
  int num[BUF], leng;
  
  BI(){}

  BI(int n){
    leng = 0;
    fill(num,num+BUF,0);
    
    while(n>0){ 
      num[leng++] = n%10; 
      n /= 10;
    }
  }
  
  void print(){
    if(leng==0) cout << 0;
    for(int i=leng-1;i>=0;i--)
      cout << num[i];
    cout << endl;
  }

  BI operator+ (BI bi) {
    for(int i=0;i<max(leng,bi.leng);i++)
      bi.num[i] += num[i];
  
    for(int i=0;i<max(leng,bi.leng);i++)
      if(bi.num[i]>=10){
	bi.num[i] %= 10;
	bi.num[i+1]++;
	bi.leng = max(bi.leng,i+2);
      }
      else if(bi.num[i]>0)
	bi.leng = max(bi.leng,i+1);
      
    return bi;
  }

  BI operator* (BI bi) {
    int tmp[BUF], tLeng = 0;
    fill(tmp,tmp+BUF,0);
    
    for(int i=0;i<leng;i++)
      for(int j=0;j<bi.leng;j++){
	tmp[i+j] += num[i]*bi.num[j];

	if(tmp[i+j]>=10){
	  tmp[i+j+1] += tmp[i+j]/10;
	  tmp[i+j] %= 10;
	  tLeng = max(tLeng,i+j+2);
	}
	else if(tmp[i+j]>0)
	  tLeng = max(tLeng,i+j+1);
      }
    
    for(int i=0;i<tLeng;i++)
      bi.num[i] = tmp[i];
    bi.leng = tLeng;
    
    return bi;
  }
};

int num;
BI table[TABLE], sum[TABLE];

void makeTable(){
  //table[0] = BI(1);
  table[1] = BI(1);
  table[2] = BI(3);
  sum[1] = BI(1);
  sum[2] = BI(4);

  for(int i=3;i<TABLE;i++){
    table[i] = BI(2)*table[i-1] + sum[i-2] + BI(1);
    sum[i] = table[i]+sum[i-1];
    //sum[i] = table[i]+sum[i-1];
    //for(int j=0;j<i-1;j++)
    //table[i] = table[i]+;
  }
}

bool read(){
  cin >> num;
  return num!=0;
}

void work(){
  table[num].print();
}

int main(){
  makeTable();
  
  while(read())
    work();

  return 0;
}
