#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<set>

#define MAX_SIZE 300

using namespace std;

int nProfile, nTitle;
int numList[MAX_SIZE];
vector<string> profileList[MAX_SIZE];
vector<string> titleList[MAX_SIZE];

bool split(string str, bool isTitle, vector<string> &sList){
  
  int cursor=0;

  while(cursor<str.length()){
    
    while(cursor<str.length() && str[cursor]==' ') cursor++;

    string toPush;

    while(cursor<str.length() && str[cursor]!=' ' && str[cursor]!='|'){

      if(isTitle && isalpha(str[cursor]))
	toPush+=tolower(str[cursor]);
      else if(!isTitle)
	toPush+=str[cursor];

      cursor++;
    }
    
    if(toPush.size()>0)
      sList.push_back(toPush);
    
    if(cursor<str.length() && str[cursor]=='|') return true;
    
  }
  
  return false;
}

void read(){

  nProfile=nTitle=0;

  while(true){    
    string id;
    cin >> id;
    
    if(id[0]=='T') break;
    
    cin >> numList[nProfile];


    string str;
    getline(cin,str);

    split(str,false,profileList[nProfile]);
    nProfile++;
  }

  
  string tmpStr;  
  
  while(true){
    getline(cin,tmpStr);
    if(split(tmpStr,true,titleList[nTitle])) break;
  }
  nTitle++;
  
  while(true){
    string id;
    cin >> id;

    if(id=="#") break;
    
    while(true){
      string str;
      getline(cin,str);      
      if(split(str,true,titleList[nTitle])) break;
    }    
    nTitle++; 
  }

}

void work(){
  /*
  for(int i=0;i<nProfile;i++){
    for(int j=0;j<profileList[i].size();j++){
      cout << profileList[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  
  for(int i=0;i<nTitle;i++){
    for(int j=0;j<titleList[i].size();j++){
      cout << titleList[i][j] << ' ';
    }cout << endl;
  }cout << endl;
  */

  set<int> haveWord[MAX_SIZE];
  
  for(int i=0;i<nProfile;i++){

    for(int j=0;j<profileList[i].size();j++){
      for(int k=j+1;k<profileList[i].size();k++){
	
	for(int m=0;m<nTitle;m++){	  

	  for(int l=0;l<titleList[m].size();l++){
	    for(int n=l+1;n<=l+numList[i]+1 && n<titleList[m].size();n++){
	      
	      if(titleList[m][l]==profileList[i][j] && 
		 titleList[m][n]==profileList[i][k]){
		haveWord[i].insert(m);
		break;
	      }
	      else if(titleList[m][l]==profileList[i][k] && 
		      titleList[m][n]==profileList[i][j]){
		haveWord[i].insert(m);
		break;
	      }
	      
	    }	
	  }
	  
	}

      }
    }

  }
  
  for(int i=0;i<nProfile;i++){

    cout << i+1 << ":";
    for(set<int>::iterator k=haveWord[i].begin();k!=haveWord[i].end();k++){
      if(k==haveWord[i].begin()) cout << " " << *k+1;
      else cout << ',' << *k+1;
    }
    
    cout << endl;
  }
  
}

int main(){

  read();
  work();

  return 0;
}
