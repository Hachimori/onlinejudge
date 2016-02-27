#include<iostream>
#include<cmath>

using namespace std;

double nRoot, source;

bool read(){

	if(!(cin >> nRoot >> source)) return false;

	return true;
}

void work(){
	cout << (int)(pow(source,1.0/nRoot)+0.5) << endl;
}

int main(){

	while(read())
		work();

	return 0;
}