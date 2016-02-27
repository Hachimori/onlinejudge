#include<iostream>
#include<vector>
#include<climits>

#define MAX_SIZE 25

using namespace std;

class Element{
public:

	double value;
	vector<int> path;

	Element(){}
	Element(double v, vector<int> p): value(v), path(p) {}

};

int size;
int minLeng;
vector<int> minPath;
double table[MAX_SIZE][MAX_SIZE];

bool read(){

	if(!(cin >> size)) return false;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(j==i)
				table[i][j]=1.0;
			else
				cin >> table[i][j];
	/*
	for(int x=0;x<size;x++){
		for(int y=0;y<size;y++)	{
			cout << table[x][y] << " ";
		}cout << endl;
	}cout << endl;
	*/

	return true;
}

bool checkArbitrage(int curr, int target, Element element[MAX_SIZE][MAX_SIZE]){

	return (element[curr][target].path.front()==element[curr][target].path.back() &&
		    element[curr][target].value>1.01);

}

void rec(int currLeng, Element element[MAX_SIZE][MAX_SIZE]){
	
	if(currLeng==size) return;
	//if(currLeng==minLeng) return;

	for(int i=0;i<size;i++){

		for(int j=0;j<size;j++){
			
			if(element[currLeng+1][j].value<element[currLeng][i].value*table[i][j]){				
				element[currLeng+1][j]=element[currLeng][i];
				element[currLeng+1][j].value*=table[i][j];
				element[currLeng+1][j].path.push_back(j);

			
				if(checkArbitrage(currLeng+1,j,element)){
					if(minLeng>element[currLeng+1][j].path.size()){
						minLeng = element[currLeng+1][j].path.size();
						minPath = element[currLeng+1][j].path;
					}								
					return;
				}
			}

		}
	}

	rec(currLeng+1,element);
}

void work(){

	Element element[MAX_SIZE][MAX_SIZE];

	minLeng=INT_MAX;

	for(int i=0;i<size;i++){
	
		for(int j=0;j<size+1;j++)
			for(int k=0;k<size;k++)
				element[j][k] = Element(-1.0,vector<int>());
		
		vector<int> p;
		p.push_back(i);
		element[0][i] = Element(1.0,p);

		rec(0,element);
	
	}

	if(minLeng==INT_MAX)
		cout << "no arbitrage sequence exists" << endl;
	else {
		for(int l=0;l<minLeng;l++){
			if(l==0)
				cout << minPath[l]+1;
			else
				cout << " " << minPath[l]+1;
		}cout << endl;
	}

}

int main(){

	while(read())
		work();

	return 0;
}