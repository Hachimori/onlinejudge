#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<sstream>
#include<algorithm>

#define MAX_SIZE 105
#define MAX_TIME 245

using namespace std;

class Data{
public:

  int val, time;
  string name;

  Data(){}
  Data(int v, int t, string n): val(v), time(t), name(n) {}
  
  bool operator< (const Data &d) const {
    if(time<d.time) return true;
    else if(time==d.time) {
      if(val>d.val) return true;
      else if(val==d.val){
	return name<d.name;
      }
    }

    return false;
  }
  
};

int timeLimit;
int nData;
Data dataList[MAX_SIZE];
int board[MAX_SIZE][MAX_TIME][MAX_SIZE];
pair<int,int> val[MAX_SIZE][MAX_TIME];     // val, tail

void split(string str, vector<string> &strList){
  
  int nDigitRead=0;
  int cursor=0;
  
  while(nDigitRead!=2){
    
    string tmp;

    while(str[cursor]==' ') cursor++;
    
    while(str[cursor]!=' '){
      tmp+=str[cursor];
      cursor++;
    }

    strList.push_back(tmp);    
    nDigitRead++;
  }
  

  while(str[cursor]==' ') cursor++;
  
  strList.push_back(str.substr(cursor,str.length()-cursor));
  
  /*
  stringstream ss(str);
  string tmp;
  ss >> tmp;
  strList.push_back(tmp);
  ss >> tmp;
  strList.push_back(tmp);
  getline(ss, tmp);
  strList.push_back(tmp.substr(1,tmp.size()-1));
  */
}

void read(){
  
  cin >> timeLimit;

  nData=0;

  string str; getline(cin,str);
  

  while(true){
    if(getline(cin,str)==NULL) break;
    if(str.size()==0) break;
    
    vector<string> strList;
    
    split(str,strList);
    
    dataList[nData] = Data(atoi(strList[0].c_str()),atoi(strList[1].c_str()),strList[2]);

    nData++;
    
  }
  
  
}

void knapsack(int curr){

  if(curr==nData) return;
  
  for(int i=0;i<=timeLimit;i++){
    
    if(dataList[curr].time==i && val[curr][i].first<dataList[curr].val){ 
      board[curr][i][0]=curr;
      val[curr][i] = make_pair(dataList[curr].val,1);
    }    
    
    if(val[curr-1][i].first!=-1){
      if(val[curr][i].first<val[curr-1][i].first){	
	for(int j=0;j<val[curr-1][i].second;j++)
	  board[curr][i][j] = board[curr-1][i][j];
	
	val[curr][i] = val[curr-1][i];
      }

      if(i+dataList[curr].time<=timeLimit &&
	 val[curr][i+dataList[curr].time].first
	 <val[curr-1][i].first+dataList[curr].val){
	
	for(int j=0;j<val[curr-1][i].second;j++)
	  board[curr][i+dataList[curr].time][j] = board[curr-1][i][j];
	board[curr][i+dataList[curr].time][val[curr-1][i].second] = curr;
	
	val[curr][i+dataList[curr].time] = val[curr-1][i];
	val[curr][i+dataList[curr].time].first+=dataList[curr].val;
	val[curr][i+dataList[curr].time].second++;
      }
      
    }
    
  }

  knapsack(curr+1);

}

void work(){
  /*
  cout << endl;  cout << endl;
  for(int i=0;i<nData;i++){
    cout << dataList[i].name << endl;
  }
  */
 

  for(int i=0;i<nData+1;i++)
    fill(val[i],val[i]+timeLimit+1,make_pair(-1,0));
  
  if(dataList[0].time<=timeLimit){
    val[0][dataList[0].time] = make_pair(dataList[0].val,1);
    board[0][dataList[0].time][0] = 0;
  }

  /*
  for(int i=0;i<nData+1;i++){
    for(int j=0;j<30;j++){
      cout << val[i][j].first << ' ';
    }cout << endl;
  }cout << endl;
  */
  
  knapsack(1);

  int maxVal=-1, maxPos;
  
  for(int i=0;i<=timeLimit;i++){
    if(maxVal<val[nData-1][i].first){
      maxPos = i;
      maxVal = val[nData-1][i].first;
    }
  }

  if(maxVal==-1){
    cout << "There is not enough time to present any evidence. Drop the charges." << endl;
    return;
  }
 
  
  cout << "Score  Time  Description" << endl;
  cout << "-----  ----  -----------" << endl;

  int sum=0;

  vector<Data> dList;
  for(int i=0;i<val[nData-1][maxPos].second;i++)
    dList.push_back(dataList[board[nData-1][maxPos][i]]);

  //sort(dList.begin(),dList.end());
      
  for(int i=0;i<val[nData-1][maxPos].second;i++){
    printf("%3d    %3d   %s\n",dList[i].val,
	                       dList[i].time,
	                       dList[i].name.c_str());
    sum+=dList[i].time;
  }
  
  cout << endl;
 
  cout << "Total score: " << maxVal << " points" << endl;
  cout << " Total time: " << sum << " hours" << endl;
  
  
}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
  
  return 0;
}
