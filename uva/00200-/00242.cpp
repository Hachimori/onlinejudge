#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

#define MAX_PICK 11
#define MAX_RANGE 10005

using namespace std;

int nPick, nStampList, maxCover;
vector<int> maxStampList;
vector< vector<int> > stampList;

bool read(){

	cin >> nPick;
	if(nPick==0) return false;

	cin >> nStampList;
	stampList.assign(nStampList,vector<int>());

	for(int i=0;i<nStampList;i++){
		int nStamp;
		cin >> nStamp;

		for(int j=0;j<nStamp;j++){
			int val;
			cin >> val;
			stampList[i].push_back(val);
		}
	}

	return true;
}

void work(){
	
	bool isAvail[MAX_PICK][MAX_RANGE];

	maxCover=0;
	maxStampList = stampList[0];

	for(int i=0;i<nStampList;i++){
	
		for(int m=0;m<nPick;m++)
			fill(isAvail[m],isAvail[m]+MAX_RANGE,false);
	
		for(int k=0;k<stampList[i].size();k++)
			isAvail[0][stampList[i][k]]=true;

		for(int currPick=0;currPick<nPick-1;currPick++){
			for(int l=0;l<=nPick*stampList[i].back();l++){
				if(isAvail[currPick][l]){					

					for(int n=0;n<stampList[i].size();n++)
						if(l+stampList[i][n]<=nPick*stampList[i].back())
							isAvail[currPick+1][l+stampList[i][n]]=true;

					isAvail[currPick+1][l]=true;
				}
			}
		}

		int score=0;
		for(int o=1;o<MAX_RANGE;o++)
			if(isAvail[nPick-1][o])
				score=o;
			else
				break;

		if(maxCover<score){
			maxCover = score;
			maxStampList = stampList[i];
		}
		else if(maxCover==score){
			
			if(maxStampList.size()>stampList[i].size()){
				maxStampList = stampList[i];
			}
			else if(maxStampList.size()==stampList[i].size()){

				for(int p=stampList[i].size()-1;p>=0;p--){
					if(maxStampList[p]>stampList[i][p]){
						maxStampList = stampList[i];
						break;
					}
					else if(maxStampList[p]<stampList[i][p])
						break;
				}
			}

		}

	}

	printf("max coverage = %3d :",maxCover);
	for(int q=0;q<maxStampList.size();q++)
		printf("%3d",maxStampList[q]);
	cout << endl;
}

int main(){
	
	while(read())
		work();

	return 0;
}