#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

queue<char> cQ;
queue<char> vQ;

void pushQ(queue<char> &q,int n,char c){
	for(int i=0;i<n;i++)
		q.push(c);
}

int main(){

	pushQ(vQ,21,'A');
	pushQ(vQ,21,'U');
	pushQ(vQ,21,'E');
	pushQ(vQ,21,'O');
	pushQ(vQ,21,'I');

	pushQ(cQ,5,'J');
	pushQ(cQ,5,'S');
	pushQ(cQ,5,'B');
	pushQ(cQ,5,'K');
	pushQ(cQ,5,'T');

	pushQ(cQ,5,'C');
	pushQ(cQ,5,'L');
	pushQ(cQ,5,'D');
	pushQ(cQ,5,'M');
	pushQ(cQ,5,'V');

	pushQ(cQ,5,'N');
	pushQ(cQ,5,'W');
	pushQ(cQ,5,'F');
	pushQ(cQ,5,'X');
	pushQ(cQ,5,'G');

	pushQ(cQ,5,'P');
	pushQ(cQ,5,'Y');
	pushQ(cQ,5,'H');
	pushQ(cQ,5,'Q');
	pushQ(cQ,5,'Z');
	pushQ(cQ,5,'R');


	int cases;
	cin >> cases;

	for(int i=0;i<cases;i++){
		int n;
		cin >> n;
		
		queue<char> cons = cQ;
		queue<char> vowel = vQ;
		vector<char> cv;
		vector<char> vv;


		for(int j=0;j<n;j++){
			if(j%2==0){ 
				char c = vowel.front();
				vowel.pop();
				vv.push_back(c);
			}
			else{
				char c = cons.front();
				cons.pop();
				cv.push_back(c);
			}
		}

		sort(vv.begin(),vv.end());
		sort(cv.begin(),cv.end());

		cout << "Case " << i+1 << ": ";
		for(int k=0;k<vv.size()+cv.size();k++){
			if(k%2==0) cout << vv[k/2];
			else cout << cv[(k-1)/2];
		}
		cout << endl;
	}

	return 0;
}
