#include<iostream>
#include<climits>

#define MAX_SIZE 46340

using namespace std;

int powered, power, mod;

bool read(){
	if(!(cin >> powered >> power >> mod)) return false;
	return true;
}

void rec(int currCycle, long long currNum, int visited[MAX_SIZE]){
	
	if(currCycle==power || visited[currNum]!=INT_MAX){
		
		long long ans=currNum;
		for(int i=0;i<(power-1)%(currCycle-visited[currNum]);i++){
			ans*=powered;
			ans%=mod;
		}
		cout << (int)(ans) << endl;
		return;
	}
	visited[currNum]=currCycle;
	
	
	rec(currCycle+1,(currNum*powered)%mod,visited);
}

void work(){
	
	int visited[MAX_SIZE];

	for(int i=0;i<mod;i++)
		visited[i] = INT_MAX;

	if(power==0) cout << 1%mod << endl;
	else
    	rec(0,powered%mod,visited);

}

int main(){

	while(read())
		work();

	return 0;
}