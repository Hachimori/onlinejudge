#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 100

using namespace std;

string str;

bool read(){	
	if(!(cin >> str)) return false;
	return true;
}

void calc(int nInserted, string &currStr){
	
	if(nInserted==str.size()){
		cout << currStr << endl;
		return;
	}

	for(string::iterator i=currStr.begin();;i++){
		currStr.insert(i,str[nInserted]);
		calc(nInserted+1,currStr);
		currStr.erase(currStr.find(str[nInserted]),1);
		if(i==currStr.end()) break;
	}

}

void work(){

	string currStr;
	
	currStr+=str[0];

	calc(1,currStr);
	

}

int main(){

	for(int i=0;read();i++){
		if(i!=0) cout << endl;
		work();
	}

	return 0;
}