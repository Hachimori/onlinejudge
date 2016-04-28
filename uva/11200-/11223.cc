#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
using namespace std;

map<string,string> M;

void makeTable(){
  M[".-"] = "A";
  M[".---"] = "J";
  M["..."] = "S";
  M[".----"] = "1";
  M[".-.-.-"] = ".";
  M["---..."] = ":";
  M["-..."] = "B";
  M["-.-"] = "K";
  M["-"] = "T";
  M["..---"] = "2";
  M["--..--"] = ",";
  M["-.-.-."] = ";";
  M["-.-."] = "C";
  M[".-.."] = "L";
  M["..-"] = "U";
  M["...--"] = "3";
  M["..--.."] = "?";
  M["-...-"] = "=";
  M["-.."] = "D";
  M["--"] = "M";
  M["...-"] = "V";
  M["....-"] = "4";
  M[".----."] = "'";
  M[".-.-."] = "+";
  M["."] = "E";
  M["-."] = "N";
  M[".--"] = "W";
  M["....."] = "5";
  M["-.-.--"] = "!";
  M["-....-"] = "-";
  M["..-."] = "F";
  M["---"] = "O";
  M["-..-"] = "X";
  M["-...."] = "6";
  M["-..-."] = "/";
  M["..--.-"] = "_";
  M["--."] = "G";
  M[".--."] = "P";
  M["-.--"] = "Y";
  M["--..."] = "7";
  M["-.--."] = "(";
  M[".-..-."] = "\"";
  M["...."] = "H";
  M["--.-"] = "Q";
  M["--.."] = "Z";
  M["---.."] = "8";
  M["-.--.-"] = ")";
  M[".--.-."] = "@";
  M[".."] = "I";
  M[".-."] = "R";
  M["-----"] = "0";
  M["----."] = "9";
  M[".-..."] = "&";
}

vector<string> sList;

void read(){
  sList.clear();

  string s; getline(cin,s);

  for(int i=0;i<s.size();){
    string toPush;
    while(i<s.size() && s[i]!=' ') toPush += s[i++];

    sList.push_back(toPush);
    i++;
    while(i<s.size() && s[i]==' ') sList.push_back(" "), i++;
  }
}

void work(int cases){
  cout << "Message #" << cases << endl;

  for(int i=0;i<sList.size();i++)
    if(sList[i]==" ")
      cout << ' ';
    else
      cout << M[sList[i]];
  cout << endl;
}

int main(){
  makeTable();

  int cases;
  cin >> cases;

  string s; getline(cin,s);

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work(i+1);
  }
  
  return 0;
}
