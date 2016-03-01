#include<iostream>

#define MAX_RANGE 30005

using namespace std;

long long table[MAX_RANGE][5];

void makeTable(){
	
	for(int i=0;i<MAX_RANGE;i++)
		for(int j=0;j<5;j++)
			table[i][j] = 0;

	table[0][0] = 1;
	for(int k=1;k<MAX_RANGE;k++){
		table[k][0]++;
		
		if(k-5>=0) table[k][1]+=table[k-5][0]+table[k-5][1];
		if(k-10>=0) table[k][2]+=table[k-10][0]+table[k-10][1]+table[k-10][2];
		if(k-25>=0) table[k][3]+=table[k-25][0]+table[k-25][1]+table[k-25][2]+table[k-25][3];
		if(k-50>=0) table[k][4]+=table[k-50][0]+table[k-50][1]+table[k-50][2]+table[k-50][3]+table[k-50][4];

	}
	
}

int n;

bool read(){
	if(!(cin >> n)) return false;
	return true;
}

void work(){
	
	long long sum=0;

	for(int i=0;i<5;i++)
		sum+=table[n][i];
	
	if(sum==1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
	else cout << "There are " << sum << " ways to produce " << n << " cents change." << endl;

}

int main(){
	
	makeTable();

	while(read())
		work();
	
	return 0;
}