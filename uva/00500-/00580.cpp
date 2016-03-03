#include<iostream>
#include<vector>

#define MAX_SIZE 35

using namespace std;

int n;
int table[MAX_SIZE];


void makeTable(){
	table[1]=0;
	table[2]=0;
	table[3]=1;

	int tribonacci[MAX_SIZE];

	tribonacci[1]=2;
	tribonacci[2]=4;
	tribonacci[3]=7;

	for(int i=4;i<MAX_SIZE;i++)
		tribonacci[i] = tribonacci[i-1] + tribonacci[i-2] + tribonacci[i-3];
	
	int p=16;

	for(int j=4;j<MAX_SIZE;j++,p*=2)
		table[j] = p-tribonacci[j];
	

}

bool read(){
	cin >> n;
	if(n==0) return false;	

	return true;
}

void work(){
	
	cout << table[n] << endl;

}

int main(){

	makeTable();

	while(read())
		work();

	return 0;
}