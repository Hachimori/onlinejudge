#include<iostream>

using namespace std;

int main(){

	int cases;
	cin >> cases;

	for(int i=0;i<cases;i++){
	
		int lower, upper;
		cin >> lower >> upper;

		int sum=0;
		for(int j=lower;j<=upper;j++){
			if(j%2==1) sum+=j;
		}
	
		cout << "Case " << i+1 << ": " << sum << endl;
	}

	return 0;
}
