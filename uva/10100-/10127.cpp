#include<iostream>

using namespace std;

int n;

bool read(){
	if(!(cin >> n)) return false;
	return true;
}

void work(){
	
	int curr=n;
	int score=0;
	
	while(curr!=0){
		
		for(int i=0;i<=9;i++){
			if((curr+n*i)%10==1){ 
				curr=curr+n*i;
				break;
			}
		}

		while(curr%10==1){ 
			curr/=10;
			score++;
		}
		

	}

	cout << score << endl;

}

int main(){

	while(read())
		work();

	return 0;
}