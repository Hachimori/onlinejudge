#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cmath>

#define PI 3.14159265358979323846
#define MAX_SIZE 10000

using namespace std;

class Roof{
public:

  double base, ridge, height, degree;

  Roof(){}  
  Roof(double b, double r, double h, double d):
    base(b), ridge(r), height(h), degree(d) {}

};

class Ans{
public:

  double lotArea, roofArea, coverArea, percentage;

  Ans(){}
  Ans(double l, double r, double c, double p):
    lotArea(l), roofArea(r), coverArea(c), percentage(p) {}
  
};

double totalArea;
int nRoof;
Roof roofList[MAX_SIZE];
Ans ansList[MAX_SIZE];

void split(string str, vector<string> &sList){

  int cursor=0;

  while(cursor<str.length()){

    string s;

    while(cursor<str.length() && str[cursor]==' ') cursor++;

    while(cursor<str.length() && str[cursor]!=' '){
      s += str[cursor];
      cursor++;
    }

    if(s.size()>0)
      sList.push_back(s);

  }

}

bool read(){
  

  if(!(cin >> totalArea)) return false;
  
  nRoof=0;
  int currPushed=0;

  while(true){

    string str;
    vector<string> sList;
    
    getline(cin,str);
    if(nRoof!=0 && str.length()==0) break;
    
    
    split(str,sList);
    
    for(int i=0;i<sList.size();i++,currPushed++){
      if(currPushed==0)
	roofList[nRoof].base = atof(sList[i].c_str());
      else if(currPushed==1)
	roofList[nRoof].ridge = atof(sList[i].c_str());
      else if(currPushed==2)
	roofList[nRoof].height = atof(sList[i].c_str());
      else if(currPushed==3){
	roofList[nRoof].degree = atof(sList[i].c_str());
	currPushed=-1;
	nRoof++;
      }
    }
    
  }
	 
  return true;
}

void work(int cases){
  /*
  cout << totalArea << endl;
  for(int i=0;i<nRoof;i++){
    cout << roofList[i].base << ' ' << roofList[i].ridge 
	 <<  ' ' << roofList[i].height << ' ' << roofList[i].degree << endl;
  }  
  cout << endl;
  */

  double roofArea=0, coverArea=0, percent;

  for(int i=0;i<nRoof;i++)
    roofArea += (roofList[i].base+roofList[i].ridge)*roofList[i].height/2;

  for(int i=0;i<nRoof;i++)
    coverArea += cos(roofList[i].degree/180*PI)*
      (roofList[i].base+roofList[i].ridge)*roofList[i].height/2;

  percent=min(coverArea/totalArea,100.0);

  ansList[cases] = Ans(totalArea,roofArea,coverArea,percent);
  
}

void printResult(int nLot){

  cout << "Roof Area     Floor Area     % Covered" << endl;
  cout << "---------     ----------     ---------" << endl;
  
  for(int i=0;i<nLot;i++)
    printf("%9.2f     %10.2f     %8.2lf%%\n"
	   ,ansList[i].roofArea,ansList[i].coverArea,ansList[i].percentage*100);
  
  cout << endl;
  


  double sumRoofArea=0, sumCoverArea=0,percentage, sumLotArea=0;

  for(int i=0;i<nLot;i++){
    sumRoofArea+=ansList[i].roofArea;
    sumCoverArea+=ansList[i].coverArea;
    sumLotArea+=ansList[i].lotArea;
  }

  percentage=sumCoverArea/sumLotArea;

  printf("Total surface area of roofs%12.2lf\n",sumRoofArea);
  printf("Total area covered by roofs%12.2lf\n",sumCoverArea);
  printf("Percentage of total area covered by roofs%8.2lf%%\n",percentage*100);
  printf("Average roof surface area per lot%16.2lf\n",sumRoofArea/nLot);
  printf("Average floor space covered per lot%14.2lf\n",sumCoverArea/nLot);
  
}

int main(){

  int cases;
  
  for(cases=0;read();cases++)
    work(cases);

  printResult(cases);
  
  return 0;
}
