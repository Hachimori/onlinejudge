#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

double length;

void read(){

	
	char str[1000];

	length = 0.0;	

	int startx,starty;
	cin >> startx >> starty;
	gets(str);

	while(true){
		
		int x1, y1, x2, y2;	

		if(gets(str)==NULL) break;
		if(strlen(str)==0) break;

		sscanf(str,"%d%d%d%d",&x1,&y1,&x2,&y2);

		length += sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		
	}
	
}

void work(){
	
	//cout << length << endl;

	double time = length/10000;
	int hour = (int)time;
	double minuteD = time - (int)time;
	int minuteI = (int)(minuteD*60+0.5);
	
	if(minuteI==60){ 
		hour++;
		minuteI = 0;
	}

	cout << hour << ":";
	if(minuteI<10) cout << 0;
	cout << minuteI << endl;

}

int main(){

	char str[100];
	int cases;

	cin >> cases;
	gets(str);
	gets(str);

	for(int i=0;i<cases;i++){
		if(i!=0) cout << endl;
		read();
		work();
	}


	return 0;
}
