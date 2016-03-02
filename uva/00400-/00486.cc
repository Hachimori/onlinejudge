#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>
using namespace std;

map<string,int> num2val;

void makeTable(){
  string numStr[]={"zero", "one", "two", "three", "four", "five", "six", 
                   "seven", "eight", "nine", "ten", "eleven", "twelve", 
                   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                   "eighteen", "nineteen", "twenty", "thirty", "forty", 
                   "fifty", "sixty", "seventy", "eighty", "ninety",
                   "hundred", "thousand", "million"};
  int numVal[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
                30,40,50,60,70,80,90,100,1000,1000000};

  for(int i=0;i<31;i++)
    num2val[numStr[i]] = numVal[i];
}


vector<string> sList;

bool read(){
  sList.clear();
  string str;
  if(!getline(cin,str)) return false;
  stringstream in(str);
  while(in >> str) sList.push_back(str);
  return true;
}


void work(){
  int sum = 0;
  for(int i=0;i<sList.size();){
    if(!num2val.count(sList[i])){i++; continue;}
    
    int toAdd = num2val[sList[i++]];
    if(i<sList.size() && sList[i]=="hundred"){
      toAdd *= 100;
      i++;
    }
    
    if(i<sList.size() && num2val.count(sList[i]) && 
       (sList[i]!="thousand" && sList[i]!="million")){
      toAdd += num2val[sList[i]];
      i++;
    }

    if(i<sList.size() && num2val.count(sList[i]) && 
       (sList[i]!="thousand" && sList[i]!="million")){
      toAdd += num2val[sList[i]];
      i++;
    }
      
    if(i<sList.size() && sList[i]=="thousand"){
      toAdd *= 1000;
      i++;
    }
    else if(i<sList.size() && sList[i]=="million"){
      toAdd *= 1000000;
      i++;
    }
    
    sum += toAdd;
  }

  if(sList[0]=="negative") cout << '-';
  cout << sum << endl;
}


int main(){
  makeTable();
  while(read()) work();
  return 0;
}

