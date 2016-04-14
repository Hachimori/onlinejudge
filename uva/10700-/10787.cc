#include<iostream>
#include<fstream>

//#define cin fin

using namespace std;

//ifstream fin("test.txt");

int main(){

	int cases;
	cin >> cases;

	for(int i=0;i<cases;i++){
		
		int la, ra, lb, rb, lm, rm, na;
		cin >> la >> ra >> lb >> rb >> lm >> rm;
		na = ra-la+1;

		int sum=0;
		for(int j=lb;j<=rb;j++){
			for(int k=lm;k<=rm;k++)
				if(j*2%k==0){
					sum+=na;
				}
		}
		
		cout << "Case " << i+1 << ": " << sum << endl;
	}
	

	return 0;
}
