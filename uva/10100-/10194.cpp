#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<fstream>

//#define cin fin

using namespace std;

//ifstream fin("tmp.txt");

class Data{
public:

	string name;
	int point, nWin, nTie, nLose, nGoal, nOppGoal, nGame;

	Data(){}
	Data(string name): name(name) {
		point=0,nWin=0,nTie=0,nLose=0,nGoal=0,nOppGoal=0,nGame=0;
	}

	bool operator< ( const Data &d ) const {
		if(point>d.point) return true;
		else if(point==d.point){
			if(nWin>d.nWin) return true;
			else if(nWin==d.nWin){
				if(nGoal-nOppGoal>d.nGoal-d.nOppGoal) return true;
				else if(nGoal-nOppGoal==d.nGoal-d.nOppGoal){
					if(nGoal>d.nGoal) return true;
					else if(nGoal==d.nGoal){
						if(nGame<d.nGame) return true;
						else if(nGame==d.nGame){
							
							for(int i=0;i<name.length();i++){
								if(toupper(name[i])<toupper(d.name[i])) return true;
								else if(toupper(name[i])>toupper(d.name[i])) return false;
							}
							
							if(name.length()<d.name.length()) return true;
						}
					}
				}
			}
		}

		return false;
	}
	
};

int nTeam;
string title;
map<string,Data> teamList;

void split(string str, vector<string> &strList){
	
	int cursor=0;

	while(cursor<str.length()){
		
		string toPush;

		while(cursor<str.length() && str[cursor]!='#' && str[cursor]!='@'){
			toPush += str[cursor];
			cursor++;
		}cursor++;
		
		strList.push_back(toPush);
	}

}

void read(){

	string str;

	teamList.clear();
	
	getline(cin,title);

	cin >> nTeam; getline(cin,str);

	for(int i=0;i<nTeam;i++){
		string name;
		getline(cin,name);

		teamList[name] = Data(name);
	}


	int nGame; 
	cin >> nGame; getline(cin,str);

	for(int j=0;j<nGame;j++){
		getline(cin,str);

		vector<string> strList;

		split(str,strList);
	
		/*
		for(int k=0;k<strList.size();k++)
			cout<< strList[k] << " ";
		cout << endl;
		*/

		teamList[strList[0]].nGame++;
		teamList[strList[3]].nGame++;
		teamList[strList[0]].nGoal+=atoi(strList[1].c_str());
		teamList[strList[3]].nGoal+=atoi(strList[2].c_str());
		teamList[strList[0]].nOppGoal+=atoi(strList[2].c_str());
		teamList[strList[3]].nOppGoal+=atoi(strList[1].c_str());
		
		if(atoi(strList[1].c_str())<atoi(strList[2].c_str())){
			teamList[strList[3]].nWin++;
			teamList[strList[0]].nLose++;
			teamList[strList[3]].point+=3;
		}
		else if(atoi(strList[1].c_str())>atoi(strList[2].c_str())){
			teamList[strList[0]].nWin++;
			teamList[strList[3]].nLose++;
			teamList[strList[0]].point+=3;
		}
		else {
			teamList[strList[0]].nTie++;
			teamList[strList[3]].nTie++;
			teamList[strList[0]].point++;
			teamList[strList[3]].point++;
		}

	}

}

void work(){

	cout << title << endl;
	
	vector<Data> result;

	for(map<string,Data>::iterator i=teamList.begin();i!=teamList.end();i++)
		result.push_back(i->second);
		
	sort(result.begin(),result.end());

	for(int j=0;j<result.size();j++){
		cout << j+1 << ") " << result[j].name << " " << result[j].point << "p, " << result[j].nGame 
			 << "g " << "(" << result[j].nWin << "-" << result[j].nTie << "-" << result[j].nLose << ")" 
			 << ", " << result[j].nGoal-result[j].nOppGoal << "gd (" << result[j].nGoal << "-" 
			 << result[j].nOppGoal << ")" << endl;
	}

}

int main(){

	int cases;
	string str;
	
	cin >> cases; getline(cin,str);

	for(int i=0;i<cases;i++){
		if(i!=0) cout << endl;
		read();
		work();
	}

	return 0;
}