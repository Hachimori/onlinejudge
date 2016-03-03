#include<iostream>
#include<vector>
#include<string>
#include<map>

#define MAX_SIZE 28

using namespace std;

class Graph{
public:

	vector< vector<int> > adjList;

	Graph(){}
	Graph(int n){
		adjList.assign(n+1,vector<int>());
	}

	void insert(int source, int target){
		adjList[source].push_back(target);
	}

	vector<int> &operator[](int n){
		return adjList[n];
	}

};

int nNode;
Graph g;
map<char,int> charToInt;
map<int,char> intToChar;
string str1, str2;

bool read(){
	
	if(!(cin >> str1 >> str2)) return false;	
	
	charToInt.clear();
	intToChar.clear();

	nNode=str1.size();
	g = Graph(nNode);

	for(int i=0;i<str1.size();i++){
		charToInt[str1[i]] = i;
		intToChar[i] = str1[i];
	}

	return true;
}


void print(int curr){
	
	if(g[curr].size()==0){
		cout << intToChar[curr];
		return;
	}

	for(int i=0;i<g[curr].size();i++)
		print(g[curr][i]);

	cout << intToChar[curr];
}

void construct(int currNode, int str1Left, int str1Right, int str2Left, int str2Right){
	
	//cout << intToChar[currNode] << " " << str1Left << "-" << str1Right << endl;

	if(str1Right-str1Left<=1) return;

	int parentPos;
	for(int i=str2Left;i<str2Right;i++)
		if(charToInt[str2[i]]==currNode){
			parentPos = i;
			break;
		}
	
	int nextRight = str1Left+parentPos-str2Left+1;

	
	if(str1Left+1!=nextRight) g.insert(currNode,str1Left+1);
	
	construct(str1Left+1,str1Left+1,nextRight,str2Left,parentPos);

	if(nextRight!=str1Right) g.insert(currNode,nextRight);
	
	construct(nextRight,nextRight,str1Right,parentPos+1,str2Right);


}

void work(){

	
	construct(0,0,nNode,0,nNode);

	print(0);
	cout << endl;

}

int main(){

	while(read())
		work();

	return 0;
}