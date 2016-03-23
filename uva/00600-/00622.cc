#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<fstream>

//#define cin fin
#define ERR -1
#define PLUS -2
#define MUL -3
#define LPAREN -4
#define RPAREN -5

using namespace std;

//ifstream fin("test.txt");
string target;
vector<int> targetv;

int errChk(){
	
	int nLeftParen=0, nRightParen=0, nOpe=0, nDigit=0;

	for(int i=0;i<targetv.size();i++){
		if(targetv[i]==MUL || targetv[i]==PLUS) nOpe++;
		else if(targetv[i]==LPAREN) nLeftParen++;
		else if(targetv[i]==RPAREN) nRightParen++;
		else nDigit++;
	}

	if(nLeftParen!=nRightParen) return ERR;
	if(nOpe+1!=nDigit) return ERR;
	if(targetv.front()==MUL || targetv.front()==PLUS || targetv.front()==RPAREN ||
		targetv.back()==MUL || targetv.back()==PLUS || targetv.back()==LPAREN) 
		return ERR;

	for(int j=0;j<targetv.size();j++){
		if(targetv[j]==LPAREN && targetv[j+1]==RPAREN ) return ERR;
		if(targetv[j]==RPAREN && targetv[j+1]==LPAREN ) return ERR;
		if(targetv[j]==MUL || targetv[j]==PLUS){
			if(targetv[j-1]==MUL || targetv[j-1]==PLUS) return ERR;
			if(targetv[j-1]==LPAREN || targetv[j+1]==RPAREN) return ERR;
		}
		if(j>=1 && targetv[j]>=0 && targetv[j-1]==RPAREN) return ERR;
		if(j+1<targetv.size() && targetv[j]>=0 && targetv[j+1]==LPAREN) return ERR;
	}


	return 1;
}

void print(){
	for(int i=0;i<targetv.size();i++){
		if(targetv[i]==MUL) cout << "*";
		else if(targetv[i]==PLUS) cout << "+";
		else if(targetv[i]==LPAREN) cout << "(";
		else if(targetv[i]==RPAREN) cout << ")";
		else cout << targetv[i];
	}cout << endl;
}

int calc2(int a, int b, int ope){

	if(ope==PLUS) return a+b;
	if(ope==MUL) return a*b;

}

int calc(int cursor){
	
	vector<int>::iterator i;
	vector<int>::iterator mulPos,plusPos;
	vector<int>::iterator first;
	vector<int>::iterator end;

	while(true){
		bool mul=false;
		first = targetv.begin();
		end = targetv.end();
		
		for(i=first+cursor;*i!=RPAREN && i!=end;i++){
			if(*i==MUL){
				mul= true;
				mulPos = i;
				break;
			}
		}

		if(mul){
			int num = calc2(*(mulPos-1),*(mulPos+1),*mulPos);
			targetv.erase(mulPos-1,mulPos+2);
			targetv.insert(mulPos-1,num);
		}
		else break;
	
	}

	while(true){
		bool plus=false;
		first = targetv.begin();
		end = targetv.end();
		
		for(i=first+cursor;*i!=RPAREN && i!=end;i++){
			if(*i==PLUS){
				plus= true;
				plusPos = i;
				break;
			}
		}

		if(plus){
			int num = calc2(*(plusPos-1),*(plusPos+1),*plusPos);
			targetv.erase(plusPos-1,plusPos+2);
			targetv.insert(plusPos-1,num);
		}
		else break;
	
	}

	return targetv[cursor];
}

int rec(int cursor){

	vector<int>::iterator i,j,k;
	vector<int>::iterator first;
	vector<int>::iterator end;

	while(true){

		int firstPos=-1;

		for(int ii=cursor;ii<targetv.size();ii++){
			if(targetv[ii]==LPAREN){ 
				firstPos=ii;
				break;
			}
		}
	

		if(firstPos!=-1){
			int depth=1;		
			first = targetv.begin();
			end = targetv.end();
			for(j=first+firstPos+1;j!=end;j++){
				if(*j==LPAREN) depth++;
				if(*j==RPAREN) depth--;
				if(depth==0){
					
					int num = rec(firstPos+1);
					if(num==ERR) return ERR;
					
					first = targetv.begin();
					end = targetv.end();

					depth = 1;
					for(k=first+firstPos+1;k!=end;k++){
						if(*k==LPAREN) depth++;
						if(*k==RPAREN) depth--;
						if(depth==0){
							targetv.erase(first+firstPos,k+1);
							targetv.insert(first+firstPos,num);
							break;
						}
					}
					break;
				}
			}

			if(depth!=0) return ERR;
			
		}
		else break;
	}

	return calc(cursor);
	
}

void separate(){
	
	for(int i=0;i<target.length();i++){
		
		if(isdigit(target[i])){
			int sum=0;
			
			while(i<target.length() &&isdigit(target[i])){
				sum*=10;
				sum+=target[i]-'0';
				i++;
			}
			
			i--;
			targetv.push_back(sum);
			continue;
		}
		
		if(target[i]=='+') targetv.push_back(PLUS);
		if(target[i]=='*') targetv.push_back(MUL);
		if(target[i]=='(') targetv.push_back(LPAREN);
		if(target[i]==')') targetv.push_back(RPAREN);
		
	}
	
}


void work(){
	
	for(int i=0;i<target.length();i++){
		if(!isdigit(target[i]) && target[i]!='+' && 
			target[i]!='*' && target[i]!='(' && target[i]!=')') {
			cout << "ERROR" << endl;
			return;
		}
	}
	
	targetv.clear();
	separate();

	if(errChk()==ERR){
		cout << "ERROR" << endl;
		return;
	}


	/*
	for(int z=0;z<targetv.size();z++){
		if(targetv[z]==PLUS) cout << '+';
		else if(targetv[z]==MUL) cout << '*';
		else if(targetv[z]==LPAREN) cout << '(';
		else if(targetv[z]==RPAREN) cout << ')';
		else cout << targetv[z];
	}cout << endl;
	*/
	
	int ans = rec(0);

	if(ans == ERR) cout << "ERROR" << endl;
	else cout << ans << endl;
	
}

int main(){

	int cases;

	cin >> cases;

	for(int i=0;i<cases;i++){
		cin >> target;
		work();
	}

	return 0;
}