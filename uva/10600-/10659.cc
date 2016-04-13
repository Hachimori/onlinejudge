#include<iostream>
#include<string>
#include<vector>

using namespace std;

void split(string source, vector< vector<string> > &strList, int line,  char c){
  
  for(int i=0;i<source.length();i++){
    string substr;
    
    while(i<source.length() && source[i]!=c)
      substr+=source[i++];

    if(substr.length()>0)
      strList[line].push_back(substr);
  }
  
}

vector< vector<string> > wordList;
int width, height;

void read(){
  
  string str;
  int nLine;
  
  cin >> nLine;
  wordList.clear();
  wordList.assign(nLine,vector<string>());

  getline(cin,str);

  for(int i=0;i<nLine;i++){
    getline(cin,str);
    split(str,wordList,i,' ');
  }
  
  cin >> width >> height;
  
}

bool fitable(int size){
  
  int currLine=0, currWord=0, currX, currY;

   
  for(currY=0;currY+size<=height && currLine<wordList.size() && currWord<wordList[currLine].size();
      currY+=size){
    for(currX=0;
	 currWord<wordList[currLine].size() && currX+size*wordList[currLine][currWord].length()<=width;
	currX+=size*wordList[currLine][currWord].length()+size,currWord++){
      //  cout << currWord << "  " << currX <<  " " << currY << endl;
    }
    //cout << currWord << "  " << currX << " " << currY << endl;
    
    if(currWord==wordList[currLine].size()){
      currWord=0;
      currLine++;
    }

  }
  //cout << endl;
  

  return currLine==wordList.size();
}

void work(){

  /*
  for(int i=0;i<wordList.size();i++){
    for(int j=0;j<wordList[i].size();j++)
      cout << wordList[i][j].size() << " ";
    cout << endl;
  }
  cout << endl;
  */

  
  for(int size=28;size>=8;size--){
    if(fitable(size)){
      cout << size << endl;
      return;
    }
  }

  cout << "No solution" << endl;

}

int main(){
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
