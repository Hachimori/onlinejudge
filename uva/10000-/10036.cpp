#include<iostream>
#include<algorithm>
#include<cstdlib>

#define MAX_SIZE 10005
#define MAX_RANGE 210
#define SHIFT 100

using namespace std;

int nNum, divider;
int nList[MAX_SIZE];
bool isAvail[MAX_SIZE][MAX_RANGE];

bool &access(int curr, int n){
	return isAvail[curr][n+SHIFT];
}

void read(){
	
	cin >> nNum >> divider;

	for(int i=0;i<nNum;i++)
		cin >> nList[i];

}

void work(){

	for(int i=0;i<=nNum;i++)
		fill(isAvail[i],isAvail[i]+MAX_RANGE,false);

	if(nList[0]>0)
		access(0,nList[0]%divider) = true;
	else
		access(0,-(abs(nList[0])%divider)) = true;

	for(int j=1;j<nNum;j++){
		for(int k=-divider+1;k<divider;k++){
			if(access(j-1,k)){
				if(k+nList[j]<0)
					access(j,-(abs(k+nList[j])%divider)) = true;
				else
					access(j,(k+nList[j])%divider) = true;

				if(k-nList[j]<0)
					access(j,-(abs(k-nList[j])%divider))=true;
				else
					access(j,(k-nList[j])%divider)=true;						
			}
		}
/*
		for(int l=-divider+1;l<divider;l++)
			if(access(j,l)) cout << l << " ";
		cout << endl;
		*/
	}

	if(access(nNum-1,0)) cout << "Divisible" << endl;
	else cout << "Not divisible" << endl;

}

int main(){

	int cases;
	cin >> cases;

	for(int i=0;i<cases;i++){
		read();
		work();
	}


	return 0;
}