#include<iostream>
#include<string>

using namespace std;

int main(){

  string str;

  while(getline(cin,str)!=NULL){

    for(int i=0;i<str.length();i++){
      if(str[i]=='1') cout << "`";
      if(str[i]=='X') cout << "Z";
      if(str[i]=='S') cout << "A";
      if(str[i]=='W') cout << "Q";
      if(str[i]=='2') cout << "1";
      if(str[i]=='C') cout << "X";
      if(str[i]=='D') cout << "S";
      if(str[i]=='E') cout << "W";
      if(str[i]=='3') cout << "2";
      if(str[i]=='V') cout << "C";
      if(str[i]=='F') cout << "D";
      if(str[i]=='R') cout << "E";
      if(str[i]=='4') cout << "3";
      if(str[i]=='B') cout << "V";
      if(str[i]=='G') cout << "F";
      if(str[i]=='T') cout << "R";
      if(str[i]=='5') cout << "4";
      if(str[i]=='N') cout << "B";
      if(str[i]=='H') cout << "G";
      if(str[i]=='Y') cout << "T";
      if(str[i]=='6') cout << "5";
      if(str[i]=='M') cout << "N";
      if(str[i]=='J') cout << "H";
      if(str[i]=='U') cout << "Y";
      if(str[i]=='7') cout << "6";
      if(str[i]==',') cout << "M";
      if(str[i]=='K') cout << "J";
      if(str[i]=='I') cout << "U";
      if(str[i]=='8') cout << "7";
      if(str[i]=='.') cout << ",";    
      if(str[i]=='L') cout << "K";     
      if(str[i]=='O') cout << "I";     
      if(str[i]=='9') cout << "8";     
      if(str[i]=='/') cout << ".";     
      if(str[i]==';') cout << "L";     
      if(str[i]=='P') cout << "O";     
      if(str[i]=='0') cout << "9";     
      if(str[i]=='\'') cout << ";";     
      if(str[i]=='[') cout << "P";     
      if(str[i]=='-') cout << "0";     
      if(str[i]==']') cout << "[";     
      if(str[i]=='=') cout << "-";     
      if(str[i]=='\\') cout << "Z";     
      if(str[i]==' ') cout << " ";      

    }
    cout << endl;
  }

  return 0;
}
