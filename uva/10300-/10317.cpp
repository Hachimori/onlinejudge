#include<iostream>
#include<cctype>
#include<vector>
#include<string>
//#include<fstream>
#include<algorithm>

#define PLUS -1
#define MINUS -2
#define EQUAL -3

#define MAX_RANGE 3400
#define MAX_SIZE 34
//#define cin fin

using namespace std;

//ifstream fin("tmp.txt");

int nNum, sum;
int nLeft, nRight;
int nList[MAX_SIZE];
vector<int> equation;

void split(string str, vector<int> &tmpList){

	for(int i=0;i<str.length();i++){

		while(i<str.length() && str[i]==' ') i++;

		int sum=0;
		while(i<str.length() && isdigit(str[i])){
			sum*=10;
			sum+=str[i]-'0';
			i++;
		}

		tmpList.push_back(sum);

		while(i<str.length() && str[i]==' ') i++;

		if(i<str.length() && str[i]=='+') tmpList.push_back(PLUS);
		if(i<str.length() && str[i]=='-') tmpList.push_back(MINUS);
		if(i<str.length() && str[i]=='=') tmpList.push_back(EQUAL);

	}

}

bool read(){
	
	string str; 
	
	if(getline(cin,str)==NULL) return false;

	
	equation.clear();
	split(str,equation);

	/*
	for(int j=0;j<equation.size();j++){
		if(equation[j]==PLUS) cout << " +";
		else if(equation[j]==MINUS) cout << " -";
		else if(equation[j]==EQUAL) cout << " =";
		else cout << " " << equation[j];	
	}cout << endl;
*/
	
	nNum = (equation.size()+1)/2;
	sum=0; nLeft=1, nRight=1;

	int cursor=0;
	
	while(equation[cursor]!=EQUAL){
		if(equation[cursor]==PLUS) nLeft++;
		else if(equation[cursor]==MINUS) nRight++;

		cursor++;
	}cursor++;

	while(cursor<equation.size()){
		if(equation[cursor]==PLUS) nRight++;
		else if(equation[cursor]==MINUS) nLeft++;

		cursor++;
	}

	
	cursor=0;
	for(int i=0;i<equation.size();i++){
		if(equation[i]>=0){
			nList[cursor]=equation[i];
			sum+=equation[i];
			cursor++;
		}
	}

	return true;
}

void output(bool used[MAX_SIZE]){
	int leftCur=0, rightCur=0;
	int nPrinted=0;

	if(nLeft<nRight){
		while(leftCur<nNum || rightCur<nNum){

			while(leftCur<nNum && !used[leftCur]) leftCur++;
			while(rightCur<nNum && used[rightCur]) rightCur++;

			if(nPrinted==0){ 
				cout << nList[leftCur];
				leftCur++;
				nPrinted++;
			}
			else{ 
				if(nPrinted<equation.size() && equation[nPrinted]==PLUS){
					cout << " + " << nList[leftCur];
					leftCur++;
				}
				else if(nPrinted<equation.size() && equation[nPrinted]==MINUS){
					cout << " - " << nList[rightCur];
					rightCur++;
				}
				else if(nPrinted<equation.size() && equation[nPrinted]==EQUAL){
					cout << " = " << nList[rightCur];
					rightCur++;
					nPrinted+=2;
					
					while(leftCur<nNum || rightCur<nNum){

						while(leftCur<nNum && !used[leftCur]) leftCur++;
						while(rightCur<nNum && used[rightCur]) rightCur++;
						
						if(nPrinted<equation.size() && equation[nPrinted]==PLUS){
							cout << " + " << nList[rightCur];
							rightCur++;
						}
						else if(nPrinted<equation.size() && equation[nPrinted]==MINUS){
							cout << " - " << nList[leftCur];
							leftCur++;
						}
						nPrinted+=2;
					}
					cout << endl;
					return;
				}
				nPrinted+=2;
			}

		}	
	}
	else {
		while(leftCur<nNum || rightCur<nNum){

			while(leftCur<nNum && used[leftCur]) leftCur++;
			while(rightCur<nNum && !used[rightCur]) rightCur++;

			if(nPrinted==0){ 
				cout << nList[leftCur];
				leftCur++;
				nPrinted++;
			}
			else{ 
				if(nPrinted<equation.size() && equation[nPrinted]==PLUS){
					cout << " + " << nList[leftCur];
					leftCur++;
				}
				else if(nPrinted<equation.size() && equation[nPrinted]==MINUS){
					cout << " - " << nList[rightCur];
					rightCur++;
				}
				else if(nPrinted<equation.size() && equation[nPrinted]==EQUAL){
					cout << " = " << nList[rightCur];
					rightCur++;
					nPrinted+=2;
					
					while(leftCur<nNum || rightCur<nNum){

						while(leftCur<nNum && used[leftCur]) leftCur++;
						while(rightCur<nNum && !used[rightCur]) rightCur++;
						
						if(nPrinted<equation.size() && equation[nPrinted]==PLUS){
							cout << " + " << nList[rightCur];
							rightCur++;
						}
						else if(nPrinted<equation.size() && equation[nPrinted]==MINUS){
							cout << " - " << nList[leftCur];
							leftCur++;
						}
						nPrinted+=2;
					}
					cout << endl;
					return;
				}
				nPrinted+=2;
			}

		}	
	}

}

bool calc(int nChose, int currScore, int limit, bool visited[MAX_SIZE][MAX_RANGE], bool used[MAX_SIZE]){
	
	if(nChose==limit){	

		if(currScore==sum-currScore){ 
			output(used);
			return true;
		}
	
		return false;
	}
	if(currScore>=sum/2) return false;

	visited[nChose][currScore]=true;

	for(int i=0;i<nNum;i++){
		if(used[i]) continue;
		if(visited[nChose+1][currScore+nList[i]]) continue;
		
		used[i] = true;

		if(calc(nChose+1,currScore+nList[i],limit,visited,used)) return true;

		used[i] = false;
	}


	return false;
}

void work(){
	/*
	cout << nLeft << " " << nRight << endl;
	for(int i=0;i<nNum;i++)
		cout << nList[i] << " ";
	cout << endl << endl;
	*/

	bool visited[MAX_SIZE][MAX_RANGE], used[MAX_SIZE];
	int smaller;

	if(nRight<nLeft) smaller = nRight;
	else smaller = nLeft;

	if(sum%2==1){
		cout << "no solution" << endl;
		return;
	}

	for(int j=0;j<=nNum;j++)
		fill(visited[j],visited[j]+MAX_RANGE,false);
	fill(used,used+MAX_SIZE,false);

	for(int i=0;i<nNum;i++){
		if(!visited[0][nList[i]]){
			used[i]=true;
			if(calc(1,nList[i],smaller,visited,used)) return;
			used[i]=false;
		}
	}

	cout << "no solution" << endl;

}

int main(){

	while(read())
		work();

	return 0;
}