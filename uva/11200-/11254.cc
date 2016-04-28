#include<iostream>
#include<cmath>
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
typedef long long LL;

int main(){
  
  while(true){
    int num; cin >> num;
    if(num==-1) break;
  
    int sqrtN = (int)(sqrt(num*2)-EPS);

    for(int nSeq=sqrtN;nSeq>=1;nSeq--){
      double average = 1.0*num/nSeq;
      int aveInt = (int)(average+EPS);
      //cout << average << ' ' << aveInt << endl;
      if(!EQ(average-aveInt,0) && !EQ(average-aveInt,0.5)) continue;
      
      if(EQ(average-aveInt,0)){
	int L = num/nSeq - nSeq/2;
	int R = num/nSeq + nSeq/2;
	if((LL)R*(R+1)/2-(LL)L*(L-1)/2!=num){
	  //cout << "hf" << endl;
	  continue;
	}
	cout << num << " = " << L << " + ... + " << R << endl;
	break;
      }
      else {
	int L = 1.0*num/nSeq - nSeq/2 + 1;
	int R = 1.0*num/nSeq + nSeq/2;
	
	if((LL)R*(R+1)/2-(LL)L*(L-1)/2!=num){
	  //cout << "hjh" << endl;
	  continue;
	}
	cout << num << " = " << L << " + ... + " << R << endl;
	break;
      }
    }
  }

  return 0;
}
