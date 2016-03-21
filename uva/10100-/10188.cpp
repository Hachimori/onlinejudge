#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<fstream>

//#define cin fin
#define MAX_SIZE 105

using namespace std;

//ifstream fin("test.txt");

int nStr1, nStr2;
string strList1[MAX_SIZE], strList2[MAX_SIZE];

bool read(){
	
	cin >> nStr1;
	if(nStr1==0) return false;
	
	getline(cin,strList1[0]);

	for(int i=0;i<nStr1;i++)
		getline(cin,strList1[i]);


	cin >> nStr2;
	
	getline(cin,strList2[0]);

	for(int j=0;j<nStr2;j++)
		getline(cin,strList2[j]);

	return true;
}

bool isAccept(){
	
	if(nStr1!=nStr2) return false;

	for(int i=0;i<nStr1;i++)
		if(strList1[i]!=strList2[i]) 
			return false;

	return true;

}

void split(string strList[MAX_SIZE], int nLine, vector<int> &intList){
	
	for(int i=0;i<nLine;i++)
		for(int j=0;j<strList[i].size();j++)
			if(isdigit(strList[i][j])) 
				intList.push_back(strList[i][j]-'0');
					
}

bool isWrong(){

	vector<int> intList1, intList2;

	split(strList1,nStr1,intList1);
	split(strList2,nStr2,intList2);

	if(intList1.size()!=intList2.size()) return true;

	for(int i=0;i<intList1.size();i++)
		if(intList1[i]!=intList2[i]) return true;


	return false;
}

void work(int cases){
	
	cout << "Run #" << cases << ": ";

	if(isAccept()) {
		cout << "Accepted" << endl;
		return;
	}

	if(isWrong()){
		cout << "Wrong Answer" << endl;
		return;
	}

	cout << "Presentation Error" << endl;
}

int main(){

	for(int cases=1;read();cases++)
		work(cases);

	return 0;
}