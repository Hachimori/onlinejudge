#include<iostream>
#include<algorithm>

#define MAX_SIZE 10000000

using namespace std;

bool isPrime[MAX_SIZE];
int primeList[MAX_SIZE/2];
int nPrime, N;

void makeTable(){

	fill(isPrime,isPrime+MAX_SIZE,true);

	for(int i=2;i*i<MAX_SIZE;i++)
		if(isPrime[i])
			for(int j=i*2;j<MAX_SIZE;j+=i)
				isPrime[j]=false;
	
	isPrime[0]=false;
	isPrime[1]=false;

	nPrime=1;
	primeList[0]=2;

	for(int k=3;k<MAX_SIZE;k+=2)
		if(isPrime[k]){
			primeList[nPrime]=k;
			nPrime++;
		}

}

bool read(){
	if(!(cin >> N)) return false;
	return true;
}

void work(){
	
	if(N<=7){ 
		cout << "Impossible." << endl;
		return;
	}
	else if(N==8){
		cout << "2 2 2 2" << endl;
		return;
	}

	int targetA;
	if(N%2==1) targetA=N-5;
	else targetA=N-4;

	for(int i=0;;i++){
		if(isPrime[targetA-primeList[i]]){
			if(N%2==1)
				cout << targetA-primeList[i] << " " << primeList[i] << " 2 3" << endl;
			else
				cout << targetA-primeList[i] << " " << primeList[i] << " 2 2" << endl;
			break;
		}
	}

}

int main(){

	makeTable();

	while(read())
		work();

	return 0;
}